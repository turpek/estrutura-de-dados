/*
 * 30. Implemente uma função que receba como entrada uma lista duplamente 
 * encadeada de inteiros e um número inteiro positivo n. A função deverá 
 * imprimir o elemento da posição n, n-1 e n+1. Se não houver algum dos 
 * elementos a função deverá imprimir o valor -1.
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

void imprimir_vizinhanca_de_n(Lista *lista, int n){
  if(lista == NULL){
    printf("-1\n");
    return;
  }

  int i;
  for(i=0; i<(n-1); i++, lista=lista->prox){
    if(lista == NULL){
      printf("-1\n");
      return;
    }
  }
  if(lista == NULL){
    printf("-1\n");
    return;
  }

  Lista *left = lista->ante, *right = lista->prox;
  if(left == NULL || right == NULL){
    printf("-1\n");
    return;
  }
  printf("%d, %d, %d\n", left->num, lista->num, right->num);
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
  printf("30. Implemente uma função que receba como entrada uma lista duplamente "
         "encadeada de inteiros e um número inteiro positivo n. A função deverá "
         "imprimir o elemento da posição n, n-1 e n+1. Se não houver algum dos "
         "elementos a função deverá imprimir o valor -1.\n\n");

  printf("\tlista               -> ");
  imprimir(lista);
  printf("\telemento 2o, 3o, 3o -> ");
  imprimir_vizinhanca_de_n(lista, 3);
  printf("\telemento 6o, 7o, 8o -> ");
  imprimir_vizinhanca_de_n(lista, 7);
  printf("\telemento 7o, 8o, 9o -> ");
  imprimir_vizinhanca_de_n(lista, 8);
  liberar(&lista);
  return 0;
}
