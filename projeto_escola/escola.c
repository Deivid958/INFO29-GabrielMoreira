#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escola.h"

#define TAM_ALUNO 50
#define aluno_inexistente -1


char menugeral(void);
char menu_pessoa(char tipo[]);
void cadastrar_pessoa(int posicao, pessoa pessoas[]);
void listar_pessoas(int tamanho, pessoa pessoas[]);
pessoa excluir_pessoa(int tamanho, pessoa pessoas[], int indice);
int procura_pessoa(int tamanho, pessoa pessoas[], char matricula[]);
void atualizar_pessoa(pessoa pessoas[], int indice);

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
                    opcao_aluno = menu_pessoa("Aluno");

                    switch(opcao_aluno)
                    {
                        case '0':
                        {
                            sair_aluno = 1;
                            break;
                        }
                        case '1':
                        {
                            cadastrar_pessoa(q_alunos, alunos);
                            q_alunos++;
                            break;
                        }
                        case '2':{
                            listar_pessoas(q_alunos, alunos);
                            break;
                        }
                        case '3':{
                            char matricula[TAM_ALUNO];
                            printf("Digite a matricula do aluno: ");
                            fgets(matricula, 50, stdin);
                            int posicao_aluno = procura_pessoa(q_alunos, alunos, matricula);
                        
                            if (posicao_aluno == aluno_inexistente)
                            {
                                printf("Matricula digitada não pertence a nenhum aluno cadastrado!!\n");
                            }
                            else
                            {
                                atualizar_pessoa(alunos, posicao_aluno);
                            }
                            break;
                        }
                        case '4':{
                            char matricula[TAM_ALUNO];
                            printf("Digite a matricula do aluno: ");
                            fgets(matricula, 50, stdin);
                            int posicao_aluno = procura_pessoa(q_alunos, alunos, matricula);
                        
                            if (posicao_aluno == aluno_inexistente)
                            {
                                printf("Matricula digitada não pertence a nenhum aluno cadastrado!!\n");
                            }
                            else
                            {
                                alunos[TAM_ALUNO] = excluir_pessoa(q_alunos, alunos, posicao_aluno);
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

