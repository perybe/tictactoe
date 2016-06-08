#include "libtic.h"
#include <stdio.h>

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

