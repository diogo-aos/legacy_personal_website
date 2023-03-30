#include <stdio.h>
#include <float.h>

/*
Função calcula o imposto do rendimento num determinado escalão.
O escalão é definido pelo mínimo, máximo e a taxa a aplicar.
*/
float calc_escalao(float esc_min, float esc_max, float esc_tax, float r){
  float esc_total;
  if (r > esc_min){
    if (r <= esc_max) esc_total = r - esc_min;
    else esc_total = esc_max - esc_min;
  
    return esc_total * esc_tax / 100;
  }
  else
    return 0.0;
}

float calcular_irs(float r){
  float esc0_max = 0;
  float esc1_max = 7116, esc1_tax = 14.5;
  float esc2_max = 15216, esc2_tax = 23.0;
  float esc3_max = 36757, esc3_tax = 28.5;
  float esc4_max = 75009, esc4_tax = 43.5;
  float esc5_max = FLT_MAX, esc5_tax = 48.0;  
  float tax=0.0;  // rendimento
  
  
  // escalao 1
  tax += calc_escalao(esc0_max, esc1_max, esc1_tax, r);
  // escalao 2
  tax += calc_escalao(esc1_max, esc2_max, esc2_tax, r);
  // escalao 3
  tax += calc_escalao(esc2_max, esc3_max, esc3_tax, r);
  // escalao 4
  tax += calc_escalao(esc3_max, esc4_max, esc4_tax, r);
  // escalao 5
  tax += calc_escalao(esc4_max, esc5_max, esc5_tax, r);

  return tax;
}

int main(void) {
  float rendimento, imposto;
  printf("Rendimento:");
  scanf("%f", &rendimento);
  imposto = calcular_irs(rendimento);
  printf("imposto: %f\n", imposto);
  
  return 0;
}