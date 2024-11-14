/*
 *
 * 6. Escreva um programa, usando uma Pilha, que inverte as letras de cada palavra de um texto terminado 
 * por ponto ('.') preservando a ordem das palavras. Por exemplo, dado o texto: HOJE ESTÁ CHOVENDO.
 * A saída deve ser: EJOH ÁTSE ODNEVOHC.
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pilha{
  char dado;
  struct _pilha *prox;
} Pilha;


Pilha *inicializa(){
  return NULL;
}


int empty(Pilha *pilha){
  if(pilha == NULL){
    return 1;
  }
  return 0;
}

void push(Pilha **pilha, const char ch){
  Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
  if(novo == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return;
  }

  novo->dado = ch;
  novo->prox = *pilha;
  *pilha = novo;
}

char pop(Pilha **pilha){
  if(empty(*pilha)){
    return '\0';
  }

  Pilha *aux = *pilha;
  char dado = aux->dado;
  *pilha = aux->prox;
  free(aux);
  return dado;
}


char top(Pilha *pilha){
  if(empty(pilha)){
    return '\0';
  }
  return pilha->dado;
}

//Devolve um ponteiro que retorna o texto quando encontra o '.'
char *tokens(const char *texto){
  int n = 0;
  const char *aux = texto;
  while(*aux != '\0'){
    if(*aux == '.'){
      char *texto_cpy = (char *)malloc((n + 1) * sizeof(char));
      strncpy(texto_cpy, texto, n);
      return texto_cpy;
    }
    n++;
    aux++;
  }
  return NULL;

}

char *inverte(Pilha **pilha, const char *texto){
  char *texto_tmp = tokens(texto);

  if(texto_tmp != NULL){
    int n = strlen(texto_tmp);
    char *texto_inv = (char *)malloc((n + 1) * sizeof(char));
    char *token = strtok(texto_tmp, ". ");

    char *aux = texto_inv;
    while(token != NULL){
      while(*token != '\0'){
        push(pilha, *token);
        token++;
      }
      while(!empty(*pilha)){
        *aux = pop(pilha);
        aux++;
      }
      *aux = ' ';
      token = strtok(NULL, " ");
      if(token != NULL){
        aux++;
      }
    }
    *aux = '\0';
    strcat(texto_inv, ".");
    return texto_inv;
  }

  return NULL;
}


int main(){

  Pilha *pilha = inicializa();
  char *texto = inverte(&pilha, "HOJE ESTA CHOVENDO.");

  if(texto != NULL){
    printf("6. Escreva um programa, usando uma Pilha, que inverte as letras de cada palavra de um texto terminado"
           "por ponto ('.') preservando a ordem das palavras. Por exemplo, dado o texto: HOJE ESTÁ CHOVENDO."
           "A saída deve ser: EJOH ÁTSE ODNEVOHC.\n\n");
    printf("\tSAIDA -> %s\n\n", texto);
    free(texto);
  }
  return 0;
}
