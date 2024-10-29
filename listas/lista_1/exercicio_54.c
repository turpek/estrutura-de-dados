/*
 * 54. Escreva uma função em C que, dada uma lista l qualquer, retorne, numa lista
 * de saída, os elementos ímpares e os elementos pares da lista l, na ordem em que
 * os elementos aparecem em l. Ao final da execução desta função, a lista resultante
 * terá todos os elementos da lista l (primeiro os ímpares, depois os pares, na ordem
 * em que eles aparecem em l), e a lista l continuará contendo os seus elementos. O
 * protótipo da função é o seguinte: TLista* lparimpar (TLista *l).
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list {
  int num;
  struct list *prox;
} TLista;


void liberar(TLista **lista){
  TLista *aux, *p = *lista;
  while(p != NULL){
    aux = p;
    p = p->prox;
    free(aux);
  }
  *lista = NULL;
}


TLista *inicializa(void){
  return NULL;
}


TLista *novo_elemento(int numero){
  TLista *novo = (TLista*) malloc(sizeof(TLista));
  if(novo == NULL){
    printf("Não foi possível alocar memória, tente novamente!\n");
    return NULL;
  }

  novo->prox = NULL;
  novo->num = numero;
  return novo;
}


TLista *inserir_no_final(TLista *lista, int num){
  TLista *novo = novo_elemento(num);
  if(lista == NULL){
    return novo;
  }
  else if(novo == NULL){
    return lista;
  }
  TLista *aux = lista;
  while(aux-> prox != NULL){
    aux = aux->prox;
  }
  aux->prox = novo;

  return lista;
}


void imprimir(TLista *lista){
  TLista *aux = lista;
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


int count_primo(TLista *lista){
  int count = 0;
  while(lista != NULL){
    if(eh_primo(lista->num)){
      count += 1;
    }
    lista = lista->prox;
  }
  return count;
}


// Busca o ponteiro para o ultimo elemento impar na lista
TLista *busca_impar(TLista *lista){
  if(lista == NULL){
    return lista;
  }
  while(lista->prox != NULL && lista->prox->num % 2 != 0){
    lista = lista->prox;
  }
  return lista;
}

// Busc o ponteiro para o ultimo elemento par na lista
TLista *busca_par(TLista *lista){
  if(lista == NULL){
    return lista;
  }
  while(lista->prox != NULL){
    lista = lista->prox;
  }
  return lista;
}

TLista *inserir_parimpar(TLista *lista, int num){
  TLista *aux = NULL;

  TLista *novo = novo_elemento(num);
  if(lista == NULL){
    return novo;
  }
  else if(num % 2 == 0){
    aux = busca_par(lista);
  }
  else{
    aux = busca_impar(lista);
  }

  novo->prox = aux->prox;
  aux->prox = novo;

  return lista;
}

TLista *lparimpar(TLista *l){
  TLista *nova = inicializa();
  while(l != NULL){
    nova = inserir_parimpar(nova, l->num);
    l = l->prox;
  }
  return nova;
}


int main(){

  TLista *lista = inicializa();
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

  printf("54. Escreva uma função em C que, dada uma lista l qualquer, retorne, numa "
         "lista de saída, os elementos ímpares e os elementos pares da lista l, na "
         "ordem em que os elementos aparecem em l. Ao final da execução desta função, "
         "a lista resultante terá todos os elementos da lista l (primeiro os ímpares, "
         "depois os pares, na ordem em que eles aparecem em l), e a lista l continuará "
         "contendo os seus elementos. O protótipo da função é o seguinte:\n\n"
         "\tTLista* lparimpar (TLista *l).\n\n");
  printf("\tlista           -> ");
  imprimir(lista);

  TLista *impar_par = lparimpar(lista);
  printf("\tlista impar-par -> ");
  imprimir(impar_par);
  liberar(&lista);
  liberar(&impar_par);
  return 0;
}
