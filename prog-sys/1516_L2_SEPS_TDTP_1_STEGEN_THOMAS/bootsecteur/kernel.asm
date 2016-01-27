[BITS 32] ; on passeen 32 bit car on est en mode protégé
[ORG 0x1000]

; Affichage d'un message par ecriture dans la RAM video
    mov byte [0xB8A00], 'E'
    mov byte [0xB8A01], 0x57
    mov byte [0xB8A02], 'N'
    mov byte [0xB8A03], 0x0A
    mov byte [0xB8A04], 'T'
    mov byte [0xB8A05], 0x4E
    mov byte [0xB8A06], 'E'
    mov byte [0xB8A07], 0x62
    mov byte [0xB8A08], 'R'
    mov byte [0xB8A09], 0x0E

end:
    jmp end

