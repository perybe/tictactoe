#include <stdio.h>
#include "conio.h"
#include <string.h>
#include "libtic.h"

int posimax, posimin;

int main()
{
    int GdBgColor = 6;
    system("clear");
    setbgrcolor(GdBgColor);
    int i, partidas, posicao, cont, final,jogada, soma1 = 0, soma2 = 0;
    char grade[11];
    char nome[50], c;

    puts("Forneça seu nome: ");
    fgets(nome, 49, stdin);
    nome[strlen(nome)- 1] = '\0';
    printf("\n");

    partidas = -1;
    while (partidas < 0)
    {
        printf("informe o número de partidas que você quer jogar: ");
        scanf("%i", &partidas);
        scanf("%c",&c);

    }


    while ( partidas != 0)
    {

        for(i = 1; i < 10; i++)
        {
            grade[i] = ' ';
        }

        printf("Jogo da Velha:\n");
        printf("\n");

        print_grade(grade);

        for(i = 1; i < 10; i++)
        {
            final = checaVitoria(grade);

            if (final == 1)
            {
                printf("O jogador X ganhou essa partida!\n");
                printf("%s\n", nome);
                printf("\n");
                soma1 = soma1 + 1;
                break;
            }
            else if (final == -1)
            {
                printf("O jogador O ganhou essa partida!\n");
                printf("\n");
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
                    scanf("%c",&c);


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
                printf("\n");
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
