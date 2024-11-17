/*
 * 23. Escreva um algoritmo para determinar se uma string de caracteres de entrada é da forma: xCy
 * onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso de x (isto é, se x = "ABABBA", y deve equivaler
 * a "ABBABA"). Em cada ponto, você só poderá ler o próximo caractere da string.
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


void liberar(Pilha *pilha){
  while(!empty(pilha)){
    pop(pilha);
  }
}

int compara_xCy(char *string){
  Pilha pilha;
  inicializa(&pilha);

  while(*string != '\0'){
    if(*string == 'C'){
      string++;
      break;
    }
    push(&pilha, *string);
    string++;
  }

  if(*string == '\0'){
    return 0;
  }

  while(*string != '\0'){
    if(empty(&pilha)){
      liberar(&pilha);
      return 0;
    }
    char ch = pop(&pilha);

    if(ch != *string){
      liberar(&pilha);
      return 0;
    }
    string++;
  }

  return 1;
}

int main(){


  printf("23. Escreva um algoritmo para determinar se uma string de caracteres de entrada é da forma: xCy "
         "onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso de x (isto é, "
         "se x = 'ABABBA', y deve equivaler a 'ABBABA'). Em cada ponto, você só poderá ler o "
         "próximo caractere da string.\n\n");


  char *string = "ABABBACABBABA";
  printf("\n\t'%s' esta na forma xCy -> %d\n", string, compara_xCy(string));

  return 0;
}
