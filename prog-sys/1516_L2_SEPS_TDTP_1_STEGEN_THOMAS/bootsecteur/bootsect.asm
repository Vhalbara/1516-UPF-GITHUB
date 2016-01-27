%define BASE   0x100  
%define KSIZE  1  ; nombre de secteurs de 512 octets a charger

[BITS 16]
[ORG 0x0]

jmp start
%include "UTIL.INC"
start:

; initialisation des segments en 0x07C0
    mov ax, 0x07C0
    mov ds, ax
    mov es, ax
    mov ax, 0x8000  ; stack en 0xFFFF
    mov ss, ax
    mov sp, 0xf000

; recuparation de l'unite de boot
    mov [bootdrv], dl  

; affiche un msg
    mov si, msgDebut
    call afficher

; charger le noyau
    xor ax, ax
    int 0x13

    push es
    mov ax, BASE
    mov es, ax
    mov bx, 0

    mov ah, 2
    mov al, KSIZE
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, [bootdrv]
    int 0x13
    pop es

    ; initialisation du pointeur sur la GDT
    mov ax, gdtend    ; calcule la limite de GDT
    mov bx, gdt
    sub ax, bx
    mov word [gdtptr], ax

    xor eax, eax      ; calcule l'adresse lineaire de GDT
    xor ebx, ebx
    mov ax, ds
    mov ecx, eax
    shl ecx, 4
    mov bx, gdt
    add ecx, ebx
    mov dword [gdtptr+2], ecx

    ; passage en modep
    cli

    ; charge la gdt
    lgdt [gdtptr]

    ; PE mis a 1 (CR0) (on passe véritablement en mode protégé)
    mov eax, cr0
    or  ax, 1
    mov cr0, eax        ; PE mis a 1 (CR0)

    jmp next

next:
    ; reinitialise le segment de donnees
    mov ax, 0x10        
    mov ds, ax
    mov fs, ax
    mov gs, ax
    mov es, ax

    ; reinitialise la pile
    mov ss, ax
    mov esp, 0x9F000    

    ; reinitialise le segment de code et execute le noyau
    jmp dword 0x8:0x1000    

    ; affiche un msg
    mov si, kerCharged
    call afficher

; saut vers le kernel
    jmp dword BASE:0

;---------------------------- Message pour l'affichage --------------------------------------

msgDebut: db "Chargement du kernel. Cela peut prendre quelque miliseconde!", 13, 10, 0
kerCharged: db "Kernel chargé ...", 13, 10, 0

;--------------------------------------------------------------------------------------------

bootdrv: db 0

;------------- pointeur sur le début du tableau qui contient trois descripteurs -------------

gdt: ;décrit le descripteur NULL
    db 0, 0, 0, 0, 0, 0, 0, 0

gdt_cs: ;décrit le segment de code.
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10011011b, 11011111b, 0x0

gdt_ds: ;décrit le segment de données.
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10010011b, 11011111b, 0x0

gdtend:

;- pointeur sur une structure qui contient les informations à charger dans le registre GDTR -

gdtptr:
    dw 0  ; limite
    dd 0  ; base

;---------------------------------------------------------------------------------------------

;; NOP jusqu'a 510
times 510-($-$$) db 144
dw 0xAA55
