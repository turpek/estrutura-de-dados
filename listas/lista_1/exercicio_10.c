/*
 * 10. Implemente uma função que crie uma cópia de uma lista encadeada. O protótipo da função deve ser dado por:
 *  
 *    Lista* copia (Lista* l);
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

int igual(Lista* l1, Lista* l2){
  Lista *aux1, *aux2;
  for(aux1=l1, aux2=l2; aux1 != NULL && aux2 != NULL; aux1=aux1->prox, aux2=aux2->prox){
    if(aux1->num != aux2->num){
      return 0;
    }
  }

  // So serão iguais se ambos forem NULL, caso contrario as listas são diferentes!
  if(aux1 == aux2){
    return 1;
  }

  return 0;
}


Lista* copia(Lista* l){
  Lista *aux, *nova = nova_lista();
  for(aux=l; aux!=NULL; aux=aux->prox){
    nova = inserir_final(nova, aux->num);
  }

  return nova;
}


int main(){

  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);

  Lista *lista_cp = copia(lista);

  printf("lista -> ");
  imprimir(lista);
  printf("copia -> ");
  imprimir(lista_cp);
  liberar(&lista);
  liberar(&lista_cp);

   return 0;
}
