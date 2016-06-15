tictactoe: tictactoe.c
	cc -o tictactoe tictactoe.c tic1.c tic2.c tic3.c tic4.c

executar: tictactoe.c	
	./tictactoe

abrir: tictactoe.c
	cat tictactoe.c

abrir1: tic1.c
	cat tic1.c

abrir2: tic2.c
	cat tic2.c

abrir3: tic3.c
	cat tic3.c

abrir4: tic4.c
	cat tic4.c

abrirh: libtic.h
	cat libtic.h

organizar: tictactoe.c
	 astyle tictactoe.c

O: tictactoe.c
	cc -c tictactoe.c 

removeO: 
	rm tictactoe.o
	
removetic:
	rm tictactoe
	rm tictactoe.c.orig

