#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ALUNO 50
#define aluno_inexistente -1
#define caractere_invalido -2

typedef struct
{
    char nome[TAM_ALUNO];
    char matricula[TAM_ALUNO];
    char sexo;
    char data[TAM_ALUNO];
    char cpf[TAM_ALUNO];
    int ativo;
} aluno;

char menugeral(void);
char menu_aluno(void);
void cadastrar_aluno(int posicao, aluno alunos[]);
int listar_alunos(int tamanho, aluno aluno[]);
void excluir_alunos(int tamanho, aluno aluno[], int indice);
int procura_aluno(int tamanho, aluno aluno[], char matricula[]);
void atualizar_aluno(aluno aluno[], int indice);
int analisa_string(char string[], int tipo);
void ler_matricula(char matricula[]);
void ler_nome(char nome[]);

int listar_alunos(int tamanho, aluno aluno[])
{
    if (tamanho  == 0)
    {
        return aluno_inexistente;
    }
    else
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
    return 0;
    
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
    
    ler_nome(aluno[tamanho].nome);
    ler_matricula(aluno[tamanho].matricula);
    ler_data(aluno[tamanho].data);
   
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

void excluir_alunos(int tamanho, aluno aluno[], int indice)
{
    for(int i = indice; i < tamanho; i++)
    {
        aluno[i] = aluno[i+1];   
    }
}

void atualizar_aluno(aluno aluno[], int indice)
{
    cadastrar_aluno(indice, aluno);
}

void ler_matricula(char matricula[])
{
    int teste = 0;
    do
    {
        printf("MATRÍCULA: ");
        fgets(matricula, 50, stdin);
        matricula[strcspn(matricula, "\n")] = '\0';
        for (int x = 0; matricula[x] != '\0'; x++)
        {
            if (isdigit(matricula[x]) == 0)
            {
                teste = 1;
                break;
            }
            if (isspace(matricula[x]) != 0)
            {
                teste++;
                if(teste == 2)
                    break;
            }
            else
                teste = 0;
            if (strlen(matricula) > 12 || strlen(matricula) < 12)
            {
                printf("Digite 12 números\n");
                teste = 1;
                break;
            }
        }
    }
    while(teste != 0);
}

void ler_nome(char nome[])
{
    int test = 0;
    do{
        test = 0;
        printf("NOME: ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        for(int x = 0; x < strlen(nome); x++)
        {
            if (isalpha(nome[x]) == 0 && nome[x] != ' ')
            {
                test = 1;
                break;
            }
            if (isspace(nome[x]) != 0)
            {
                test++;
                if(test == 2)
                    break;
            }
            else
                test = 0;
        }
    }
    while(test != 0);
}

void ler_data(char data[])
{   
    int contador = 0;
    int teste = 0;
    char *parte;

    do{
        teste = 0;
        contador = 0;
        printf("DATA: ");
        fgets(data, 50, stdin);
        data[strcspn(data, "\n")] = '\0';
        parte = strtok(data, "/");

        while(parte != NULL)
        {
            contador++;
            if(contador == 1 && atoi(parte) <= 0 || contador == 1 && atoi(parte) > 31)
                teste = 1;
            if(contador == 2 && atoi(parte) <= 0 || contador == 2 && atoi(parte) > 12)
                teste = 1;
            if(contador == 3 && atoi(parte) <= 1970 || contador == 3 && atoi(parte) > 2025)
                teste = 1;
        
            parte = strtok(NULL, "/");
        }
        
    }
    while (teste != 0);
    
}