/*
 * 15. Implemente uma função inserir() que realiza a inserção dos elementos de uma lista de inteiros
 * ordenadamente. O protótipo da função deve ser dado por:
 *
 * Lista *inserir (Lista* l, int num);
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


Lista *inserir(Lista *lista, int num){
  Lista *novo = novo_elemento(num);
  if(novo == NULL){
    return lista;
  }
  else if(lista == NULL){
    return novo;
  }



  Lista *aux = NULL, *ptr = lista;
  while(ptr != NULL && (ptr->num < num)){
    aux = ptr;
    ptr = ptr->prox;
  }

  if(aux == NULL){
    novo->prox = lista;
    return novo;
  }

  novo->prox = aux->prox;
  aux->prox = novo;
  return lista;
}

void imprimir(Lista *lista){
  while(lista != NULL){
    printf("%d ", lista->num);
    lista = lista->prox;
  }
  printf("\n");
}


int main(){

  Lista *lista = nova_lista();
  lista = inserir(lista, 2);
  lista = inserir(lista, 3);
  lista = inserir(lista, 9);
  lista = inserir(lista, 4);
  lista = inserir(lista, 1);
  lista = inserir(lista, -3);
  lista = inserir(lista, 5);
  lista = inserir(lista, 6);
 
  imprimir(lista);
  liberar(&lista);

  return 0;
}
