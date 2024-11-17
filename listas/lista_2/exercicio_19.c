/*
 *
 * 19. Implemente a função main() de um programa que leia 15 números e 
 * proceda, para cada um deles,como segue:
 *
 *  − se o número for par, insira-o na pilha;
 *  − se o número lido for ímpar, retire um número da pilha;
 *  − Ao final, esvazie a pilha imprimindo os elementos.
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
    printf("%d ", pop(pilha));
  }
  printf("\n");
}

void pipeline(Pilha *pilha, int array[15]){
  int i;
  for(i=0; i<15; i++){
    if(array[i]%2 == 0){
      pop(pilha);
    }
    else{
      push(pilha, array[i]);
    }
  }
}

int main(){

  Pilha pilha;
  inicializa(&pilha);

  printf("19. Implemente a função main() de um programa que leia 15 números e proceda, \n"
         "para cada um deles, como segue:\n"
         "  − se o número for par, insira-o na pilha;\n"
         "  − se o número lido for ímpar, retire um número da pilha;\n"
         "  − Ao final, esvazie a pilha imprimindo os elementos.\n\n");

  int array[15] = {24, 89, 34, 56, 78, 45, 12, 67, 39, 81, 22, 93, 55, 60, 10};
  printf("pilha -> ");
  pipeline(&pilha, array);
  liberar(&pilha);
  return 0;
}
