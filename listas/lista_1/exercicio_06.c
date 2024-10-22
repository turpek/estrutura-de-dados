/*
 *6. Escrever uma função que receba como entrada uma lista simplesmente encadeada e ordene os elementos da lista em ordem crescente.
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

Lista *inserir(Lista *lista, int numero){
  Lista *novo = novo_elemento(numero);
  if(novo == NULL){
    return lista;
  }

  novo->prox = lista;
  return novo;
}

void imprimir(Lista *lista){
  if(lista == NULL)
    return;

  Lista *aux = lista;
  while(aux != NULL){
    printf("%d ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}

void sorted(Lista *lista){
  Lista *l, *p;
  for(l=lista; l!=NULL; l=l->prox){
    for(p=l->prox; p!=NULL; p=p->prox){
      if(l->num > p->num){
        int aux = l->num;
        l->num = p->num;
        p->num = aux;
      }
    }
  }
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir(lista, 6);
  lista = inserir(lista, 4);
  lista = inserir(lista, -1);
  lista = inserir(lista, 3);
  lista = inserir(lista, 5);
  lista = inserir(lista, 0);
  lista = inserir(lista, 9);
  lista = inserir(lista, 2);
  lista = inserir(lista, 12);
  lista = inserir(lista, 1);
  imprimir(lista);
  printf("ordenando a lista!\n");
  sorted(lista);
  imprimir(lista);
  liberar(&lista);

  return 0;
}
