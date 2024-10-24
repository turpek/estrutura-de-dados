/*
 * 16. Escreva uma função para executar cada uma das seguintes operações:
 *
 *  a) Incluir um elemento no final de uma lista.
 *  b) Concatenar duas listas.
 *  c) Liberar todos os nós de uma lista.
 *  d) Inverter uma lista de modo que o último elemento se torne o primeiro, e assim por diante.
 *  e) Eliminar o último elemento de uma lista.
 *  f) Eliminar o e-nésimo elemento de uma lista.
 *  g) Combinar duas listas ordenadas numa única lista ordenada.
 *  h) Formar uma lista contendo a união dos elementos de duas listas.
 *  i) Formar uma lista contendo a intersecção dos elementos de duas listas.
 *  j) Inserir um elemento depois do e-nésimo elemento de uma lista.
 *  k) Eliminar o segundo elemento de uma lista.
 *  l) Colocar os elementos de uma lista em ordem ascendente.
 *  m) Retornar a soma dos números inteiros de uma lista.
 *  n) Retornar a média dos números inteiros de uma lista.
 *  o) Retornar o número de elementos numa lista.
 *  p) Retornar a quantidade de elementos da lista que possuem valor ímpar.
 *  q) Retornar a quantidade de elementos da lista que possuem valor par.
 *  r) Deslocar um nó n posições à frente numa lista.
 *  s) Criar uma cópia de uma lista.
 *  t) Retornar o maior valor de uma lista de inteiros.
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

Lista *inserir_inicio(Lista *lista, int num){
  Lista *novo = novo_elemento(num);
  if(novo == NULL){
    return lista;
  }
  else if(lista == NULL){
    return novo;
  }
  
  novo->prox = lista;
  return novo;
}

Lista *inserir_final(Lista *lista, int num){
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


Lista *inserir_meio(Lista *lista, int num, int enesimo){
  if(enesimo == 0){
    return inserir_inicio(lista, num);
  }

  Lista *novo = novo_elemento(num);
  
  if(novo == NULL){
    return lista;
  }
  else if(lista == NULL){
    return novo;
  }

  int count = 0;
  Lista *aux = lista, *ptr = lista;
  while((ptr!= NULL) && (count < enesimo)){
    count += 1;
    aux = ptr;
    ptr = ptr->prox;
  }

  novo->prox = aux->prox;
  aux->prox = novo;

  return lista;
}

Lista *inserir_ordenado(Lista *lista, int num){
  Lista *novo = novo_elemento(num);
  if(novo == NULL){
    return lista;
  }
  else if(lista == NULL){
    return novo;
  }



  Lista *aux = NULL, *ptr = lista;
  while(ptr != NULL && (ptr->num < num)){
    aux = ptr;
    ptr = ptr->prox;
  }

  if(aux == NULL){
    novo->prox = lista;
    return novo;
  }

  novo->prox = aux->prox;
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

// Função que retorna 1 caso lista contenha valor e 0 caso contrario
int buscar(Lista *lista, int valor){
  Lista *aux = lista;
  while(aux != NULL){
    if(aux->num == valor)
      return 1;
    aux = aux->prox;
  }

  return 0;
}

Lista *concat(Lista *lista1, Lista *lista2){
  Lista *aux = lista1;
  while(aux->prox!=NULL){
    aux = aux->prox;
  }
  aux->prox = lista2;
  return lista1;
}


void ordenar(Lista *lista){
  if(lista == NULL){
    return;
  }

  Lista *aux1, *aux2;
  for(aux1=lista; aux1!=NULL; aux1=aux1->prox){
    for(aux2=aux1->prox; aux2!=NULL; aux2=aux2->prox){
      if(aux1->num > aux2->num){
        int aux = aux1->num;
        aux1->num = aux2->num;
        aux2->num = aux;
      }
    }
  }
}

Lista *merge_ordenado(Lista *lista1, Lista *lista2){
  Lista *lista = nova_lista();

  Lista *aux;
  for(aux=lista1; aux!=NULL; aux=aux->prox){
    lista = inserir_ordenado(lista, aux->num);
  }
  for(aux=lista2; aux!=NULL; aux=aux->prox){
    lista = inserir_ordenado(lista, aux->num);
  }
  return lista;
}

Lista *inverter(Lista *lista){

  Lista *prev=NULL, *ptr=lista, *next=NULL;
  while(ptr!=NULL){
    next = ptr->prox;

    ptr->prox = prev;

    prev = ptr;
    ptr = next;
  }

  return prev;
}


Lista *remove_ultimo(Lista *lista){
  Lista *aux = NULL, *ptr = lista;
  while(ptr->prox != NULL){
    aux = ptr;
    ptr = ptr->prox;
  }
  free(ptr);
  if(aux != NULL){
    aux->prox = NULL;
    return lista;
  }

  return NULL;
}


Lista *remove_meio(Lista *lista, int enesimo){
  int count = 0;
  Lista *aux = NULL, *next = NULL, *ptr = lista;
  while((ptr != NULL) && (count < enesimo)){
    aux = ptr;
    ptr = ptr->prox;
    count += 1;
  }
  if(ptr != NULL){
    next = ptr->prox;
    free(ptr);

    if(aux == NULL){
      return next;
    }
  }
  if(aux != NULL){
    aux->prox = next;
    return lista;
  }

  return NULL;
}

Lista *remove_segundo(Lista *lista){
  if(lista == NULL){
    return NULL;
  }
  else if(lista->prox == NULL){
    return lista;
  }

  Lista *ptr = lista->prox;
  lista->prox = ptr->prox;
  free(ptr);

  return lista;
}

Lista *uniao(Lista *lista1, Lista *lista2){
  Lista *aux, *lista = nova_lista();
  for(aux=lista1; aux!=NULL; aux=aux->prox){
    if(buscar(lista2, aux->num)){
      lista = inserir_ordenado(lista, aux->num);
    }
  }

  return lista;
}


Lista *interseccao(Lista *lista1, Lista *lista2){
  Lista *aux, *lista = nova_lista();
  for(aux=lista1; aux!=NULL; aux=aux->prox){
    if(!buscar(lista2, aux->num)){
      lista = inserir_ordenado(lista, aux->num);
    }
  }
  for(aux=lista2; aux!=NULL; aux=aux->prox){
    if(!buscar(lista1, aux->num)){
      lista = inserir_ordenado(lista, aux->num);
    }
  }

  return lista;
}

int len(Lista *lista){
  int count = 0;
  while(lista!=NULL){
    count += 1;
    lista = lista->prox;
  }
  return count;
}


int len_impar(Lista *lista){
  int count = 0;
  while(lista!=NULL){
    if(lista->num%2 != 0){
      count += 1;
    }
    lista = lista->prox;
  }
  return count;
}


int len_par(Lista *lista){
  int count = 0;
  while(lista!=NULL){
    if(lista->num%2 == 0){
      count += 1;
    }
    lista = lista->prox;
  }
  return count;
}

int soma(Lista *lista){
  int sum = 0;
  while(lista!=NULL){
    sum += lista->num;
    lista = lista->prox;
  }
  return sum;
}

float media(Lista *lista){
  return (float)soma(lista) / len(lista);
}

int maior(Lista *lista){
  if(lista == NULL){
    return -1;
  }

  int maior_n = lista->num;
  while(lista != NULL){
    if(maior_n < lista->num){
      maior_n = lista->num;
    }
    lista = lista->prox;
  }

  return maior_n;
}

// Desloca o nó *lista->prox "n" posições para a "direita",
// se n for menor ou igual ao número de elementos restantes na lista
Lista *deslocar_no(Lista *lista, int n){
  if(lista == NULL){
    return NULL;
  }

  int count = 0;
  Lista *ptr = lista->prox, *aux = lista;  
  while(aux != NULL && count < (n + 1)){
    count += 1;
    aux = aux->prox;
  }
  if(aux != NULL){
    lista->prox = ptr->prox;
    ptr->prox = aux->prox;
    aux->prox = ptr;
  }

  return lista;
}

Lista *copiar(Lista *lista){
  Lista *nova = nova_lista();
  while(lista != NULL){
    nova = inserir_final(nova, lista->num);
    lista = lista->prox;
  }
  return nova;
}
/* ========================================= */

