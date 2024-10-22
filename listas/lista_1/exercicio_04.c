/*
 * 4. Escrever uma função que recebe como entrada uma lista duplamente encadeada de inteiros e retorne a quantidade de elementos da lista.
 */


#include <stdio.h>
#include <stdlib.h>

struct list {
   int num;
   struct list *prev;
   struct list *next;
};

typedef struct list Lista;


// Cria uma Lista vazia
Lista *nova_lista(){
  Lista *nova = NULL;
  return nova;
}

Lista *novo_elemento(Lista *lista, int num){
  Lista *elemento = (Lista*) malloc(sizeof(Lista));

  if(elemento == NULL){
    printf("Nao foi possivel alocar memoria, tente novamente!\n");
    return NULL;
  }

  elemento->num = num;
  elemento->prev = NULL;
  elemento->next = NULL;
  return elemento;
}

Lista *inserir(Lista *lista, int num){
  Lista *novo = novo_elemento(lista, num);
  if(novo == NULL){
    return lista;
  }
  else if(lista != NULL){
    novo->next = lista;
    lista->prev = novo;
  }

  return novo;
}

void liberar(Lista **lista){
  Lista *aux, *p = *lista;
  while(p!=NULL){
    aux = p;
    p = p->next;
    free(aux);
  }
  *lista = NULL;
}

int len(Lista *lista){
  int count = 0;
  Lista *aux = lista;
  while(aux != NULL){
    count += 1;
    aux = aux->next;
  }

  return count;
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir(lista, 6);
  lista = inserir(lista, 5);
  lista = inserir(lista, 3);
  lista = inserir(lista, 2);
  lista = inserir(lista, 1);
  printf("A Lista duplamente encadeada tem %d elementos!\n", len(lista));
  liberar(&lista);

  return 0;
}
