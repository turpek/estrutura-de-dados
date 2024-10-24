/*
 * 11. Escrever funções que recebem como entrada uma lista encadeada de inteiros e retornam:
 *  
 *    a) O maior elemento da lista;
 *    b) O menor elemento da lista;
 *    c) O primeiro elemento da lista;
 *    d) O endereço do primeiro elemento da lista;
 *    e) O último elemento da lista;
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


Lista *memoria_primeiro(Lista *lista){
  return lista;
}


Lista *memoria_ultimo(Lista *lista){
  while(lista->prox!=NULL){
    lista = lista->prox;
  }
  return lista;
}

Lista *memoria_maior(Lista *lista){

  if(lista == NULL)
    return NULL;

  int num_maior = lista->num;
  Lista *aux, *mem_maior;
  for(aux=lista; aux!=NULL; aux=aux->prox){
    if(num_maior < aux->num){
      num_maior = aux->num;
      mem_maior = aux;
    }
  }
  return mem_maior;
}


int maior(Lista *lista){
  Lista *aux = memoria_maior(lista);
  if(aux==NULL)
    return 0;
  return aux->num;
}

int menor(Lista *lista){
  if(lista == NULL)
    return 0;

  int num_menor = lista->num;
  Lista *aux;
  for(aux=lista; aux!=NULL; aux=aux->prox){
    if(num_menor > aux->num)
      num_menor = aux->num;
  }

  return num_menor;
}

int primeiro(Lista *lista){
  
  if(lista == NULL)
    return 0;
  return lista->num;
}


int ultimo(Lista *lista){
  if(lista == NULL)
    return 0;

  while(lista->prox!=NULL)
    lista = lista->prox;
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
  printf("a) O maior elemento da lista -> ");
  printf("%d\n", maior(lista));
  printf("b) O menor elemento da lista -> ");
  printf("%d\n", menor(lista));
  printf("c) O primeiro elemento da lista -> ");
  printf("%d\n", primeiro(lista));
  printf("d) O endereço do primeiro elemento da lista -> ");
  printf("%p\n", memoria_primeiro(lista));
  printf("e) O último elemento da lista -> ");
  printf("%d\n", ultimo(lista));
  printf("f) O endereço do último elemento da lista -> ");
  printf("%d\n", ultimo(lista));
  printf("g) O endereço do maior elemento da lista -> ");
  printf("%d\n", ultimo(lista));
  liberar(&lista);

  return 0;
}
