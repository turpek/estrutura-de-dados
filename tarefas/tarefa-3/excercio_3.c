#include <stdio.h>
#include <stdlib.h>


struct no{
  int info;
  struct no *prox;
};

typedef struct no Lista;


// Função usada para desalocar todos os elementos da lista.
void liberar_lista(Lista **lista){
  Lista *aux, *p = *lista;
  while(p != NULL){
    aux = p;
    p = p->prox;
    free(aux);
  }
  *lista = NULL;
}


Lista *nova_lista(){
  Lista *lista = NULL;
  return lista;
}


// Função que aloca memória para um novo elemento, além disso
// o mesmo já inicializa o campo info com o seu valor.
Lista *novo_elemento(int info){
  Lista *novo = (Lista *) malloc(sizeof(Lista));
  if(novo == NULL){
    printf("não foi possível alocar memória, tente novamente...\n");
    return NULL;
  }
  novo->info = info;
  novo->prox = NULL;

  return novo;
}

// Função que busca a posição com base no valor info, na qual um novo elemento
// será inserido na Lista.
Lista *pesquisa_posicao(Lista *lista, int info){
  Lista *anterior = NULL;
  Lista *p = lista;
  
  while((p != NULL) && (info > p->info)){
    anterior = p;
    p = p->prox;
  }

  return anterior;
}


Lista *inserir(Lista *lista, int info){
  Lista *novo = novo_elemento(info);
  
  if(novo != NULL){
    Lista *anterior = pesquisa_posicao(lista, info);
    
    // Se anterior for NULL, então o elemento será inserido no começo da lista
    if(anterior == NULL){
      novo->prox = lista;
      return novo;
    }

    novo->prox = anterior->prox;
    anterior->prox = novo;
  }

  return lista;
}


void listar(Lista *lista){
  Lista *aux = lista;

  // Verificação para impedir a quebra de linha caso aux == NULL.
  if(aux == NULL)
    return;

  while(aux != NULL){
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
}


// Função usada para testar o programa.
void testar_programa(void){
  Lista *lista = nova_lista();
  lista = inserir(lista, 4);
  lista = inserir(lista, 2);
  lista = inserir(lista, 3);
  lista = inserir(lista, 2);
  lista = inserir(lista, 1);
  lista = inserir(lista, 5);
  lista = inserir(lista, 9);
  lista = inserir(lista, 7);
  lista = inserir(lista, 0);
  listar(lista);
  printf("Removendo todos os elementos da lista!\n");
  liberar_lista(&lista);
}


int main(){
  testar_programa();
  return 0;
}
