#include <stdio.h>
#define M_MESES 200

/* * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * *
                ARRAYS
* * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * */

/*
Escreva um programa que guarde os salários
pagos a um indivíduo durante M meses.
Em seguida deverá mostrar os valores
mensais e o total de todos os meses.

Crie um vector para guardar os salários.

Crie uma função que pede ao utilizador o salário de cada
mês e depois o guarda no vetor.

Crie 3 funções
para: mostrar todos os salários, calcular a soma
e a média dos salarios. Não use variáveis globais.
*/

void test( int rows, int cols, int vec[rows][cols]) { return; }

void pede_salarios(float sals[], int n_meses);
void print_salarios(float sals[], int n_meses);
float soma_salarios(float sals[], int n_meses);
float media_salarios(float sals[], int n_meses);

int main() {
  float salarios[M_MESES];
  int meses;
  printf("Quandos meses:");
  scanf("%d", &meses);

  pede_salarios(salarios, meses);
  print_salarios(salarios, meses);
  printf("Total: %.2f\n", soma_salarios(salarios, meses));
  printf("Media: %.2f\n", media_salarios(salarios, meses));
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