/*
 * Escrever uma função que receba como parâmetro a cabeça de uma lista encadeada de 
 * inteiros e retorne o último valor armazenado na lista ou -1 caso a lista esteja vazia. 
 * Considere a estrutura abaixo.
 *
 *  struct lista {
 *    int num;
 *    struct lista *prox;
 *  };
 *  typedef struct lista Lista
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


int ultimo(Lista *lista){
  if(lista == NULL){
    return 0;
  }
  while(lista->prox!=NULL){
    lista = lista->prox;
  }
  return lista->num;
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 9);
  lista = inserir_final(lista, -3);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, 6);
 
  imprimir(lista);
  printf("O último elemento da lista é: %d\n", ultimo(lista));
  liberar(&lista);

  return 0;
}
