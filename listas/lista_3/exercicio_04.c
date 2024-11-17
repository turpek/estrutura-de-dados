/*
 *
 * 4. Escreva um programa que inverta o conteúdo de uma fila
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
  char dado;
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

int pop(Pilha *pilha){
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

int remover(Fila *fila){
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
    printf("%c", p->dado);
    p = p->prox;
  }
  printf("\n");
}

void inverter_fila(Fila *fila){
  Pilha pilha;
  inicializa_pilha(&pilha);
  while(!empty_fila(*fila)){
    push(&pilha, remover(fila));
  }
  while(!empty_pilha(pilha)){
    insert(fila, pop(&pilha));
  }
  
}

int main(){
  Fila fila;
  inicializa_fila(&fila);
  insert(&fila, 'P');
  insert(&fila, 'i');
  insert(&fila, 'l');
  insert(&fila, 'h');
  insert(&fila, 'a');

  printf("4. Escreva um programa que inverta o conteúdo de uma fila\n\n");
  printf("fila           -> ");
  mostrar(fila);

  inverter_fila(&fila);
  printf("fila invertida -> ");
  mostrar(fila);

  liberar(&fila);
  return 0;
}
