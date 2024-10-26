/*
 * 23. Implementar uma função que recebe como entrada um vetor com n
 * números inteiros e insere os números em uma lista encadeada. 
 * 
 * Lista *addvetor(Lista *l, int *vetor, int n);
 
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


Lista *inserir_final(Lista *lista, int num){
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


Lista *addvetor(Lista *lista, int *vetor, int n){
  int i;
  for(i=0; i <n; i++){
    lista = inserir_final(lista, vetor[i]);
  }
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


int main(){

  Lista *lista = nova_lista();
  int vetor[] = {1, 3, 4, 6, 7, 8};
  int N = 6;

  printf("23. Implementar uma função que recebe como entrada um vetor com n "
         "números inteiros e insere os números em uma lista encadeada.\n");
  Lista *addvetor(Lista *l, int *vetor, int n);

  int i;
  printf("\nlista   -> ");
  for(i=0; i < 6; i++){
    printf("%d ", vetor[i]);
  }
  lista =  addvetor(lista, vetor, N - 2);
  printf("\nlista 4 -> ");
  imprimir(lista);
  liberar(&lista);
  return 0;
}
