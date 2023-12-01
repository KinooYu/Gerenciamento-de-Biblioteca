#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define TAMANHO_TITULO 50
#define TAMANHO_AUTOR 50

typedef struct {
    char titulo[TAMANHO_TITULO];
    char autor[TAMANHO_AUTOR];
    int emprestado;
    int ativo;  // Adicionado o campo 'ativo'
    int codigo;
} Livro;

Livro livros[MAX_LIVROS];

void menu();
void cadastrarLivros();
void listarLivros();
void deletarLivros();
void listarLivrosDelet();
void lerString(char *string, int tamanho);

int main() {
    menu();
    return 0;
}

void menu() {
    int op;
    char input[256];

    do {
        system("clear"); //Esse para quem estiver no linux
        printf("\n1 - Cadastrar Livro \n2 - Emprestar Livro \n3 - Devolver Livro ");
        printf("\n4 - Listar Livros \n5 - Excluir Livro \n0 - Sair\n");
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
            case 4:
                listarLivros();
                break;
            case 5:
                deletarLivros();
                break;
        }

    } while (op != 0);
}

void lerString(char *string, int tamanho) {
    scanf("%49[^\n]s", string);
}

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

    printf("Livros cadastrados com sucesso. Pressione enter para voltar ao menu.");
    getchar();  // Aguarda um enter antes de retornar ao menu
    fflush(stdin);
}

void listarLivros() {
    system("clear"); //Esse para quem estiver no linux
    printf("\n LISTA DE LIVROS\n");
    for (int i = 0; i < MAX_LIVROS; ++i) {
        if (livros[i].ativo == 1) {
            // Verificando se o livro está ativo
            printf("Código: %d\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("\n-----------------------\n");
        }
    }
    printf("Pressione enter para voltar");
    getchar();  // Aguarda um enter antes de retornar ao menu
}

void listarLivrosDelet() {
    printf("\n LISTA DE LIVROS\n");
    for (int i = 0; i < MAX_LIVROS; ++i) {
        if (livros[i].ativo == 1) {
            printf("Código: %d\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("\n-----------------------\n");
        }
    }
}

void deletarLivros() {
    int codigo;
    listarLivrosDelet();
    printf("\nQual o código do livro a ser removido: ");
    scanf("%d", &codigo);

    if (codigo >= 1 && codigo <= MAX_LIVROS) {
        printf("Livro de código %d excluído com sucesso\n", codigo);
        --codigo;
        livros[codigo].ativo = 0;
    } else {
        printf("Código inválido. Livro não encontrado.\n");
    }

    getchar();  // Aguarda um enter antes de retornar ao menu
}
