#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIVROS 50

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
    int emprestado;
    int ativo;
} Livro;

Livro livros[MAX_LIVROS];

void menu();
void cadastrar();
void listarLivros();

int main(){

    menu();
    return 0;
}

void menu(){
    int op;
    do {
        system("clear"); //Esse para quem estiver no linux
        //system(cls) Para quem estiver no windows
        printf("\n1 - Cadastrar Livro \n2 - Emprestar Livro \n3 - Devolver Livro ");
        printf("\n4 - Listar Livros \n5 - Excluir Livro \n0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &op);
        getchar(); // Limpar o buffer de entrada

        switch (op) {
            case 1:
                cadastrar();
                break;
            case 4:
                listarLivros();
                break;
        }

    } while (op != 0);
}

void cadastrar(){
    char titulo[50];
    char autor[50];
    int op;
    do {
        system("clear"); //Esse para quem estiver no linux
        //system(cls) Para quem estiver no windows
        printf("\nTitulo: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = '\0';  // Remover o caractere de nova linha

        printf("\nAutor: ");
        fgets(autor, sizeof(autor), stdin);
        autor[strcspn(autor, "\n")] = '\0';  // Remover o caractere de nova linha

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
    //system(cls) Para quem estiver no windows
    printf("\n LISTA DE LIVROS\n");
    for (int i = 0; i < MAX_LIVROS; ++i) {
        if(livros[i].ativo==1){
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("\n-----------------------\n");
        }
    }
    getchar(); // Limpar o buffer de entrada
}