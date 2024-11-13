/*
 * 35. Considerando uma lista de números inteiros, implemente uma função que receba como parâmetro
 * uma lista encadeada e um valor inteiro n e divida a lista em duas, de tal forma que a segunda lista
 * comece no primeiro nó logo após a primeira ocorrência de n na lista original. Essa função deve
 * obedecer ao protótipo:
 *
 *      Lista *divide (Lista *l, int n);
 *
 * A função deve retornar um ponteiro para a segunda subdivisão da lista original, enquanto l deve
 * continuar apontando para o primeiro elemento da primeira subdivisão da lista. Se o elemento de valor n
 * não for encontrado na lista, deve retornar NULL e manter a lista l inalterada.
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


Lista *dividir(Lista *lista, int n){
  int i;
  for(i=0; i<n; i++, lista=lista->prox){
    if(lista->prox == NULL){
      return NULL;
    }
    else if(lista->num == n){
      break;
    }
  }

  Lista *nova = lista->prox;
  lista->prox = NULL;

  return nova;
}

int main(){

  Lista *lista = nova_lista();
  lista = inserir_no_final(lista, 1);
  lista = inserir_no_final(lista, 2);
  lista = inserir_no_final(lista, 3);
  lista = inserir_no_final(lista, 4);
  lista = inserir_no_final(lista, 5);
  lista = inserir_no_final(lista, 6);
  lista = inserir_no_final(lista, 7);
  lista = inserir_no_final(lista, 8);

  printf("35. Considerando uma lista de números inteiros, implemente "
         "uma função que receba como parâmetro uma lista encadeada e um "
         "valor inteiro n e divida a lista em duas, de tal forma que a "
         "segunda lista comece no primeiro nó logo após a primeira ocorrência "
         "de n na lista original. Essa função deve obedecer ao protótipo:\n\n"
         "\tLista *divide (Lista *l, int n);\n"
         "A função deve retornar um ponteiro para a segunda subdivisão da lista "
         "original, enquanto l deve continuar apontando para o primeiro elemento "
         "da primeira subdivisão da lista. Se o elemento de valor n não for "
         "encontrado na lista, deve retornar NULL e manter a lista l inalterada.\n");
  printf("\n\tlista    -> ");
  imprimir(lista);
  printf("\n\tdividida -> ");
  Lista *div = dividir(lista, 4);
  imprimir(div);
  liberar(&lista);
  liberar(&div);
  return 0;
}
