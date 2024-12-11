#include <stdio.h>
#include <stdlib.h>


typedef struct tree {
  int info;
  struct tree *left;
  struct tree *right;
} Tree;


Tree *create_tree(void){
  return NULL;
}



Tree *rt;

int empty_tree(Tree *r){
  if(r == NULL)
    return 1;
  return 0;
}


Tree *stree(Tree *root, Tree *r, int num){
  if(!r){
    r = (Tree *)malloc(sizeof(Tree));
    if(r == NULL){
      printf("Erro: não foi possível alocar mémoria");
      return root;
    }

    r->left = NULL;
    r->right = NULL;
    r->info = num;

    if(root == NULL){
      return r;
    }
    if(num < root->info){
      root->left = r;
    }
    else{
      root->right = r;
    }

    return r;
  }

  if(num < root->info){
    stree(r, r->left, num);
  }
  else{
    stree(r, r->right, num);
  }
}


Tree *liberar(Tree *root){
  if(root != NULL){
    liberar(root->left);
    liberar(root->right);
    free(root);
  }

  return NULL;
}

void inorder(Tree *root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  printf("%d ", root->info);
  inorder(root->right);
}


Tree *inserir(Tree *rt, int num){
  if(rt == NULL){
    rt = stree(rt, rt, num);
  }
  else{
    stree(rt, rt, num);
  }

  return rt;
}


void max(Tree *root){
  if(root == NULL){
    return;
  }

  if(root->right == NULL){
    printf("Maior número: %d\n", root->info);
  }
  else{
    max(root->right);
  }
}


void min(Tree *root){
  if(root == NULL){
    return;
  }

  if(root->left == NULL){
    printf("Menor número: %d\n", root->info);
  }
  else{
    min(root->left);
  }
}


int count_node(Tree *root){
    if(root == NULL){
      return 0;
    }
    else{
      int count_left = count_node(root->left);
      int count_right = count_node(root->right);
      return count_left + count_right + 1;
    }
}

int sum(Tree *root){
  if(root == NULL){
    return 0;
  }
  else{
    int sum_left = sum(root->left);
    int sum_right = sum(root->right);

    return sum_left + sum_right + root->info;
  }
}


void show_children(Tree *root, int num){
  if(root == NULL){
    return;
  }
  else if(root->info == num){
    if(root->left)
      printf("Left  -> %d\n", root->left->info);
    if(root->right)
      printf("Right -> %d\n", root->right->info);
    return;
  }

  if(num < root->info){
    show_children(root->left, num);
  }
  else{
    show_children(root->right, num);
  }
}

int main(){
  rt = create_tree();

  // Valores para testar as funções
  
  /*
  rt = inserir(rt, 3);
  rt = inserir(rt, 1);
  rt = inserir(rt, 2);
  rt = inserir(rt, 5);
  rt = inserir(rt, 4);
  rt = inserir(rt, 6);
  rt = inserir(rt, 7);
  */


  int opcao = 0, num = 0;

  do{
    printf("\n\n**************************************************************\n\n");
    printf("\t1 - Inserir um número.\n");
    printf("\t2 - Mostrar todos os números.\n");
    printf("\t3 - Mostrar o maior número.\n");
    printf("\t4 - Mostrar o menor número.\n");
    printf("\t5 - Mostrar a quantidade de nós da árvore.\n");
    printf("\t6 - Mostrar a soma dos nós.\n");
    printf("\t7 - Mostrar os filhos de um nó.\n");
    printf("\t8 - Sair.\n");
    printf("\n\nDigite a opção: ");
    scanf("%d", &opcao);
    printf("\n\n**************************************************************\n\n");

    switch(opcao){
      case 1:
        printf("Digite o valor: ");
        scanf("%d", &num);
        rt = inserir(rt, num);
        break;
      case 2:
        inorder(rt);
        break;
      case 3:
        max(rt);
        break;
      case 4:
        min(rt);
        break;
      case 5:
        printf("Quantidade de nós: %d\n", count_node(rt));
        break;
      case 6:
        printf("Soma dos nós: %d\n", sum(rt));
        break;
      case 7:
        printf("Digite o valor do nó: ");
        scanf("%d", &num);
        show_children(rt, num);
        break;
      case 8:
        printf("Saindo...\n");
        rt = liberar(rt);
    }
  }while(opcao != 8);

  return 0;
}
