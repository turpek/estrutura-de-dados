/*
 * 40. Escreva um programa que armazena n valores da sequência de Fibonacci em
 * fuma lista simplesmente encadeada. O primeiro elemento da lista deve ser o
 * número 0 e o segundo o número 1.
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
  while(lista->prox != NULL){
    if(lista->num == num){
      return left;
    }
    left = lista;
    lista = lista->prox;
  }

  return NULL;
}


Lista *termos_de_fibonacci(int n){
  Lista *lista = nova_lista();

  lista = inserir_no_final(lista, 0);
  if(n == 1){
    return lista;
  }

  lista = inserir_no_final(lista, 1);
  if(n == 2){
    return lista;
  }

  int i, a=0, b=1;
  for(i=0; i<(n - 2); i++){
    int soma = a + b;
    inserir_no_final(lista, soma);
    a = b;
    b = soma;
  }

  return lista;
}

int main(){
  printf("40. Escreva um programa que armazena n valores da sequência de Fibonacci em uma lista simplesmente"
         "encadeada. O primeiro elemento da lista deve ser o número 0 e o segundo o número 1.\n");
  printf("\n\tFibonacci 12  -> ");
  Lista *lista = termos_de_fibonacci(12);
  imprimir(lista);
  liberar(&lista);
  return 0;
}
