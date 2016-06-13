#include "libtic.h"

int checaEmpate(char grade[])
{			//Verificando se empatou o jogo
    if ((checaVitoria(grade) == 0) && (grade[1] != ' ') && (grade[2] != ' ') &&
            (grade[3] != ' ') && (grade[4] != ' ') && (grade[5] != ' ') &&
            (grade[6] != ' ') && (grade[7] != ' ') && (grade[8] != ' ') &&
            (grade[9] != ' '))
    {
        return 1;
    }
    else return 0;
}

