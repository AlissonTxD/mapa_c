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
    char telefone[20];
    char data_cadastro[20];
};

struct Emprestimo
{
    int codigo;
    int matricula_usuario;
    int codigo_livro;
    char data_emprestimo[20];
    char data_devolucao[20];
    char status[15];
};

struct Livro livros[QTD_MAXIMA_DE_REGISTROS];
struct Usuario usuarios[QTD_MAXIMA_DE_REGISTROS];
struct Emprestimo emprestimos[QTD_MAXIMA_DE_REGISTROS];

void inicializarLivros();
void inicializarUsuarios();
void inicializarEmprestimos();
void menu();
void cadastrarLivro();
void cadastrarUsuario();
void validarEntradaInteira(char *entrada, int *var_final);
void listarLivros();
void listarUsuarios();

int main()
{
    inicializarLivros();
    inicializarUsuarios();
    inicializarEmprestimos();
    menu();
    system("pause");
    return 0;
}

// Inicializadores
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

void menu()
{   
    while (1)
    {   
        char validador[50];
        int escolha = 0;
        system("cls");
        printf("Sistema de Gerenciamento da Biblioteca\n");
        printf("================ Menu ================\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Cadastrar Livro\n");
        printf("3. Registrar Emprestimo\n");
        printf("4. Registrar Devolucao\n");
        printf("5. Pesquisar Livro\n");
        printf("6. Pesquisar Usuario\n");
        printf("7. Listar Emprestimos\n");
        printf("8. Sair\n");
        printf("\nEscolha uma opcao: ");
        //Validador de entrada
        fgets(validador, sizeof(validador), stdin);
        validarEntradaInteira(validador, &escolha);
        switch (escolha)
        {
        case 1 :
            //Cadastrar Usuario
            cadastrarUsuario();
            break;
        case 2 :
            //Cadastrar Livro
            cadastrarLivro();
            break;
        case 3 :
            //Registrar Emprestimo
            break;
        case 4 :
            //Registrar Devolucao
            break;
        case 5 :
            //Pesquisar Livro
            listarLivros();
            break;
        case 6 :
            //Pesquisar Usuario
            listarUsuarios();
            break;
        case 7 :
            //Listar Emprestimos
            break;
        case 8 :
            //Sair
            return;
        default:
            printf("Valor Invalido\n");
            break;
        }
        system("pause");
    }
}

void validarEntradaInteira(char *entrada, int *var_final)
{
    if (sscanf(entrada, "%d", var_final) != 1)
    {
        *var_final = 0; 
    }
    return;
}

void cadastrarLivro(){
    system("cls");
    int vazio = -1;
    struct Livro livro_entrada;   
    printf("===== Cadastrando Livro =====\n");
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(livros[i].codigo == 0){
            vazio = i;
            break;
        }
    }
    if(vazio == -1){
        printf("Limite de cadastro de livros atingido!\n");
        return;
    }
    char entrada[50];
    int codigo;
    printf("Codigo do livro: ");
    fgets(entrada, sizeof(entrada), stdin);
    validarEntradaInteira(entrada, &codigo);
    if(codigo <= 0){
        printf("Codigo invalido!\n");
        return;
    }else{
        for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
            if(livros[i].codigo == codigo){
                printf("Codigo ja cadastrado!\n");
                return;
            }
        }
    }
    livro_entrada.codigo = codigo;
    printf("Titulo do livro: ");
    fgets(livro_entrada.titulo, sizeof(livro_entrada.titulo), stdin);
    printf("Autor do livro: ");
    fgets(livro_entrada.autor, sizeof(livro_entrada.autor), stdin);
    printf("Editora do livro: ");
    fgets(livro_entrada.editora, sizeof(livro_entrada.editora), stdin);
    int ano;
    printf("Ano de publicacao: ");
    fgets(entrada, sizeof(entrada), stdin);
    validarEntradaInteira(entrada, &ano);
    if (ano <= 0){
        printf("Ano invalido!\n");
        return;
    }
    livro_entrada.ano_de_publicao = ano;
    int exemplares;
    printf("Quantidade de exemplares: ");
    fgets(entrada, sizeof(entrada), stdin);
    validarEntradaInteira(entrada, &exemplares);
    if (exemplares <= 0){
        printf("Quantidade invalida!\n");
        return;
    }
    livro_entrada.exemplares = exemplares;
    printf("Status do livro: ");
    fgets(livro_entrada.status, sizeof(livro_entrada.status), stdin);
    livros[vazio] = livro_entrada;
    printf("Livro cadastrado com sucesso.\n");
}

void listarLivros(){
    system("cls");
    printf("===== Lista de Livros Cadastrados =====\n");
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(livros[i].codigo != 0){
            printf("Codigo: %d\n", livros[i].codigo);
            printf("Titulo: %s", livros[i].titulo);
            printf("Autor: %s", livros[i].autor);
            printf("Editora: %s", livros[i].editora);
            printf("Ano de Publicacao: %d\n", livros[i].ano_de_publicao);
            printf("Exemplares: %d\n", livros[i].exemplares);
            printf("Status: %s\n", livros[i].status);
            printf("-------------------------------\n");
        }
    }
}

void cadastrarUsuario(){
    system("cls");
    printf("===== Cadastrando Usuario =====\n");
    int vazio = -1;
    struct Usuario usuario_entrada;
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(usuarios[i].matricula == 0){
            vazio = i;
            break;
        }
    }
    if (vazio == -1){
        printf("Limite de cadastro de usuarios atingido!\n");
        return;
    }
    char entrada[50];
    int matricula;
    printf("Matricula do usuario: ");
    fgets(entrada, sizeof(entrada), stdin);
    validarEntradaInteira(entrada, &matricula);
    if(matricula <= 0){
        printf("Matricula invalida!\n");
        return;
    }else{
        for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
            if(usuarios[i].matricula == matricula){
                printf("Matricula ja cadastrada!\n");
                return;
            }
        }
    }
    usuario_entrada.matricula = matricula;
    printf("Nome do usuario: ");
    fgets(usuario_entrada.nome_completo, sizeof(usuario_entrada.nome_completo), stdin);
    printf("Curso do usuario: ");
    fgets(usuario_entrada.curso, sizeof(usuario_entrada.curso), stdin);
    printf("Telefone do usuario: ");
    fgets(usuario_entrada.telefone, sizeof(usuario_entrada.telefone), stdin);
    printf("Data de cadastro (DD/MM/AAAA): ");
    fgets(usuario_entrada.data_cadastro, sizeof(usuario_entrada.data_cadastro), stdin);
    usuarios[vazio] = usuario_entrada;
    printf("Usuario cadastrado com sucesso.\n");
}

void listarUsuarios(){
    system("cls");
    printf("(67) 99999-9999\n");
    printf("===== Lista de Usuarios Cadastrados =====\n");
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(usuarios[i].matricula != 0){
            printf("Matricula: %d\n", usuarios[i].matricula);
            printf("Nome Completo: %s", usuarios[i].nome_completo);
            printf("Curso: %s", usuarios[i].curso);
            printf("Telefone: %s", usuarios[i].telefone);
            printf("Data de Cadastro: %s\n", usuarios[i].data_cadastro);
            printf("-------------------------------\n");
        }
    }
}