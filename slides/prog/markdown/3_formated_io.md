<img src="img/afa.png" height="100">

## Leitura e escrita formatada

### Diogo Silva
####  CAP / ENGEL
dasilva@academiafa.edu.pt

<!-- .slide: data-background="white" -->

---

### I/O formatado

O ``printf`` e ``scanf`` são 2 das funções mais usadas quando programamos em C.

Ambas as funções permitem escrever/ler um número arbitrário de valores:
<!-- .element: class="fragment" -->


```
printf("string", expr1, ..., exprN);
scanf("string", &var1, ..., &varN);
```
<!-- .element: class="fragment" -->

```
int altura, idade;
float massa, imc;
printf("Insira a idade e massa separadas por um espaco:");
scanf("%d %f", &altura, &massa);
printf("altura: %d\nmassa:%f\n", altura, massa);
```
<!-- .element: class="fragment" -->

--

```[]
scanf("%d %f", &altura, &massa);
printf("altura: %d\nmassa:%f\n", altura, massa);
```

Quando usamos múltiplos descritores nestas funções, a correspondência com as variáveis/expressões é feita por ordem sequencial:
- linha 1: o primeiro ``%d`` corresponde à variável ``altura``, ``%f`` corresponde à ``massa``
- linha 2: idem

<!-- .element: class="fragment" -->

--

Os compiladores de C não são obrigados a verificar que o número de descritores é coerente com o número de valores fornecidos.

```c
printf("%d %d %d\n", i); /*** ERRADO ***/
printf("%d\n", i, j, x, y, k); /*** ERRADO ***/
```

--

Os compiladores de C não são obrigados a verificar que o descritor `%` usado é o apropriado para o tipo da expressão/variável.

```c
int natural;
float real;
printf("%f %d\n", natural, realj); /*** ERRADO ***/
```

---

### ``printf``

Os descritores ``%d``, ``%f``, ... também podem ser denominados por **especificações de conversão**.

--

### Número de digitos

``%d`` escreve o número inteiro que recebe, mas podemos definir um número de ditigos mínimo.

```c []
// output no comentário após as linhas
// • significa um espaço
printf("%d\n", 42);    // -> 42
printf("%5d\n", 42);   // -> •••42 (3 espaços antes do 2)
printf("%05d\n", 422); // -> 00042 (3 zeros antes do 2)
```
<!-- .element: class="fragment" -->


- a linha 2 especifica que o que é escrito deve ter pelo menos 5 caracteres, se não tiver, são adicionados espaços antes do número até os perfazer;
- a linha 3 indica o mesmo, para são usados 0s para preencher.


<!-- .element: class="fragment" -->

--

### casas decimais

Podemos fazer o mesmo com os números reais.

```c []
printf("%f\n", 3.14159);     // -> 3.141590
printf("%.2f\n", 3.14159);   // -> 3.14 (2 casas decimais)
printf("%.f\n", 3.14159);    // -> 3 (0 casas decimais, arredonda)
                             //também podia ser %.0f
```

```c []
printf("%5.2f\n", 3.14159);  // -> •3.14 (2 casas decimais,
                             // pelo menos 5 characteres no total,
                             // adiciona 1 espaço antes)
printf("%05.2f\n", 3.14159); // -> 03.14 (adiciona 0s)
```
<!-- .element: class="fragment" -->

```c []
printf("%-5.2f\n", 3.14159);  // -> 3.14• (2 casas decimais,
                             // pelo menos 5 characteres no total,
                             // adiciona 1 espaço depois)

```
<!-- .element: class="fragment" -->

--

### regra geral

Temos a fórmula
<span style="color:Salmon">`%m.pX`</span> ou 
<span style="color:Salmon">`%-m.pX`</span>, onde
<span style="color:Salmon">`m`</span> e 
<span style="color:Salmon">`p`</span> são números naturais positivos, mas opcionais.
<span style="color:Salmon">`X`</span> é uma letra válida para conversão, e.g. `d` ou `f`.


