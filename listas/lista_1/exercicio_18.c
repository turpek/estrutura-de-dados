/*
 * 18. Implemente uma função para dividir uma lista em duas outras listas, 
 * uma com elementos de chaves pares e a outra com elementos de chaves ímpares.
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


Lista *chave_pares(Lista *lista){
  if(lista == NULL){
    return NULL;
  }
  int i = 0;
  Lista *chaves = nova_lista();
  while(lista != NULL){
    if(i % 2 == 0){
      chaves = inserir(chaves, lista->num);
    }
    i += 1;
    lista = lista->prox;
  }

  return chaves;
}

Lista *chave_impares(Lista *lista){
  if(lista == NULL){
    return NULL;
  }

  int i = 0;
  Lista *chaves = nova_lista();
  while(lista != NULL){
    if(i % 2 != 0){
      chaves = inserir(chaves, lista->num);
    }
    i += 1;
    lista = lista->prox;
  }

  return chaves;
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

  printf("18. Implemente uma função para dividir uma lista em duas "
         "outras listas, uma com elementos de chaves pares e a outra "
         "com elementos de chaves ímpares.\n");

  printf("lista       -> ");
  imprimir(lista);
  printf("key pares   -> ");
  Lista *pares = chave_pares(lista);
  imprimir(pares);
  printf("key impares -> ");
  Lista *impares = chave_impares(lista);
  imprimir(impares);

  liberar(&lista);
  liberar(&pares);
  liberar(&impares);

  return 0;
}


