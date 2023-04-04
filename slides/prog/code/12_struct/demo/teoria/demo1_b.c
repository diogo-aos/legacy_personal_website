#include <stdio.h>
#include <string.h>
#define MAX_NOME_SIZE 50
#define MAX_ALUNOS 300
#define MAX_ALUNOS_UC 150
#define MAX_UC 100

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
} Aluno;

typedef struct {
    char nome[MAX_NOME_SIZE];
    char abrev[5];
    unsigned char n_creds;
    unsigned char n_inscritos;
    Aluno * alunos[MAX_ALUNOS_UC];
    float notas[MAX_ALUNOS_UC];
} UC;

void mostrar_aluno(Aluno * pa){
    printf("\n\n---- Aluno ----\n");
    printf("Nome:%s\n", pa->nome);
    printf("NIP:%u\n", pa->NIP);
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

    printf("---------------------");

    return temp;
}

UC criar_UC(){
    UC temp;

    printf("\n\n---- Criar UC ----\n");

    // ler nome
    printf("nome:");
    fgets(temp.nome, MAX_NOME_SIZE, stdin);

    // ler abrev
    printf("abrev:");
    fgets(temp.abrev, 4, stdin);

    // ler creditos
    printf("# creditos:");
    scanf("%hhu", &temp.n_creds);

    temp.n_inscritos = 0;

    printf("---------------------");

    return temp;
}

void mostrar_UC(UC * puc){
    printf("\n\n---- UC ----\n");
    printf("\tnome: %s\n", puc->nome);
    printf("\tabreviatura: %s\n", puc->abrev);
    printf("\tcréditos: %u\n", puc->n_creds);
    printf("\t# inscritos: %u\n", puc->n_inscritos);
    printf("\talunos:\n");
    for(int i=0; i<puc->n_inscritos; i++){
        Aluno * p_aluno = puc->alunos[i];
        printf("\t\t%d - %s\n", p_aluno->NIP, p_aluno->nome);
    }
}

int main(){
    unsigned int n_alunos = 4;
    Aluno alunos[MAX_ALUNOS] = {
        {"Asimov", 136787},
        {.NIP=144555, .nome="Newton"},
        {.NIP=133444, .nome="Einstein"},
        {.NIP=122333, .nome="Saramgo"},
    };

    unsigned int n_cadeiras = 2;
    UC cadeiras[MAX_UC] = {
        {.nome="Programação", .abrev="PROG", .n_creds=6, .n_inscritos=2,
        .alunos={&alunos[0], &alunos[1]},
        .notas={18.0, 17.0}
        },
        {.nome="Cálculo Integral Diferencial II", .abrev="CDI2", .n_creds=6, .n_inscritos=2,
        .alunos={&alunos[2], &alunos[3]},
        .notas={20.0, 8.0}
        },
    };

    cadeiras[n_cadeiras] = criar_UC();
    n_cadeiras++;

    // mostrar alunos da turma
    for(int i=0; i<n_alunos; i++){
        mostrar_aluno(&alunos[i]);
    }

    // mostrar alunos da turma
    for(int i=0; i<n_cadeiras; i++){
        mostrar_UC(&cadeiras[i]);
    }

    return 0;
}