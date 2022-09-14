#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TIME.H>

typedef struct Aluno
{
    float n1, n2, n3, media;
    char status[20];
    char nome[30];
} aluno;

void gerar_boletin(int n, aluno *p)
{
    FILE *arq;

    arq = fopen("Boletin.txt", "w");

    fprintf(arq, "Nome \t Nota 1 \t Nota2 \t Nota3 \t Media Final \t Status do Aluno\n\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(arq, "%s \t %.2f \t %.2f \t %.2f \t %.2f \t %s \n", p[i].nome, p[i].n1, p[i].n2, p[i].n3, p[i].media, p[i].status);
    }
    arq = fclose(arq);
}

void calcular_media(aluno *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].media = (p[i].n1 + p[i].n2 + p[i].n3) / 3;

        if (p[i].media > 7)
        {
            *p[i].status = 'Aprovado';
        }
        else
        {
            *p[i].status = "Reprovado";
        }
    }
}

void cadastrar_notas(aluno *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o nome do Aluno: \t");
        scanf("%s", p[i].nome);
        printf("Digite as notas do Aluno: \n");
        printf("Nota 1:\t");
        scanf("%f", &p[i].n1);
        printf("Nota 2:\t");
        scanf("%f", &p[i].n2);
        printf("Nota 3:\t");
        scanf("%f", &p[i].n3);
    }
}

int main()
{
    int menu;
    int tam;
    aluno *p;

    do
    {
        printf("Digite o numero referente a necessidade!!\n");
        printf("1 - Cadastrar notas\n");
        printf("2 - Calcular media\n");
        printf("3 - Gerar Boletin\n");
        printf("0 - Sair do sistema\n");
        scanf("%d", &menu);

        system("cls");

        switch (menu)
        {

        case 1:
            printf("Quantos alunos quer cadastrar ?");
            scanf("%d", &tam);

            p = (aluno *)malloc(tam * sizeof(aluno));

            cadastrar_notas(p, tam);
            system("cls");
            printf("Alunos cadastrados com Sucesso!!");
            sleep(2);
            system("cls");

            break;

        case 2:
            calcular_media(p, tam);
            printf("Media calculada com Sucesso!!\n");
            sleep(2);
            system("cls");
            printf("Nome\tNota 1\tNota 2\tNota 3\tMedia Final\tStatus do Aluno\n\n");
            for (int i = 0; i < tam; i++)
            {
                printf("%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", p[i].nome, p[i].n1, p[i].n2, p[i].n3, p[i].media, p[i].status);
            }
            system("pause");
            system("cls");

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
