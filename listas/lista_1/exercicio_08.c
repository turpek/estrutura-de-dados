/*
 * 8. Construa um método que recebe uma lista encadeada de números inteiros e retorna uma lista sem repetições, ou seja, uma lista onde cada número apareça apenas uma vez. Exemplo:
 *
 *  12 5 -7 8 5 9 12 1 8 -> 12 5 -7 8 9 1
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
}

int buscar(Lista *lista, int num){
  Lista *aux = lista;
  while(aux != NULL){
    if(aux->num == num)
      return 1;
    aux = aux->prox;
  }
  return 0;
}

/* retorna uma nova lista, portanto, crie um novo ponteiro para recebe-la! */
Lista *sem_duplicatas(Lista *lista){
  Lista *aux, *nova = nova_lista();
  for(aux=lista; aux != NULL; aux=aux->prox){
    if(!buscar(nova, aux->num)){
      printf("Add %d\n", aux->num);
      nova = inserir_final(nova, aux->num);
    }
  }
  return nova;
}


int main(){

  Lista *lista = nova_lista();
  lista = inserir_final(lista, 12);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, -7);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, 9);
  lista = inserir_final(lista, 12);
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 8);
  Lista *lista_sem = sem_duplicatas(lista);
  

  // 12 5 -7 8 5 9 12 1 8 -> 12 5 -7 8 9 1
  imprimir(lista);
  printf(" -> ");
  imprimir(lista_sem);
  printf("\n");
  liberar(&lista);
  liberar(&lista_sem);

  return 0;
}
