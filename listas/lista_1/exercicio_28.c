/*
 * 28. Implemente uma função para inserir elementos em uma lista encadeada circular.
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list {
  int num;
  struct list *prox;
} Lista;


void liberar(Lista **lista){
  Lista *aux, *p = *lista;
  while(p != *lista){
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

  novo->prox = novo;
  novo->num = numero;
  return novo;
}


Lista *inserir_no_final(Lista *lista, int numero){
  Lista *novo = novo_elemento(numero);
  if(lista == NULL){
    return novo;
  }
  if(novo == NULL){
    return lista;
  }

  Lista *aux  = lista;
  while(aux->prox != lista){
    aux = aux->prox;
  }
  novo->prox = aux->prox;
  aux->prox = novo;

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

int main(){

  Lista *lista = nova_lista();
  lista = inserir_no_final(lista, 6);
  lista = inserir_no_final(lista, 5);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 1);

  printf("28. Implemente uma função para inserir elementos "
         "em uma lista encadeada circular.\n\n");
  printf("\tlista circuilar -> ");
  imprimir(lista);
  liberar(&lista);

  return 0;
}
