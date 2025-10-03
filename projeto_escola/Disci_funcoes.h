#ifndef Disci_funcoes
#define Disci_funcoes

typedef struct disciplina{
    int codigo;
    int semestre;
    char nome[31];
    char professor[31];
}disci;

int Disci_menu(void);
void Disci_CadastrarAtualizar(int qtdisciplina,disci disciplina[]);
void Disci_listar(int qtdisciplina,disci disciplina[]);
void Disci_excluir(int qtdisciplina,int exclui,disci disciplina[]);

#endif