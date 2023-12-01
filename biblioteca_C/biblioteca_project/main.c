#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_USUARIOS 50
#define TAMANHO_TITULO 100
#define TAMANHO_AUTOR 50
#define TAMANHO_NOME 50
#define TAMANHO_CPF 14

typedef struct {
  char nome[TAMANHO_NOME];
  char cpf[TAMANHO_CPF];
  int codigo_de_usuario;
  int usuario_ativo;
} Usuario;

typedef struct {
  char titulo[TAMANHO_TITULO];
  char autor[TAMANHO_AUTOR];
  int emprestado;
  int ativo;
  int codigo;
} Livro;

Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];

void menu();
void cadastrarLivros();
void listarLivros();
void deletarLivros();
void listarLivrosSymple();
void emprestarLivros();
void devolverLivros();
void listarLivrosEmprestados();
void lerString(char *string, int tamanho);
void cadastrarUsuario();
void listarUsuario();

int main() {
  menu();
  return 0;
}

void menu() {
  int op;
  char input[256];

  do {
    system("clear"); // Esse para quem estiver no linux
    printf("\n1 - Cadastrar Livro \n2 - Emprestar Livro \n3 - Devolver Livro ");
    printf("\n4 - Listar Livros \n5 - Listar Livros Emprestados \n6 - Excluir "
           "Livro \n7 - Cadastrar usuário \n8 - Listar usuários \n0 - Sair\n");
    printf("Selecione uma opção: ");

    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &op) != 1) {
      // Tratamento de erro se a leitura falhar
      printf("Opção inválida. Tente novamente.\n");
      continue;
    }

    switch (op) {
    case 1:
      cadastrarLivros();
      break;
    case 2:
      emprestarLivros();
      break;
    case 3:
      devolverLivros();
      break;
    case 4:
      listarLivros();
      break;
    case 5:
      listarLivrosEmprestados();
      break;
    case 6:
      deletarLivros();
      break;
    case 7:
      cadastrarUsuario();
      break;
    case 8:
      listarUsuario();
      break;
    }

  } while (op != 0);
}

void lerString(char *string, int tamanho) { scanf("%49[^\n]s", string); }

void cadastrarLivros() {
  char titulo[TAMANHO_TITULO];
  char autor[TAMANHO_AUTOR];
  int totalLivros;

  printf("--------------------\n");
  printf("Quantos livros você quer cadastrar?  ");
  scanf("%d", &totalLivros);
  getchar();
  fflush(stdin);

  for (int i = 0; i < totalLivros && i < MAX_LIVROS; i++) {
    printf("--------------------\n");
    printf("Digite o título do livro: ");
    lerString(titulo, TAMANHO_TITULO);
    getchar();
    fflush(stdin);

    printf("Digite o autor do livro: ");
    lerString(autor, TAMANHO_AUTOR);
    getchar();
    fflush(stdin);

    for (int j = 0; j < MAX_LIVROS; ++j) {
      if (livros[j].ativo == 0) {
        Livro *livroAtual = &livros[j];
        strcpy(livroAtual->titulo, titulo);
        strcpy(livroAtual->autor, autor);
        livroAtual->ativo = 1;
        livroAtual->emprestado = 0;
        livroAtual->codigo = j + 1;
        break;
      }
    }
  }

  printf(
      "Livros cadastrados com sucesso. Pressione enter para voltar ao menu.");
  getchar(); // Aguarda um enter antes de retornar ao menu
  fflush(stdin);
}

void listarLivros() {
  system("clear"); // Esse para quem estiver no linux
  printf("\n LISTA DE LIVROS\n");
  for (int i = 0; i < MAX_LIVROS; ++i) {
    if (livros[i].ativo == 1) {
      // Verificando se o livro está ativo
      printf("Código: %d\n", livros[i].codigo);
      printf("Titulo: %s\n", livros[i].titulo);
      printf("Autor: %s\n", livros[i].autor);
      if (livros[i].emprestado == 1) {
        printf("Status: Emprestado");
      } else {
        printf("Status: Disponivel");
      }
      printf("\n-----------------------\n");
    }
  }
  printf("Pressione enter para voltar");
  getchar(); // Aguarda um enter antes de retornar ao menu
}

void listarLivrosSymple() {
  printf("\n LISTA DE LIVROS\n");
  for (int i = 0; i < MAX_LIVROS; ++i) {
    if (livros[i].ativo == 1) {
      printf("Código: %d\n", livros[i].codigo);
      printf("Titulo: %s\n", livros[i].titulo);
      printf("Autor: %s\n", livros[i].autor);
      if (livros[i].emprestado == 1) {
        printf("Status: Emprestado");
      } else {
        printf("Status: Disponivel");
      }
      printf("\n-----------------------\n");
    }
  }
}

