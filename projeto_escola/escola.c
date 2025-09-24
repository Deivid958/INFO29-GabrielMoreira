#include <stdio.h>
#include <stdlib.h>
#define TAM_ALUNO 50

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

int main(void)
{
    int sair = 0, sair_aluno = 0;
    int opcao = 0, opcao_aluno = 0; 
    aluno alunos[TAM_ALUNO];
    int q_alunos = 0;

    while (!sair)
    {
        opcao = menugeral();
        sair_aluno = 0;

        switch(opcao)
        {
            case '0':{
                sair = 1;
                break;
            }
            case '1':{
                while (!sair_aluno)
                {
                    opcao_aluno = menu_aluno();

                    switch(opcao_aluno)
                    {
                        case '0':
                        {
                            sair_aluno = 1;
                            break;
                        }
                        case '1':
                        {
                            cadastrar_aluno(q_alunos, alunos);
                            q_alunos++;
                        }
                        
                    }

                } 
                break;
            }
            
            case '2':{
                printf("Professores\n");
                break; 
            }
            case '3':{
                printf("Relatórios\n");
                break;
            }
            default:{
                printf("opção invalida!\n");
                break;
            }    
        }
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