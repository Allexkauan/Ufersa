#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TIME.H>
#include "aluno.c"

int main()
{
    int menu;
    int tam;
    aluno *p;
    int submenu;
    int esc;
    FILE *arqv;

    do
    {
        printf("Digite o numero referente a necessidade!!\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Buscar Aluno\n");
        printf("3 - Gerar Boletin\n");
        printf("0 - Sair do sistema\n");
        scanf("%d", &menu);

        system("cls");

        switch (menu)
        {

        case 1:
            do
            {
                printf("1 - Cadastrar via teclado\n");
                printf("2 - Cadastrar via arquivo\n");
                printf("0 - Voltar ao menu");
                scanf("%d", &esc);
                system("cls");

                switch (esc)
                {
                case 1:
                    printf("Quantos alunos quer cadastrar ?\n");
                    scanf("%d", &tam);

                    p = (aluno *)malloc(tam * sizeof(aluno));
                    // p = (aluno *)realloc(p, tam * sizeof(aluno));

                    cadastrar_notas(p, tam);
                    system("cls");
                    calcular_media(p, tam);
                    printf("Media calculada com Sucesso!!\n");
                    sleep(2);
                    system("cls");
                    printf("Alunos cadastrados com Sucesso!!");
                    sleep(2);
                    system("cls");
                    break;

                case 2:
                    p = (aluno *)malloc(maxAluno * sizeof(aluno));
                    ler_boletin(p, &tam);
                    printf("Boletin lido com Sucesso!!");
                    sleep(2);
                    system("cls");
                    printf("Nome\tNota 1\tNota 2\tNota 3\tMedia Final\tStatus do Aluno\n\n");
                    for (int i = 0; i < tam; i++)
                    {
                        if (p[i].nome != "\0")
                        {
                            printf("%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", p[i].nome, p[i].n1, p[i].n2, p[i].n3, p[i].media, p[i].status);
                        }
                        else
                            break;
                    }
                    system("pause");
                    system("cls");
                    break;

                case 0:
                    system("cls");
                    printf("Voltando ao Menu!!");
                    sleep(1);
                    break;

                default:
                    system("cls");
                    printf("Valor invalido, tente novamente!");
                    sleep(2);
                    system("cls");
                    break;
                }
            } while (esc != 0);

            break;

        case 2:
            do
            {
                printf("1 - Buscar Pelo Nome\n");
                printf("2 - Listar Maiores Notas\n");
                printf("3 - Listar Aprovados");
                printf("4 - Listar Reprovados");
                printf("0 - Voltar ao Menu");
                scanf("%d", &submenu);
                system("cls");

                switch (submenu)
                {
                case 1:

                    break;

                case 2:

                    break;

                case 3:

                    break;

                case 4:

                    break;

                case 0:
                    system("cls");
                    printf("Voltando ao Menu!!");
                    sleep(1);
                    break;

                default:
                    system("cls");
                    printf("Valor invalido, tente novamente!");
                    sleep(2);
                    system("cls");
                    break;
                }
            } while (esc != 0);

            break;
            break;

        case 3:
            gerar_boletin(tam, p);
            printf("Boletin gerado com Sucesso!!");
            sleep(2);
            system("cls");

            break;

        case 0:
            system("cls");
            printf("Sistema Fechado com Sucesso!!");
            sleep(2);
            system("cls");
            return 0;

            break;

        default:
            system("cls");
            printf("Valor invalido, tente novamente!");
            sleep(2);
            system("cls");
            break;
        }

    } while (menu != 0);

    return 0;
}
