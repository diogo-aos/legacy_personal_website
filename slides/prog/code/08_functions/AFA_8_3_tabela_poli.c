#include <stdio.h>

void poli2_intervalo(float inf, float sup, int n_pontos, float c1, float c2, float c3){
  float step = (sup - inf) / (n_pontos-1);
  while(inf <= sup){
    printf("%f\t%f\n", inf, inf*inf*c1+inf*c2+c3);
    inf += step;
  }
  
}

int main(void) {
  poli2_intervalo(2.0, 3.0, 5, 0, 1, 0);
  return 0;
}