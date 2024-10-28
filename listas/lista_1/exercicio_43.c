/*
 * 43. Considerando uma lista de números inteiros, implemente uma função que receba como parâmetro
 * uma lista encadeada e um valor inteiro positivo n e divida a lista em duas, de tal forma que a segunda
 * lista comece a partir do enésimo elemento da lista original. Essa função deve obedecer ao protótipo:
 * Lista *separa (Lista *l, int n);
 * A função deve retornar um ponteiro para a segunda subdivisão da lista original, enquanto l deve
 * continuar apontando para o primeiro elemento da primeira subdivisão da lista.
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

  printf("43. Considerando uma lista de números inteiros, implemente uma função que receba como parâmetro"
         "uma lista encadeada e um valor inteiro positivo n e divida a lista em duas, de tal forma que a segunda"
         "lista comece a partir do enésimo elemento da lista original. Essa função deve obedecer ao protótipo:\n"
         "\n\tLista *separa (Lista *l, int n);\n\n"
         "A função deve retornar um ponteiro para a segunda subdivisão da lista original, enquanto l deve"
         "continuar apontando para o primeiro elemento da primeira subdivisão da lista.\n\n");
  printf("\tlista -> ");
  imprimir(lista);
  Lista *lista2 = separa(&lista, 4);
  printf("\tlista parte_1 -> ");
  imprimir(lista);
  printf("\tlista parte_2 -> ");
  imprimir(lista2);
  liberar(&lista);
  liberar(&lista2);
  return 0;
}
