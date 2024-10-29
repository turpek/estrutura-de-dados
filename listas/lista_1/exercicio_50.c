/*
 * 50. Escreva uma função que retorne um ponteiro para o último
 * elemento de uma lista circular simplesmente encadeada.
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list {
  int num;
  struct list *prox;
} Lista;


void liberar(Lista **lista){
  if(*lista == NULL){
    return;
  }

  Lista *aux, *p = *lista, *inicio = *lista;
  do{
    aux = p;
    p = p->prox;
    free(aux);
  }while(p != inicio);
  *lista = NULL;
}


Lista *inicializa(void){
  return NULL;
}


Lista *novo_elemento(int numero){
  Lista *novo = (Lista*) malloc(sizeof(Lista));
  if(novo == NULL){
    printf("Não foi possível alocar memória, tente novamente!\n");
    return NULL;
  }

  novo->prox = novo;
  novo->num = numero;
  return novo;
}


Lista *inserir_no_final(Lista *lista, int num){
  Lista *novo = novo_elemento(num);
  if(lista == NULL){
    return novo;
  }
  else if(novo == NULL){
    return lista;
  }
  Lista *aux = lista, *inicio = lista;
  while(aux->prox != inicio){
    aux = aux->prox;
  }
  aux->prox = novo;
  novo->prox = lista;
  return lista;
}


void imprimir(Lista *lista){
  if(lista == NULL){
    return;
  }

  Lista *aux = lista;
  do{
    printf("%d ", aux->num);
    aux = aux->prox;
  }while(aux != lista);
  printf("\n");
}

Lista *obter_final(Lista *lista){
  if(lista == NULL){
    return NULL;
  }

  Lista *inicio = lista;
  while(lista->prox != inicio){
    lista = lista->prox;
  }
  return lista;
}


int main(){

  Lista *lista = inicializa();
  lista = inserir_no_final(lista, 1);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 4);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 6);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 8);

  printf("50. Escreva uma função que retorne um ponteiro para o último "
         "elemento de uma lista circular simplesmente encadeada.\n\n");
  printf("\tlista           -> ");
  imprimir(lista);

  Lista *ultimo = obter_final(lista);
  printf("\tultimo elemento -> %p\n", ultimo);
  printf("\tvalor           -> %d\n\n", ultimo->num);

  liberar(&lista);
  return 0;
}
