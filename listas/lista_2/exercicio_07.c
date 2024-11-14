/*
 *
 * 7. Codifique um programa em C que leia uma sequência de números inteiros e imprima na ordem
 * inversa usando uma pilha
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pilha{
  int num;
  struct _pilha *prox;
} Pilha;


#define MAXLEN 5

Pilha *inicializa(){
  return NULL;
}


int empty(Pilha *pilha){
  if(pilha == NULL){
    return 1;
  }
  return 0;
}

void push(Pilha **pilha, int num){
  Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return;
  }

  novo->num = num;
  novo->prox = *pilha;
  *pilha = novo;
}

int pop(Pilha **pilha){
  if(empty(*pilha)){
    return '\0';
  }

  Pilha *aux = *pilha;
  int num = aux->num;
  *pilha = aux->prox;
  free(aux);
  return num;
}


int top(Pilha *pilha){
  if(empty(pilha)){
    return '\0';
  }
  return pilha->num;
}

//Devolve um ponteiro que retorna o texto quando encontra o '.'
char *tokens(const char *texto){
  int n = 0;
  const char *aux = texto;
  while(*aux != '\0'){
    if(*aux == '.'){
      char *texto_cpy = (char *)malloc((n + 1) * sizeof(char));
      strncpy(texto_cpy, texto, n);
      return texto_cpy;
    }
    n++;
    aux++;
  }
  return NULL;

}

void inverte(Pilha **pilha, int *array_num, int size){
  int i;
  for(i=0; i < size; i++){
    push(pilha, array_num[i]);
  }

  while(!empty(*pilha)){
    printf("%d ", pop(pilha));
  }
  printf("\n");
}


int main(){

  Pilha *pilha = inicializa();
  int array[MAXLEN] = {1, 2, 3, 4, 5};

  printf("7. Codifique um programa em C que leia uma sequência de números inteiros \n"
         "e imprima na ordem inversa usando uma pilha\n\n");
  printf("\tarray           -> ");

  int i;
  for(i=0; i < MAXLEN; i++){
    printf("%d ", array[i]);
  }
  printf("\n\tarray invertido -> ");
  inverte(&pilha, array, MAXLEN);

  return 0;
}
