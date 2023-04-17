#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *fp;
  int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int v2[10];
  int escritos1, lidos2;
  
  fp = fopen("dados.bin", "wb");
  escritos1 = fwrite(v, sizeof(int), 10, fp);
  fclose(fp);
  

  fp = fopen("dados.bin", "rb");
  lidos2 = fread(v2, sizeof(int), 10, fp);
  fclose(fp);

  for(int i=0; i<lidos2; i++)
    printf("v[%d]=%d\n", i, v2[i]);

  fp = fopen("dados.bin", "rb+");
  printf("%ld\tfile position after opening file with r\n", ftell(fp));

  fseek(fp, 0, SEEK_END);  
  printf("%ld\tfile position after fseek(fp, 0, SEEK_END)\n", ftell(fp));

  fseek(fp, -2 * sizeof(int), SEEK_END);
  printf("%ld\tfile position after fseek(fp, -2 * sizeof(int), SEEK_END)\n", ftell(fp));

  int val = 42;
  fwrite(&val, sizeof(int), 1, fp);
  printf("%ld\tfile position after writing one int\n", ftell(fp));

  rewind(fp);
  printf("%ld\tfile position after rewind(fp)\n", ftell(fp));
  
  
  fclose(fp);


  fp = fopen("dados.bin", "rb");
  lidos2 = fread(v2, sizeof(int), 10, fp);
  fclose(fp);

  for(int i=0; i<lidos2; i++)
    printf("v[%d]=%d\n", i, v2[i]);
  
  return 0;
}