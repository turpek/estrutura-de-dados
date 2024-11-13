/*
 * 42. Escreva uma função que tenha como parâmetros ponteiros para duas listas. A função deve retornar
 * um ponteiro para uma terceira lista, que é o resultado da intersecção das duas (isto é, deve retornar
 * apenas os elementos presentes em ambas).
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



/*Retorna o nó a esquerda do nó que contém num*/
Lista *obter_no(Lista *lista, int num){
  Lista *left = NULL;
  while(lista->prox != NULL){
    if(lista->num == num){
      return left;
    }
    left = lista;
    lista = lista->prox;
  }

  return NULL;
}


int existe(Lista *lista, int num){
  while(lista != NULL){
    if(lista->num == num){
      return 1;
    }
    lista = lista->prox;
  }
  return 0;
}


Lista *uniao_de_lista(Lista *lista1, Lista *lista2){

  Lista *uniao = nova_lista();
  while(lista1 != NULL){
    int valor = lista1->num;
    if(existe(lista2, valor) && !existe(uniao, valor)){
      uniao = inserir_no_final(uniao, valor);
    }
    lista1 = lista1->prox;
  }

  return uniao;
}



int main(){

  Lista *lista1 = nova_lista();
  lista1 = inserir_no_final(lista1, 1);
  lista1 = inserir_no_final(lista1, 2);
  lista1 = inserir_no_final(lista1, 3);
  lista1 = inserir_no_final(lista1, 3);
  lista1 = inserir_no_final(lista1, 5);

  Lista *lista2 = nova_lista();
  lista2 = inserir_no_final(lista2, 1);
  lista2 = inserir_no_final(lista2, 3);
  lista2 = inserir_no_final(lista2, 4);
  lista2 = inserir_no_final(lista2, 5);
  lista2 = inserir_no_final(lista2, 6);

  printf("42. Escreva uma função que tenha como parâmetros ponteiros para duas listas. A função deve retornar"
         "um ponteiro para uma terceira lista, que é o resultado da intersecção das duas (isto é, deve retornar"
         "apenas os elementos presentes em ambas).\n\n");
  printf("\tlista1 -> ");
  imprimir(lista1);
  printf("\tlista2 -> ");
  imprimir(lista2);
  printf("\tuniao  -> ");
  Lista *lista = uniao_de_lista(lista1, lista2);
  imprimir(lista);
  printf("\n");
  liberar(&lista);
  liberar(&lista1);
  liberar(&lista2);
  return 0;
}
