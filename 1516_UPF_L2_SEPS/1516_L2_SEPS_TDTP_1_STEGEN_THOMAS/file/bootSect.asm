[BITS 16]  			  ; indique a nasm que l'on travaille en 16 bits
[ORG 0x7C00]
 
main:
  jmp short start                 ; jump to beginning of code
  nop
 
bootsector:
 iOEM:          db "Stegt   "     ; OEM String
 iSectSize:     dw  0x200         ; bytes per sector
 iClustSize:    db  1             ; sectors per cluster
 iResSect:      dw  1             ; ;of reserved sectors
 iFatCnt:       db  2             ; ;of FAT copies
 iRootSize:     dw  224           ; size of root directory
 iTotalSect:    dw  2880          ; total ; of sectors if over 32 MB
 iMedia:        db  0xF0          ; media Descriptor
 iFatSize:      db  9             ; size of each FAT
 iTrackSect:    dw  9             ; sectors per track
 iHeadCnt:      dw  2             ; number of read-write heads
 iHiddenSect:   dw  0             ; number of hidden sectors
 iSect32:       dd  0             ; ; sectors for over 32 MB
 iBootDrive:    db  0             ; holds drive that the boot sector came from
 iReserved:     db  0             ; reserved, empty
 iBootSign:     db  0x29          ; extended boot sector signature
 iVolID:        db "JMM "         ; disk serial
 acVolumeLabel: db "Stt_VOLUME "  ; volume label
 acFSType:      db "FAT16   "     ; file system type
 

WriteString:
  lodsb                   ; load byte at ds:si into al (advancing si)
  or     al, al           ; test if character is 0 (end)
  jz     WriteString_done ; jump to end if 0.
 
  mov    ah, 0xe          ; Subfunction 0xe of int 10h (video teletype output)
  mov    bx, 9            ; Set bh (page nr) to 0, and bl (attribute) to white (9)
  int    0x10             ; call BIOS interrupt.
 
  jmp    WriteString      ; Repeat for next character.
 
WriteString_done:
  ret

 

Reboot:
  mov    si, rebootmsg ; Load address of reboot message into si
  call   WriteString   ; print the string
  xor    ax, ax        ; subfuction 0
  int    0x16          ; call bios to wait for key
  db  0xEA          ; machine language to jump to FFFF:0000 (reboot)
  dw  0x0000
  dw  0xFFFF

 
start:
  ; Setup segments:
  cli
  mov  [iBootDrive], dl  ; save what drive we booted from (should be 0x0)
  mov  ax, cs          ; CS = 0x0, since that's where boot sector is (0x07c00)
  mov  ds, ax          ; DS = CS = 0x0
  mov  es, ax          ; ES = CS = 0x0
  mov  ss, ax          ; SS = CS = 0x0
  mov  sp, 0x7C00      ; Stack grows down from offset 0x7C00 toward 0x0000.
  sti  
 
  ; Display "loading" message:
  mov  si, loadmsg
  call WriteString
  mov  si, secondmsg
  call WriteString
 
 
  ; End of loader, for now. Reboot.
  call Reboot
 
bootFailure:
  mov  si, diskerror
  call WriteString
  call Reboot
 
; PROGRAM DATA
loadmsg:          db "Boating from Floppy",0Dh,0Ah,0
secondmsg:        db "Boating from second",0Dh,0Ah,0
diskerror:        db "Disk error.",0Dh,0Ah,0
rebootmsg:        db "Press any key to reboot.",0Dh,0Ah,0
 
times 510-($-$$)  db 144   ; Pad with nulls up to 510 bytes (excl. boot magic)
BootMagic:        dw 0xAA55    ; magic word for BIOS





