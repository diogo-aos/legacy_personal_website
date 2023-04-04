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
    }

    printf("---------------------");

    return temp;
}

int main(){
    Aluno a = {"Asimov", 136787, {20.0, 20.0, 20.0}};
    float notas_b[NOTAS_SIZE] = {15.0, 16.0, 17};
    Aluno b = criar_aluno();
    mostrar_aluno(&a);
    mostrar_aluno(&b);

    scanf(" %c");  // getchar apenas para terminal não sair antes de ler resultado
    return 0;
}