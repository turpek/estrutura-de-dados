/*
 * 49. Escreva uma função que retorne um ponteiro para o último elemento
 * de uma lista simplesmente encadeada.
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list {
  int num;
  struct list *prox;
} Lista;


void liberar(Lista **lista){
  Lista *aux, *p = *lista;
  while(p != NULL){
    aux = p;
    p = p->prox;
    free(aux);
  }
  *lista = NULL;
}


Lista *nova_lista(void){
  Lista *novo = NULL;
  return novo;
}


Lista *novo_elemento(int numero){
  Lista *novo = (Lista*) malloc(sizeof(Lista));
  if(novo == NULL){
    printf("Não foi possível alocar memória, tente novamente!\n");
    return NULL;
  }

  novo->prox = NULL;
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
  Lista *aux = lista;
  while(aux-> prox != NULL){
    aux = aux->prox;
  }
  aux->prox = novo;

  return lista;
}


void imprimir(Lista *lista){
  Lista *aux = lista;
  while(aux != NULL){
    printf("%d ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}

Lista *obter_final(Lista *lista){
  if(lista == NULL){
    return NULL;
  }

  while(lista->prox != NULL){
    lista = lista->prox;
  }
  return lista;
}


int main(){

  Lista *lista = nova_lista();
  lista = inserir_no_final(lista, 1);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 4);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 6);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 8);

  printf("49. Escreva uma função que retorne um ponteiro para o último elemento "
         "de uma lista simplesmente encadeada.\n\n");
  printf("\tlista           -> ");
  imprimir(lista);

  Lista *ultimo = obter_final(lista);
  printf("\tultimo elemento -> %p\n", ultimo);
  printf("\tvalor           -> %d\n\n", ultimo->num);

  liberar(&lista);
  return 0;
}
