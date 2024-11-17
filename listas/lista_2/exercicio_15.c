/*
 *
 * 15. Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas operações da fila e da pilha,
 * escreva uma função que inverta a ordem dos elementos da fila.
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  int dado;
  struct no *prox;
}No;

typedef struct _pilha{
  No *top;
}Pilha;


typedef struct no_fila{
  int dado;
  struct no_fila *prox;
}NoFila;

typedef struct _fila{
  NoFila *front;
  NoFila *rear;
}Fila;


void inicializaf(Fila *fila){
  fila->front = NULL;
  fila->rear = NULL;
}

void insert(Fila *fila, const int dado){
  NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória para a fila, tente novamente!\n");
    return;
  }

  novo->prox = NULL;
  novo->dado = dado;

  if(fila->rear == NULL){
    fila->front = novo;
  }
  else{
    NoFila *aux = fila->rear;
    aux->prox = novo;
  }
  fila->rear = novo;
}

int emptyf(Fila *fila){
  if(fila->front == NULL){
    return 1;
  }
  return 0;
}

int removef(Fila *fila){
  if(emptyf(fila)){
    printf("Fila vazia!\n");
    return -1;
  }
  NoFila *aux = fila->front;
  int dado = aux->dado;

  fila->front = aux->prox;
  if(fila->front == NULL){
    fila->rear = NULL;
  }
  free(aux);
  return dado;
}

void inicializa(Pilha *pilha){
  pilha->top = NULL;
}

int empty(Pilha *pilha){
  if(pilha->top == NULL){
    return 1;
  }
  return 0;
}

void push(Pilha *pilha, const int dado){
  No *novo = (No *)malloc(sizeof(No));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return;
  }

  novo->dado = dado;
  novo->prox = pilha->top;
  pilha->top = novo;
}

int pop(Pilha *pilha){
  if(empty(pilha)){
    return '\0';
  }

  No *aux = pilha->top;
  int dado = aux->dado;
  pilha->top = aux->prox;
  free(aux);
  return dado;
}


int top(Pilha *pilha){
  if(empty(pilha)){
    return '\0';
  }
  return pilha->top->dado;
}


void inverter_fila(Fila *fila){
  Pilha pilha;
  inicializa(&pilha);

  while(!emptyf(fila)){
    push(&pilha, removef(fila));
  }
  while(!empty(&pilha)){
    insert(fila, pop(&pilha));
  }
}


int main(){


  Fila fila;
  inicializaf(&fila);

  printf("15. Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas operações da fila e da pilha,"
         "escreva uma função que inverta a ordem dos elementos da fila.\n\n");

  int i;
  printf("\tfila           -> ");
  for(i=0; i<9; i++){
    printf("%d ", i);
    insert(&fila, i);
  }
  printf("\n");

  inverter_fila(&fila);
  printf("\tfila invertida -> ");
  while(!emptyf(&fila)){
    printf("%d ", removef(&fila));
  }
  printf("\n");

  return 0;
}
