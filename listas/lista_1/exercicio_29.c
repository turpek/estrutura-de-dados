/*
 * 29. Implemente uma função que receba como entrada uma lista simplesmente encadeada de inteiros e
 * um número inteiro positivo n. A função deverá imprimir o elemento da posição n, n-1 e n+1. Se não
 * houver algum dos elementos a função deverá imprimir o valor -1.
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
  if(novo == NULL){
    return lista;
  }
  else if(lista == NULL){
    return novo;
  }

  Lista *aux = lista;
  while(aux->prox!=NULL){
    aux = aux->prox;
  }
  aux->prox = novo;
  return lista;
}


void imprimir(Lista *lista){
  if(lista == NULL){
    return;
  }

  Lista *aux = lista;
  while(aux != NULL){
    printf("%d ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}


void imprimir_vizinhanca_de_n(Lista *lista, int n){
  if(n < 0){
    printf("-1\n");
  }
  else if(lista == NULL){
    printf("-1\n");
    return;
  }

  int i;
  for(i=0; i<(n- 2); i++, lista=lista->prox){
    if(lista == NULL){
      printf("-1\n");
      return;
    }
  }
  if(lista == NULL){
    printf("-1\n");
    return;
  }


  Lista *left = lista, *ptr = lista->prox, *right = NULL;
  if(ptr == NULL){
    printf("-1\n");
    return;
  }
  else{
    right = ptr->prox;
  }
  if(right == NULL){
    printf("-1\n");
    return;
  }

  printf("%d, %d, %d\n", left->num, ptr->num, right->num);
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir_no_final(lista, 6);
  lista = inserir_no_final(lista, 5);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 1);
  lista = inserir_no_final(lista, 10);
  lista = inserir_no_final(lista, 8);
  lista = inserir_no_final(lista, 7);

  printf("29. Implemente uma função que receba como entrada "
         "uma lista simplesmente encadeada de inteiros e um número "
         "inteiro positivo n. A função deverá imprimir o elemento "
         "da posição n, n-1 e n+1. Se não houver algum dos elementos "
         "a função deverá imprimir o valor -1.\n\n");
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
