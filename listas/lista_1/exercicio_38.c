/*
 * 38. Escreva uma função que recebe como parâmetro uma lista simplesmente encadeada e um número
 * inteiro n. Caso o número exista na lista ele deve ser transferido para o início da lista
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
  while(lista != NULL){
    if(lista->num == num){
      return left;
    }
    left = lista;
    lista = lista->prox;
  }

  return NULL;
}


Lista *novo_inicio(Lista *lista, int num){
  Lista *aux = obter_no(lista, num);

  if(aux == NULL){
    return lista;
  }

  Lista *head = aux->prox;

  aux->prox = head->prox;
  head->prox = lista;

  return head;
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

  printf("38. Escreva uma função que recebe como parâmetro uma lista simplesmente encadeada e um número "
         "inteiro n. Caso o número exista na lista ele deve ser transferido para o início da lista\n\n");
  printf("\n\tlista  -> ");
  imprimir(lista);
  printf("\n\thead 5 -> ");
  lista = novo_inicio(lista, 5);
  imprimir(lista);
  printf("\n\thead 8 -> ");
  lista = novo_inicio(lista, 8);
  imprimir(lista);
  printf("\n\thead 8 -> ");
  lista = novo_inicio(lista, 8);
  imprimir(lista);
  liberar(&lista);
  return 0;
}
