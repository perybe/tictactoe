#include "libtic.h"

int posimax, posimin;

int minimax(int player, char grade[], int n)
{
    int i, res, j;

    int max = -999;
    int min = 999;

    int final = checaVitoria(grade);
		//verificando se ele tem de fazer alguma jogada
    if (final == 1)
        return 1;
    else if (final == (-1))
        return -1;
    else if (final = checaEmpate(grade))
        return 0;

    for (i = 1; i < 10; i++)
    {//verificando se o lugar nao tem um X ou um O no local
        if(grade[i] == ' ') 
        { //fazendo a jogada e verificando se é o jogador correto
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
