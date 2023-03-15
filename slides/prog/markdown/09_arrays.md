<img src="img/afa.png" height="100">


## Array

### Diogo Silva
####  CAP / ENGEL
dasilva@academiafa.edu.pt

<!-- .slide: data-background="Cornsilk" id="array" -->

--

## Array


- [Videos](#/array_videos)
- [Slides, PDF](pdf/06_arrays.pptx.pdf)
- [Slides, extra](#/array_slides_extra)


--

<!-- .slide: id="array_videos"-->

#### videos 1/2

1. [Intro, criar, mudar - 5min](https://www.loom.com/share/72db64a535b2489ba91d65010bfadc63)
2. [Arrays e funções - 5min](https://www.loom.com/share/2ce3044d564e49f9bd11c4ca138e6851)
3. [Demo exercício salários - 14min](https://www.loom.com/share/2583c4a69d0141de8f1a1271ad92c9e1)
   1. 00:00 explicar enunciado
   2. 01:10 inicio da solução
   3. 02:28 função pedir salarios
   4. 04:05 função para mostrar salários
   5. 07:25 função para somar salários
   6. 9:30 função para a média dos salários
   7. 11:56 utilizador indica quantos salários quer introduzir

--

#### videos 2/2

4. [_Arrays_ multi-dimensionais - 4min](https://www.loom.com/share/9316e9020fa74a409f6c492d69dc7b76)
5. [Demo _Arrays_ multi-dimensionais - 10min](https://www.loom.com/share/2c9dfef1a9f64ae7b84092c4111933cc)
   1. 0:00 explicação do enunciado
   2. 0:56 inicio do resolução
6. [Erros comuns, VLAs - 5min](https://www.loom.com/share/a5ef7a580a604309b9b3938e3b47552e)


---

<!-- .slide: id="array_slides_extra"-->


### Erros comuns

- Aceder a posições inexistentes do _array_
- C permite mas o comportamento não está definido.

```c
int vec[20];
vec[25] = 4;
```


---

### Arrays de tamanho variável (VLA)

- O que são?
- Exemplos
- VLA e funções
- VLA multidimensional e funções

--

### VLA - o que são?

- Variable Length Arrays (VLA)
- Disponíveis apenas para compiladores >C99
- Permitem criar _arrays_ cujo tamanho é definido durante a execução do programa
- Estes _arrays_ não podem ser globais.
- Aplicável a arrays multi-dimensionais.

--

#### VLA - exemplo 1

```c
unsigned int n;
printf("tamanho do vector:");
scanf("%u", &n);
int posicoes[n];
```

--

#### VLA - exemplo 2 - multi-dimensional


```c
unsigned int rows, cols;
printf("linhas e colunas da matriz:");
scanf("%u%u", &rows, &cols);
int matrix[rows][cols];
```

--

#### VLA e funções

```c
int func(int n, int vec[n]){
   //...
}
```

--

#### VLA multi-dimensional e funções

```c
int func(int rows, int cols, int mat[rows][cols]){
   //...
}
```

Desta forma, deixa de ser necessário especificar o tamanho concreto das últimas N-1 dimensões.