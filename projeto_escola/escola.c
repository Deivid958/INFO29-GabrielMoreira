#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escola.h"
#include "Disci_funcoes.h"

#define TAM_ALUNO 50
#define TAM_DISCIPLINA 20
#define cadastro_inexistente -1

int main(void)
{
    char matricula[TAM_ALUNO];
    int codigo, posicao_disciplina, resposta_disciplina;
    int sair = 0, sair_menu = 0;
    int opcao = 0, opcao_menu = 0; 
    aluno alunos[TAM_ALUNO];
    disci disciplina[TAM_DISCIPLINA];
    int q_alunos = 0,q_disicplinas = 0;

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
                while (!sair_menu)
                {
                    opcao_menu = menu_aluno();

                    switch(opcao_menu)
                    {
                        case '0':
                        {
                            sair_menu = 1;
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
                        
                            if (posicao_aluno == cadastro_inexistente)
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
                            printf("Digite a matricula do aluno: ");
                            fgets(matricula, 50, stdin);
                            int posicao_aluno = procura_aluno(q_alunos, alunos, matricula);
                        
                            if (posicao_aluno == cadastro_inexistente)
                            {
                                printf("Matricula digitada não pertence a nenhum aluno cadastrado!!\n");
                            }
                            else
                            {
                                excluir_alunos(q_alunos, alunos, posicao_aluno);
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
            case '4':{
                printf("Disciplinas\n");
                resposta_disciplina = -1;
                while(resposta_discplina != 0)
                {
                    switch(resposta_discplina)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            Disci_CadastrarAtualizar(q_disciplina, disciplina);
                            q_disicplina++;
                            break;
                        }
                        case 2:
                        {
                            Disci_listar(q_discplina, disciplina);
                            break;
                        }
                        case 3:
                        {
                            printf("Digite o codigo da disciplina: ");
                            fgets(matricula, 50, stdin);
                            int posicao_aluno = procura_aluno(q_alunos, alunos, matricula);
                            if (posicao_aluno == cadastro_inexistente)
                            {
                                printf("Codigo digitado não pertence a nenhuma disciplina cadastrada!!\n");
                            }
                            else
                            {
                                Disci_CadastrarAtualizar(disicplina, posicao_disciplina);
                            }
                            break;
                        }
                        case 4:
                        { 
                            printf("Digite o codigo da disciplina: ");
                            fgets(matricula, 50, stdin);
                            int posicao_aluno = procura_aluno(q_alunos, alunos, matricula);
                            if (posicao_aluno == cadastro_inexistente)
                            {
                                printf("Codigo digitado não pertence a nenhuma disciplina cadastrada!!\n");
                            }
                            else
                            {
                                Disci_excluir(disicplina, posicao_disciplina);
                            }
                        }
                    }
                }   
                break;
            }
            default:{
                printf("opção invalida!\n");
                break;
            }    
        }
    }
}