void a(){

  Lista *lista = nova_lista();
  lista = inserir_inicio(lista, 4);
  lista = inserir_inicio(lista, 3);
  lista = inserir_inicio(lista, 2);
  lista = inserir_inicio(lista, 1);
  printf("a) Incluir um elemento no final de uma lista.\n");
  printf("\tlista original -> ");
  imprimir(lista);
  lista = inserir_final(lista, 5);
  printf("\tlista final    -> ");
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}

void b(){
  Lista *lista1 = nova_lista();
  lista1 = inserir_final(lista1, 1);
  lista1 = inserir_final(lista1, 2);
  lista1 = inserir_final(lista1, 3);
  lista1 = inserir_final(lista1, 4);


  Lista *lista2 = nova_lista();
  lista2 = inserir_final(lista2, 5);
  lista2 = inserir_final(lista2, 6);
  lista2 = inserir_final(lista2, 7);
  lista2 = inserir_final(lista2, 8);

  printf("b) Concatenar duas listas.\n");
  printf("\tlista 1 -> ");
  imprimir(lista1);
  printf("\tlista 2 -> ");
  imprimir(lista2);

  Lista *lista = concat(lista1, lista2);
  printf("\tconcat  -> ");
  imprimir(lista);
  printf("\n");
  liberar(&lista);
}

