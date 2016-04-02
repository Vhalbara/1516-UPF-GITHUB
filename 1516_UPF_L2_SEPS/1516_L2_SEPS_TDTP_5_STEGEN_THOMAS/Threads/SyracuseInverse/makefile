COMPIL = cc
OBJ = arboSyrac.o
PROGRAM = SyracuseInverse

all = $(PROGRAM)

SyracuseInverse:	syracuseInverse.c arboSyrac.o
			cc syracuseInverse.c arboSyrac.o -pthread -o syracuseInverse.out

arboSyrac.o:	lib/arboSyrac.c lib/arboSyrac.h
			$(COMPIL) lib/arboSyrac.c -c

clean:
		@rm -f $(OBJ) core

clobber:	clean
			@rm -f tags SyracuseInverse
