//Pedro Bergamin (pedro.bergamin@acad.pucrs.br)	e Rebeca Gomes (rebeca.gomes@acad.pucrs.br)

//incluindo bibliotecas
#include <stdio.h>
#include "conio.h"
#include <string.h>
#include "libtic.h"

int posimin;

int main()
{   //botando cor
    int GdBgColor = 6;
    system("clear");	// limpa a tela para o jogo ficar no inicio do terminal
    setbgrcolor(GdBgColor);
    int i, partidas, posicao, cont, final, jogada, soma1 = 0, soma2 = 0;
    char grade[10];
    char nome[50], c;

    //pegando nome do jogador
    puts("Forneça seu nome: ");
    fgets(nome, 49, stdin);		//ler o nome do jogador
    nome[strlen(nome)- 1] = '\0';	//não ocorrer enter para caracteres que são escritos depois de ler o nome que o jogador fornecer
    printf("\n");

    partidas = -1;
    while (partidas < 0)

    {   //perguntando a quantidade de partidas
        printf("informe o número de partidas que você quer jogar: ");
        scanf("%i", &partidas);
        scanf("%c",&c);

    }


    while ( partidas != 0)
    {
        // criando a tabela
        for(i = 1; i < 10; i++)
        {
            grade[i] = ' ';
        }

        printf(" _   _      _             _             \n");
        printf("| | (_)    | |           | |            \n");
        printf("| |_ _  ___| |_ __ _  ___| |_ ___   ___ \n");
        printf("| __| |/ __| __/ _` |/ __| __/ _ \\ / _ \\\n");
        printf("| |_| | (__| || (_| | (__| || (_) |  __/\n");
        printf(" \\__|_|\\___|\\__\\__,_|\\___|\\__\\___/ \\___|\n");
        printf("\n");

        print_grade(grade);	//tic1.c

        //verificando se alguem ganhou
        for(i = 1; i < 10; i++)
        {
            final = checaVitoria(grade);	//tic2.c

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

                // pergutando a jogada do jogador
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

            //Computador fazendo sua jogada
            if ((final == 0) && (i != 9))
            {
                posimin = -1;

                if(i % 2 == 0)
                {
                    jogada = mini(2, grade, 0);	//tic4.c
                    grade[posimin] = 'O';
                    print_grade(grade);		//tic1.c

                }
            }
            else
            {   //finalizando o jogo
                printf("Deu velha!\n");
                print_grade(grade);		//tic1.c
                printf("\n");
            }

        }

        partidas = partidas - 1;
    }
    //vendo quem ganhou mais vezes
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
