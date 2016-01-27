OBJ=JmOsFloppy

all: $(OBJ) 

JmOsFloppy: bootsect kernel
	cat bootsect kernel /dev/zero | dd of=JmOsFloppy.img bs=512 count=2880 

bootsect: bootsect.asm
	nasm -f bin -o $@ $^

kernel: kernel.asm
	nasm -f bin -o $@ $^ 

clean:
	rm -f $(OBJ) bootsect kernel
