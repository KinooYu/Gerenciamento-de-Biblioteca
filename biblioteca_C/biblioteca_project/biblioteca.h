#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

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
    int verificar_emprestimo;
} Usuario;

typedef struct {
    char titulo[TAMANHO_TITULO];
    char autor[TAMANHO_AUTOR];
    int emprestado;
    int ativo;
    int codigo;
} Livro;

extern Livro livros[MAX_LIVROS];
extern Usuario usuarios[MAX_USUARIOS];

void menu();
void cadastrarLivros();
void listarLivros();
void deletarLivros();
void listarLivrosSymple();
void emprestarLivros();
void devolverLivros();
void listarLivrosEmprestados();
void cadastrarUsuario();
void listarUsuario();

#endif
