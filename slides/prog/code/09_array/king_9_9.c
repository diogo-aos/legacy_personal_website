#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char mat[10][10];
  time_t t;
  char posC = 'A', posRow=0, posCol=0;
  unsigned char esq, dir, cima, baixo;
  int direcao; //0 -> down, 1 -> left, 2 -> up, 3 -> right
  
  /* Intializes random number generator */
   srand((unsigned) time(&t));
  
  // init
  for(int i=0; i<10; i++)
    for(int j=0; j<10; j++)
      mat[i][j] = '.';

  
  // fill
  mat[posRow][posCol] = posC;
  while (posC < 'Z'){
    // inicialmente, todas as posições são consideradas indisponíveis
    esq = dir = cima = baixo = 0; 
    
    // verificar posições disponiveis
    if(posRow-1 >= 0 && mat[posRow-1][posCol] == '.') // verificar cima
      cima = 1;
    if(posRow+1 < 10 && mat[posRow+1][posCol] == '.') // verificar baixo
      baixo = 1;
    if(posCol-1 >= 0 && mat[posRow][posCol-1] == '.') // verificar esquerda
      esq = 1;
    if(posCol+1 < 10 && mat[posRow][posCol+1] == '.') // verificar baixo
      dir = 1;

    // se nenhuma posição disponível, parar
    if (cima + baixo + esq + dir == 0) break;

    // gerar nova direção
    direcao = rand() % 4;

    // print para ver decisões intermédias -> DEBUG
    // printf("e=%d , d=%d , c=%d, b=%d | direcao=%d\n", esq, dir, cima, baixo, direcao);

    switch(direcao){
      case 0:
        if(baixo){
          posRow++;
          posC++;
          mat[posRow][posCol] = posC;
          break;
        }
      case 1:
        if(esq){
          posCol--;
          posC++;
          mat[posRow][posCol] = posC;
          break;
        }
      case 2:
        if(cima){
          posRow--;
          posC++;
          mat[posRow][posCol] = posC;
          break;
        }
      case 3:
        if(dir){
          posCol++;
          posC++;
          mat[posRow][posCol] = posC;
          break;
        }
      default: // nunca deveria acontecer
        break;
    }
  }
  
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++)
      printf("%c ", mat[i][j]);
    printf("\n");
  }
  
  return 0;
}
