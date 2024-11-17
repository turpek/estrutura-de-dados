/*
 *
 * 6. Escreva um programa que leia uma sequência de números inteiros positivos enquanto for diferente
 * de zero. Para cada valor lido, se o número for par adicionar em uma Fila Par, caso contrário adicionar
 * em uma Fila Impar. Após finalizar a entrada de dados, retirar um elemento de cada fila
 * alternadamente (iniciando pela Fila Impar) até que ambas as filas estejam vazias
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct no_fila{
  int dado;
  struct no_fila *prox;
}NoFila;


typedef struct fila_{
  NoFila *front;
  NoFila *rear;
}Fila;


void inicializa_fila(Fila *fila){
  fila->front = NULL;
  fila->rear = NULL;
}


void insert(Fila *fila, const int dado){
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if(novo != NULL){
      novo->prox =  NULL;
      novo->dado = dado;

      if(fila->front == NULL){
        fila->front = novo;
      }
      else{
        fila->rear->prox = novo;
      }
      fila->rear = novo;
    }
}

int empty(Fila fila){
  if(fila.front == NULL){
    return 1;
  }
  return 0;
}


int remover(Fila *fila){
  if(empty(*fila)){
    printf("Fila vazia!\n");
    return -1;
  }

  NoFila *aux = fila->front;
  int dado = aux->dado;
  fila->front = aux->prox;
  free(aux);
  return dado;
}

void liberar(Fila *fila){
  NoFila *p = fila->front, *aux;
  while(p != NULL){
    aux = p;
    p = p->prox;
    free(aux);
  }
  fila->front = NULL;
  fila->rear = NULL;
}

void mostrar(Fila fila){
  NoFila *p = fila.front;
  while(p != NULL){
    printf("%d ", p->dado);
    p = p->prox;
  }
  printf("\n");
}

void separador(){

  int num = -1;
  Fila impar, par;
  inicializa_fila(&impar);
  inicializa_fila(&par);
  while(num != 0){
    printf("Digite um número inteiro (0 para encerrar!): ");
    scanf("%d", &num);
    if(num > 0 && num%2 == 0 ){
      insert(&par, num);
    }
    else if(num > 0 && num%2 != 0){
      insert(&impar, num);
    }
  }

  int empty_i, empty_p;
  printf("\nresultado -> ");
  do{
    empty_i = empty(impar);
    empty_p = empty(par);
    if(empty_i == 0){
      printf("%d ", remover(&impar));
    }
    if(empty_p == 0){
      printf("%d ", remover(&par));
    }
  }while((empty_i + empty_p) != 2);
  printf("\n");
}

int main(){
  printf("6. Escreva um programa que leia uma sequência de números inteiros positivos enquanto for diferente "
         "de zero. Para cada valor lido, se o número for par adicionar em uma Fila Par, caso contrário adicionar "
         "em uma Fila Impar. Após finalizar a entrada de dados, retirar um elemento de cada fila "
         "alternadamente (iniciando pela Fila Impar) até que ambas as filas estejam vazias.\n\n");
  separador();
  return 0;
}
