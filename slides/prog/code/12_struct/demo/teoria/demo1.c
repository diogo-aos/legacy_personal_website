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

Aluno criar_aluno(char * nome_aluno, unsigned int nip_aluno,
                  unsigned int n_notas, float notas_aluno[n_notas]){
    Aluno temp;

    // copiar nome
    strcpy(temp.nome, nome_aluno);
    
    // copiar NIO
    temp.NIP = nip_aluno;

    // copiar notas
    for(int i=0; i<n_notas; i++){
        temp.notas[i] = notas_aluno[i];
    }
    return temp;
}

int main(){
    Aluno a = {"Asimov", 136787, {20.0, 20.0, 20.0}};
    float notas_b[NOTAS_SIZE] = {15.0, 16.0, 17};
    Aluno b = criar_aluno("Asimov2", 144442, NOTAS_SIZE, notas_b);
    mostrar_aluno(&a);
    mostrar_aluno(&b);

    getchar();  // getchar apenas para terminal não sair antes de ler resultado
    return 0;
}