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

unsigned char single_test(int b, int e, float esperado){
  if (potencia(b,e) != esperado){
    printf("potencia(%d,%d) -> %f, esperado %f", b, e, potencia(b,e), esperado);
    return 0;
  }
  return 1;
}

unsigned char tests_potencia(){
  // multiplicamos o resultado dos single_test (0 ou 1)
  // se todos os testes passarem, o resultado é 1
  return single_test(2, 2, 4.0) *
         single_test(2, 3, 8.0) *
         single_test(2, -2, 0.25) *
         single_test(2, 0, 1.0) *
         1;
}

int main(void) {

  int b, e;
  float p;

  if(tests_potencia() == 0){
    printf("testes não passaram.");
    return 1;
  }
  
  printf("Base: ");
  scanf("%d", &b);

  printf("Espoente: ");
  scanf("%d", &e);

  p = potencia (b, e);

  printf("Potencia: %f", p);  
  
  return 0;
}

