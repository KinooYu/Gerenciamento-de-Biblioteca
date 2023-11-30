#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIVROS 50

typedef struct {
    char titulo[50];
    char autor[50];
    int emprestado;
    int ativo;
} Livro;

Livro livros[MAX_LIVROS];

void menu();
void cadastrarLivros();
void listarLivros();
void deletarLivros();
void listarLivrosDelet();

int main(){

    menu();
    return 0;
}

void menu(){
    int op;
    do {
        system("clear"); //Esse para quem estiver no linux
        printf("\n1 - Cadastrar Livro \n2 - Emprestar Livro \n3 - Devolver Livro ");
        printf("\n4 - Listar Livros \n5 - Excluir Livro \n0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &op);
        getchar(); // Limpar o buffer de entrada

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

void cadastrarLivros(){
    char titulo[50];
    char autor[50];
    int op;
    do {
        system("clear"); //Esse para quem estiver no linux
        printf("\nTitulo: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = '\0';  // Remover o caractere de nova linha
        if (titulo[0] == '\0'){
            printf("O campo titulo não pode estar vazio ou conter espaço no seu inicio, voltando a tela inicial");
            return;
        }

        printf("\nAutor: ");
        fgets(autor, sizeof(autor), stdin);
        autor[strcspn(autor, "\n")] = '\0';  // Remover o caractere de nova linha
        if (autor[0] == '\0'){
            printf("O campo autor não pode estar vazio ou conter espaço no seu inicio, voltando a tela inicial");
            return;
        }

        printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d", &op);

        for (int i = 0; i < MAX_LIVROS; ++i) {
            if (livros[i].ativo == 0) {
                strcpy(livros[i].titulo, titulo);
                strcpy(livros[i].autor, autor);
                livros[i].ativo=1;
                break;
            }
        }

        // Limpar o buffer de entrada
        while (getchar() != '\n');

    } while (op != 0);
}

void listarLivros(){
    system("clear"); //Esse para quem estiver no linux
    printf("\n LISTA DE LIVROS\n");
    for (int i = 0; i < MAX_LIVROS; ++i) {
        if(livros[i].ativo==1){
            printf("Código: %d\n", i+1);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("\n-----------------------\n");
        }
    }
    printf("Pressione enter para voltar");
    getchar(); // Limpar o buffer de entrada
}

void listarLivrosDelet(){
    printf("\n LISTA DE LIVROS\n");
    for (int i = 0; i < MAX_LIVROS; ++i) {
        if(livros[i].ativo==1){
            printf("Código: %d\n", i+1);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("\n-----------------------\n");
        }
    }
}

void deletarLivros(){
    int codigo;
    listarLivrosDelet();
    printf("\n Qual o codigo do livro a ser removido: \n");
    scanf("%d", &codigo);
    printf("Livro de codigo: %d excluido com sucesso\n", codigo);
    --codigo;
    livros[codigo].ativo=0;
    getchar();
}