<span style="color:Salmon">`m`</span>
 é o número de caracteres mínimo que devem ser escritos, sendo adicionados, à esquerda, espaços, ou zeros se designarmos
 <span style="color:Salmon">`0m`</span>.
<!-- .element: class="fragment" -->


<span style="color:Salmon">`p`</span>
é o número de casas decimais a usar.
<!-- .element: class="fragment" -->

Quando temos
<span style="color:Salmon">`-m`</span>, adicionamos os espaços à direita do número.
<!-- .element: class="fragment" -->

--

`p` nem sempre faz sentido, pois depende da letra `X` escolhida.

--

### tabela de especificações de conversão

| letras | descrição |
| ------ | --------- | 
| d      | inteiros, `p` não faz sentido, `m` é o número mínimo de caracteres a serem escritos |
| e      | reais em notação científica, `p` é o número de casas decimais
| f      | reais em "decimal fixo", sem expoente, `p` tem o mesmo significado |

--

### símbolos especiais

| Símbolo | descrição |
| --- | ---- |
| \n  | nova linha |
| \t | tabulação |
| `\\` | permite inserir um \ |
| \a | causa um alerta sonoro na maior parte dos computadores |

---

## ``scanf``

### Como funciona?

--

Na sua essência, o `scanf` faz correspondência de padrões.
Tenta fazer a correspondência entre grupos de *input* com especificações de conversão.

Para cada especificação de conversão, o `scanf` tenta encontrar um item do tipo apropriado no *input* recebido, parando quando recebe um caracter incompatível com esse tipo.
<!-- .element: class="fragment" -->

Se algum item não for lido com sucesso, o ``scanf`` retorna sem tentar fazer a correspondência entre as restantes especificações de conversão com o resto do *input*.
<!-- .element: class="fragment" -->

--

Ao procurar pelo início de um número, todos os espaços em branco são ignorados, e.g. espaços, novas linhas, tabulações, ...

--

```c
int i, j;
float x, y;
scanf("%d%d%f%f", &i, &j, &x, &y);
printf("i=%d, j=%d\nx=%f, y=%f\n", i, j, x, y);
```

Este programa irá ler os seguintes números de igual forma:

```bash [2]
Introduza 2 inteiros e 2 reais:
1 2 3 4 5
i=1, j=2
x=3.000000, y=4.000000
```

```bash [2-4]
Introduza 2 inteiros e 2 reais:
3
    4
5 6
i=3, j=4
x=5.000000, y=6.000000
```

--

Porquê é que isto acontece?

O scanf lê todo o input como uma sequência de caracteres.
Os espaços, enters, tabulações, etc. são todos caracteres.

```bash
3
    4
5 6
```

é equivalente a

```bash
3¤••••4¤5•6¤
```

onde `¤` é uma nova linha e `•` é um espaço.

--

 O ``scanf`` pára de ler quando encontra um enter (nova linha) após a correspondência da última especificação de conversão.

⚠️Importante⚠️ Contudo, o último enter não é consumido do *input* e por isso será o primeiro caracter a ser lido na próxima chamada do ``scanf``.

--

Regras de correspondência para inteiros ``%d``:
- procura pelo primeiro digito ou sinal de + ou -
- lê digitos até encontrar o primeiro caracter não digito

--

Regras de correspondência para reais ``%f %e``:
- procura pelo sinal de + ou - (opcional)
- lê uma série de digitos, que podem conter **1** ``.`` a indicar que depois vêm casas decimais
- um expoente (opcional): consiste na letra e ou E seguida de um sinal e mais digitos, e.g. ``1e-3`` (=0.001), ``1E3`` (=10000).

--

Quando o scanf lê um caracter que não encaixa na especificação de conversão que está a ser processada, é novamente colocado no input para ser processado 

--

Ler apenas N digitos

```c
int d1, d2;
printf("Numero inteiro:");
scanf("%1d%2d", &d1, &d2);  // utilizador escreve 242
printf("d1=%d\n", d1); // d1=2
printf("d2=%d\n", d2); // d2=42
```

`%Nd` permite ler `N` digitos inteiros. 

---

## Exercício

Soma de frações.