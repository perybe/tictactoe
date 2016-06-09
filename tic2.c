#include "libtic.h"

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

