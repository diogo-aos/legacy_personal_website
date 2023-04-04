#include <stdio.h>
#include <string.h>
#define MAX_NOME_SIZE 50
#define MAX_ALUNOS 300
#define MAX_ALUNOS_UC 150
#define MAX_UC 100

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

float media_UC(UC * puc){
    float media = 0.0;
    if (puc->n_inscritos == 0) return 0.0;

    for(int i=0; i<puc->n_inscritos; i++){
        media += puc->notas[i];
    }

    return media / puc->n_inscritos;
}

void mostrar_UC(UC * puc){
    printf("\n\n---- UC ----\n");
    printf("\tnome: %s\n", puc->nome);
    printf("\tabreviatura: %s\n", puc->abrev);
    printf("\tcréditos: %u\n", puc->n_creds);
    printf("\tmédia: %f\n", media_UC(puc));
    printf("\t# inscritos: %u\n", puc->n_inscritos);
    printf("\talunos:\n");
    for(int i=0; i<puc->n_inscritos; i++){
        Aluno * p_aluno = puc->alunos[i];
        printf("\t\t%d - %s\n", p_aluno->NIP, p_aluno->nome);
    }
}

float media_aluno(Aluno * pa, int n_cadeiras, UC cadeiras[n_cadeiras]){
    float media = 0.0;
    float pesos = 0.0;

    if (n_cadeiras == 0) return 0.0;

    for (int i=0; i<n_cadeiras; i++){
        UC * puc = &cadeiras[i];
        // verificar se o aluno está inscrito na UC i
        for(int j=0; j<puc->n_inscritos; j++){
            if(puc->alunos[j] == pa){
                pesos += puc->n_creds;
                media += puc->notas[j] * puc->n_creds;
            }
        }
    }

    if (pesos == 0.0) return 0.0;
    return media / pesos;
}

int main(){
    unsigned int n_alunos = 4;
    Aluno alunos[MAX_ALUNOS] = {
        {"Asimov", 136787},
        {.NIP=144555, .nome="Newton"},
        {.NIP=133444, .nome="Einstein"},
        {.NIP=122333, .nome="Saramgo"},
    };

    unsigned int n_cadeiras = 3;
    UC cadeiras[MAX_UC] = {
        {.nome="Programação", .abrev="PROG", .n_creds=6, .n_inscritos=2,
        .alunos={&alunos[0], &alunos[1]},
        .notas={18.0, 17.0}
        },
        {.nome="Cálculo Integral Diferencial II", .abrev="CDI2", .n_creds=6, .n_inscritos=2,
        .alunos={&alunos[2], &alunos[3]},
        .notas={20.0, 8.0}
        },
        {.nome="Arquitectura de Computadores", .abrev="ARQC", .n_creds=7, .n_inscritos=1,
        .alunos={&alunos[0]},
        .notas={20.0}
        },
    };

    //cadeiras[n_cadeiras] = criar_UC();
    //n_cadeiras++;

    // mostrar alunos da turma
    for(int i=0; i<n_alunos; i++){
        mostrar_aluno(&alunos[i]);
    }

    // mostrar alunos da turma
    for(int i=0; i<n_cadeiras; i++){
        mostrar_UC(&cadeiras[i]);
    }

    printf("media aluno 0:%f\n", media_aluno(&alunos[0], n_cadeiras, cadeiras));

    return 0;
}