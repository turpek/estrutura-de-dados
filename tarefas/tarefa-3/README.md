# Exercício 3 - Lista Duplamente Encadeada Circular

Escrever uma função CLista* inserir(Clista *l, int v) para inserir números inteiros no início de uma Lista Duplamente Encadeada Circular. Por fim, retornar a cabeça da lista. Incluir também no código uma função para listar os nós da lista. Considere a estrutura abaixo:

```
struct clista {
  int info;
  struct clista *ant;
  struct clista *prox;
};

typedef struct clista CLista;
```
