/*
 * 24. Faça um programa que receba 20 números inteiros e armazene os pares em uma lista simplesmente
 * encadeada não ordenada e os ímpares em uma segunda lista simplesmente encadeada e não ordenada.
 * Posteriormente, o programa deverá montar uma terceira lista, duplamente encadeada e ordenada de
 * forma crescente, com os números das duas listas anteriores. Para finalizar, o programa deve mostrar
 * todos os números da terceira lista na ordem crescente e decrescente.
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct list {
  int num;
  struct list *prox;
} Lista;


typedef struct dlist {
  int num;
  struct dlist *prox;
  struct dlist *ante;
} Dlista;


void liberar(Lista **lista){
  Lista *aux, *p = *lista;
  while(p != NULL){
    aux = p;
    p = p->prox;
    free(aux);
  }
  *lista = NULL;
}


void dliberar(Dlista **lista){
  Dlista *aux, *p = *lista;
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


Dlista *nova_dlista(void){
  Dlista *novo = NULL;
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

Dlista *novo_delemento(int numero){
  Dlista *novo = (Dlista*) malloc(sizeof(Dlista));
  if(novo == NULL){
    printf("Não foi possível alcoar memória, tente novamente\n");
    return NULL;
  }

  novo->ante = NULL;
  novo->prox = NULL;
  novo->num = numero;
  return novo;
}

Lista *inserir_final(Lista *lista, int num){
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

Dlista *buscar_dno(Dlista *lista, int num){
  Dlista *aux = NULL;
  while((lista != NULL) && (lista->num < num)){
    aux = lista;
    lista = lista->prox;
  }
  return aux;
}

Dlista *inserir_dordenada(Dlista *lista, int num){
  Dlista *novo = novo_delemento(num);
  if(lista == NULL){
    return novo;
  }
  else if(novo == NULL){
    return lista;
  }

  Dlista *ptr = buscar_dno(lista, num);

  // Colocar no inicio da dlista
  if(ptr == NULL){
    novo->prox = lista;
    lista->ante = novo;

    // O novo nó passa a ser a cabeça da lista então devemos retorna-lo
    return novo;
  }
  // Colocar no fim da dlista
  else if(ptr->prox == NULL){
    ptr->prox = novo;
    novo->ante = ptr;
  }
  // Colocar no meio da dlista
  else{
    Dlista *right = ptr->prox;

    novo->prox = ptr->prox;
    ptr->prox = novo;

    right->ante = novo;
    novo->ante = ptr;
  }
  
  return lista;
}


void imprimir(Lista *lista){
  if(lista == NULL){
    return;
  }

  Lista *aux = lista;
  while(aux != NULL){
    printf("%d ", aux->num);
    aux = aux->prox;
  }
  printf("\n");
}


void dimprimir(Dlista *lista){
  if(lista == NULL)
    return;

  while(lista != NULL){
    printf("%d ", lista->num);
    lista = lista->prox;
  }
  printf("\n");
}


void dimprimir_reversa(Dlista *lista){
  if(lista == NULL)
    return;

  while(lista->prox != NULL){
    lista = lista->prox;
  }
  while(lista != NULL){
    printf("%d ", lista->num);
    lista = lista->ante;
  }
  printf("\n");
}

Lista *pares(int *vetor, int n){
  Lista *lista = nova_lista();
  int i;
  for(i=0; i<20; i++){
    if(vetor[i]%2 == 0){
      lista = inserir_final(lista, vetor[i]);
    }
  }
  return lista;
}


Lista *impares(int *vetor, int n){
  Lista *lista = nova_lista();
  int i;
  for(i=0; i<20; i++){
    if(vetor[i]%2 != 0){
      lista = inserir_final(lista, vetor[i]);
    }
  }
  return lista;
}


// Copiamos os elementos de *source em *dest,
// se *dest for NULL, uma nova lista é criada
Dlista *sorted(Dlista *dest, Lista *source){
  if(dest == NULL){
    dest = nova_dlista();
  }
  while(source != NULL){
    dest = inserir_dordenada(dest, source->num);
    source = source->prox;
  }
  return dest;
}


int main(){

  int vetor[20] = {43, 17, 8, 92, 35, 54, 23, 71, 5, 60, 12, 89, 34, 27, 6, 40, 98, 19, 46, 3};

  printf("24. Faça um programa que receba 20 números inteiros e armazene os pares em uma lista simplesmente "
         "encadeada não ordenada e os ímpares em uma segunda lista simplesmente encadeada e não ordenada. "
         "Posteriormente, o programa deverá montar uma terceira lista, duplamente encadeada e ordenada de "
         "forma crescente, com os números das duas listas anteriores. Para finalizar, o programa deve mostrar "
         "todos os números da terceira lista na ordem crescente e decrescente.\n\n");

  printf("\tvetor   -> ");
  int i;
  for(i=0; i<20; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");

  Lista *lista_par = pares(vetor, 20);
  printf("\tpares   -> ");
  imprimir(lista_par);

  Lista *lista_impar = impares(vetor, 20);
  printf("\timpares -> ");
  imprimir(lista_impar);
  
  Dlista *dlista = sorted(NULL, lista_par);
  dlista = sorted(dlista, lista_impar);
  printf("\tdlista ordenada -> ");
  dimprimir(dlista);
  printf("\tdlista reversa  -> ");
  dimprimir_reversa(dlista);

  liberar(&lista_par);
  liberar(&lista_impar);
  dliberar(&dlista);
  return 0;
}
