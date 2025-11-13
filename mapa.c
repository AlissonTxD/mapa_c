#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTD_MAXIMA_DE_REGISTROS 5

struct Livro
{
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
void inicializarUsuarios();
void inicializarEmprestimos();
int menu();
void testeLivros();
void testeUsuarios();
void testeEmprestimos();

int main()
{
    inicializarLivros();
    inicializarUsuarios();
    inicializarEmprestimos();
    menu();
    system("pause");
    return 0;
}

void inicializarLivros()
{
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

void inicializarUsuarios()
{
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        usuarios[i].matricula = 0;
        strcpy(usuarios[i].nome_completo, "");
        strcpy(usuarios[i].curso, "");
        strcpy(usuarios[i].telefone, "");
        strcpy(usuarios[i].data_cadastro, "");
    }
}

void inicializarEmprestimos()
{
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        emprestimos[i].codigo = 0;
        emprestimos[i].matricula_usuario = 0;
        emprestimos[i].codigo_livro = 0;
        strcpy(emprestimos[i].data_emprestimo,"");
        strcpy(emprestimos[i].data_devolucao,"");
        strcpy(emprestimos[i].status,"");
    }
}

int menu()
{   
    while (1)
    {
        int escolha = 0;
        system("cls");
        printf("===== Menu =====\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Cadastrar Livro\n");
        printf("3. Registrar Emprestimo\n");
        printf("4. Registrar Devolucao\n");
        printf("5. Pesquisar Livro\n");
        printf("6. Pesquisar Usuario\n");
        printf("7. Listar Emprestimos\n");
        printf("8. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1 :
            printf("voce escolheu 1\n");
            break;
        case 2 :
            printf("voce escolheu 2\n");
            break;
        case 3 :
            printf("voce escolheu 3\n");
            break;
        case 4 :
            printf("voce escolheu 4\n");
            break;
        case 5 :
            printf("voce escolheu 5\n");
            break;
        case 6 :
            printf("voce escolheu 6\n");
            break;
        case 7 :
            printf("voce escolheu 7\n");
            break;
        case 8 :
            printf("voce escolheu 8\n");
            return 0;
        default:
            printf("Valor Invalido\n");
            break;
        }
        system("pause");
    }
}


void testeLivros()
{
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        printf("livro %d\n", i + 1);
        printf("codigo %d\n\n", livros[i].codigo);
    }
}

void testeUsuarios()
{
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        printf("usuario %d\n", i + 1);
        printf("matricula %d\n\n", usuarios[i].matricula);
    }
}

void testeEmprestimos()
{
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        printf("emprestimo %d\n", i + 1);
        printf("matricula %d\n", emprestimos[i].codigo);
        printf("teste %s\n", emprestimos[i].status);
    }
}