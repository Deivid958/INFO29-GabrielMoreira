#include <stdio.h>
#include <string.h>
#include "Disci_funcoes.h"

int Disci_menu(void){
    int resposta_disciplina;
    printf("[0]Voltar para modulos\n");
    printf("[1]Cadastrar disciplina\n");
    printf("[2]Listar disciplina\n");
    printf("[3]Atualizar disciplina\n");
    printf("[4]Excluir disciplina\n");
    printf("Escolha:");
    scanf("%d",&resposta_disciplina);
    return resposta_disciplina;
}

void Disci_CadastrarAtualizar(int i,disci disciplina[]){
    getchar();
    printf("Nome da disciplina:");
    fgets(disciplina[i].nome,31,stdin);
    getchar();
    printf("Codigo da diiplina:");
    scanf("%d",&disciplina[i].codigo);
    while(disciplina[i].codigo <= 0)
    {
        printf("Codigo tem que ser maior que 0\n");
        printf("Codigo da disciplina:");
        scanf("%d",&disciplina[i].codigo);
    }
    printf("Semestre:");
    scanf("%d",&disciplina[i].semestre);
    while(disciplina[i].semestre <= 0)
    {
        printf("Semestre tem que ser maior que 0\n");
        printf("Semestre da disciplina:");
        scanf("%d",&disciplina[i].semestre);
    }
    getchar();
    printf("Professor da disciplina:");
    fgets(disciplina[i].professor,31,stdin);
    getchar();
}
void Disci_listar(int qtdisciplina,disci disciplina[]){
    for(int i = 0;i < qtdisciplina;i++)
    {
        printf("\tDisciplina %d:\n",i+1);
        printf("Nome:%s",disciplina[i].nome);
        printf("Codigo:%d\n",disciplina[i].codigo);
        printf("Semestre:%d\n",disciplina[i].semestre);
        printf("Professor:%s\n",disciplina[i].professor);
    }
}

void Disci_excluir(int qtdisciplina,int i, disci disciplina[]){    
    for(int j = i; j < qtdisciplina-1;j++)
    {
        disciplina[j].codigo = disciplina[j+1].codigo;
        disciplina[j].semestre = disciplina[j+1].semestre;
        strcpy(disciplina[j].nome,disciplina[j+1].nome);
        strcpy(disciplina[j].professor,disciplina[j+1].professor);
    } 
}