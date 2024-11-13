#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _pilha {
  int num;
  struct _pilha *prox;
}Pilha;


Pilha *inicializa_pilha(){
  return NULL;
}


int empty(Pilha *pilha){
  if(pilha == NULL){
    return 1;
  }
  return 0;
}


Pilha *pilha = NULL;


int push(int num){
  Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return 0;
  }
  novo->num = num;
  novo->prox = pilha;
  pilha = novo;
  return 1;
}


int pop(){
  if(empty(pilha)){
    printf("Pilha vazia!\n");
    return -1;
  }

  Pilha *aux = pilha;
  int num = pilha->num;
  pilha = pilha->prox;
  free(aux);
  return num;
}


int top(){
  if(empty(pilha)){
    printf("Pilha vazia!\n");
    return -1;
  }
  return pilha->num;
}

void liberar(){
  while(!empty(pilha)){
    pop(pilha);
  }
}

int size(){
  Pilha *aux = pilha;
  int count = 0;
  while(aux != NULL){
    aux = aux->prox;
    count++;
  }
  return count;
}


int eh_operacao(char *token){
  char ch = token[0];
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
    return 1;
  }

  return 0;
}


void calcula(char operacao){
  if(size(pilha) < 2){
    return;
  }

  int a, b, result = 0;
  b = pop(pilha);
  a = pop(pilha);
  switch(operacao){
    case '+':
      result = a + b;
      break;
    case '-':
      result = a - b;
      break;
    case '*':
      result = a * b;
      break;
    case '/':
      result = a / b;
      break;
  }
  push(result);
}

int calcula_expressao(const char *expressao){

  char *exp_copy = (char *) malloc(strlen(expressao) * sizeof(char));
  strcpy(exp_copy, expressao);
  char *token = strtok(exp_copy, " ");
  while(token != NULL){
    if(eh_operacao(token)){
      calcula(*token);
    }
    else{
      push(atoi(token));
    }
    token = strtok(NULL, " ");
  }
  free(exp_copy);
  return pop(pilha);
}

int main(){
  char expressao[150];
  printf("Digite uma expressão pós-fixa: ");
  fgets(expressao, sizeof(expressao), stdin);
  printf("> %d\n", calcula_expressao(expressao));

  liberar();
  return 0;
}
