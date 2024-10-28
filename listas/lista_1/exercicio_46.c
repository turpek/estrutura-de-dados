/*
 * 46. Desenvolva uma função em C que receba como parâmetro uma lista encadeada e um número inteiro
 * positivo n e remova da lista todos os nós que possuam valor igual a n. A função deverá retornar a
 * nova lista resultante.
 *
 *    Lista* RemoveValor(Lista *l, int n);
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

Lista *RemoveValor(Lista *lista, int n){
  if(lista == NULL){
    return NULL;
  }

  Lista *ptr = lista;
  while(ptr->prox != NULL){
    Lista *right = ptr->prox;

    if(right->num == n){
      ptr->prox = right->prox;
      free(right);
    }
    ptr = ptr->prox;
  }

  return lista;
}


int main(){

  Lista *lista = nova_lista();
  lista = inserir_no_final(lista, 1);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 4);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 6);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 8);

  printf("46. Desenvolva uma função em C que receba como parâmetro uma lista encadeada e um número inteiro"
         "positivo n e remova da lista todos os nós que possuam valor igual a n. A função deverá retornar a"
         "nova lista resultante.\n\n"
         "\tLista* RemoveValor(Lista *l, int n);\n\n");

  printf("\tlista    -> ");
  imprimir(lista);

  lista = RemoveValor(lista, 3);
  printf("\tremove 3 -> ");
  imprimir(lista);
  liberar(&lista);
  return 0;
}
