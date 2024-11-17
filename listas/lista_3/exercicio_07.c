/*
 *
 * 7. Dada uma lista encadeada de caracteres formada por uma sequência alternada de letras e dígitos,
 * construa um método que retorne uma lista na qual as letras são mantidas na sequência original e os
 * dígitos são colocados na ordem inversa. Exemplos:
 *
 *    A 1 E 5 T 7 W 8 G -> A E T W G 8 7 5 1
 *    3 C 9 H 4 Q 6 ->  C H Q 6 4 9 3
 *
 * Como mostram os exemplos, as letras devem ser mostradas primeiro, seguidas dos dígitos. Sugestão:
 * usar uma fila e uma pilha.
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct no_fila{
  char dado;
  struct no_fila *prox;
}NoFila;


typedef struct fila_{
  NoFila *front;
  NoFila *rear;
}Fila;


typedef struct no_pilha{
  char  dado;
  struct no_pilha *prox;
}NoPilha;

typedef struct pilha_{
  NoPilha *top;
}Pilha;


void inicializa_pilha(Pilha *pilha){
  pilha->top = NULL;
}


int empty_pilha(Pilha pilha){
  if(pilha.top == NULL){
    return 1;
  }
  return 0;
}

void push(Pilha *pilha, const char dado){
  NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return;
  }

  novo->dado = dado;
  novo->prox = pilha->top;
  pilha->top = novo;
}

char pop(Pilha *pilha){
  if(empty_pilha(*pilha)){
    return -1;
  }

  NoPilha *aux = pilha->top;
  char dado = aux->dado;
  pilha->top = aux->prox;
  free(aux);
  return dado;
}


void inicializa_fila(Fila *fila){
  fila->front = NULL;
  fila->rear = NULL;
}


void insert(Fila *fila, const char dado){
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if(novo != NULL){
      novo->prox =  NULL;
      novo->dado = dado;

      if(fila->front == NULL){
        fila->front = novo;
      }
      else{
        fila->rear->prox = novo;
      }
      fila->rear = novo;
    }
}

int empty_fila(Fila fila){
  if(fila.front == NULL){
    return 1;
  }
  return 0;
}

char remover(Fila *fila){
  if(empty_fila(*fila)){
    printf("Fila vazia!\n");
    return -1;
  }

  NoFila *aux = fila->front;
  char dado = aux->dado;
  fila->front = aux->prox;
  free(aux);
  return dado;
}

void liberar(Fila *fila){
  NoFila *p = fila->front, *aux;
  while(p != NULL){
    aux = p;
    p = p->prox;
    free(aux);
  }
  fila->front = NULL;
  fila->rear = NULL;
}

void mostrar(Fila fila){
  NoFila *p = fila.front;
  while(p != NULL){
    printf("%c ", p->dado);
    p = p->prox;
  }
  printf("\n");
}


void separar_digitos(Fila *fila){
  Fila letras;
  Pilha digitos;
  inicializa_fila(&letras);
  inicializa_pilha(&digitos);

  while(!empty_fila(*fila)){
    char ch = remover(fila);
    if(ch >= '0' && ch <= '9'){
      push(&digitos, ch);
    }
    else{
      insert(&letras, ch);
    }
  }
  while(!empty_fila(letras)){
    insert(fila, remover(&letras));
  }
  while(!empty_pilha(digitos)){
    insert(fila, pop(&digitos));
  }
}

int main(){

  Fila fila;
  inicializa_fila(&fila);
  insert(&fila, 'A');
  insert(&fila, '1');
  insert(&fila, 'E');
  insert(&fila, '5');
  insert(&fila, 'T');
  insert(&fila, '7');
  insert(&fila, 'W');
  insert(&fila, '8');
  insert(&fila, 'G');

  printf("7. Dada uma lista encadeada de caracteres formada por uma sequência alternada de letras e dígitos, "
         "onstrua um método que retorne uma lista na qual as letras são mantidas na sequência original e os "
         "dígitos são colocados na ordem inversa. Exemplos:\n\n"
         "\tA 1 E 5 T 7 W 8 G -> A E T W G 8 7 5 1\n"
         "\t3 C 9 H 4 Q 6 -> C H Q 6 4 9 3\n\n"
         "Como mostram os exemplos, as letras devem ser mostradas primeiro, seguidas dos dígitos. "
         "Sugestão: usar uma fila e uma pilha.\n\n");

  printf("fila      -> ");
  mostrar(fila);
  separar_digitos(&fila);
  printf("resultado -> ");
  mostrar(fila);
  liberar(&fila);
  return 0;
}
