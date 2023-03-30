#include <stdio.h>
#include <string.h>
#define MAX_NOME_SIZE 50
#define NOTAS_SIZE 3

/*
 nome (string)
  NIP
(int),
vector com 3 números reais para guardar asclassificações das avaliações.


criar_aluno 

 mostrar_aluno 
*/

typedef struct {
    char nome[MAX_NOME_SIZE];
    unsigned int NIP;
    float notas[NOTAS_SIZE];
} Aluno;

void mostrar_aluno(Aluno * pa){
    printf("\n\n---- Aluno ----\n");
    printf("Nome:%s\n", pa->nome);
    printf("NIP:%u\n", pa->NIP);
    printf("Notas:\n");
    for(int i=0; i<NOTAS_SIZE; i++)
        printf("%d: %f\n", i+1, pa->notas[i]);
    printf("---------------\n");
}

Aluno criar_aluno(){
    Aluno temp;

    printf("\n\n---- Criar aluno ----\n");

    // ler nome
    printf("nome:");
    fgets(temp.nome, MAX_NOME_SIZE, stdin);

    // ler nip
    printf("nip:");
    scanf("%u", &temp.NIP);

    // ler notas
    printf("notas:\n");
    for(int i=0; i<NOTAS_SIZE; i++){
        printf("\t%d:", i+1);
        scanf("%f", &temp.notas[i]);
        getchar();
    }

    printf("---------------------");

    return temp;
}

int main(){
    unsigned int n_alunos;

    printf("Tamanho da turma:");
    scanf("%u", &n_alunos);
    getchar();

    Aluno turma[n_alunos];

    // pedir dados de todos os alunos
    for(int i=0; i<n_alunos; i++){
        turma[i] = criar_aluno();
    }

    // mostrar alunos da turma
    for(int i=0; i<n_alunos; i++){
        mostrar_aluno(&turma[i]);
    }

    scanf(" %c");  // getchar apenas para terminal não sair antes de ler resultado
    return 0;
}