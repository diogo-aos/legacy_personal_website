#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *fp;
  fp = fopen("test.txt", "w");
  for (int i = 0; i < 10; i++)
    fprintf(fp, "%d, Ola mundo!\n", i);
  fclose(fp);

  fp = fopen("test.txt", "r");
  char frase[100];
  while (fgets(frase, 100, fp) != NULL) {
    puts(frase);
  }
  fclose(fp);

  fp = fopen("test.txt", "r");
  int x;
  while (fscanf(fp, "%d, ", &x) != EOF && fgets(frase, 100, fp) != NULL){
    printf("x=%d | frase=%s", x, frase);
  }
  fclose(fp);
  return 0;
}