# Exercícios

---

# 5 Seleção

---

## Livro King

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