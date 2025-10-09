#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escola.h"

#define TAM_ALUNO 50
#define aluno_inexistente -1


char menugeral(void);
char menu_aluno(void);
void cadastrar_aluno(int posicao, pessoa alunos[]);
void listar_alunos(int tamanho, pessoa aluno[]);
pessoa excluir_alunos(int tamanho, pessoa aluno[], int indice);
int procura_aluno(int tamanho, pessoa aluno[], char matricula[]);
void atualizar_aluno(pessoa aluno[], int indice);

int main(void)
{
    int sair = 0, sair_aluno = 0;
    int opcao = 0, opcao_aluno = 0; 
    pessoa alunos[TAM_ALUNO];
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
                            break;
                        }
                        case '2':{
                            listar_alunos(q_alunos, alunos);
                            break;
                        }
                        case '3':{
                            char matricula[TAM_ALUNO];
                            printf("Digite a matricula do aluno: ");
                            fgets(matricula, 50, stdin);
                            int posicao_aluno = procura_aluno(q_alunos, alunos, matricula);
                        
                            if (posicao_aluno == aluno_inexistente)
                            {
                                printf("Matricula digitada não pertence a nenhum aluno cadastrado!!\n");
                            }
                            else
                            {
                                atualizar_aluno(alunos, posicao_aluno);
                            }
                            break;
                        }
                        case '4':{
                            char matricula[TAM_ALUNO];
                            printf("Digite a matricula do aluno: ");
                            fgets(matricula, 50, stdin);
                            int posicao_aluno = procura_aluno(q_alunos, alunos, matricula);
                        
                            if (posicao_aluno == aluno_inexistente)
                            {
                                printf("Matricula digitada não pertence a nenhum aluno cadastrado!!\n");
                            }
                            else
                            {
                                alunos[TAM_ALUNO] = excluir_alunos(q_alunos, alunos, posicao_aluno);
                                q_alunos--;
                            }
                           
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

