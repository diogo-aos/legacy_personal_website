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
  float output = potencia(b, e);
  
  if (output != esperado){ // teste falhou
    printf("potencia(%d, %d) -> %f, o esperado é %f\n", b, e, output, esperado);
    return 0;
  }
  else return 1;
}

unsigned char tests_potencia(){
  return single_test(2, 2, 4.0) * 
         single_test(2, 3, 8.0) * 
         single_test(2, 0, 1.0) * 
         single_test(2, -2, 0.25) * 
         single_test(2, 4, 16.0) * 
         1;
}


int main(void) {

  if(tests_potencia() == 0){ // testes falharam
    printf("testes falharam\n");
    return 1;
  }

  int b, e;
  float p;
  
  printf("Base: ");
  scanf("%d", &b);

  printf("Expoente: ");
  scanf("%d", &e);

  p = potencia (b, e);

  printf("Potencia: %f", p);  
  
  return 0;
}

