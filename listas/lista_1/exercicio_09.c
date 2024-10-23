/*
 * Implemente uma função que verifique se duas listas encadeadas são iguais. Duas listas são consideradas iguais se têm a mesma sequência de elementos. O protótipo da função deve ser dado por:
 *
 *  int igual (Lista* l1, Lista* l2);
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

int main(){

  Lista *lista1 = nova_lista();
  lista1 = inserir_final(lista1, 1);
  lista1 = inserir_final(lista1, 2);
  lista1 = inserir_final(lista1, 3);
  lista1 = inserir_final(lista1, 4);

  Lista *lista2 = nova_lista();
  lista2 = inserir_final(lista2, 1);
  lista2 = inserir_final(lista2, 2);
  lista2 = inserir_final(lista2, 3);
  lista2 = inserir_final(lista2, 4);
  

  printf("Lista1 é igual a lista 2? %d\n\n", igual(lista1, lista2));

  printf("Lista1 -> ");
  imprimir(lista1);
  printf("Lista2 -> ");
  imprimir(lista2);
  liberar(&lista1);
  liberar(&lista2);

  printf("\n\n**************************************\n\n");
  lista1 = nova_lista();
  lista1 = inserir_final(lista1, 1);
  lista1 = inserir_final(lista1, 2);
  lista1 = inserir_final(lista1, 3);
  lista1 = inserir_final(lista1, 4);

  lista2 = nova_lista();
  lista2 = inserir_final(lista2, 1);
  lista2 = inserir_final(lista2, 2);
  lista2 = inserir_final(lista2, 3);
  lista2 = inserir_final(lista2, 5);
  

  printf("Lista1 é igual a lista 2? %d\n\n", igual(lista1, lista2));

  printf("Lista1 -> ");
  imprimir(lista1);
  printf("Lista2 -> ");
  imprimir(lista2);
  liberar(&lista1);
  liberar(&lista2);

  return 0;
}
