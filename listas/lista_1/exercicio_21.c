/*
 * 21. Implementar uma função que retorna o valor do último elemento. Se a lista estiver vazia, retornar -1.
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

int checar_ordenagem(Lista *lista){
  if(lista == NULL){
    return -1;
  }
  int aux = lista->num;
  do{
    lista = lista->prox;
    if(aux > lista->num){
      return 0;
    }
  }while(lista->prox != NULL);

  return 1;
}

int ultimo_elemento(Lista *lista){
  if(lista == NULL){
    return -1;
  }
  while(lista->prox != NULL){
    lista = lista->prox;
  }

  return lista->num;
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir(lista, 6);
  lista = inserir(lista, 5);
  lista = inserir(lista, 3);
  lista = inserir(lista, 2);
  lista = inserir(lista, 1);
  lista = inserir(lista, 10);
  lista = inserir(lista, 8);
  lista = inserir(lista, 7);

  printf("21. Implementar uma função que retorna o valor do último elemento. "
        "Se a lista estiver vazia, retornar -1.\n");
  printf("lista           -> ");
  imprimir(lista);
  printf("ultimo elemento -> %d\n", ultimo_elemento(lista));
  liberar(&lista);
  return 0;
}
