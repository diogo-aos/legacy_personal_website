<img src="img/afa.png" height="100">

# Exercícios
<!-- .slide: data-background="Cornsilk" -->

- [Fundamentos](#/2_exercicios)
- [I/O Formatado](#/3_exercicios)
- [Expressões](#/4_exercicios)
- [Seleção](#/5_exercicios)

---

# Exercícios
## 2 Fundamentos
<!-- .slide: data-background="Coral" id="2_exercicios" -->

[Slides da matéria](#/2_fundamentals)

---

# Exercícios
## 3 I/O Formatado
<!-- .slide: data-background="Coral" id="3_exercicios"-->

[Slides da matéria](#/3_formated_io)

---

# Exercícios
## 3 I/O Formatado
### Livro King

--

### King 3.1.

Escreve um programa que aceita uma data do utilizador no formato "dd/mm/aaaa" e escreve na consola a mesma data no formato "aaaa-mm-dd".

```text
Insira data: 01/02/2023
Escreveu:    2023/02/01
```

--

### King 3.2.

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

### King 3.3. TODO

--

### King 3.4. TODO

--

### King 3.5. TODO

--

### King 3.6. frações

Escreve um programa que recebe 2 frações do utilizador e escreve a sua soma.
O programa recebe as duas frações de uma só vez, separadas por +.

```text
Insira as fracoes: 5/6+3/4
Soma: 38/24
```


---

# Exercícios
## 4 Expressões
<!-- .slide: data-background="Coral" id="4_exercicios" -->

[Slides da matéria](#/4_expressions)

---

# Exercícios
## 4 Expressões
### Livro King

--

### King 4.1.

Escreve um programa que pede ao utilizar um número inteiro de 2 digitos e devolve esse número com os digitos invertidos.
Exemplo de execução:

```bash
Insira número inteiro: 42
Invertido:             24
```

Os 2 números devem estar alinhados.

Dica: %10 devolve o último digito de um número e /10 remove o último digito.

--

### King 4.2

Extende o programa anterior para números de 3 digitos.

--

### King 4.3

Reimplementa o programa do 4.2 sem usar aritmética. O enunciado dos 4.1 e 4.2 estão abaixo.


---

# Exercícios
## 5 Seleção
<!-- .slide: data-background="Coral" id="5_exercicios" -->

[Slides da matéria](pdf/03_testes_condicoes.pptx.pdf)


---

# Exercícios
## 5 Seleção
### Livro King

--

### King 5.1

Escreve um programa que recebe um número inteiro e indica quantos digitos esse número tem.

Assume que o número nunca tem mais de 4 digitos.

```
Introduza numero inteiro (maximo 4 digitos): 42
# digitos:                                   2
```

Ajuda: usa if para fazer essa verificação, e.g. se o número estiver entre 10 e 99, então tem 2 digitos.

--

### King 5.2

Escreve um programa que recebe uma hora no formato de 0-24h e converte para o formato 0-12h.

```
Introduza hora no formato 24h: 23:32
Hora no formato 12h:           11:32 PM

Introduza hora no formato 24h: 10:32
Hora no formato 12h:           10:32 AM

```

--

### King 5.3. TODO

--

### King 5.4

A escala de Beaufort indica uma descrição do vento com base na sua velocidade.
Uma versão simplificada é a seguinte:

![](img/5_selection/king_5_4.png)

Escreve um programa que recebe a valocidade do vento e indica a descrição correspondente.

--

### King 5.5 escalões IRS

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

### King 5.6 TODO

--

### King 5.7

Escreve um programa que recebe 4 números inteiros e indica o número mais alto e o mais pequeno.

```text
Enter four integers: 21 43 10 35
Largest: 43
Smallest : 10
```

Usa o mínimo de ``if`` possível.

Ajuda: se trocares o valor das variáveis, ``4`` if são suficientes.

--

### King 5.8 voo mais próximo TODO

--

### King 5.9 data menor

Escreve um programa que pede 2 datas ao utilizador e indica qual é a data que vem antes no calendário.

```text
Data 1: 3/6/2007
Data 2: 3/6/2005
3/6/2005 vem antes de 3/6/2007
```

--

### King 5.10 nota para letra

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

### King 5.11 número por extenso

Escreve um programa que recebe um inteiro de 2 digitos e escreve o número por extenso. Implementa o programa sem ``if``.

```text
Nota: 42
Letra: quarenta e dois
```

---



## AFA

--

## AFA 5.1

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

## AFA 5.2

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

# Exercícios
## 6 Ciclos
<!-- .slide: data-background="Coral" id="5_exercicios" -->

[Slides da matéria](pdf/03_testes_condicoes.pptx.pdf)


---

# Exercícios
## 6 Ciclos
### Livro King

---

#### King 6.1.

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

#### King 6.2.

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

#### King 6.3.

Escreve um programa que recebe 1 fração e simplifica-a.

```text
Introduza fracao: 6/12
Simplificada: 1/2
```

Dica: usar a implementação do 6.2. para dividir o numerador e denominador pelo máximo divisor comum.

--

#### king 6.4. TODO

--

#### king 6.5.

Escreve um programa que recebe um inteiro (de qualquer tamanho) e inverte os digitos.
Usar apenas aritmética.

--

#### king 6.6.

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

#### king 6.7. TODO

--

#### king 6.8

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

# Exercícios
## 6 Ciclos
### AFA

---

# Exercícios
## 7 Tipos
### King

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

# Exercícios
## 7 Tipos
### AFA

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

--




