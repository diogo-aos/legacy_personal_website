
## Leitura e escrita formatada
# RASCUNHO

### Diogo Silva
####  CAP / ENGEL
dasilva@academiafa.edu.pt

<!-- .slide: data-background="white" -->

---

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
int i;
float j;
printf("%f %d\n", i, j); /*** ERRADO ***/
```

--

### especificações de conversão

Os descritores ``%d``, ``%f``, ... também podem ser denominados por **especificações de conversão**.

--



