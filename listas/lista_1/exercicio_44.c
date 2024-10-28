/*
 * 44. Desenvolva uma função que, dados uma lista simplesmente encadeada e um número inteiro positivo
 * n, remova da lista seus n primeiros nós e retorne a lista resultante. Caso n seja maior do que o
 * tamanho da lista, todos os seus nós devem ser removidos e a lista resultante deve ser uma lista vazia.
 * Essa função deve possuir o seguinte protótipo:
 * Lista *remove_elementos (Lista *l, int n);
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
  Lista *aux = lista;
  while(aux != NULL){
    printf("%d ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}


Lista *separa(Lista **l, int n){
  int i;
  Lista *lista = *l;
  if(n < 0 || lista == NULL){
    return lista;
  }
  else if(n == 0){
    return NULL;
  }
  else if(n == 1){
    Lista *separada = lista;
    *l = NULL;
    return separada;
  }
  for(i=0; i<(n - 2) && lista->prox!=NULL; i++){
    lista=lista->prox;
  }
  Lista *separada = lista->prox;
  lista->prox = NULL;
  return separada;
}


Lista *remove_elementos(Lista *l, int n){
  Lista *aux = NULL, *ptr = l;
  int i = 0;
  for(i=0; i<n && ptr!=NULL; i++){
    aux = ptr;
    ptr=ptr->prox;
    free(aux);
  }

  return ptr;
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

  printf("44. Desenvolva uma função que, dados uma lista simplesmente encadeada e um número inteiro positivo"
         "n, remova da lista seus n primeiros nós e retorne a lista resultante. Caso n seja maior do que o"
         "tamanho da lista, todos os seus nós devem ser removidos e a lista resultante deve ser uma lista vazia."
         "Essa função deve possuir o seguinte protótipo:\n\n"
         "\tLista *remove_elementos (Lista *l, int n);\n\n");

  printf("\tlista -> ");
  imprimir(lista);

  lista = remove_elementos(lista, 4);
  printf("\tlista att -> ");
  imprimir(lista);
  liberar(&lista);
  return 0;
}
