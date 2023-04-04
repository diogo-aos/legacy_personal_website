<img src="img/afa.png" height="100">


## _Struct_

### Diogo Silva
####  CAP / ENGEL
dasilva@academiafa.edu.pt

<!-- .slide: data-background="Cornsilk" id="struct" -->


--

## _Struct_


- [Videos TODO](#/struct_videos)
- [Slides, PDF](pdf/10_struct.pptx.pdf)


--

<!-- .slide: id="struct_videos"-->

#### videos 1/2

1. [Intro, motivação | 1.5min](https://www.loom.com/share/bea2cbd37ce74a7b9d5c7a881169985a)
2. [Declarar, aceder | 4min](https://www.loom.com/share/b7f6b136b06945deabb4a46d5f96a1f2)
3. [Comparação, estruturas dentro de estruturas, funções | 4min](https://www.loom.com/share/2ce3c39cdd18400e9a21221f73ecc6bc)
4. [typedef | 2min](https://www.loom.com/share/9867f03b2f3d4a18a9b2fbeaa4cf08f7)
5. [estruturas e apontadores | 4min](https://www.loom.com/share/3d28ce3e73e748bf89c3daad774940b5)

--

#### videos 2/2

6. [Demo 1 | 10min](https://www.loom.com/share/80c0eace852b42c897bb420b4bd8dcfd)
7. [Demo 1 | correção de criar_aluno | 3min](https://www.loom.com/share/f6c2db7eb645495dbd207f37fdb7366d)
8. [Demo 1a | vector de Aluno | 4min](https://www.loom.com/share/e9dc20b505b04c1891e4efd0cea2e548)
9. [Demo 1b](https://www.loom.com/share/f067103801864b5cb8bc2bcbaa7f4eea)
10. [Demo 1c](https://www.loom.com/share/6440a24081944296bc94c7e0e768a98b)
11. [Demo 1d](https://www.loom.com/share/6440a24081944296bc94c7e0e768a98b)
12. [Demo 1f](https://www.loom.com/share/93b3b54c1b694e91b50bd27513855725)
13. [Demo 1g](https://www.loom.com/share/ab6294191a52423ca921aacd6c550be6)


--

#### Exercício 1

- Escreva um programa que guarde e mostre o registo de um aluno ``Aluno`` da cadeira de programação.
- Um aluno tem os seguintes parâmetros:
  - `nome` (string)
  - `NIP` (int)
  - `notas` (vector com 3 números reais para guardar as classificações das avaliações)
- Escreva uma função ``criar_aluno`` que pede os dados do aluno ao utilizador e devolve um registo de aluno com esses dados.
- Escreva uma função ``mostrar_aluno`` que recebe o apontador de um registo de aluno e imprime os seus valores na consola.

--

#### Exercício 1a

- Expanda o programa anterior para mostrar os registos dos alunos da cadeira de Programação.
- Crie um vector de ``Aluno`` de tamanho ``MAX_ALUNOS`` e uma variável ``n_alunos`` que recebe do utilizador quantos alunos vai receber.
- Peça os dados de todos os alunos a receber e no final, escreva na consola os dados de todos os alunos.

--

#### Exercício 1b

- Modifique o programa anterior por forma a termos várias Unidades Curriculares (UC). 
- Crie uma estrutura para uma UC, com os seguintes campos:
   - ``nome`` (string, max 50 chars)
   - ``abreviatura`` (vector 4 chars)
   - ``n_creditos`` (int): número de créditos (ECTS)
   - ``alunos`` (vector de apontadores para Aluno, max 100): lista de alunos inscritos 
   - ``n_inscritos`` (unsigned char): número de alunos inscritos
   - ``avals`` (vector de reais): notas finais dos alunos à UC
- Agora a estrutura ``Aluno`` já não precisa do campo `notas`, estes dados estão guardados nas UCs. Remova esse campo.
- Agora a lista de ``Aluno`` é a lista de todos os alunos.
- Crie um vector para a lista de UCs (tamanho de ``MAX_UC``) na ``main``.
- Crie a função ``criarUC``:
  - não recebe argumentos
  - pede os dados de uma ``UC`` (nome, abreviatura, número de créditos) ao utilizador
  - devolver a ``UC`` criada
- Cria a função ``mostrarUC``
  - recebe um apontador de ``UC``
  - mostra os dados da ``UC``, incluindo a lista dos alunos inscritos
- Dicas:
  - para facilitar o teste das funcionalidades, inicialize o vector de todos os alunos com dados no código
  - para facilitar o teste das funcionalidades, inicialize o vetor de todas as UCs com algumas UCs já com alunos inscritos

--

#### Exercício 1c

- Implementa a função ``media_UC`` que recebe um apontador de UC e calcula a média das notas dos alunos.
- Altera a função ``mostrarUC`` para mostrar a média da UC que recebe.

--


#### Exercício 1d

- Implementa a função ``media_aluno``
  - recebe
    - apontador de Aluno
    - lista de todas as UCs
  - devolve
    - valor real com a média ponderada (ter em conta os ECTS de cada UC) de todas as UCs em que o aluno está inscrito
  - esta função tem de percorrer todas as UCs e verificar se o aluno está inscrito nessa UC

--


#### Exercício 1e

- Implementa a função ``media_total``
  - recebe
    - lista de todos os alunos
    - lista de todas as UCs
  - devolve
    - real correspondente à média aritmética da média ponderada de todos os alunos

--

#### Exercício 1f

- Implementa a função ``inscrever_UC``
  - recebe apontador de ``UC``
  - lista de todos os alunos
- mostra lista de todos os alunos
- utilizador escolhe quais os alunos da lista a inscrever nesta UC
  - escrever os índices e terminar lista com algum carater não numérico
  - exemplo:
    ```text
    Lista de todos os alunos:
            0 - 136787 - Asimov
            1 - 136867 - Turing
            2 - 122444 - Oppenheimer
            3 - 133555 - Newton
    Índices dos alunos que quer inscrever (separados por espaço):
    1 5 3 f
    ```
- adicionar os alunos escolhidos ao vetor ``alunos`` da UC

--

#### Exercício 1g

- Implementa a função ``inscrever_aluno``
  - recebe
    - apontador de ``Aluno``
    - lista de todas as UCs
  - mostra lista de todas as UCs e permite escolher as UCs em que o aluno está inscrito
  - para cada UC selecionada
    - adicionar o aluno à lista de inscritos
  - não devolve nada

