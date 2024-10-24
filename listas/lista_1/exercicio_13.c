/*
 * Desenvolver um programa que insere 10 números inteiros em uma lista inicialmente vazia. Em seguida, o programa deverá excluir os números ímpares existentes na lista deixando apenas os números pares.
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

Lista *inserir_final(Lista *lista, int numero){
  Lista *novo = novo_elemento(numero);
  if(novo == NULL){
    return lista;
  }
  else if(lista == NULL){
    return novo;
  }

  Lista *aux, *p = lista;
  while(p != NULL){
    aux = p;
    p = p->prox;
  }

  aux->prox = novo;
  return lista;
}

void imprimir(Lista *lista){
  while(lista != NULL){
    printf("%d ", lista->num);
    lista = lista->prox;
  }
  printf("\n");
}


/* Função que remove o nó *lista e retorna o proximo nó, 
 * está função não refaz o ligamento da lista, o mesmo
 * deve ser implementado logo apos a chamada da mesma.
 * */
Lista *remove_no(Lista *lista){
  if(lista == NULL)
    return NULL;
  Lista *prox = lista->prox;
  free(lista);
  return prox;
}

Lista *remove_impar(Lista *lista){
  Lista *aux = NULL, *ptr = lista;
  while(ptr!=NULL){
    if(ptr->num % 2 != 0){
      ptr = remove_no(ptr);
      if(aux == NULL){
        lista = ptr;
      }
      else{
        aux->prox = ptr;
      }
    }
    else{
      aux = ptr;
      ptr = ptr->prox;
    }
  }

  return lista;
}


int main(){

  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, 6);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 9);
  lista = inserir_final(lista, 10);
 
  imprimir(lista);
  printf("Removendo números ímpares!\n");
  lista = remove_impar(lista);
  imprimir(lista);
  liberar(&lista);

  return 0;
}
