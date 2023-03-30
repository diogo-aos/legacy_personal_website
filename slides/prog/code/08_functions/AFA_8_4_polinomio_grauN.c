#include <math.h>
#include <stdio.h>

float poliN_ponto(float x) {
  int grau = 0;
  float coef, res = 0.0;
  for (char c = 'a'; c != 'f'; grau++) {
    printf("Coef grau %d:", grau);
    scanf("%f%c", &coef, &c);
    res += coef * pow(x, grau);
  }
  return res;
}

int main(void) {
  float ponto;
  printf("Ponto a avaliar:");
  scanf("%f", &ponto);
  printf("Resultado do polinómio: %f", poliN_ponto(ponto));
  return 0;
}