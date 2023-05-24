#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int id;
  char cidade[50];
  char nome[50];
} Estudante;

char* nomes[20] = {
  "Afonso",
  "Ana",
  "António",
  "Beatriz",
  "Bernardo",
  "Carla",
  "Catarina",
  "Daniel",
  "Diogo",
  "Eduardo",
  "Fábio",
  "Francisco",
  "Gonçalo",
  "Inês",
  "Joana",
  "João",
  "José",
  "Luís",
  "Margarida",
  "Marta"
};

int main() {
  char cidades[5][50] = {
    "Lisboa",
    "Porto",
    "Coimbra",
    "Braga",
    "Funchal"
  };

  Estudante estudantes[20];

  // Initialize the array with mock data
  srand(time(NULL));
  for (int i = 0; i < 20; i++) {
    estudantes[i].id = rand() % 101 + 1400;
    strcpy(estudantes[i].cidade, cidades[i % 5]);
    strcpy(estudantes[i].nome, nomes[rand() % 20]);
  }

  // Print the array
  for (int i = 0; i < 20; i++) {
    printf("%d %s %s\n", estudantes[i].id, estudantes[i].cidade, estudantes[i].nome);
  }

FILE * fp = fopen("estudantes.bd", "wb");
fwrite(estudantes, sizeof(Estudante), 20, fp);
fclose(fp);

  return 0;
}