void c(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);

  printf("c) Liberar todos os nós de uma lista.\n");
  printf("\tlista   -> ");
  imprimir(lista);
  printf("\taddress -> %p", lista);

  printf("\n\tliberando...\n");
  liberar(&lista);
  printf("\taddress -> %p\n\n", lista);
}


void d(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);

  printf("d) Inverter uma lista de modo que o último elemento se torne o primeiro, e assim por diante.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tinvertida -> ");
  lista = inverter(lista);
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}


void e(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);

  printf("e) Eliminar o último elemento de uma lista.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tresultado -> ");
  lista = remove_ultimo(lista);
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}

void f(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);

  printf("f) Eliminar o e-nésimo elemento de uma lista.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tresultado -> ");
  lista = remove_meio(lista, 3);
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}


void g(){

  Lista *lista1 = nova_lista();
  lista1 = inserir_ordenado(lista1, 6);
  lista1 = inserir_ordenado(lista1, 1);
  lista1 = inserir_ordenado(lista1, 5);
  lista1 = inserir_ordenado(lista1, 3);


  Lista *lista2 = nova_lista();
  lista2 = inserir_ordenado(lista2, 4);
  lista2 = inserir_ordenado(lista2, 7);
  lista2 = inserir_ordenado(lista2, 2);
  lista2 = inserir_ordenado(lista2, 8);


  printf("g) Combinar duas listas ordenadas numa única lista ordenada.\n");
  printf("\tlista 1     -> ");
  imprimir(lista1);
  printf("\tlista 2     -> ");
  imprimir(lista2);

  Lista *lista = merge_ordenado(lista1, lista2);
  printf("\tconcat_ord  -> ");
  imprimir(lista);
  printf("\n");
  liberar(&lista);
  liberar(&lista1);
  liberar(&lista2);
}

void h(){

  Lista *lista1 = nova_lista();
  lista1 = inserir_ordenado(lista1, 2);
  lista1 = inserir_ordenado(lista1, 1);
  lista1 = inserir_ordenado(lista1, 5);
  lista1 = inserir_ordenado(lista1, 3);


  Lista *lista2 = nova_lista();
  lista2 = inserir_ordenado(lista2, 4);
  lista2 = inserir_ordenado(lista2, 5);
  lista2 = inserir_ordenado(lista2, 2);
  lista2 = inserir_ordenado(lista2, 8);


  printf("h) Formar uma lista contendo a união dos elementos de duas listas.\n");
  printf("\tlista 1 -> ");
  imprimir(lista1);
  printf("\tlista 2 -> ");
  imprimir(lista2);

  Lista *lista = uniao(lista1, lista2);
  printf("\tuniao   -> ");
  imprimir(lista);
  printf("\n");
  liberar(&lista);
  liberar(&lista1);
  liberar(&lista2);
}


