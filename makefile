tictactoe: tictactoe.c
	cc -o tictactoe tictactoe.c tic1.c tic2.c tic3.c tic4.c

executar: tictactoe.c	
	./tictactoe

abrir: tictactoe.c
	cat tictactoe.c

organizar: tictactoe.c
	 astyle tictactoe.c

o: tictactoe.c
	cc -c tictactoe.c 

removeO: 
	rm tictactoe.o
	
removetic:
	rm tictactoe
	rm tictactoe.c.orig

