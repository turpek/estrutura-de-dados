#include <stdio.h>
#include <stdlib.h>

struct clista{
  int info;
  struct clista *ant;
  struct clista *prox;
};

typedef struct clista CLista;


CLista *inicializa(){
  return NULL;
}


CLista *novo_elemento(int info){
  CLista *novo = (CLista *)malloc(sizeof(CLista));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return NULL;
  }

  novo->info = info;
  novo->ant = novo;
  novo->prox = novo;

  return novo;
}


CLista *inserir(CLista *lista, int info){
  CLista *novo = novo_elemento(info);
  if(lista == NULL){
    return novo;
  }
  else if(novo == NULL){
    return lista;
  }

  CLista *left = lista->ant;

  novo->prox = lista;
  lista->ant = novo;

  left->prox = novo;
  novo->ant = left;

  return novo;
}


void liberar(CLista **lista){
  if(*lista == NULL){
    return;
  }

  CLista *aux, *ptr = *lista, *inicio = *lista;
  do{
    aux = ptr;
    ptr = ptr->prox;
    free(aux);
  }while(ptr != inicio);

  *lista = inicializa();
}


void imprimir(CLista *lista){
  if(lista == NULL){
    return;
  }

  CLista *aux = lista;
  do{
    printf("%d ", aux->info);
    aux = aux->prox;
  }while(aux != lista);
  printf("\n");
}


int main(){
  CLista *lista = inicializa();
  lista = inserir(lista, 7);
  lista = inserir(lista, 6);
  lista = inserir(lista, 5);
  lista = inserir(lista, 4);
  lista = inserir(lista, 3);
  lista = inserir(lista, 2);
  lista = inserir(lista, 1);
  imprimir(lista);
  liberar(&lista);

  return 1;
}
