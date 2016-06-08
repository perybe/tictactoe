tictactoe: tictactoe.c
	cc -o tictactoe tictactoe.c

executar: tictactoe.c
	./tictactoe

abrir: tictactoe.c
	cat tictactoe.c

astyle: tictactoe.c
	 astyle tictactoe.c


