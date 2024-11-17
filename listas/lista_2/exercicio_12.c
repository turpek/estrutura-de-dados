/*
 *
 * 12. Considere uma pilha com valores numéricos inteiros positivos. Faça um programa que remova todos
 * os múltiplos de 3 (utilizar apenas as primitivas push e pop
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
  char dado;
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

void push(Pilha *pilha, const char ch){
  No *novo = (No *)malloc(sizeof(No));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return;
  }

  novo->dado = ch;
  novo->prox = pilha->top;
  pilha->top = novo;
}

char pop(Pilha *pilha){
  if(empty(pilha)){
    return '\0';
  }

  No *aux = pilha->top;
  char dado = aux->dado;
  pilha->top = aux->prox;
  free(aux);
  return dado;
}


char top(Pilha *pilha){
  if(empty(pilha)){
    return '\0';
  }
  return pilha->top->dado;
}


void remove_multiplos_de_3(Pilha *pilha){
  Pilha aux;
  inicializa(&aux);

  while(!empty(pilha)){
    int val = pop(pilha);
    if(val % 3 != 0){
      push(&aux, val);
    }
  }
  while(!empty(&aux)){
    push(pilha, pop(&aux));
  }
}

int main(){

  Pilha pilha;
  inicializa(&pilha);

  printf("12. Considere uma pilha com valores numéricos inteiros positivos. Faça um programa que remova todos"
         "os múltiplos de 3 (utilizar apenas as primitivas push e pop).\n\n");

  printf("\tempilhando    -> ");
  int i;
  for(i=1; i<19; i++){
    printf("%d ", i);
    push(&pilha, i);
  }
  printf("\n\tdesempilhando -> ");
  remove_multiplos_de_3(&pilha);
  while(!empty(&pilha)){
    printf("%d ", pop(&pilha));
  }
  printf("\n");

  return 0;
}
