<img src="img/afa.png" height="100">

## Expressões

### Diogo Silva
####  CAP / ENGEL
dasilva@academiafa.edu.pt

<!-- .slide: data-background="white" -->

---

### O que são?

Expressões devolvem sempre um valor concreto com um determinado tipo.

```c
    int raio = 2;
    float area = 3.14 * raio * raio;
```

---

### Operações aritméticas

```c
1+2    // soma
3.14-2 // subtração
1*2.3  // multiplicação
5/2    // divisão, devolve 2 -> porquê?
5%2    // resto da divisão

int v = 2;
-v     // torna valor negativo, operação unária
```

--

Operação unária? Operação que recebe apenas 1 operando.

Por outro lado, as outras operações são binárias (2 operandos).

--

⚠️ Cuidado com a divisão! ⚠️

O operador para a divisão, quando recebe 2 operandos inteiros, devolve sempre um valor inteiro (ignorando, sem arredondamento, a parte decimal)

```c
5/2 // devolve 2
```

Quando misturamos um inteiro com um real, o inteiro é automaticamente convertido e o resultado será o valor preciso

```c
5.0/2 // devolve 2.5
```

--

O resto da divisão `%` requer 2 operandos inteiros.

Usar 0 como o segundo operando da divisão `/` ou resto da divisão `%`, i.e. divisão por 0, gera comportamento não definido. 

---

### Precedência e associatividade

<!-- .slide: id="4_1_precedencia"-->

``1+2*-2``

É o tipo de expressão que não devem escrever. Devem usar () para melhorar legibilidade.

Mas se vissem esta expressão, qual seria o resultado?
<!-- .element: class="fragment" -->

--

As operações no C têm uma precedência.

| Precedência | Operadores |
| -- | -- |
| Alta | + - unários (e.g. -2) |
| `---`  | * / % |
| Baixa | + - |

``1 + 2 * -2 == 1 + (2 * (-2))``

--

`i + j * k == i + (j * k)`

``-i * -j == (-i) * (-j)``

--

E quando uma expressão tem 2 operações com a mesma precedência?

`i - j + k`

`i / j * k `

--  

Tem-se em conta a associatividade.

`i - j + k == (i - j) + k`

`i / j * k == (i / j) * k`


`+ - * / %` têm associtividade à esquerda, o que quer dizer que agrupam o que está antes do operador.

Os operadores unários têm associatividade à direita.

`- -2 == - (-2)`

---

### Operadores de atribuição
<!-- .slide: id="4_2_atribuicao"-->

Já conhecemos o operador de atribuição simples `=`.

É o que designamos por uma operação com **efeitos secundários**, porque altera o estado dos operandos.
<!-- .element: class="fragment" -->

--

`a = 2` altera o estado da variável ``a`` porque o seu valor é agora 2.


Adicionalmente, `a = 2` é uma expressão válida que devolve o valor que foi atribuido à variável
<!-- .element: class="fragment" -->


```c
int a=10;
printf("a=%d\n", a=2); // escreve 2 na consola e altera o valor de a
```

<!-- .element: class="fragment" -->


--

Todas as operações de atribuição exigem que o operando da esquerda seja uma variável.

--

Existem outros que se combinam com operações aritméticas.

| Expressão | Descrição |
| -- | -- |
| var+=3 | soma 3 ao valor de var e atribui o resultado a var |
| var-=3 | subtrai 3 ao valor de var e atribui o resultado a var |
| var/=3 | multiplica 3 com o valor de var e atribui o resultado a var |
| var/=3 | divide o valor de var por 3 e atribui o resultado a var |
| var%=3 | faz o resto da divisão entre var e 3 e atribui o resultado a var |

--

`v*=3` não é equivalente a `v = v * 3`, embora na maior parte das utilizações o resultado seja o mesmo.

Porquê? Observem a expressão `v*=3+10`

Não é equivalente a `v = v * 3 + 10`. Esta expressão, deviso às regras de precedência a associatividade iria dar um resultado diferente.

```c
int a=3;
printf("a=%d\n", (a = a * 3 + 10)); // a=19
a=3;
printf("a=%d\n", a*=3+10); // a=39
```

--

Não confundir `+=` com `=+`.

A primeira operação acumula o valor à direita.

A segunda atribui o valor que a variável já tem.

--

Posto isto, usem **sempre** ( ) para deixar claro qual é a ordem das operações.


---

### Incremento e decremento
<!-- .slide: id="4_3_incremento"-->

Existe uma instrução que é frequentemente usada no C (irão perceber porquê quando abordarmos ciclos):

```c
i = i + 1;
i += 1;
```

--

Existe outra forma de escrever esta instrução, com o operador de incremento ``++``

```c[3]
i = i + 1;
i += 1;
i++;
```

--

Este operador pode ser usado tanto antes de uma variável (pré-incremento) como depois (pós-incremneto).

Qual será a diferença?

```c
int i=10;
printf("%d\n", ++i); // ?
printf("%d\n", i);   // ?
i=10;
printf("%d\n", i++); // ?
printf("%d\n", i);   // ?
```

--

```c
int i=10;
printf("%d\n", ++i); // 11
printf("%d\n", i);   // 11
i=10;
printf("%d\n", i++); // 10
printf("%d\n", i);   // 11
```

--

Além do incremento `++`, também temos disponível o decremento `--`, que funciona da mesma forma, mas subtrai em uma unidade.

---

### Avaliação de expressões
<!-- .slide: id="4_4_avaliacao"-->

<small>Resumo das operações que já vimos:</small>

![](img/4_expressions/precedence_table.png)

<small>postfix == pós-incremento</small>

<small>prefix == pré-incremento</small>

--

Com este conhecimento conseguimos avaliar expressões complicadas.

`a= b += c++ - d + --e / -f`

1. Encontrar o operador com maior precedência.
2. Colocar ( ) à volta do operador e operandos.
   1. Aplicar regras de precedência e associatividade.
3. Repetir.

--

`a= b += c++ - d + --e / -f`

<small>c++ e depois --e (precedência)</small>
<!-- .element: class="fragment" -->

`a= b += (c++) - d + (--e) / -f`
<!-- .element: class="fragment" -->

<small>operador unário -f (precedência)</small>
<!-- .element: class="fragment" -->

`a= b += (c++) - d + (--e) / (-f)`
<!-- .element: class="fragment" -->

<small>divisão (precedência)</small>
<!-- .element: class="fragment" -->

`a= b += (c++) - d + ((--e) / (-f))`
<!-- .element: class="fragment" -->

--

`a= b += (c++) - d + ((--e) / (-f))`

<small>- e + com a mesma precedência e com operando em comum d (precedência)</small>
<!-- .element: class="fragment" -->

<small>agrupam da esquerda para a direita, logo - primeiro (associatividade)</small>
<!-- .element: class="fragment" -->

`a= b += ((c++) - d) + ((--e) / (-f))`
<!-- .element: class="fragment" -->

<small>e depois o + (precedência)</small>
<!-- .element: class="fragment" -->

`a= b += (((c++) - d) + ((--e) / (-f)))`
<!-- .element: class="fragment" -->

<small>= e += com mesma precedência (precedência)</small>
<!-- .element: class="fragment" -->

<small>agrupam da direita para a esquerda, logo += primeiro (associatividade)</small>
<!-- .element: class="fragment" -->


`a= (b += (((c++) - d) + ((--e) / (-f))))`
<!-- .element: class="fragment" -->

<small>sobra apenas o = (precedência)</small>
<!-- .element: class="fragment" -->

`(a= (b += (((c++) - d) + ((--e) / (-f)))))`
<!-- .element: class="fragment" -->
