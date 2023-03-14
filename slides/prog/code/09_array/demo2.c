#include <stdio.h>
#define M_MESES 2
#define N_PESSOAS 3

/* * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * *
                ARRAYS
* * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * */



void pede_salarios(float sals[], int n_meses);
void pede_salarios_todos(float todos_sals[][M_MESES], unsigned int n_pax);
void print_salarios(float sals[], int n_meses);
float soma_salarios(float sals[], int n_meses);
float media_salarios(float sals[], int n_meses);

int main() {
  float salarios[N_PESSOAS][M_MESES];
  pede_salarios_todos(salarios, N_PESSOAS);


  printf("\n\n");
  printf("Pessoa No.\tTotal\tMedia\n");
  for(int i=0; i<N_PESSOAS; i++){
    printf("%10d\t%5.2f\t%5.2f\n", i, soma_salarios(salarios[i], M_MESES), media_salarios(salarios[i], M_MESES));
  }

}

void pede_salarios_todos(float todos_sals[][M_MESES], unsigned int n_pax){
  for(int i=0; i<n_pax; i++){
    printf("\n--- Salarios Pessoa %d ---\n", i);
    pede_salarios(todos_sals[i], M_MESES);
  }
}

float media_salarios(float sals[], int n_meses) {
  return soma_salarios(sals, n_meses) / n_meses;
}

float soma_salarios(float sals[], int n_meses) {
  float total = 0;
  for (int i = 0; i < n_meses; i++) {
    total = total + sals[i];
  }
  return total;
}

void print_salarios(float sals[], int n_meses) {
  printf("\n\n----Valores dos salarios----\n");
  for (int i = 0; i < n_meses; i++) {
    printf("Salario do mes %d: %.2f\n", i, sals[i]);
  }
}

void pede_salarios(float sals[], int n_meses) {
  for (int i = 0; i < n_meses; i++) {
    printf("Introduza salario do mes %d:", i);
    scanf("%f", &sals[i]);
  }
}