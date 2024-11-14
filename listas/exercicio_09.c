/*
 *
 * 9. Codifique um programa em C que leia um número inteiro decimal e transforma em um número
 * binário usando uma pilha.
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



void para_binario(Pilha *pilha, int num){
  int div = num;
  do{
    push(pilha, div%2);
    div /= 2;
  }while(div != 0 );

  while(!empty(pilha)){
    printf("%d", pop(pilha));
  }
  printf("\n");
}

int main(){

  Pilha pilha;
  inicializa(&pilha);

  printf("9. Codifique um programa em C que leia um número inteiro decimal "
         "e transforma em um número binário usando uma pilha.\n\n");
  printf("150 -> ");
  para_binario(&pilha, 150);
  return 0;
}
