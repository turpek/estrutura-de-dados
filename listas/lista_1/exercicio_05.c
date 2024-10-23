/*
 *5. Escrever uma função que recebe como entrada uma lista encadeada circular de inteiros e retorne a quantidade de elementos da lista.
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct clist {
  int num;
  struct clist *prox;
} CLista;


void liberar(CLista **lista){
  if(*lista == NULL)
    return;

  CLista *aux, *p = *lista;
  do{
    aux = p;
    p = p->prox;
    free(aux);
  }while(p != *lista);

  *lista = NULL;
}


CLista *nova_lista(void){
  CLista *nova = NULL;
  return nova;
}


CLista *novo_elemento(int num){
  CLista *novo = (CLista*) malloc(sizeof(CLista));
  if(novo == NULL){
    printf("Não foi possível alocar memória, tente novamente!\n");
    return NULL;
  }

  novo->num = num;
  novo->prox = novo;

  return novo;
}

/* inserir_inicio espera que *lista aponte para o final da lista */
CLista *inserir(CLista *lista, int num){
  CLista *novo = novo_elemento(num);
  
  if(lista == NULL){
    return novo;
  }
  else if(novo != NULL){
    novo->prox = lista->prox;
    lista->prox = novo;
  }

  return lista;
}


/* imprimir espera que *lista aponte para o final da lista */
void imprimir(CLista *lista){

  if(lista == NULL)
    return;

  CLista *inicio = lista->prox;
  CLista *aux = inicio;
  do{
    printf("%d ", aux->num);
    aux = aux->prox;
  }while(aux != inicio);
  printf("\n");
}

int len(CLista *lista){
  if(lista == NULL)
    return 0;

  int count = 0;
  CLista *aux = lista;
  do{
    count += 1;
    aux = aux->prox;
  }
  while(aux != lista);

  return count;
}


int main(){

  CLista *lista = nova_lista();
  lista = inserir(lista, 6);
  lista = inserir(lista, 5);
  lista = inserir(lista, 3);
  lista = inserir(lista, 2);
  lista = inserir(lista, 1);
  printf("A Lista encadeada circular tem %d elementos!\n", len(lista));
  liberar(&lista);

  return 0;
}
