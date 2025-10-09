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
} pessoa;

void listar_pessoas(int tamanho, pessoa pessoas[])
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n-------------------- LISTA DE ALUNOS --------------------\n");
        for(int i = 0; i < tamanho; i++)
        {
            printf("NOME: %sMATRICULA: %sDATA: %sCPF: %sSEXO: %c\n", pessoas[i].nome, pessoas[i].matricula, pessoas[i].data, pessoas[i].cpf, pessoas[i].sexo);
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

char menu_pessoa(char tipo[])
{
    char resposta;

    printf("\n---------- %s ----------\n", tipo);
    printf("[0] - Voltar\n");
    printf("[1] - Cadastrar %s\n", tipo);
    printf("[2] - Listar %s\n", tipo);
    printf("[3] - Atualizar Cadastro\n");
    printf("[4] - Excluir %s\n", tipo);
    printf("----------------------------\n");
    printf("Opção: ");
    resposta = getchar();
    while (getchar() != '\n');
    return resposta;

}

void cadastrar_pessoa(int tamanho, pessoa pessoas[])
{
    printf("\n---------- CADASTRAR ----------\n");
    printf("NOME: ");
    fgets(pessoas[tamanho].nome, 50, stdin);
    printf("MATRÍCULA: ");
    fgets(pessoas[tamanho].matricula, 50, stdin);
    printf("DATA: ");
    fgets(pessoas[tamanho].data, 50, stdin);
    printf("CPF: ");
    fgets(pessoas[tamanho].cpf, 11, stdin);
    printf("SEXO: ");
    pessoas[tamanho].sexo = getchar();
    while (getchar() != '\n');
    printf("---------------------------------\n");
}

int procura_pessoa(int tamanho, pessoa pessoas[], char matricula[])
{

    for(int i = 0; i < tamanho; i++)
    {
        if (strcmp(matricula, pessoas[i].matricula) == 0) 
        {
            return i;
        }
        
    }
    return aluno_inexistente;
}

pessoa excluir_pessoa(int tamanho, pessoa pessoas[], int indice)
{
    for(int i = indice; i < tamanho; i++)
    {
        pessoas[i] = pessoas[i+1];   
    }
    return pessoas[TAM_ALUNO];
}

void atualizar_pessoa(pessoa pessoas[], int indice)
{
    cadastrar_pessoa(indice, pessoas);
}