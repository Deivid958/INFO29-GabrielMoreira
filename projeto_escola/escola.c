#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escola.h"
#define TAM_ALUNO 50
#define aluno_inexistente -1
#include "Disci_funcoes.h"
#define TAM_ALUNO 50
#define TAM_DISCIPLINA 10

char menugeral(void)
{
    char resposta;

    printf("\n-------- MENU GERAL --------\n");
    printf("[0] - Sair\n");
    printf("[1] - Alunos\n");
    printf("[2] - Professores\n");
    printf("[3] - Disciplinas\n");
    printf("[4] - Relatórios\n");
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

void cadastrar_aluno(int posicao, aluno aluno[])
{
    printf("\n---------- CADASTRAR ----------\n");
    printf("NOME: ");
    fgets(aluno[posicao].nome, 50, stdin);
    printf("MATRÍCULA: ");
    fgets(aluno[posicao].matricula, 50, stdin);
    printf("DATA: ");
    fgets(aluno[posicao].data, 50, stdin);
    printf("CPF: ");
    fgets(aluno[posicao].cpf, 11, stdin);
    printf("SEXO: ");
    aluno[posicao].sexo = getchar();
     printf("---------------------------------\n");
}
