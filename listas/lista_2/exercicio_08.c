/*
 *
 * 8. Codifique um programa em C que leia uma sequência de caracteres e 
 * imprima na ordem inversa usando uma pilha.
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


void inverte(Pilha *pilha, const char *texto){
  while(*texto != '\0'){
    push(pilha, *texto);
    texto++;
  }
  while(!empty(pilha)){
    printf("%c", pop(pilha));
  }
  printf("\n");
}


int main(){

  Pilha pilha;
  inicializa(&pilha);

  printf("8. Codifique um programa em C que leia uma sequência de caracteres "
         "e imprima na ordem inversa usando uma pilha.\n\n");

  char frase[] = "dia de sol";
  printf("\tfrase     -> %s\n", frase);
  printf("\tinvertida -> ");
  inverte(&pilha, "dia de sol");
  return 0;
}
