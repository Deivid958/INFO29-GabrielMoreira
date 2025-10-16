#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ALUNO 50
#define invalido -5
#define pessoa_inexistente -2
#define vazio -3
#define excluido 0

int menu_relatorio(void)
{
    int resposta;

    printf("\n------------------------------ Relatórios ----------------------------------\n");
    printf("[0] - Voltar\n");
    printf("[1] - Listar Disciplinas\n");
    printf("[2] - Listar uma Disciplina\n");
    printf("[3] - Listar Alunos por sexo\n");
    printf("[4] - Listar Alunos ordenados por Nome\n");
    printf("[5] - Listar Alunos ordenados por data de nascimento\n");
    printf("[6] - Listar Professores por sexo\n");
    printf("[7] - Listar Professores ordenados por Nome\n");
    printf("[8] - Listar Professores ordenados por data de nascimento\n");
    printf("[9] - Aniversariante do mês\n");
    printf("[10] - Busca com 3 letras\n");
    printf("[11] - Lista de alunos matriculados em menos de 3 disciplinas\n");
    printf("[12] - Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas\n");        
    printf("-------------------------------------------------------------------------------\n");
    printf("Opção: ");
    scanf("%d", &resposta);
    while (getchar() != '\n');
    return resposta;
}

void exibir_disciplinas(int tamanho, disciplina disciplinas[])
{   
    printf("\nDisciplinas: ");
    for(int x = 0; x < tamanho; x++)
    {
        printf("%s - %s\n", disciplinas[x].nome, disciplinas[x].codigo);
    }
}

int exibir_disciplina(int tamanho, disciplina disciplinas[], int q_alunos, pessoa alunos[])
{
    char codigo[20];
    int posicao = -1;

    if (tamanho == 0)
    {
        printf("nenhuma pessoa disciplina cadastrada\n");
        return vazio;
    }

    printf("Digite o código da disciplina: ");
    fgets(codigo, 20, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';
  
    for (int i = 0; i < tamanho; i++)
    {
        if(strcmp(disciplinas[i].codigo, codigo) == 0)
        {
            posicao = i;
            printf("\nDisciplina: %s\n", disciplinas[i].nome);
            break;
        }
    }

    if(posicao == -1)
    {
        printf("A disciplina digitada não existe\n");
    }

    for (int j = 0; j < q_alunos; j++)
    {
        if (alunos[j].cursando[posicao] == 1)
        {
            printf("%s - %s\n", alunos[j].nome, alunos[j].matricula);
        }
    }
    return 0;      
}

int listar_alunos_sexo(int tamanho, pessoa alunos[])
{   
    char modo;

    if (tamanho == 0)
    {
        printf("Nenhum aluno cadastrado\n");
        return vazio;
    }
    printf("[M] -> listar homens\n");
    printf("[F] -> listar mulheres\n");

    do{
        scanf("%c", &modo);
        while (getchar() != '\n');
    }
    while(modo != 'M' && modo != 'F');
    
    printf("%c:\n", modo);
    for(int x = 0; x < tamanho; x++)
    {
        if (alunos[x].sexo == modo)
        {
            printf("%s - %s\n", alunos[x].nome, alunos[x].matricula);
        }
    }
}

void ordenar_lista(int tamanho, pessoa alunos[])
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int pos_menor = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (strcmp(alunos[j].nome, alunos[pos_menor].nome) < 0)
            {
                pos_menor = j;
            }
        }

        if (pos_menor != i)
        {
            pessoa temp = alunos[i];
            alunos[i] = alunos[pos_menor];
            alunos[pos_menor] = temp;
        }
    }
}

void matriculados(int tamanho, pessoa alunos[])
{
    int count = 0;

    printf("\nAlunos que estão matriculados em menos 3 disciplinas: \n");
    for(int x = 0; x < tamanho; x++)
    {
        for(int y = 0; y < 50; y++)
        {
            if(alunos[x].cursando[y] == 1)
            {
                count++;
            }

        }
        if (count < 3)
        {
            printf("%s - %s\n", alunos[x].nome, alunos[x].matricula);
        }
        count = 0;
    }
}

void disciplinas_cheias(int tamanho, pessoa alunos[], int q_disciplinas, disciplina disciplinas[])
{
    int count = 0;
    int d = 0;

    printf("\ndisciplinas que estão com mais de 40 alunos matriculados: \n");
    
    for(int d = 0; d < q_disciplinas; d++)
    {
        for(int y = 0; y < tamanho; y++)
        {
            if(alunos[y].cursando[d] == 1)
            {   
                count++;
            }
        }
        if (count > 40)
        {
            printf("%s - %s\n", disciplinas[d].nome, disciplinas[d].codigo);
        }
        count = 0;
    }
        
    
}
