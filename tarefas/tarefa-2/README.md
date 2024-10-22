# Exercício 2 - Lista Duplamente Encadeada (Navegar)

Considere a seguinte estrutura de uma Lista Duplamente Encadeada:

```
struct lista

{

   char nome[40];

   struct lista *prev;

   struct lista *next;

};

typedef struct lista Lista;
```

Escreva uma função `void navegar(Lista *ptr)` que recebe o endereço de um elemento qualquer da lista e permita que o usuário navegue para frente e para trás na lista. Utilize as seguintes teclas para navegação:

- '<' para exibir o nome anterior;
- '>' para exibir o nome seguinte; e
- 'q' para encerrar a navegação.

Se os ponteiros `prev` ou `next` apontarem para NULL, exiba a mensagem "Início de Lista" ou "Fim de Lista", respectivamente.
