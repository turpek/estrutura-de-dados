/*
 *
 * 14. Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.
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

void imprimir(Pilha *pilha){
  if(pilha->top == NULL)
    return;

  Pilha aux;
  inicializa(&aux);
  while(!empty(pilha)){
    int val = pop(pilha);
    printf("%d, ", val);
    push(&aux, val);
  }
  printf("\n");

  while(!empty(&aux)){
    push(pilha, pop(&aux));
  }
}

int main(){

  Pilha pilha1, pilha2;
  inicializa(&pilha1);
  inicializa(&pilha2);

  printf("14. Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.\n\n");

  int i = 0;
  for(i=0; i<8; i++){
    push(&pilha1, i);
    push(&pilha2, i);
  }

  printf("\tpilha1                   -> ");
  imprimir(&pilha1);
  printf("\tpilha2                   -> ");
  imprimir(&pilha2);
  printf("\tpilha1 eh igual a pilha2 -> %d\n\n", eh_igual(&pilha1, &pilha2));

  pop(&pilha1);
  printf("\tpilha1                   -> ");
  imprimir(&pilha1);
  printf("\tpilha2                   -> ");
  imprimir(&pilha2);
  printf("\tpilha1 eh igual a pilha2 -> %d\n", eh_igual(&pilha1, &pilha2));

  return 0;
}
