#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TIME.H>

#define maxAluno 40

typedef struct Aluno
{
    float n1, n2, n3, media;
    char status[20];
    char nome[30];
} aluno;

void ler_boletin(aluno *p, int *n)
{
    int i = 0;
    FILE *arq;

    arq = fopen("Ler-Boletin.txt", "r");
    if (arq == NULL)
    {
        printf("nao leu");
    }

    fscanf(arq, "%d\n", n);
    printf("%d valor de N\n\n", *n);

    while (!feof(arq))
    {
        fscanf(arq, "%s\t%f\t%f\t%f\t%f\t%s\n", p[i].nome, &p[i].n1, &p[i].n2, &p[i].n3, &p[i].media, p[i].status);
        i++;
    }

    fclose(arq);
}

void gerar_boletin(int n, aluno *p)
{
    FILE *arq;

    arq = fopen("Boletin.txt", "w");

    fprintf(arq, "Nome \t Nota 1 \t Nota2 \t\t Nota3 \t\t Media Final \t Status do Aluno\n\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(arq, "%s \t %.2f \t\t %.2f \t\t %.2f \t\t %.2f \t\t\t %s \n", p[i].nome, p[i].n1, p[i].n2, p[i].n3, p[i].media, p[i].status);
    }
    fclose(arq);
}

void calcular_media(aluno *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].media = (p[i].n1 + p[i].n2 + p[i].n3) / 3;

        if (p[i].media >= 7)
        {
            strcpy(p[i].status, "Aprovado");
        }
        else
        {
            strcpy(p[i].status, "Reprovado");
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

    FILE *arq;

    arq = fopen("Boletin.txt", "a");

    for (int i = 0; i < tam; i++)
    {
        fprintf(arq, "%s \t %.2f \t\t %.2f \t\t %.2f \t\t %.2f \t\t\t %s \n", p[i].nome, p[i].n1, p[i].n2, p[i].n3, p[i].media, p[i].status);
    }
    fclose(arq);
}