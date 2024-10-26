/*
 * 33. Considere uma estrutura de lista encadeada que armazena valores reais. 
 * Implemente uma função em C que receba como entrada duas listas encadeadas l1 e l2, 
 * concatene a lista l2 no final de l1, conforme ilustra a figura abaixo: 
 *
 * A função deve retornar a lista resultante da concatenação, obedecendo ao protótipo: 
 *  
 *    Lista* concatena (Lista *l1, Lista *l2); 
 *
 * Observe que l1 e/ou l2 podem ser listas vazias.
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list {
  float  num;
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


Lista *novo_elemento(float numero){
  Lista *novo = (Lista*) malloc(sizeof(Lista));
  if(novo == NULL){
    printf("Não foi possível alocar memória, tente novamente!\n");
    return NULL;
  }

  novo->prox = NULL;
  novo->num = numero;
  return novo;
}


Lista *inserir(Lista *lista, float num){
  Lista *novo = novo_elemento(num);
  if(novo == NULL){
    return lista;
  }
  else if(lista == NULL){
    return novo;
  }

  Lista *aux = lista;
  while(aux->prox!=NULL){
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
    printf("%.2f ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}

Lista *concatena(Lista *lista1, Lista *lista2){
  if(lista2 == NULL){
    return lista1;
  }
  else if(lista1 == NULL){
    return lista2;
  }
  Lista *aux = lista1;
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  aux->prox = lista2;
  return lista1;
}

int main(){

  Lista *lista1 = nova_lista();
  lista1 = inserir(lista1, 6.4);
  lista1 = inserir(lista1, 5.2);
  lista1 = inserir(lista1, 3.9);
  lista1 = inserir(lista1, 2.7);

  Lista *lista2 = nova_lista();
  lista2 = inserir(lista2, 1);
  lista2 = inserir(lista2, 10.5);
  lista2 = inserir(lista2, 8.88);
  lista2 = inserir(lista2, 7.1);

  printf("22. Implementar uma função que retorna o endereço do último "
         "elemento. Se a lista estiver vazia, retornar NULL.\n");
  printf("lista1       -> ");
  imprimir(lista1);
  printf("lista2       -> ");
  imprimir(lista2);

  Lista *lista = concatena(lista1, lista2);
  printf("lista concat -> ");
  imprimir(lista);
  liberar(&lista);
  return 0;
}
