/*
 * 53. Considere uma lista encadeada de inteiros. Implemente uma função para
 * retornar o número de nós da lista que possuem um número primo armazenado.
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

int eh_primo(int number){
  if(number < 2){
    return 0;
  }

  int i, count = 2;
  for(i=2; i<=(number/2); i++){
    if(number % i == 0){
      count += 1;
    }
  }
  return count == 2;
}


int count_primo(Lista *lista){
  int count = 0;
  while(lista != NULL){
    if(eh_primo(lista->num)){
      count += 1;
    }
    lista = lista->prox;
  }
  return count;
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
  lista = inserir_no_final(lista, 9);
  lista = inserir_no_final(lista, 10);
  lista = inserir_no_final(lista, 11);
  lista = inserir_no_final(lista, 12);
  lista = inserir_no_final(lista, 13);

  printf("53. Considere uma lista encadeada de inteiros. Implemente uma função para "
         "retornar o número de nós da lista que possuem um número primo armazenado.\n\n");
  printf("\tlista           -> ");
  imprimir(lista);
  printf("\tnúmero de primos -> %d\n\n", count_primo(lista));
  liberar(&lista);
  return 0;
}
