#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct list {
   char nome[40];
   struct list *prev;
   struct list *next;
};

typedef struct list Lista;


// Cria uma Lista vazia
Lista *nova_lista(){
  Lista *nova = NULL;
  return nova;
}

Lista *novo_elemento(Lista *lista, char *nome){
  Lista *elemento = (Lista*) malloc(sizeof(Lista));

  if(elemento == NULL){
    printf("Nao foi possivel alocar memoria, tente novamente!\n");
    return NULL;
  }

  elemento->prev = NULL;
  elemento->next = NULL;
  strcpy(elemento->nome, nome);
  return elemento;
}

Lista *inserir_inicio(Lista *lista, char *nome){
  Lista *novo = novo_elemento(lista, nome);
  if(novo == NULL){
    return lista;
  }
  else if(lista != NULL){
    novo->next = lista;
    lista->prev = novo;
  }

  return novo;
}

void liberar(Lista **lista){
  Lista *aux, *p = *lista;
  while(p!=NULL){
    aux = p;
    p = p->next;
    free(aux);
  }
  *lista = NULL;
}

// Mostra todos os nomes da lista
void imprimir(Lista *lista){
  Lista *aux = lista;

  printf("Lista: ");
  while(aux != NULL){
    printf("%s, ", aux->nome);
    aux = aux->next;
  }
}

// Menu de "ajuda" que será usada na função navegar
void ajuda(void){
  printf("\n\n");
  printf("*************************************************************\n");
  printf("* Ajuda: '>' para avancar | '<' para voltar | 'q' para sair *\n");
  printf("*************************************************************\n\n");
}


// Função que passa para o proximo elemento da lista
Lista *avancar(Lista *lista){
  if(lista->next == NULL){
    printf("Fim de Lista\n");
    return lista;
  }

  lista = lista->next;
  printf("Nome: %s\n", lista->nome);
  return lista;
}

// Função que volta para o elemento anterior na lista
Lista *voltar(Lista *lista){
  if(lista->prev == NULL){
    printf("Início de Lista\n");
    return lista;
  }
  lista = lista->prev;
  printf("Nome: %s\n", lista->nome);
  return lista;
}

void navegar(Lista *ptr){
  if(ptr == NULL){
    printf("Lista vazia!\n");
    return;
  }

  ajuda();
  char ch;
  printf("start->%s\n", ptr->nome);

  do{
    printf("\nDigite: ");
    ch = getchar();
    getchar();

    switch(ch){
      case '>':
        ptr = avancar(ptr);
        break;
      case '<':
        ptr = voltar(ptr);
        break;
      case 'q':
        printf("Saindo...\n");
        break;
      default:
        printf("valor invalido!\n\n");
        ajuda();
        break;
    }
  }while(ch != 'q');
}

int main(){

  Lista *lista = nova_lista();

  // Use esse ponteiro para alterar o ponto de partida da função navegar
  Lista *ponto_de_partida = NULL;

  lista = inserir_inicio(lista, "Maria");
  lista = inserir_inicio(lista, "João");
  lista = inserir_inicio(lista, "Ana");
  lista = inserir_inicio(lista, "Delfina");
  ponto_de_partida = lista;  // Delfina, será o ponto de partida
  lista = inserir_inicio(lista, "Pedro");
  lista = inserir_inicio(lista, "Paula");

  imprimir(lista);
  navegar(ponto_de_partida);
  liberar(&lista);
  return 0;
}