void i(){

  Lista *lista1 = nova_lista();
  lista1 = inserir_ordenado(lista1, 2);
  lista1 = inserir_ordenado(lista1, 1);
  lista1 = inserir_ordenado(lista1, 4);
  lista1 = inserir_ordenado(lista1, 3);


  Lista *lista2 = nova_lista();
  lista2 = inserir_ordenado(lista2, 4);
  lista2 = inserir_ordenado(lista2, 1);
  lista2 = inserir_ordenado(lista2, 2);
  lista2 = inserir_ordenado(lista2, 8);


  printf("i) Formar uma lista contendo a intersecção dos elementos de duas listas.\n");
  printf("\tlista 1 -> ");
  imprimir(lista1);
  printf("\tlista 2 -> ");
  imprimir(lista2);

  Lista *lista = interseccao(lista1, lista2);
  printf("\tuniao   -> ");
  imprimir(lista);
  printf("\n");
  liberar(&lista);
  liberar(&lista1);
  liberar(&lista2);
}


void j(){

  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 5);
  printf("j) Inserir um elemento depois do e-nésimo elemento de uma lista.\n");
  printf("\tlista original -> ");
  imprimir(lista);
  lista = inserir_meio(lista, 0, 3);
  printf("\tlista final    -> ");
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}

void k(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);

  printf("k) Eliminar o segundo elemento de uma lista.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tresultado -> ");
  lista = remove_segundo(lista);
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}


void l(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 1);

  printf("l) Colocar os elementos de uma lista em ordem ascendente.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tresultado -> ");
  ordenar(lista);
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}

void m(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 1);

  printf("m) Retornar a soma dos números inteiros de uma lista.\n");
  printf("\tlista -> ");
  imprimir(lista);
  printf("\tsoma  -> %d\n", soma(lista));
  printf("\n");

  liberar(&lista);
}


void n(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 1);

  printf("n) Retornar a média dos números inteiros de uma lista.\n");
  printf("\tlista -> ");
  imprimir(lista);
  printf("\tmedia -> %.2f\n", media(lista));
  printf("\n");

  liberar(&lista);
}


void o(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 1);

  printf("o) Retornar o número de elementos numa lista.\n");
  printf("\tlista -> ");
  imprimir(lista);
  printf("\tsize  -> %d\n", len(lista));
  printf("\n");

  liberar(&lista);
}

void p(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 1);

  printf("p) Retornar a quantidade de elementos da lista que possuem valor ímpar.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tsize_par  -> %d\n", len_impar(lista));
  printf("\n");

  liberar(&lista);
}


void q(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 1);

  printf("q) Retornar a quantidade de elementos da lista que possuem valor par.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tsize_par  -> %d\n", len_par(lista));
  printf("\n");

  liberar(&lista);
}


void r(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, 6);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 7);

  printf("r) Deslocar um nó n posições à frente numa lista.\n");
  printf("\tlista     -> ");
  imprimir(lista);
  printf("\tsize_par  -> ");
  deslocar_no(lista, 3);
  imprimir(lista);
  printf("\n");

  liberar(&lista);
}


void s(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 8);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 1);

  printf("s) Criar uma cópia de uma lista.\n");
  printf("\tlista -> ");
  imprimir(lista);
  Lista  *lista2 = copiar(lista);
  printf("\tcopia -> ");
  imprimir(lista2);
  printf("\n");

  liberar(&lista);
  liberar(&lista2);
}


void t(){
  Lista *lista = nova_lista();
  lista = inserir_final(lista, 1);
  lista = inserir_final(lista, 2);
  lista = inserir_final(lista, 3);
  lista = inserir_final(lista, 4);
  lista = inserir_final(lista, 9);
  lista = inserir_final(lista, 5);
  lista = inserir_final(lista, 6);
  lista = inserir_final(lista, 7);
  lista = inserir_final(lista, 7);

  printf("t) Retornar o maior valor de uma lista de inteiros.\n");
  printf("\tlista -> ");
  imprimir(lista);
  printf("\tmaior -> %d\n", maior(lista));
  liberar(&lista);
}

int main(){

  a();
  b();
  c();
  d();
  e();
  f();
  g();
  h();
  i();
  j();
  k();
  l();
  m();
  n();
  o();
  p();
  q();
  r();
  s();
  t();

  return 0;
}
