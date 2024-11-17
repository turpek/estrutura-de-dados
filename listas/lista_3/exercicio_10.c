/*
 *
 * 10. Implemente a função main() de um programa que leia 15 números e proceda, para cada um deles,
 * como segue:
 *
 *    − se o número for par, insira-o na fila;
 *    − se o número lido for ímpar, retire um número da fila (caso exista);
 *    − ao final, esvazie a fila imprimindo os elementos.
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct no_fila{
  int dado;
  struct no_fila *prox;
}NoFila;


typedef struct fila_{
  NoFila *front;
  NoFila *rear;
}Fila;


void inicializa_fila(Fila *fila){
  fila->front = NULL;
  fila->rear = NULL;
}


void insert(Fila *fila, const int dado){
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if(novo != NULL){
      novo->prox =  NULL;
      novo->dado = dado;

      if(fila->front == NULL){
        fila->front = novo;
      }
      else{
        fila->rear->prox = novo;
      }
      fila->rear = novo;
    }
}

int empty(Fila fila){
  if(fila.front == NULL){
    return 1;
  }
  return 0;
}


int remover(Fila *fila){
  if(empty(*fila)){
    printf("Fila vazia!\n");
    return -1;
  }

  NoFila *aux = fila->front;
  int dado = aux->dado;
  fila->front = aux->prox;
  free(aux);
  return dado;
}

void liberar(Fila *fila){
  NoFila *p = fila->front, *aux;
  while(p != NULL){
    aux = p;
    p = p->prox;

    printf("%d ", aux->dado);
    free(aux);
  }
  printf("\n");
  fila->front = NULL;
  fila->rear = NULL;
}

void mostrar(Fila fila){
  NoFila *p = fila.front;
  while(p != NULL){
    printf("%d ", p->dado);
    p = p->prox;
  }
  printf("\n");
}



int main(){

  Fila fila;
  inicializa_fila(&fila);

  printf("10. Implemente a função main() de um programa que leia 15 números e proceda, para cada um deles, como segue:\n\n"
         "\t− se o número for par, insira-o na fila;\n"
         "\t− se o número lido for ímpar, retire um número da fila (caso exista);\n"
         "\t− ao final, esvazie a fila imprimindo os elementos.\n\n");

  int i, num;
  for(i=0; i<15; i++){
    printf("Digite o número %do.: ", i + 1);
    scanf("%d", &num);

    if(num%2 == 0){
      insert(&fila, num);
    }
    else{
      remover(&fila);
    }
  }

  printf("\nresultado -> ");
  liberar(&fila);

  return 0;
}
