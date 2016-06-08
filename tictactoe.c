#include <stdio.h>
#include "conio.h"
#include <string.h> 

int posimax, posimin;


void print_grade(char b[10])
{
    printf(" %c |%c |%c\n",b[1],b[2],b[3]);
	printf(" --+--+--\n");
    printf(" %c |%c |%c\n",b[4],b[5],b[6]);
	printf(" --+--+--\n");
    printf(" %c |%c |%c\n",b[7],b[8],b[9]);
}

int checaVitoria(char grade[])
{
    if ((grade[1] == 'X' && grade[2] == 'X' && grade[3] == 'X') ||
            (grade[4] == 'X' && grade[5] == 'X' && grade[6] == 'X') ||
            (grade[7] == 'X' && grade[8] == 'X' && grade[9] == 'X') ||
            (grade[1] == 'X' && grade[4] == 'X' && grade[7] == 'X') ||
            (grade[2] == 'X' && grade[5] == 'X' && grade[8] == 'X') ||
            (grade[3] == 'X' && grade[6] == 'X' && grade[9] == 'X') ||
            (grade[1] == 'X' && grade[5] == 'X' && grade[9] == 'X') ||
            (grade[3] == 'X' && grade[5] == 'X' && grade[7] == 'X'))
    {
        return 1;
    }
    else if((grade[1] == 'O' && grade[2] == 'O' && grade[3] == 'O') ||
            (grade[4] == 'O' && grade[5] == 'O' && grade[6] == 'O') ||
            (grade[7] == 'O' && grade[8] == 'O' && grade[9] == 'O') ||
            (grade[1] == 'O' && grade[4] == 'O' && grade[7] == 'O') ||
            (grade[2] == 'O' && grade[5] == 'O' && grade[8] == 'O') ||
            (grade[3] == 'O' && grade[6] == 'O' && grade[9] == 'O') ||
            (grade[1] == 'O' && grade[5] == 'O' && grade[9] == 'O') ||
            (grade[3] == 'O' && grade[5] == 'O' && grade[7] == 'O'))
    {
        return -1;
    }
    else return 0;
}

int checaEmpate(char grade[])
{
    if ((checaVitoria(grade) == 0) && (grade[1] != ' ') && (grade[2] != ' ') &&
            (grade[3] != ' ') && (grade[4] != ' ') && (grade[5] != ' ') &&
            (grade[6] != ' ') && (grade[7] != ' ') && (grade[8] != ' ') &&
            (grade[9] != ' '))
    {
        return 1;
    }
    else return 0;
}

int minimax(int player, char grade[], int n)
{
    int i, res, j;

    int max = -999;
    int min = 999;

    int final = checaVitoria(grade);

    if (final == 1)
        return 1;
    else if (final == (-1))
        return -1;
    else if (final = checaEmpate(grade))
        return 0;

    for (i = 1; i < 10; i++)
    {
        if(grade[i] == ' ')
        {
            if(player == 2)
            {
                grade[i] = 'O';
                res = minimax(1, grade, n + 1);

                grade[i] = ' ';

                if(res < min)
                {
                    min = res;
                    if (n == 0)
                        posimin = i;
                }
            }
            else if (player == 1)
            {
                grade[i] = 'X';
                res = minimax(2, grade, n + 1);
                grade[i] = ' ';
                if (res > max)
                {
                    max = res;
                    if (n == 0)
                        posimax = i;
                }
            }
        }
    }

    if (player == 1)
        return max;
    else return min;
}



int main()
{
	int GdBgColor = 6;
	system("clear");
    	setbgrcolor(GdBgColor);
    	int i, partidas, posicao, cont, final,jogada, soma1 = 0, soma2 = 0;
    	char grade[10];
   	char nome[50];
	
	puts("Forneça seu nome: ");
	fgets(nome, 49, stdin);
	nome[strlen(nome)- 1] = '\0';

	printf("informe o número de partidas que você quer jogar: ");
	scanf("%i", &partidas);
	
     	while ( partidas != 0)
    	{

    		for(i = 1; i < 10; i++)
   		{
      			grade[i] = ' ';
    		}

	printf("Jogo da Velha:\n");
	
	print_grade(grade);

		for(i = 1; i < 10; i++)
   		{
        		final = checaVitoria(grade);
        		
			if (final == 1)
        		{
           			printf("O jogador X ganhou essa partida!\n");
	    			printf("%s\n", nome);
				soma1 = soma1 + 1;
            			break;
        		}
        		else if (final == -1)
        		{
           			printf("O jogador O ganhou essa partida!\n");
				soma2 = soma2 + 1;
	    			break;
        		}

        		if (i % 2 == 1)
        		{
            			cont = 0;


            			while ( cont != 1)
            			{
                			printf("Jogada do jogador %s:\n", nome);
                			scanf("%d", &posicao);

	                		if(( posicao <= 9) && (posicao >= 1) && (grade[posicao] == ' '))
                			{
                    				grade[posicao] = 'X';
                    				cont = 1;
                			}
                			else
                			{
                    				printf("jogada invalida, tente novamente...\n");
                			}

            			}
        		}


        	if ((final == 0) && (i != 9))
        	{
            	posimax = -1;
            	posimin = -1;
            		if(i % 2 == 1)
            		{
                		jogada = minimax(1, grade, 0);
               		 	//printf("A melhor jogada para o jogador X e: %d\n", posimax);
           		}
            		else
            		{
                		jogada = minimax(2, grade, 0);
                		grade[posimin] = 'O';
                		print_grade(grade);

            		}
        	}
        	else 
		{
        		printf("Deu velha!\n");
            		print_grade(grade);
        	}

    		}
	
		partidas = partidas - 1;
	}

	printf( "O jogador %s venceu %i vezes e o jogador O venceu %i vezes\n", nome, soma1, soma2);
	
	
	if ( soma1 > soma2)
	{
		printf("Jogador %s é o vencedor dos jogos\n", nome);
	}
	else
	{
		if ( soma2 > soma1)
		{
			printf ("Jogador O é o vencedor dos jogos\n");
		}
		else
		{
			printf("Empate\n");
		}
	}

	printf("FIM DO JOGO\n");

    return 0;
}
