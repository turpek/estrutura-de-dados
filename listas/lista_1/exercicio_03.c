/*
 *3. Escreva uma função que procure um elemento n na lista simplesmente encadeada circular e retorne 1 (TRUE) caso ele esteja presente e 0 (FALSE) caso contrário.
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
CLista *inserir_inicio(CLista *lista, int num){
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

int buscar(CLista *lista, int num){
  if(lista == NULL)
    return 0;

  CLista *aux = lista;
  do{
    if(aux->num == num)
      return 1;
    aux = aux->prox;
  }while(aux != lista);

  return 0;
}

int main(){

  CLista *lista = nova_lista();
  lista = inserir_inicio(lista, 6);
  lista = inserir_inicio(lista, 5);
  lista = inserir_inicio(lista, 3);
  lista = inserir_inicio(lista, 2);
  lista = inserir_inicio(lista, 1);

  int num = 4;
  imprimir(lista);
  printf("Considere 1==True e 0==False\n\n");
  printf("O elemento %d esta contido na lista? %d\n", num, buscar(lista, num));
  num = 6;
  printf("O elemento %d esta contido na lista? %d\n", num, buscar(lista, num));
  liberar(&lista);

  return 0;
}


