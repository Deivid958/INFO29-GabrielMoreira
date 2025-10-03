#include <stdio.h>
#include <stdlib.h>
#include "Disci_funcoes.h"
#define TAM_ALUNO 50
#define TAM_DISCIPLINA 10

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
    disci disciplina[TAM_DISCIPLINA];
    int codigo,i,resposta,q_disciplina = 0;
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
                printf("Disciplinas\n");
                resposta = 1;
                while(resposta != 0)
                {
                    resposta = Disci_menu();
                    switch (resposta)
                    {
                        case 0:{
                            break;
                        }
                        case 1:{
                            if(q_disciplina == TAM_DISCIPLINA)
                            {
                                printf("Limite de disciplinas atingido\n");
                            }
                            else
                            {
                                printf("Cadastrando disciplina...\n");
                                Disci_CadastrarAtualizar(q_disciplina,disciplina);
                                printf("Cadastro concluido");
                                q_disciplina++;
                            }
                            break;
                        }
                        case 2:{
                            if(q_disciplina == 0)
                            {
                                printf("Lista vazia\n");
                            }
                            else
                            {
                                printf("Listando disciplinas...\n");  
                                Disci_listar(q_disciplina,disciplina);
                            }
                            break;
                        }
                        case 3:{
                            printf("Atualizando disciplina...\n");
                            printf("Codigo da disciplina:");
                            scanf("%d",&codigo);
                            for(i = 0;i != q_disciplina;i++)
                            {
                                if(codigo == disciplina[i].codigo)
                                {
                                    Disci_CadastrarAtualizar(i,disciplina);
                                    printf("Atualizacao concluida\n");
                                    break;
                                }
                                else if(i+1 == q_disciplina)
                                {
                                    printf("Codigo inexistente\n");
                                }
                            }
                            break;
                        }
                        case 4:{
                            printf("Excluindo disciplina...\n");
                            printf("Codigo da disciplina:");
                            scanf("%d",&codigo);
                            for(i = 0;i != q_disciplina;i++)
                            {
                                if(codigo == disciplina[i].codigo)
                                {
                                    Disci_excluir(q_disciplina,i,disciplina);
                                    printf("Disciplina excluida\n");
                                    q_disciplina--;
                                    break;
                                }
                                else if(i+1 == q_disciplina)
                                {
                                    printf("Codigo inexistente\n");
                                }
                            }
                            break;
                        }
                        default:
                        {
                            printf("Opcao invalida\n");
                            break;
                        }
                    }
                }
                break;
            }
            case '4':{
                printf("Relatorios");
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