/*
 * 37. Escreva uma função para inserir um elemento antes do n-ésimo
 * elemento de uma lista duplamente encadeada.
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

Lista *novo_elemento(int numero){
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
  Lista *novo = novo_elemento(numero);

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


Lista *inserir_antes_de_n(Lista *lista, int num, int n){
  if(lista == NULL){
    return NULL;
  }
  else if(n < 1){
    printf("Erro: n deve ser maior que 0!\n");
    return lista;
  }

  int i;
  Lista *aux = NULL, *ptr = lista;
  for(i=0; i<(n - 1); i++, ptr=ptr->prox){
    if(ptr == NULL){
      return lista;
    }
    aux = ptr;
  }
  Lista *novo = novo_elemento(num);

  if(aux == NULL){
    novo->prox = lista;
    lista->ante = novo;
    return novo;
  }
  else if(aux->prox != NULL){
    Lista *right = aux->prox;
    novo->prox = aux->prox;
    aux->prox = novo;

    right->ante = novo;
    novo->ante = aux;
  }

  return lista;
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir_no_final(lista, 1);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 4);
  lista = inserir_no_final(lista, 5);
  lista = inserir_no_final(lista, 6);
  lista = inserir_no_final(lista, 7);
  lista = inserir_no_final(lista, 8);
  printf("37. Escreva uma função para inserir um elemento antes "
         "do n-ésimo elemento de uma lista duplamente encadeada.\n");

  printf("\tlista -> ");
  imprimir(lista);
  printf("\n\tinsercao 4o -> ");
  lista = inserir_antes_de_n(lista, 0, 4);
  imprimir(lista);
  printf("\n\tinsercao 1o -> ");
  lista = inserir_antes_de_n(lista, 0, 1);
  imprimir(lista);
  printf("\n\tinsercao 10o -> ");
  lista = inserir_antes_de_n(lista, 0, 10);
  imprimir(lista);
  liberar(&lista);
  return 0;
}
