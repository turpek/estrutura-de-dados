/*
 *
 * 13. Escreva um programa que armazena n valores da sequência de Fibonacci em uma pilha.
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


void get_nfibonacci(Pilha *pilha, const int n){
  if(n > 0){
    int i, a=1, b=0, swap;
    // 0 1 2 3 5
    for(i=1; i<n+1; i++){
      push(pilha, b);
      swap = b;
      b = a + b;
      a = swap;
    }
  }
}

int main(){

  Pilha pilha;
  inicializa(&pilha);

  printf("13. Escreva um programa que armazena n valores da sequência de Fibonacci em uma pilha.\n\n");

  int n = 8;
  printf("\tOs %d termos de fibonacci -> ", n);
  get_nfibonacci(&pilha, n);
  while(!empty(&pilha)){
    printf("%d, ", pop(&pilha));
  }
  printf("\n");

  return 0;
}
