#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM_ALUNO 50
#define invalido -5
#define pessoa_inexistente -2
#define vazio -3
#define excluido 0

typedef struct
{
    char nome[TAM_ALUNO];
    char codigo[TAM_ALUNO];
    char semestre[TAM_ALUNO];
    char professor[TAM_ALUNO];
   
} disciplina;

char menu_disciplina(void);
int cadastrar_disciplina(int tamanho, disciplina disciplinas[], int p_tamanho, pessoa professores[]);
int listar_disciplina(int tamanho, disciplina disciplinas[], int q_alunos, pessoa alunos[]);
int excluir_disciplina(int tamanho, disciplina disciplinas[]);


char menu_disciplina(void)
{
    char resposta;

    printf("\n---------- DISCIPLINAS ----------\n");
    printf("[0] - Voltar\n");
    printf("[1] - Cadastrar Disciplina\n");
    printf("[2] - Listar Disciplinas\n");
    printf("[3] - Atualizar Disciplina\n");
    printf("[4] - Excluir Disciplina\n");
    printf("[5] - Incluir Aluno\n");
    printf("-----------------------------------\n");
    printf("Opção: ");
    resposta = getchar();
    while (getchar() != '\n');
    return resposta;
}

int cadastrar_disciplina(int tamanho, disciplina disciplinas[], int p_tamanho, pessoa professores[])
{
    printf("\n---------- CADASTRAR ----------\n");
    printf("NOME: ");
    fgets(disciplinas[tamanho].nome, 50, stdin);
    disciplinas[tamanho].nome[strcspn(disciplinas[tamanho].nome, "\n")] = '\0';

    printf("Código: ");
    fgets(disciplinas[tamanho].codigo, 50, stdin);
    disciplinas[tamanho].codigo[strcspn(disciplinas[tamanho].codigo, "\n")] = '\0';

    printf("Semestre: ");
    fgets(disciplinas[tamanho].semestre, 50, stdin);
    disciplinas[tamanho].semestre[strcspn(disciplinas[tamanho].semestre, "\n")] = '\0';

    printf("Professor: ");
    fgets(disciplinas[tamanho].professor, 50, stdin);
    disciplinas[tamanho].professor[strcspn(disciplinas[tamanho].professor, "\n")] = '\0';
    
    for(int x = 0; x < p_tamanho; x++)
    {
        if(strcmp(disciplinas[tamanho].professor, professores[x].matricula) == 0)
        {
            return 0;
        }
    }
    printf("---------------------------------\n");
    //se retornar invalido imprima uma mensagem falando que o professor não foi encontrado e não acrescente nenhum valor ao q_disciplinas
    return invalido;
}

int incluir_aluno(int tamanho, disciplina disciplinas[], int q_alunos, pessoa alunos[])
{
    char matricula[TAM_ALUNO];
    char discip[TAM_ALUNO];
    int teste = 0, x = 0, y = 0;

    printf("Digite a matricula do aluno: ");
    fgets(matricula, 50, stdin);
    matricula[strcspn(matricula, "\n")] = '\0';
    printf("Digite o código da disciplina: ");
    fgets(discip, 50, stdin);
    discip[strcspn(discip, "\n")] = '\0';

    for(int i = 0; i < q_alunos; i++)
    {
        if (strcmp(matricula, alunos[i].matricula) == 0) 
        {
            x = i;
            teste++;
            break;
        }
    }

    for(int j = 0; j < tamanho; j++)
    {
        if (strcmp(discip, disciplinas[j].codigo) == 0)
        {
            y = j;
            teste++;
            break;
        }
    }

    if (teste == 2)
    {
        alunos[x].cursando[y] = 1;
        return 0;
    }
    return pessoa_inexistente;
}

int listar_disciplina(int tamanho, disciplina disciplinas[], int q_alunos, pessoa alunos[])
{
    printf("---------------- Lista de disciplinas ------------------\n");
    for(int x = 0; x < tamanho; x++)
    {
        printf("Displina: %s\n", disciplinas[x].nome);
        printf("Professor: %s\n", disciplinas[x].professor);
        printf("Código: %s\n", disciplinas[x].codigo);
        printf("Alunos:\n");
        for(int y = 0; y < q_alunos; y++)
        {
            if (alunos[y].cursando[x] == 1)
            {
                printf("%s - %s\n", alunos[y].nome, alunos[y].matricula);
            }
        }
        printf("\n");
    }
    printf("--------------------------------------------------------\n");
    return 0;
}

int excluir_disciplina(int tamanho, disciplina disciplinas[])
{
    char codigo[20];
    int encontrado = 0;
    if (tamanho == 0)
    {
        printf("nenhuma pessoa disciplina cadastrada");
        return vazio;
    }

    printf("Digite o código da disciplina: ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';
  
    for(int i = 0; i < tamanho; i++)
    {
        if(strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            for(int j = i; j < tamanho; j++)
            {
                disciplinas[j] = disciplinas[j + 1];
            }
            encontrado = 1;
            break;
        }
        
    }
    if (encontrado == 1)
        return excluido;
    else
        return pessoa_inexistente;
}