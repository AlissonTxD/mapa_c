#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTD_MAXIMA_DE_REGISTROS 20

struct Livro{
    int codigo;
    char titulo[50];
    char autor[80];
    char editora[60];
    int ano_de_publicao;
    int exemplares;
    char status[20];
};

struct Usuario
{
    int matricula;
    char nome_completo[100];
    char curso[50];
    char telefone[15];
    char data_cadastro[15];
};

struct Emprestimo
{
    int codigo;
    int matricula_usuario;
    int codigo_livro;
    char data_emprestimo[15];
    char data_devolucao[15];
    char status[15];
};

struct Livro livros[QTD_MAXIMA_DE_REGISTROS];
struct Usuario usuarios[QTD_MAXIMA_DE_REGISTROS];
struct Emprestimo emprestimos[QTD_MAXIMA_DE_REGISTROS];

void inicializarLivros();
void testeLivros();

int main()
{
    inicializarLivros();
    testeLivros();
    system("pause");
    return 0;
}

void inicializarLivros(){
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        livros[i].codigo = 0;
        strcpy(livros[i].titulo, "");
        strcpy(livros[i].autor,"");
        strcpy(livros[i].editora,"");
        livros[i].ano_de_publicao = 0;
        livros[i].exemplares = 0;
        strcpy(livros[i].status, "disponivel");
    }
}

void testeLivros(){
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        printf("livro %d\n", i + 1);
        printf("codigo %d\n\n", livros[i].codigo);
    }
}
