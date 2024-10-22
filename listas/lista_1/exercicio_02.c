/*
 *2. Escreva uma função que procure um elemento n na lista simplesmente encadeada e retorne 1 (TRUE) caso ele esteja presente e 0 (FALSE) caso contrário.
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

// Função que retorna 1 caso lista contenha valor e 0 caso contrario
int buscar(Lista *lista, int valor){
  Lista *aux = lista;
  while(aux != NULL){
    if(aux->num == valor)
      return 1;
    aux = aux->prox;
  }

  return 0;
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir(lista, 6);
  lista = inserir(lista, 5);
  lista = inserir(lista, 3);
  lista = inserir(lista, 2);
  lista = inserir(lista, 1);

  int num = 4;
  printf("Considere 1==True e 0==False\n\n");
  printf("O elemento %d esta contido na lista? %d\n", num, buscar(lista, num));
  num = 6;
  printf("O elemento %d esta contido na lista? %d\n", num, buscar(lista, num));
  liberar(&lista);

  return 0;
}


