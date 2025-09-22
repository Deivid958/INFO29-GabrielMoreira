#include <stdio.h>
#include <stdlib.h>

void menugeral(void);

int main(void)
{
    int sair = 0;
    char opcao;

    while (!sair)
    {
        menugeral();
        printf("opção: ");
        scanf("%c", &opcao);

        switch(opcao)
        {
            case '0':{
                sair++;
                break;
            }
            case '1':{
                printf("Alunos\n");
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
            }
                
        }
    }
}

void menugeral(void)
{
    printf("-------- MENU GERAL --------\n");
    printf("[0] - Sair\n");
    printf("[1] - Alunos\n");
    printf("[2] - Professores\n");
    printf("[3] - Relatórios\n");
    printf("----------------------------\n");
}

//void menu_aluno(void)