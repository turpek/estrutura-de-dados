#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no_cliente{
  int senha;
  char cpf[20];
  char *nome_completo;
  int idade;
  char sexo;

  struct no_cliente *prox;
}NoCliente;


typedef struct fila_cliente{
  int restantes;
  NoCliente *primeiro;
  NoCliente *ultimo;
}FilaCliente;


void nova_fila_clientes(FilaCliente *clientes){
  clientes->restantes = 0;
  clientes->primeiro = NULL;
  clientes->ultimo = NULL;
}

int gravar_nome(NoCliente *cliente, const char *nome_completo){
  int tamanho = strlen(nome_completo) + 1;
  cliente->nome_completo = (char *)malloc(tamanho * sizeof(char));
  if(cliente->nome_completo == NULL){
    printf("Não foi possível alocar memória para gravar o nome, tente novamente!\n");
    return 0;
  }
  strcpy(cliente->nome_completo, nome_completo);
  return 1;
}


int insert(
    FilaCliente *clientes, 
    const char cpf[20], //Deve estar no formato 111.111.111-11
    const char *nome_completo, 
    int idade, 
    const char sexo){
  
  if(sexo != 'F' && sexo != 'M'){
    printf("Erro: o sexo do cliente deve ser \"F\" ou \"M\"!\n");
    return 0;
  }
  else if(idade < 0){
    printf("Erro: a idade do cliente deve ser maior que 0!\n");
    return 0;
  }

  NoCliente *novo_cliente = (NoCliente *)malloc(sizeof(NoCliente));
  if(novo_cliente == NULL){
    printf("Erro: não foi possível alocar memória, tente novamente!\n");
    return 0;
  }

  // Salvando as informações do cliente
  static int contador_de_senha = 1;
  novo_cliente->senha = contador_de_senha;
  strcpy(novo_cliente->cpf, cpf);
  if(!gravar_nome(novo_cliente, nome_completo)){
    return 0;
  }
  novo_cliente->idade = idade;
  novo_cliente->sexo = sexo;
  novo_cliente->prox = NULL;

  // Alterando o estado da fila de clientes
  if(clientes->primeiro == NULL){
    clientes->primeiro = novo_cliente;
  }
  else{
    clientes->ultimo->prox = novo_cliente;
  }
  clientes->ultimo = novo_cliente;

  contador_de_senha++;
  clientes->restantes++;
  return 1;
}

int empty(FilaCliente *clientes){
  if(clientes->primeiro == NULL)
    return 1;
  return 0;
}


// Remove o cliente da fila, retornando o mesmo para o atendimento
NoCliente *remover(FilaCliente *clientes){
  if(empty(clientes)){
    printf("Erro: fila vazia!\n");
    return NULL;
  }

  NoCliente *cliente = clientes->primeiro;
  clientes->primeiro = cliente->prox;
  if(clientes->primeiro == NULL){
    clientes->ultimo = NULL;
  }

  clientes->restantes--;
  return cliente;
}


// Desaloca a memória do cliente
void liberar_cliente(NoCliente *cliente){
  if(cliente != NULL){
    free(cliente->nome_completo);
    free(cliente);
  }
}


// Remove todos os clientes da fila
void liberar(FilaCliente *clientes){
  while(!empty(clientes)){
    liberar_cliente(remover(clientes));
  }
}

void imprimir_cliente(NoCliente *cliente){
  printf("%-6d %-15s %-30s %-5d %c\n", 
      cliente->senha,
      cliente->cpf,
      cliente->nome_completo,
      cliente->idade,
      cliente->sexo);
}

void imprimir_clientes(FilaCliente *clientes){
  printf("%-6s %-15s %-30s %-5s Sexo\n", "Senha", "CPF", "Nome", "Idade");
  if(!empty(clientes)){
    NoCliente *cliente = clientes->primeiro;
    while(cliente != NULL){
      imprimir_cliente(cliente);
      cliente = cliente->prox;
    }
  }
  printf("\n");
}

void imprimir_primeiro_cliente(FilaCliente *clientes){
  printf("%-6s %-15s %-30s %-5s Sexo\n", "Senha", "CPF", "Nome", "Idade");
  if(!empty(clientes)){
    imprimir_cliente(clientes->primeiro);
  }
}


void imprimir_ultimo_cliente(FilaCliente *clientes){
  printf("%-6s %-15s %-30s %-5s Sexo\n", "Senha", "CPF", "Nome", "Idade");
  if(!empty(clientes)){
    imprimir_cliente(clientes->ultimo);
  }
}


void atendendo_cliente(FilaCliente *clientes){
  NoCliente *cliente = remover(clientes);
  if(cliente != NULL){
    printf("\nChamando o cliente com a senha %d para o atendimento.\n", cliente->senha);
    liberar_cliente(cliente);
  }
}


void tamanho_da_fila(FilaCliente *clientes){
  printf("Existe %d clientes na fila de espera\n", clientes->restantes);
}

// Função para remover o "\n" de uma string
void remove_br(char *string){
    string[strcspn(string, "\n")] = '\0';
}

void adicionar_cliente(FilaCliente *clientes){
  char cpf[20], nome_completo[100], sexo;
  int idade;

  do{
    printf("\n\tAdicionando os dados do cliente para à fila de espera:\n\n");
    printf("Digite o CPF: ");
    fgets(cpf, sizeof(cpf), stdin);
    remove_br(cpf);

    printf("Digite o nome_completo: ");
    fgets(nome_completo, sizeof(nome_completo), stdin);
    remove_br(nome_completo);
    
    printf("Digite a idade: ");
    scanf("%d", &idade);
    getchar();

    printf("Digite o sexo (F|M): ");
    scanf("%c", &sexo);
    getchar();
    
    
  }while(!insert(clientes, cpf, nome_completo, idade, sexo));
}

int main(){
  FilaCliente clientes;
  nova_fila_clientes(&clientes);

  int opcao;
  do{

    printf("\n\n********************************************************************\n\n");
    printf("\t1 - Adicionar cliente à fila de espera;\n");
    printf("\t2 - Autoriazar o atendimento do primeiro cliente a fila;\n");
    printf("\t3 - Listar o número de clientes na fila de espera;\n");
    printf("\t4 - Listar os dados de todos os clientes na fila de espera;\n");
    printf("\t5 - Listar as informações do primeiro cliente da fila;\n");
    printf("\t6 - Listar as informações do último cliente da fila;\n");
    printf("\t0 - Para sair;\n");
    printf("\n********************************************************************\n\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n\n");

    switch(opcao){
      case 1:
        adicionar_cliente(&clientes);
        break;
      case 2:
        atendendo_cliente(&clientes);
        break;
      case 3:
        tamanho_da_fila(&clientes);
        break;
      case 4:
        imprimir_clientes(&clientes);
        break;
      case 5:
        imprimir_primeiro_cliente(&clientes);
        break;
      case 6:
        imprimir_ultimo_cliente(&clientes);
        break;
      case 0:
        printf("Encerrando o espediente...\n");
        break;
      default:
        printf("Opção inválida, tente novamente!\n");
    }

  }while(opcao != 0);

  liberar(&clientes);
  return 0;
}
