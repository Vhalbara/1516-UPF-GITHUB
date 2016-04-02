COMPIL = cc
OBJ = eratos.o
PROGRAM = Integrator

all = $(PROGRAM)

Integrator:	Integrator.c eratos.o
			cc Integrator.c eratos.o -pthread -o Integrator.out -lm 

eratos.o:	eratos/eratos.c eratos/eratos.h
			$(COMPIL) eratos/eratos.c -c

clean:
		@rm -f $(OBJ) core

clobber:	clean
			@rm -f tags Integrator
