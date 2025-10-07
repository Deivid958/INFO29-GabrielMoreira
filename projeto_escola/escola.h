#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ALUNO 50
#define aluno_inexistente -1

typedef struct
{
    char nome[TAM_ALUNO];
    char matricula[TAM_ALUNO];
    char sexo;
    char data[TAM_ALUNO];
    char cpf[TAM_ALUNO];
    int ativo;
} aluno;

void listar_alunos(int tamanho, aluno aluno[])
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n-------------------- LISTA DE ALUNOS --------------------\n");
        for(int i = 0; i < tamanho; i++)
        {
            printf("NOME: %sMATRICULA: %sDATA: %sCPF: %sSEXO: %c\n", aluno[i].nome, aluno[i].matricula, aluno[i].data, aluno[i].cpf, aluno[i].sexo);
            printf("\n");
        }
        printf("-----------------------------------------------------------\n");
    }
}

char menugeral(void)
{
    char resposta;

    printf("\n-------- MENU GERAL --------\n");
    printf("[0] - Sair\n");
    printf("[1] - Alunos\n");
    printf("[2] - Professores\n");
    printf("[3] - Relatórios\n");
    printf("----------------------------\n");
    printf("Opção: ");
    resposta = getchar();
    while (getchar() != '\n');
    return resposta;
}

char menu_aluno(void)
{
    char resposta;

    printf("\n---------- ALUNOS ----------\n");
    printf("[0] - Voltar\n");
    printf("[1] - Cadastrar Aluno\n");
    printf("[2] - Listar Alunos\n");
    printf("[3] - Atualizar Cadastro\n");
    printf("[4] - Excluir Aluno\n");
    printf("----------------------------\n");
    printf("Opção: ");
    resposta = getchar();
    while (getchar() != '\n');
    return resposta;

}

void cadastrar_aluno(int tamanho, aluno aluno[])
{
    printf("\n---------- CADASTRAR ----------\n");
    printf("NOME: ");
    fgets(aluno[tamanho].nome, 50, stdin);
    printf("MATRÍCULA: ");
    fgets(aluno[tamanho].matricula, 50, stdin);
    printf("DATA: ");
    fgets(aluno[tamanho].data, 50, stdin);
    printf("CPF: ");
    fgets(aluno[tamanho].cpf, 11, stdin);
    printf("SEXO: ");
    aluno[tamanho].sexo = getchar();
    while (getchar() != '\n');
    printf("---------------------------------\n");
}

int procura_aluno(int tamanho, aluno aluno[], char matricula[])
{

    for(int i = 0; i < tamanho; i++)
    {
        if (strcmp(matricula, aluno[i].matricula) == 0) 
        {
            return i;
        }
        
    }
    return aluno_inexistente;
}

aluno excluir_alunos(int tamanho, aluno aluno[], int indice)
{
    for(int i = indice; i < tamanho; i++)
    {
        aluno[i] = aluno[i+1];   
    }
    return aluno[TAM_ALUNO];
}

void atualizar_aluno(aluno aluno[], int indice)
{
    cadastrar_aluno(indice, aluno);
}
