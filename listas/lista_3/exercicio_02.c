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


int eh_igual(Fila p1, Fila p2){
  NoFila *l1 = p1.front;
  NoFila *l2 = p2.front;

  while(l1 != NULL && l2 != NULL){
    if(l1->dado != l2->dado){
      return 0;
    }
    l1 = l1->prox;
    l2 = l2->prox;
  }
  if(l1 != l2){
    return 0;
  }

  return 1;
}


int main(){
  Fila p1, p2;

  inicializa_fila(&p1);
  insert(&p1, 1);
  insert(&p1, 2);
  insert(&p1, 3);
  insert(&p1, 4);
  insert(&p1, 5);

  inicializa_fila(&p2);
  insert(&p2, 1);
  insert(&p2, 2);
  insert(&p2, 3);
  insert(&p2, 4);
  insert(&p2, 5);

  printf("2. Desenvolva uma função para testar se duas Filas encadeadas P1 e P2 são iguais.\n\n");
  printf("\tp1 -> ");
  mostrar(p1);
  printf("\tp2 -> ");
  mostrar(p2);
  printf("\tp1 == p2 -> %d\n\n", eh_igual(p1, p2));

  remover(&p1);
  printf("\tp1 -> ");
  mostrar(p1);
  printf("\tp2 -> ");
  mostrar(p2);
  printf("\tp1 == p2 -> %d\n", eh_igual(p1, p2));

}
