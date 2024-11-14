/*
 *
 * 11. Codifique um programa em C que leia um número inteiro decimal e transforma em 
 * um número hexadecimal usando uma pilha. Dica: Se o resto da divisão for 10, 11, 12, 13, 14 ou 15, 
 * imprima, respectivamente, A, B, C, D, E ou F.
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


void imprime_algarismo_hex(int algarismo){
  switch(algarismo){
    case 10:
      printf("A");
      break;
    case 11:
      printf("B");
      break;
    case 12:
      printf("C");
      break;
    case 13:
      printf("D");
      break;
    case 14:
      printf("E");
      break;
    case 15:
      printf("F");
      break;
    default:
      printf("%d", algarismo);
  }
}

void para_hexadecimal(Pilha *pilha, int num){
  int div = num;
  do{
    push(pilha, div%16);
    div /= 16;
  }while(div != 0 );

  while(!empty(pilha)){
    imprime_algarismo_hex(pop(pilha));
  }
  printf("\n");
}

int main(){

  Pilha pilha;
  inicializa(&pilha);

  printf("11. Codifique um programa em C que leia um número inteiro decimal e transforma em um número"
         "hexadecimal usando uma pilha. Dica: Se o resto da divisão for 10, 11, 12, 13, 14 ou 15, imprima,"
         "respectivamente, A, B, C, D, E ou F.\n\n");
  printf("150 -> ");
  para_hexadecimal(&pilha, 150);
  printf("189 -> ");
  para_hexadecimal(&pilha, 189);
  return 0;
}
