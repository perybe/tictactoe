#include "libtic.h"
#include <stdio.h>


void print_grade(char b[10])
{	//criando o  "tabuleiro"
	printf(" %c |%c |%c\n",b[1],b[2],b[3]);
	printf(" --+--+--\n");
	printf(" %c |%c |%c\n",b[4],b[5],b[6]);
	printf(" --+--+--\n");
	printf(" %c |%c |%c\n",b[7],b[8],b[9]);
}