void deletarLivros() {
  int codigo;
  listarLivrosSymple();
  printf("\nQual o código do livro a ser removido: \n");
  scanf("%d", &codigo);

  if (codigo >= 0 || livros[codigo].emprestado == 1) {
    printf("Codigo inexistente ou Livro emprestado");
  } else {
    printf("Livro de código %d excluído com sucesso\n", codigo);
    --codigo;
    livros[codigo].ativo = 0;
    printf("Pressione enter para voltar");
  }

  getchar(); // Aguarda um enter antes de retornar ao menu
}

void emprestarLivros() {
  int codigoDesejado;
  listarLivrosSymple();
  printf("Digite o codigo do livro que deseja emprestar: ");
  scanf("%d", &codigoDesejado);
  getchar(); // Aguarda um enter antes de retornar ao menu
  fflush(stdin);

  // Procura pelo livro com o código desejado
  for (int i = 0; i < MAX_LIVROS; ++i) {
    if (livros[i].codigo == codigoDesejado) {
      // Verifica se o livro não está emprestado
      if (livros[i].emprestado == 0) {
        printf("Livro emprestado com sucesso!\n");
        livros[i].emprestado = 1; // Marca o livro como emprestado
      } else {
        printf("Livro ja emprestado!\n");
      }

      break; // Sai do loop, pois o livro foi encontrado
    }
  }
  printf("Pressione enter para voltar");
  getchar(); // Aguarda um enter antes de retornar ao menu
  fflush(stdin);
}

void devolverLivros() {
  int codigo;
  printf("\nQual o código do livro a ser devolvido: ");
  scanf("%d", &codigo);

  --codigo;

  if (codigo >= 0 && livros[codigo].emprestado == 1) {
    printf("Livro de código %d devolvido com sucesso\n", livros[codigo].codigo);
    livros[codigo].emprestado = 0;
  } else {
    printf("Este livro não foi emprestado ainda ou código inválido.\n");
  }

  printf("Pressione enter para voltar");
  getchar(); // Aguarda um enter antes de retornar ao menu
}

void listarLivrosEmprestados() {
  system("clear"); // Esse para quem estiver no linux
  printf("\n LISTA DE LIVROS EMPRESTADOS\n");
  for (int i = 0; i < MAX_LIVROS; ++i) {
    if (livros[i].emprestado == 1) {
      // Verificando se o livro está ativo
      printf("Código: %d\n", livros[i].codigo);
      printf("Titulo: %s\n", livros[i].titulo);
      printf("Autor: %s\n", livros[i].autor);
      printf("\n-----------------------\n");
    }
  }
  printf("Pressione enter para voltar");
  getchar(); // Aguarda um enter antes de retornar ao menu
  fflush(stdin);
}

void cadastrarUsuario() {
  char nome[TAMANHO_NOME];
  char cpf[TAMANHO_CPF];
  int total_para_cadastrar = 0;

  printf("--------------------\n");
  printf("Quantos usuários você quer cadastrar? ");
  scanf("%d", &total_para_cadastrar);
  getchar();
  fflush(stdin);
  printf("\n CADASTRO DO USUÁRIO\n");

  for (int i = 0; i < total_para_cadastrar && i < MAX_USUARIOS; i++) {
    printf("--------------------\n");
    printf("Qual o nome do usuário: ");
    lerString(nome, TAMANHO_NOME);
    getchar();
    fflush(stdin);

    printf("Digite o CPF do usuário com os caracteres especiais: ");
    lerString(cpf, TAMANHO_CPF);
    getchar();
    fflush(stdin);
    for (int j = 0; j < MAX_USUARIOS; j++) {
      if (usuarios[j].usuario_ativo == 0) {
        Usuario *usuario_atual = &usuarios[j];
        strcpy(usuario_atual->nome, nome);
        strcpy(usuario_atual->cpf, cpf);
        usuario_atual->usuario_ativo = 1;
        usuario_atual->codigo_de_usuario = j + 1;
        break;
      }
    }
  }
  printf("Cadastro dos usuários feito com sucesso!\nPressione enter para "
         "voltar ao menu.");
  getchar();
  fflush(stdin);
}

void listarUsuario() {
  system("clear");
  printf("\n LISTA DE USUÁRIOS\n");
  for (int i = 0; i < MAX_USUARIOS; i++) {
    if (usuarios[i].usuario_ativo == 1) {
      printf("Código do usuário: %d\n", usuarios[i].codigo_de_usuario);
      printf("CPF: %s\n", usuarios[i].cpf);
      printf("Nome: %s\n", usuarios[i].nome);
      printf("--------------------\n");
    }
  }
  printf("Pressione enter para voltar");
  getchar();
}
