/*
 * 25. Implemente uma função para inserir novos elementos no final de uma lista duplamente encadeada
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list {
  int num;
  struct list *prox;
  struct list *ante;
} Lista;

Lista *nova_lista(){
  Lista *nova = NULL;
  return nova;
}

Lista *novo_elemento(Lista *lista, int numero){
  Lista *novo = (Lista*) malloc(sizeof(Lista));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memoria, tente novamente!\n");
    return NULL;
  }

  novo->num = numero;
  novo->prox = NULL; 
  novo->ante = NULL;
  return novo;
}


Lista *inserir_no_final(Lista *lista, int numero){
  Lista *novo = novo_elemento(lista, numero);

  if(lista == NULL){
    return novo;
  }
  else if(novo == NULL){
    return lista;
  }

  Lista *aux = lista;
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  aux->prox = novo;
  novo->ante = aux;
  return lista;
}


void liberar(Lista **lista){
  Lista *aux, *ptr = *lista;
  while(ptr != NULL){
    aux = ptr;
    ptr = ptr->prox;
    free(aux);
  }
  *lista = NULL;
}


void imprimir(Lista *lista){
  if(lista == NULL){
    return;
  }

  while(lista != NULL){
    printf("%d ", lista->num);
    lista = lista->prox;
  }
  printf("\n");
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir_no_final(lista, 1);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 4);
  lista = inserir_no_final(lista, 5);
  lista = inserir_no_final(lista, 6);
  printf("25. Implemente uma função para inserir novos elementos"
         " no final de uma lista duplamente encadeada.\n");
  printf("\tlista -> ");
  imprimir(lista);
  liberar(&lista);
  return 0;
}
