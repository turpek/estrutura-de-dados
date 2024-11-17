/*
 *
 * 2. Desenvolva uma função para testar se duas Filas encadeadas P1 e P2 são iguais.
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
    free(aux);
  }
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

int len(Fila fila){
  int count = 0;
  Fila aux;
  inicializa_fila(&aux);
  while(!empty(fila)){
    insert(&aux, remover(&fila));
    count++;
  }
  while(!empty(aux)){
    insert(&fila, remover(&aux));
  }
  return count;
}

int main(){
  Fila fila;
  inicializa_fila(&fila);
  insert(&fila, 1);
  insert(&fila, 2);
  insert(&fila, 3);
  insert(&fila, 4);
  insert(&fila, 5);

  printf("5. Escrever uma função que recebe como entrada uma fila "
      "encadeada de inteiros e retorne a quantidade de elementos da fila.\n\n");
  printf("\tfila -> ");
  mostrar(fila);
  printf("\tsize -> %d\n", len(fila));
  liberar(&fila);
 return 0;
}
