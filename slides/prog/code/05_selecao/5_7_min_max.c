#include <stdio.h>

int main(void) {
  int a,b,c,d;
  int min1, min2, max1, max2;
  printf("Escreve 4 inteiros:");
  scanf("%d %d %d %d", &a, &b, &c, &d);

  if (a>b) min1=b, max1=a;
  else min1=a, max1=b;

  if (c>d) min2=d, max2=c;
  else min2=c, max2=d;

  if (min1>min2) min1=min2;
  if (max1<max2) max1=max2;
  
  printf("Mínimo:%d\n", min1);
  printf("Máximo:%d\n", max1);
  return 0;
}