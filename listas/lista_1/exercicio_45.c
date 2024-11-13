/*
 * 45. Implemente uma função em C que receba como parâmetro um vetor com n números inteiros e
 * constrói uma lista simplesmente encadeada armazenando os elementos do vetor na lista. Por
 * exemplo, se receber como parâmetro o vetor v[5] = {1, 2, 3, 4, 5}, a função deve retornar uma lista
 * cujo primeiro elemento tem a informação 1, o segundo a informação 2, e assim por diante. Se o vetor
 * tiver zero elementos, a função deve retornar uma lista vazia. O protótipo da função é dado por:
 * Lista *constroi (int n, int *v);
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


Lista *constroi(int n, int *v){
  if(n == 0){
    return NULL;
  }

  int i;
  Lista *lista = nova_lista();
  for(i=0; i<n; i++){
    lista = inserir_no_final(lista, v[i]);
  }

  return lista;
}

int main(){

  int vetor[6] = {1, 2, 3, 4, 5, 6};
  printf("45. Implemente uma função em C que receba como parâmetro um vetor com n números inteiros e"
         "constrói uma lista simplesmente encadeada armazenando os elementos do vetor na lista. Por"
         "exemplo, se receber como parâmetro o vetor v[5] = {1, 2, 3, 4, 5}, a função deve retornar uma lista"
         "cujo primeiro elemento tem a informação 1, o segundo a informação 2, e assim por diante. Se o vetor"
         "tiver zero elementos, a função deve retornar uma lista vazia. O protótipo da função é dado por:\n\n"
         "\tLista *constroi (int n, int *v);\n\n");

  Lista *lista = constroi(6, vetor);
  printf("\tlista -> ");
  imprimir(lista);
  liberar(&lista);
  return 0;
}
