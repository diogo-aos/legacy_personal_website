#include <stdio.h>

float potencia (int b, int e){
  int p;
  float total=1.0;
  
  if (e < 0) p = -e;
  else p = e;

  for(; p>0; p--)
    total *= b;

  if (e >= 0) return total;
  else return 1 / total;  
}

float poli(float x){
  return 3 * potencia(x, 5) + 2 * potencia(x, 4) - 5 * potencia(x, 3) - potencia(x,2) + 7*x - 6;
}

int main(void) {
  float x;
  printf("x:");
  scanf("%f", &x);
  printf("Polinómio em x: %f", poli(x));
  return 0;
}