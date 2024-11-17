/*
 *
 * 16. Escrever uma função que recebe como entrada uma pilha encadeada de inteiros e retorne a
 * quantidade de elementos da pilha.
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

void empilhar(Pilha *dest, Pilha *source){
  while(!empty(source)){
    push(dest, pop(source));
  }
}

int eh_igual(Pilha *pilha1, Pilha *pilha2){
  Pilha aux1, aux2;
  inicializa(&aux1);
  inicializa(&aux2);

  int val1 = 0, val2 = 0;
  while(!empty(pilha1) && !empty(pilha2)){
    if(empty(pilha1) || empty(pilha2) || val1 != val2){
      empilhar(pilha1, &aux1);
      empilhar(pilha2, &aux2);
      return 0;
    }
    val1 = pop(pilha1);
    val2 = pop(pilha2);
    push(&aux1, val1);
    push(&aux2, val2);
  }
  empilhar(pilha1, &aux1);
  empilhar(pilha2, &aux2);

  return 1;
}

void liberar(Pilha *pilha){
  while(!empty(pilha)){
    pop(pilha);
  }
}

int len(Pilha *pilha){
  int count = 0;
  Pilha aux;
  inicializa(&aux);
  while(!empty(pilha)){
    push(&aux, pop(pilha));
    count++;
  }
  while(!empty(&aux)){
    push(pilha, pop(&aux));
  }
  return count;
}

int main(){

  Pilha pilha;
  inicializa(&pilha);

  printf("16. Escrever uma função que recebe como entrada uma pilha encadeada de "
         "inteiros e retorne aquantidade de elementos da pilha.\n\n");

  int i;
  for(i=0; i<12; i++){
    push(&pilha, i);
  }
  printf("tamanho da pilha -> %d\n", len(&pilha));
  liberar(&pilha);
  return 0;
}
