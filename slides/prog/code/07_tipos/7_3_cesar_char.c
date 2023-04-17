#include <stdio.h>

int main(void) {
  char c;
  int k;
  printf("chave:");
  scanf("%d", &k);
  printf("letra:");
  scanf(" %c", &c);

  // remover voltas da chave
  k = k % ('Z' - 'A' + 1);

  // movimentar abecedário para que 'A' = 0
  // e adicionar chave
  c = (c - 'A' + k);

  // dar a volta depois da chave
  if (c>0)
    c = c % ('Z' - 'A' + 1) + 'A';
  else if (c<0)
    c = ('Z' - 'A' + 1) + c + 'A';
  else
    c += 'A';

  printf("letra: %c", c);

  return 0;
}