#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

int main()
{

    fila *normal = criaFila();
    fila *priori = criaFila();
    pilha *senhas = criaPilha();

    

    int opcaoMenu = 0;
    int senhaNormal = 1;
    int senhaPrio = 0;
    int opcao2 = 0;
    int opcao1 = 0;
    int ordem = 1;

    while (opcaoMenu != 3)
    {
        printf("Digite as opcoes, 1 - menu caixa, 2 - menu cliente, 3 - sair\n");
        scanf("%d", &opcaoMenu);
        switch (opcaoMenu)
        {
        case 1:
            while (opcao1 != 4)
            {
                printf("CAIXA\n 1- chamar cliente 2 - visualizar filas 3 - ultimas chamadas 4 - voltar ao menu anterior\n");
                scanf("%d", &opcao1);
                switch (opcao1)
                {
                case 1:

                    switch (ordem)
                    {
                    case 1:
                        if (!(filaVazia(priori)))
                        {
                            float senhaAtual = removee(priori);
                            push(senhas, senhaAtual);
                            printf("%f", senhaAtual);
                            ordem++;
                            break;
                        }
                        else if (!(filaVazia(normal)))
                        {
                            float senhaAtual = removee(normal);
                            push(senhas, senhaAtual);
                            printf("%f", senhaAtual);
                            ordem++;
                            break;
                        }

                    case 2:
                        if (!(filaVazia(normal)))
                        {
                    
                            float senhaAtual = removee(normal);
                            push(senhas, senhaAtual);
                            printf("%f", senhaAtual);
                            ordem++;
                            break;
                        }
                        else if (!(filaVazia(priori)))
                        {
                            float senhaAtual = removee(priori);
                            push(senhas, senhaAtual);
                            printf("%f", senhaAtual);
                            ordem++;
                            break;
                        }

                    case 3:
                        if (!(filaVazia(normal)))
                        {
                            float senhaAtual = removee(normal);
                            push(senhas, senhaAtual);
                            printf("%f", senhaAtual);
                            ordem = 1;
                            break;
                        }
                        else if (!(filaVazia(priori)))
                        {
                            float senhaAtual = removee(priori);
                            push(senhas, senhaAtual);
                            printf("%f", senhaAtual);
                            ordem = 1;
                            break;
                        }
                    }

                    break;
                case 2:

                    if (!(filaVazia(normal) && filaVazia(priori)))
                    {
                        imprime(normal);
                        imprime(priori);
                    }
                    else if (!(filaVazia(normal)))
                    {
                        printf("Fila prioritária vazia");
                        imprime(normal);
                    }
                    else if (!(filaVazia(priori)))
                    {
                        printf("Fila normal vazia");
                        imprime(priori);
                    }
                    else
                    {
                        printf("Ambas as filas estão vazias.");
                    }
                    opcao1 = 0;
                    break;

                case 3:
                    imprimePilha(senhas);
                    break;
                case 4:
                    printf("Voltando\n");
                    break;
                }
            }
            opcao1 = 0;
            break;

        case 2:
            while (opcao2 != 3)
            {
                printf("1 - Normal\n2 - prioritaria \n3 - voltar ao menu\n");
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                case 1:
                    insere(normal, senhaNormal);
                    senhaNormal += 2;
                    break;
                case 2:
                    insere(priori, senhaPrio);
                    senhaPrio += 2;
                    break;
                case 3:
                    printf("voltando para menu\n");
                    break;
                }
            }
            opcao2 = 0;
            break;

        case 3:
            printf("saindo do programa\n");
            break;
        }
    }
}