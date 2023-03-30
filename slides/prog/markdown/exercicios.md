<img src="img/afa.png" height="100">

# Exercícios
<!-- .slide: data-background="Cornsilk" -->

---


2. [Fundamentos](#/2_exercicios)
3. [I/O Formatado](#/3_exercicios)
4. [Expressões](#/4_exercicios)
5. [Seleção](#/5_exercicios)
6. [Ciclos](#/6_ciclos_exercicios)
7. [Tipos](#/7_tipos_exercicios)
8. [Funções](#/8_funcoes_exercicios)
9. [_Arrays_](#/9_arrays_exercicios)
10. [_Strings_](#/10_strings_exercicios)
11. [Apontadores](#/11_pointers_exercicios)
12. Struct
13. Ficheiros
14. Memória
15. Estruturas de Dados Dinâmicas

---

## 2 Exercícios Fundamentos
<!-- .slide: data-background="Coral" id="2_exercicios" -->

[Slides da matéria](#/2_fundamentals)

---


## Exercícios 3 I/O Formatado
<!-- .slide: data-background="Coral" id="3_exercicios"-->

[Slides da matéria](#/3_formated_io)

---

### Exercícios I/O Formatado King

--

#### King 3.1.

Escreve um programa que aceita uma data do utilizador no formato "dd/mm/aaaa" e escreve na consola a mesma data no formato "aaaa-mm-dd".

```text
Insira data: 01/02/2023
Escreveu:    2023/02/01
```

--

#### King 3.2.

Escreve um programa que formata os dados de um produto inseridos pelo utilizador.

```text
Insira o ID do produto: 583
Insira o preço: 13.5
Insira a data de aquisição (dd/mm/aaaa): 24/10/2010

Item        Preço       Data da
            Unitário    Compra
583         €    13.5   2010/10/24
```

Nota: o ID do item e a data deve estar alinhados à esquerda; o preço unitário deve estar alinhado à direita.
Dica: usa "\t" para alinhas as colunas.

--

#### King 3.3. TODO

--

#### King 3.4. TODO

--

#### King 3.5. TODO

--

#### King 3.6. frações

Escreve um programa que recebe 2 frações do utilizador e escreve a sua soma.
O programa recebe as duas frações de uma só vez, separadas por +.

```text
Insira as fracoes: 5/6+3/4
Soma: 38/24
```


---

## 4 Exercícios Expressões
<!-- .slide: data-background="Coral" id="4_exercicios" -->

[Slides da matéria](#/4_expressions)

---


### Exercícios Expressões King

--

#### King 4.1.

Escreve um programa que pede ao utilizar um número inteiro de 2 digitos e devolve esse número com os digitos invertidos.
Exemplo de execução:

```bash
Insira número inteiro: 42
Invertido:             24
```

Os 2 números devem estar alinhados.

Dica: %10 devolve o último digito de um número e /10 remove o último digito.

--

#### King 4.2

Extende o programa anterior para números de 3 digitos.

--

#### King 4.3

Reimplementa o programa do 4.2 sem usar aritmética. O enunciado dos 4.1 e 4.2 estão abaixo.


---

## 5 Exercícios Seleção
<!-- .slide: data-background="Coral" id="5_exercicios" -->

[Slides da matéria](pdf/03_testes_condicoes.pptx.pdf)


---

### Exercícios Seleção King

--

#### King 5.1

Escreve um programa que recebe um número inteiro e indica quantos digitos esse número tem.

Assume que o número nunca tem mais de 4 digitos.

```
Introduza numero inteiro (maximo 4 digitos): 42
# digitos:                                   2
```

Ajuda: usa if para fazer essa verificação, e.g. se o número estiver entre 10 e 99, então tem 2 digitos.

--

#### King 5.2

Escreve um programa que recebe uma hora no formato de 0-24h e converte para o formato 0-12h.

```
Introduza hora no formato 24h: 23:32
Hora no formato 12h:           11:32 PM

Introduza hora no formato 24h: 10:32
Hora no formato 12h:           10:32 AM

```

--

#### King 5.3. TODO

--

#### King 5.4

A escala de Beaufort indica uma descrição do vento com base na sua velocidade.
Uma versão simplificada é a seguinte:

![](img/5_selection/king_5_4.png)

Escreve um programa que recebe a valocidade do vento e indica a descrição correspondente.

--

#### King 5.5 escalões IRS

O imposto cobrado sobre o rendimento é feito de forma progressiva por escalões (exemplo no slide seguinte).
Versão simplificada dos escalões de 2023:

![](img/5_selection/king_5_5.png)

Escreve um programa que recebe o rendimento anual bruto e indica o imposto total sobre o rendimento e o rendimento líquido final.

--

Imposto progressivo significa que o mesmo rendimento vai ser tributado em escalões diferentes, e.g.

```text
Rendimento: 20000€
Tributaçao no escalão 1: 7116 * 14,5%
Tributaçao no escalão 2: (15216 - 7116) * 23%
Tributaçao no escalão 3: (20000 - 15216) * 28,5%
Tributaçao no escalão 4 e 5 não existe porque o
rendimento não é alto o suficiente.
```

--

#### King 5.6 TODO

--

#### King 5.7

Escreve um programa que recebe 4 números inteiros e indica o número mais alto e o mais pequeno.

```text
Enter four integers: 21 43 10 35
Largest: 43
Smallest : 10
```

Usa o mínimo de ``if`` possível.

Ajuda: se trocares o valor das variáveis, ``4`` if são suficientes.

--

#### King 5.8 voo mais próximo TODO

--

#### King 5.9 data menor

Escreve um programa que pede 2 datas ao utilizador e indica qual é a data que vem antes no calendário.

```text
Data 1: 3/6/2007
Data 2: 3/6/2005
3/6/2005 vem antes de 3/6/2007
```

--

#### King 5.10 nota para letra

Escreve um programa que converte uma nota entre 0 e 100 para uma letra, segundo a seguinte correspondência: A = 90-100, B = 80-89, C = 70-79, D = 60-69, F = 0-59.

A nota é lida do utilizador.
Usa uma instrução switch para implementar o programa.
O programa indica uma mensagem de erro se a nota for inferior a 0 ou superior a 100.

```text
Nota: 84
Letra: B

Nota: -1
Erro, nota deve estar entre 0 e 100.
```

Ajuda: usa o primeiro digito da nota para fazer a correspondência no switch.


--

#### King 5.11 número por extenso

Escreve um programa que recebe um inteiro de 2 digitos e escreve o número por extenso. Implementa o programa sem ``if``.

```text
Nota: 42
Letra: quarenta e dois
```

---

### Exercícios Seleção AFA

--

#### AFA 5.1. Converte gramas para outras unidades

Escreve um programa que converte entre unidades de massa.
O programa primeiro pede o valor da massa em gramas.
Depois mostra um menu com as opções de conversão.
O utilizador recebe a unidade de destino e no final o programa mostra a massa convertida.

```
Introduza massa em gramas: 500
Qual e a unidade de conversao:
1 - oz
2 - lb
3 - kg
Escolha: 3
500 g = 0.5000 kg
```

#### AFA 5.2 Converter unidades de massa

Altera o programa AFA 5.1 para se possa converter entre quaisquer 2 unidades.
Para conseguir isto, o programa pede o valor da massa, depois pede a unidade desse valor e finalmente a unidade da conversão.

```
Introduza massa em gramas: 500
Qual e a unidade desta masa:
1 - oz
2 - lb
3 - kg
4 - g
Escolha: 4

Qual e a unidade de conversao:
1 - oz
2 - lb
3 - kg
Escolha: 3

500 g = 0.5000 kg
```

---

## 6 Exercícios Ciclos
<!-- .slide: data-background="Coral" id="6_ciclos_exercicios" -->

[Slides da matéria](pdf/03_testes_condicoes.pptx.pdf)


---

### Exercícios Ciclos King

--

#### King 6.1. Maior número de série recebida

Escreve um programa que encontra o maior número numa série de números introduzidos pelo utilizador.
O programa pede os números um a um, até encontrar um número seguido da letra f.

```text
Número: 60
Número: 38.3
Número: 4.89
Número: 100.62
Número: 75.2295f

Número maior: 100.62
```

--

#### King 6.2. Máximo Divisor Comum

Escreve um programa para calcular o máximo divisor comum (MCD) entre 2 inteiros.
O programa pede 2 inteiros ao utilizador e indica o MCD.

```text
Numeros: 12 28
MCD: 4
```

A estratégia mais simples (embora menos eficiente) é verificar o resto da divisão dos 2 números recebidos por todos os números a partir do menos dos 2 recebidos até 1. Assim que encontrar um número cujo resto das duas divisões seja 0, é esse o MCD, e.g.

```text
28 % 12 != 0
12 % 12 == 0
--
28 % 11 != 0
12 % 11 != 0
--
28 % 10 != 0
12 % 10 != 0
--
    .
    .
    .
28 % 4 == 0
12 % 4 == 0
MCD = 4 -> parar ciclo
```

--

#### King 6.3. Simplificar fração

Escreve um programa que recebe 1 fração e simplifica-a.

```text
Introduza fracao: 6/12
Simplificada: 1/2
```

Dica: usar a implementação do 6.2. para dividir o numerador e denominador pelo máximo divisor comum.

--

#### king 6.5.

Escreve um programa que recebe um inteiro (de qualquer tamanho) e inverte os digitos.
Usar apenas aritmética.

--

#### King 6.6. Quadrados inferiores a n

Escreve um programa que recebe um número n e escreve na consola todos os quadrados pares inferiores a n.
Por exemplo, se o utilizador introduzir 100:

```text
4
16
36
64
100
```

--

#### king 6.8 Calendário
<!-- .slide: data-visibility="hidden" -->

Escreve um programa que escreve o calendário de um mês.
O utilizador especifica o número de dias e o dia da semana onde começa o mês.

```text
Num dias no mes: 31
Dia da semana (1=Domingo, 7=Sabado): 3
 D  2  3  4  5  6  S
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31
```

---

### Exercícios Ciclos AFA

---

## 7 Exercícios Tipos
<!-- .slide: data-background="Coral" id="7_tipos_exercicios" -->

[Slides da matéria]()

---

### Exercícios Tipos King

--

#### King 7.1. modificado

Escreve um programa que determina o menor número cujo quadrado causa overflow para int.
Modifica o programa para usar short int, unsigned int, long, unsigned long.

Para valores inteiros, o valor máximo é dado por 2^n, onde n é o número de bits.
Com base nos resultados, consegues perceber qual é o número de bits usado para cada tipo?

```text
A executar para int
Lado do primeiro quadrado que causa overflow: 46341
Quadro que causa overflow: -2147479015
Ultimo quadrado antes de overflow: 2147395600
```


Dica: para verificar quando houve overflow, verifica quando um determinado quadrado passa a ser menor que o quadrado anterior.

--

#### King 7.2 TODO

--

#### King 7.3 TODO

--

#### King 7.4 Número teclas telemóvel -> número

Escreve um programa que recebe um conjunto de letras e converte para um número, com a conversão usada nos teclado alfanuméricos antigos.

```text
Numero em letras: CALLAT
Numero: 225
```

Correspondência: 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY

Se o número original contém carateres não numéricos, devem permanecer inalterados:

```text
Numero em letras: 1-800-COL-LECT
Numero: 1-800-265-5328
```

Assunção: todos os carateres são em letras maiúsculas.

Ajuda:
- mesmo que um scanf peça apenas 1 char, o utilizador pode inserir um input do tamanho que quiser (até \n)
- podemos ler os restantes carateres com sucessivas chamadas a scanf ou getchar.

--

#### King 7.5. scrabble TODO

--

#### King 7.7. frações

Refaz o problema King 3.6, mas agora o utilizador pode também escolher a operação entre frações (+, -, *, /).

--

#### King 7.8. TODO

--


#### King 7.9. Horas AM/PM

Com base na lógica do programa King 5.2, faz um programa que agora recebe uma hora no formato 12h e converte para 24h.
A hora pode ser recebida das seguintes formas:
```text
1:15P
1:15PM
1:15Pm
1:15 PM
1:15 P
1:15p
1:15pm
1:15 pm
1:15 p
```

Exemplo de utilização:
```text
Hora 12: 9:11PM
Hora 24: 21:11
```

--

#### King 7.10 Contar vogais

Escreve um programa que recebe uma frase do utilizador e conta o número de vogais.

--

#### King 7.11 Trocar nome

Escreve um programa que recebe o primeiro e último nome do utilizador, e depois apresenta o nome no formato
``Ultimo, Primeira letra do primeiro``.

```text
Nome: Diogo Silva
Silva, D.
```

--

#### King 7.12 Avaliar expressão

Escreve um programa que avalia uma expressão matemática.

```text
Expressao: 1+2.5*3
Resultado: 10.2
```

Notas:
- As operações válidas são +, -, *, /.
- Os operandos são todos intepretados como valores reais.
- Não introduzir parêntises.
- Calcular as operações da esquerda para a direita sem atenção à precedência de operações.

--

#### King 7.13. Tamanho médio das palavras

Escreve um programa que recebe uma frase do utilizador e indica o tamanho médio das palavras.

```text
Frase: Este programa parece mais dificil do que e.
Tamanho medio das palavras: 4.5
```

Nota: para simplificar, assume que a pontuação faz parte da palavra.

--

#### King 7.14 TODO


---

### Exercícios Tipos AFA

--

#### AFA 7.1. minúscula -> maiúscula

Escreve um programa que recebe uma letra minúscula e converte para maiúscula.

--

#### AFA 7.2. frase -> minúsculas

Escreve um programa que recebe uma frase e converte todas as letras para minúsculas.
Todos os carateres que não são letras maiúsculas não são modificados.

--

#### AFA 7.3. César letra

- Escreve um programa que recebe uma letra e um inteiro (chave), e implementa a cifra de César.
- A cifra de César é um método simples para codificar uma mensagem, com a simples translação do abecedário.
- Por exemplo, se a chave tem o valor 1, então o 'A' é convertido para 'B', 'B' para 'C', 'Z' para 'A'.
- Se a chave for negativa, a conversão é no sentido oposto.
- Converte apenas letras.

```text
Chave: 2
Letra: L
Letra codificada: N
```

--

#### AFA 7.4. César frase

Escreve um programa que recebe uma frase e uma chave, e codifica a frase com a cifra de César.

---

## 8 Exercícios Funções
<!-- .slide: data-background="Coral" id="8_funcoes_exercicios" -->

[Slides da matéria]()

---


### Exercícios Funções King

--

#### King 9.2. IRS

Reimplementa o exercício King 5.5. na forma de função. A função tem o nome calcular_irs, recebe um rendimento sobre a forma de um valor real e devolve outro valor real correspondente ao imposto devido.

O programa pede um rendimento ao utilizador e indica no final o imposto devido e o rendimento total líquido (o valor recebido menos o imposto).

Notas:
- a função criada não lê valores da consola nem os escreve
- leitura e escrita na consola é feita na função main


--

#### King 9.6. polinómio

Escreve uma função que recebe um valor real x e devolve o resultado da avaliação desse valor no seguinte polinómio:

`3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6`

Notas:
- x^5 significa x*x*x*x*x, x^4=...
- resolva primeiro o exercício AFA 8.1. e use essa função para calcular as potências

---

### Exercícios Funções AFA

--

#### AFA 8.1. potência

Escreve uma função chamada _potencia_ que recebe uma base _b_ (valor real) e um expoente _e_ (inteiro).
A função devolve o revolve o resultado da potência.

Nota:
- quando um expoente é negativo, o resultado final é 1/(b^e).
- não ler nem escrever da consola
- usar a função main para testar se a função está a funcionar correctamente.

--

#### AFA 8.2. máximo divisor comum

- Reimplementa o exercício do máximo divisor comum (King 6.2.) na forma de função.
- A função 
  - chama-se _calcular_mdc_
  - recebe 2 valores inteiros
  - devolve o MDC entre esses 2 valores

--

#### AFA 8.3. tabela de polinómio

- Implementa uma função que avalia um polinómio de 2º grau num determinado intervalo.
- A função
  - chama-se _poli2_intervalo_
  - recebe o limite inferior e limite superior do intervalo a avaliar (reais)
  - recebe o número de pontos a avaliar (inteiro positivo)
  - recebe os 3 coeficientes (reais)
  - escreve na consola o valor do polinómio nos pontos
  - devolve o valor do polinómio no ponto limite superior

A tabela produzida deve ter o seguinte aspeto (se a=0.0, b=1.0, c=0.0, limInf=0.0, limSup=1.0, numPontos=5):

```text
   ponto    resultado do polinómio no ponto
f(0.000000) = 0.000000 
f(0.250000) = 0.250000 
f(0.500000) = 0.500000 
f(0.750000) = 0.750000 
f(1.000000) = 1.000000 
```

Possível procedimento:
1. Descobrir a distância entre os pontos a avaliar.
2. Inicializar o ponto a avaliar no limite inferior.
3. Calcular o polinómio no ponto.
4. Incrementar o ponto com a distância entre pontos.
5. Repetir 3-4 até chegar ao limite superior.

Notas:
- Além da função _poli2_intervalo_, implementa a função _poli2_ponto_ que recebe os coeficientes do polinómio, o ponto _x_ a avaliar e devolve o resultado desse polinómio no ponto recebido (ver exercício King 9.6)
- Valores introduzidos pelo utilziador (coeficiente, limite inferior, superior, e nº de pontos) são pedidos na função main.
- Um dos primeiros cálculos será a distância entre 2 pontos, e.g. no exemplo acima a distância entre pontos é de 0.25.

--

#### AFA 8.4. polinómio grau n

- Escreve uma função que avalia um polinómio de grau N num determinado ponto.
- A função 
  - chama-se _poliN_ponto_
  - recebe apenas o ponto onde o polinómio será avaliado
  - pede ao utilizador o valor dos coeficientes, começando no grau menos elevado (0)
  - pára de pedir coeficientes quando um dos coeficientes é seguido da letra f (ver King 6.1.)
  - devolve o valor do polinómio no ponto recebido

Notas:
- o ponto a ser avaliado é recebido na main
- o resultado do polinómio deve ser escrito para a consola na main, com 4 casas decimais


Exemplo:
```text
Ponto: 1.0
Coeficiente do grau 0: 1.0
Coeficiente do grau 1: 0
Coeficiente do grau 2: 0
Coeficiente do grau 3: 2f
Resultado: 1.00
```

---

## 9 Exercícios Array
<!-- .slide: data-background="Coral" id="9_arrays_exercicios" -->

[Slides da matéria]()


---

### Exercícios Array King

--

#### King 8.1. digitos repetidos

- Implementa um programa que recebe um inteiro do utilizador e indica quais são os digitos repetidos.
- No final o programa indica quais são os digitos repetidos, por ordem crescente.

Exemplo:

```text
Numero inteiro: 939577
Repetidos: 7 9

--

Numero inteiro: 9339577
Repetidos: 3 7 9
```

--

#### King 8.2. histograma digitos

Modifica o programa King 8.1. para devolver quantas vezes cada digito aparece num dado número.

```text
Numero inteiro: 41271092
Digitos:    0   1   2   3   4   5   6   7   8   9
Contagem:   1   2   2   0   1   0   0   1   0   1
```

--

#### King 8.7. matriz 5x5 

- Escreve um programa que recebe uma matriz de 5x5, linha a linha, e escreve no final o total de cada linha e de cada coluna.
- Guarda a matriz num array bidimensional.

Exemplo:
```text
Linha 1: 8 3 9 0 10
Linha 2: 3 5 17 1 1
Linha 3: 2 8 6 23 1
Linha 4: 15 7 3 2 9
Linha 5: 6 14 2 6 0

Totais linhas: 30 27 40 36 28
Totais colunas: 34 37 37 32 21
```

--

#### King 8.8. notas testes alunos

- Modifica o programa King 8.7. para que cada linha corresponda para as 5 notas de testes de um aluno
- O programa indica a nota final (soma) do aluno, assim como a média de cada teste.
- O programa indica ainda, para cada teste, qual foi a nota mínima, máxima e média.

--

#### King 8.9. _random walk_

- Escreve um programa que gera um passeio aleatório num array 10x10.
- Inicialmente todas as posições do array têm o carater '.'
- O programa não pode voltar para uma posição já visitada anteriormente.
- Cada vez que o programa visita uma posição, essa posição fica com o valor A,B,C... pela ordem de visita.
- É necessário verificar se a posição de destino selecionada está dentro da matriz.
- Se por acaso todas as direções possíveis estiverem bloqueadas (ocupadas ou fora da matriz), o programa acaba.
- O passeio acaba na letra Z.
- O programa mostra a matriz apenas no final do passeio.

Exemplo normal:
```text
A . . . . . . . . .
B C D . . . . . . .
. F E . . . . . . .
H G . . . . . . . .
I . . . . . . . . .
J . . . . . . . Z .
K . . R S T U V Y .
L M P Q . . . W X .
. N O . . . . . . .
. . . . . . . . . .
```

Exemplo de terminação prematura (acabou no Y):
```text
A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
```

Notas:
- para gerar números aleatórios, usar a função rand (ver exemplo abaixo)

```c
#include <stdio.h>
#include <stdlib.h>

int main () {
   int i, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
   return(0);
}
```

--

#### King 9.1. _selection sort_

- Escreve um programa que recebe um conjunto de inteiros do utilizador e, no final, mostra esses números ordenados.
- O programa recebe os números um a um até que um dos números tenha um 'f' após o último digito, e.g. `42f`.
- O programa guarda os números num _array_.
- Assuma que o número máximo de inteiros a receber é 200.
- O programa ordena os números do _array_ com a função *selection_sort*.
- A função *selection_sort* recebe um vector e ordena-o. Para isso, faz o seguinte:
  - Procura no array o maior elemento e passa-o a última posição.
  - Procura no array o segundo maior elemento e passa-o para a penúltima posição.
  - ...
  - Repetir n-1 vezes, em que n é o tamanho do vetor.
  - O uso de recursão é especialmente adequado.
- Os inteiros são pedidos na main.

--

#### King 9.3. modificado, _random walk_ 

- Modifica o problema King 8.9 para que seja implementado com 3 funções:
  - *void fill_array(char walk[10][10], char f)* recebe a matriz e preenche em todas as posições da matriz o carater f.
  - *random_walk_generator(char walk[10][10])* recebe a matriz e gera uma nova _random walk_ com a lógica do King 8.9.
  - *print_array(char walk[10][10])* recebe a matriz e escreve-a na consola.
- Na função main, apenas deve ser criada a matriz e o programa implementa as funcionalidades pretendidas chamando estas funções.

--

#### King 9.5. _magic square_
<!-- .slide: data-visibility="hidden" -->

- Escreve um programa que escreve uma matriz n x n:
  - com todos os números de 1 até n^2
  - em que a soma de todas as linhas, colunas e diagonais são iguais
  - n tem de ser um inteiro ímpar entre 1 e 99
- O utilizador especifica a dimensão da matriz, indicando o valor _n_.
- Implementa a lógica na função _generate_magic_square_, que recebe um vetor de tamanho variável.
- Para construir a matriz:
  - começar por escrever 1 no meio da primeira linha
  - escrever os valores seguintes na linha acima e na coluna seguinte
  - se a linha acima estiver fora da matriz, deve-se dar a volta, e.g. -1 -> n-1
  - se a coluna à direita estiver fora da matriz, deve-se dar a volta, e.g. n -> 0
  - se a posição já estiver ocupada, deve-se colocar o número na posição abaixo da última posição preenchida.
- Escreve uma função print_magic_square que recebe a matriz e apresenta o resultado na consola.
- Deve também indicar qual é o valor da soma das linhas, colunas e diagonais, que é o mesmo valor.

Exemplo:

```text
Introduza um inteiro ímpar entre 1 e 99: 5
17 24  1  8 15
23  5  7 14 16
 4  6 13 20 22
10 12 19 21  3
11 18 25  2  9
```

---


### Exercícios Array AFA

--

#### AFA 9.1. polinómio

- Escreve uma função poliN que recebe um vetor _coef_ de reais que pode ter qualquer tamanho (deve também receber outro parâmetro _n_ com o tamanho real do vector) e um real _x_.
- A função avalia um polinómio de grau n-1 no ponto _x_.
- Os coeficientes do polinómio estão no vetor recebido.
- Pode usar a função [_pow_](https://man7.org/linux/man-pages/man3/pow.3p.html) (da biblioteca math.h) para calcular as potências (ou usar a solução do exercício AFA 8.1.).
- coef[0] corresponde ao coeficiente de menor grau, coef[1] corresponde ao coeficiente do 2º menor grau, ...
- Para um polinómio de grau 3:

```text
coef[0] + coef[1] * x + coef[2] * x^2
```

Exemplo de utilização da função _pow_:

```c
#include <math.h>

int main(){
  printf("2^2 = %lf", pow(2.0, 2.0));
}
```

--

#### AFA 9.2. IRS generalizado


- Reimplementa o exercício King 9.2. para funcionar para qualquer número de escalões e com quaisquer limites dos escalões.
- A função recebe um vetor de reais (_escaloes_) com _n_ elementos, correspondentes aos limites dos escalões.
- Existem no total _n-1_ escalões.
- _escaloes[0]_ é o limite inferior do primeiro escalão, _escalores[1]_ é o limite superior do primeiro escalão e o inferior do segundo, etc.
- A função recebe ainda um vetor de reais (_taxas_) com _n-1_ elementos que contém a taxa a aplicar em cada escalão: _taxas[0]_ é a taxa a aplicar no rendimento do primeiro escalão, _taxas[1]_ é a taxa a aplicar no rendimento do segundo escalão, etc.


Dicas:
- a lógica para um determinado escalão é sempre igual, mudando apenas os limites do escalão e a taxa a aplicar;
- implementa uma função auxiliar para calcular o imposto num determinado escalão;
- usa vetores de tamanho variável;

--

#### AFA 9.3. Ordenar array

- Implementa uma função que recebe um vector de inteiros de qualquer tamanho e ordena os seus elementos por ordem crescente.

--

#### AFA 9.4. Ordenar array 2

- Implementa uma função  que recebe um vector de inteiros de qualquer tamanho e um char.
- O char indica se o vetor deve ser ordenado de forma crescente ou decrescente.
- A função ordena o vector da forma indicada pelo char.
- Usa a implementação do AFA 9.3.
  - Podes criar outra função para ordenar de forma decrescente e a função deste exercício chama a função do AFA 9.3 (crescente) ou a função para ordenar de forma decrescente, conforme o que seja indicado pelo char.


--

#### AFA 9.5. Ordenar indices array
<!-- .slide: data-visibility="hidden" -->

- Implementa uma função que recebe:
  - um vector de inteiros _vals_ de qualquer tamanho
  - um vector de inteiros positivos _indeces_ do mesmo tamanho do _vals_
- A função:
  - inicializa o vetor _indeces_ com os indices de _vals_ (0,1,2,3...)
  - muda a ordem de _indeces_ de forma a refletir uma ordenação crescente do conteúdo de _vals_

Exemplo:
```text
Input:
   vals:   42  1  9  87
indeces:    ?  ?  ?   ?

Depois de inicializar indices:
   vals:   42  1  9  87   (não foi alterado)
indeces:    0  1  2   3

Depois de ordenar:
   vals:   42  1  9  87   (não foi alterado)
indeces:    1  2  0   3
```


---

## 10 Exercícios Strings
<!-- .slide: data-background="Coral" id="10_strings_exercicios" -->

[Slides da matéria]()

---

### 10 Exercícios Strings King

---

### 10 Exercícios Strings AFA

--

#### AFA 10.1. Cifras de césar

---

## 11 Exercícios Apontadores
<!-- .slide: data-background="Coral" id="11_pointers_exercicios" -->

[Slides da matéria]()

---

## 12 Exercícios Struct
<!-- .slide: data-background="Coral" id="12_struct_exercicios" -->

[Slides da matéria]()

---

### 12 Exercícios Struct King

---

### 12 Exercícios Struct AFA

---

## 13 Exercícios Ficheiros
<!-- .slide: data-background="Coral" id="13_ficheiros_exercicios" -->

[Slides da matéria]()

---

### 13 Exercícios Ficheiros King

---

### 13 Exercícios Ficheiros AFA

---

## 14 Exercícios Memória
<!-- .slide: data-background="Coral" id="14_memory_exercicios" -->

[Slides da matéria]()

---

### 14 Exercícios Memória King

---

### 14 Exercícios Memória AFA

--

#### AFA 14.1. Image padding

- Em domínio da visão computacional, é comum termos de adicionar pixeis à volta de uma imagem.
- Implementa uma função que recebe uma imagem (vector de _unsigned char_ com 3 dimensões) com uma determinada altura ``h`` (1ª dimensão) e largura ``w`` (2ª dimensão) e o número de pixeis de padding.
- A 3ª dimensão é o número de canais de cor, que será 3.
- A função cria um novo vector (alocado dinâmicamente) com o mesmo tamanho da imagem recebida, mas com a primeira e segunda dimensões incrementadas com o número de pixeis de padding.
- Posteriormente, a função copia a imagem original para a nova imagem com padding.
- O espaço de padding deve estar inicializado com zeros.
- A função retorna a imagem com padding.

---

## 15 Exercícios Estruturas de Dados Dinâmicas
<!-- .slide: data-background="Coral" id="15_dynamic_structures_exercicios" -->

[Slides da matéria]()

---

### 15 Exercícios Estruturas de Dados Dinâmicas King

---

### 15 Exercícios Estruturas de Dados Dinâmicas AFA

---

## Table of contents

- [Exercícios](#exercícios)
  - [2 Exercícios Fundamentos](#2-exercícios-fundamentos)
  - [Exercícios 3 I/O Formatado](#exercícios-3-io-formatado)
    - [Exercícios I/O Formatado King](#exercícios-io-formatado-king)
      - [King 3.1.](#king-31)
      - [King 3.2.](#king-32)
      - [King 3.3. TODO](#king-33-todo)
      - [King 3.4. TODO](#king-34-todo)
      - [King 3.5. TODO](#king-35-todo)
      - [King 3.6. frações](#king-36-frações)
  - [4 Exercícios Expressões](#4-exercícios-expressões)
    - [Exercícios Expressões King](#exercícios-expressões-king)
      - [King 4.1.](#king-41)
      - [King 4.2](#king-42)
      - [King 4.3](#king-43)
  - [5 Exercícios Seleção](#5-exercícios-seleção)
    - [Exercícios Seleção King](#exercícios-seleção-king)
      - [King 5.1](#king-51)
      - [King 5.2](#king-52)
      - [King 5.3. TODO](#king-53-todo)
      - [King 5.4](#king-54)
      - [King 5.5 escalões IRS](#king-55-escalões-irs)
      - [King 5.6 TODO](#king-56-todo)
      - [King 5.7](#king-57)
      - [King 5.8 voo mais próximo TODO](#king-58-voo-mais-próximo-todo)
      - [King 5.9 data menor](#king-59-data-menor)
      - [King 5.10 nota para letra](#king-510-nota-para-letra)
      - [King 5.11 número por extenso](#king-511-número-por-extenso)
    - [Exercícios Seleção AFA](#exercícios-seleção-afa)
      - [AFA 5.1. Converte gramas para outras unidades](#afa-51-converte-gramas-para-outras-unidades)
      - [AFA 5.2 Converter unidades de massa](#afa-52-converter-unidades-de-massa)
  - [6 Exercícios Ciclos](#6-exercícios-ciclos)
    - [Exercícios Ciclos King](#exercícios-ciclos-king)
      - [King 6.1. Maior número de série recebida](#king-61-maior-número-de-série-recebida)
      - [King 6.2. Máximo Divisor Comum](#king-62-máximo-divisor-comum)
      - [King 6.3. Simplificar fração](#king-63-simplificar-fração)
      - [king 6.5.](#king-65)
      - [King 6.6. Quadrados inferiores a n](#king-66-quadrados-inferiores-a-n)
      - [king 6.8 Calendário](#king-68-calendário)
    - [Exercícios Ciclos AFA](#exercícios-ciclos-afa)
  - [7 Exercícios Tipos](#7-exercícios-tipos)
    - [Exercícios Tipos King](#exercícios-tipos-king)
      - [King 7.1. modificado](#king-71-modificado)
      - [King 7.2 TODO](#king-72-todo)
      - [King 7.3 TODO](#king-73-todo)
      - [King 7.4 Número teclas telemóvel -\> número](#king-74-número-teclas-telemóvel---número)
      - [King 7.5. scrabble TODO](#king-75-scrabble-todo)
      - [King 7.7. frações](#king-77-frações)
      - [King 7.8. TODO](#king-78-todo)
      - [King 7.9. Horas AM/PM](#king-79-horas-ampm)
      - [King 7.10 Contar vogais](#king-710-contar-vogais)
      - [King 7.11 Trocar nome](#king-711-trocar-nome)
      - [King 7.12 Avaliar expressão](#king-712-avaliar-expressão)
      - [King 7.13. Tamanho médio das palavras](#king-713-tamanho-médio-das-palavras)
      - [King 7.14 TODO](#king-714-todo)
    - [Exercícios Tipos AFA](#exercícios-tipos-afa)
      - [AFA 7.1. minúscula -\> maiúscula](#afa-71-minúscula---maiúscula)
      - [AFA 7.2. frase -\> minúsculas](#afa-72-frase---minúsculas)
      - [AFA 7.3. César letra](#afa-73-césar-letra)
      - [AFA 7.4. César frase](#afa-74-césar-frase)
  - [8 Exercícios Funções](#8-exercícios-funções)
    - [Exercícios Funções King](#exercícios-funções-king)
      - [King 9.2. IRS](#king-92-irs)
      - [King 9.6. polinómio](#king-96-polinómio)
    - [Exercícios Funções AFA](#exercícios-funções-afa)
      - [AFA 8.1. potência](#afa-81-potência)
      - [AFA 8.2. máximo divisor comum](#afa-82-máximo-divisor-comum)
      - [AFA 8.3. tabela de polinómio](#afa-83-tabela-de-polinómio)
      - [AFA 8.4. polinómio grau n](#afa-84-polinómio-grau-n)
  - [9 Exercícios Array](#9-exercícios-array)
    - [Exercícios Array King](#exercícios-array-king)
      - [King 8.1. digitos repetidos](#king-81-digitos-repetidos)
      - [King 8.2. histograma digitos](#king-82-histograma-digitos)
      - [King 8.7. matriz 5x5](#king-87-matriz-5x5)
      - [King 8.8. notas testes alunos](#king-88-notas-testes-alunos)
      - [King 8.9. _random walk_](#king-89-random-walk)
      - [King 9.1. _selection sort_](#king-91-selection-sort)
      - [King 9.3. modificado, _random walk_](#king-93-modificado-random-walk)
      - [King 9.5. _magic square_](#king-95-magic-square)
    - [Exercícios Array AFA](#exercícios-array-afa)
      - [AFA 9.1. polinómio](#afa-91-polinómio)
      - [AFA 9.2. IRS generalizado](#afa-92-irs-generalizado)
      - [AFA 9.3. Ordenar array](#afa-93-ordenar-array)
      - [AFA 9.4. Ordenar array 2](#afa-94-ordenar-array-2)
      - [AFA 9.5. Ordenar indices array](#afa-95-ordenar-indices-array)
  - [10 Exercícios Strings](#10-exercícios-strings)
    - [10 Exercícios Strings King](#10-exercícios-strings-king)
    - [10 Exercícios Strings AFA](#10-exercícios-strings-afa)
      - [AFA 10.1. Cifras de césar](#afa-101-cifras-de-césar)
  - [11 Exercícios Apontadores](#11-exercícios-apontadores)
  - [12 Exercícios Struct](#12-exercícios-struct)
    - [12 Exercícios Struct King](#12-exercícios-struct-king)
    - [12 Exercícios Struct AFA](#12-exercícios-struct-afa)
  - [13 Exercícios Ficheiros](#13-exercícios-ficheiros)
    - [13 Exercícios Ficheiros King](#13-exercícios-ficheiros-king)
    - [13 Exercícios Ficheiros AFA](#13-exercícios-ficheiros-afa)
  - [14 Exercícios Memória](#14-exercícios-memória)
    - [14 Exercícios Memória King](#14-exercícios-memória-king)
    - [14 Exercícios Memória AFA](#14-exercícios-memória-afa)
      - [AFA 14.1. Image padding](#afa-141-image-padding)
  - [15 Exercícios Estruturas de Dados Dinâmicas](#15-exercícios-estruturas-de-dados-dinâmicas)
    - [15 Exercícios Estruturas de Dados Dinâmicas King](#15-exercícios-estruturas-de-dados-dinâmicas-king)
    - [15 Exercícios Estruturas de Dados Dinâmicas AFA](#15-exercícios-estruturas-de-dados-dinâmicas-afa)
  - [Table of contents](#table-of-contents)
