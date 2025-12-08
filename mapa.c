#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define QTD_MAXIMA_DE_REGISTROS 50
// structs
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
    char nome_completo_usuario[100];
    int codigo_livro;
    char titulo_livro[50];
    char data_emprestimo[20];
    char data_devolucao[20];
    char status[15];
};

// structs globais
struct Livro livros[QTD_MAXIMA_DE_REGISTROS];
struct Usuario usuarios[QTD_MAXIMA_DE_REGISTROS];
struct Emprestimo emprestimos[QTD_MAXIMA_DE_REGISTROS];

// prototipos
void calcularDevolucao(char *emprestimo, char *devolucao);
void cadastrarEmprestimo();
void cadastrarLivro();
void cadastrarUsuario();
void carregarEmprestimos();
void carregarLivros();
void carregarUsuarios();
void devolucao();
void inicializarEmprestimos();
void inicializarLivros();
void inicializarUsuarios();
void listarEmprestimos();
void listarEmprestimosAtivos();
void menu();
void pesquisarLivroPorAutor();
void pesquisarLivroPorCodigo();
void pesquisarLivroPorTitulo();
void pesquisarUsuarioPorMatricula();
void pesquisarUsuarioPorNome();
void removerQuebraDeLinha(char *str);
void salvarEmprestimosEmArquivo();
void salvarLivrosEmArquivo();
void salvarUsuariosEmArquivo();
void sub_menu_listar_emprestimos();
void sub_menu_pesquisa_livro();
void sub_menu_pesquisa_usuario();
void validarEntradaInteira(char *entrada, int *var_final);
void validarFormatoData(char *entrada);

// main
int main()
{
    inicializarLivros();
    inicializarUsuarios();
    inicializarEmprestimos();
    carregarLivros();
    carregarUsuarios();
    carregarEmprestimos();
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
        strcpy(emprestimos[i].nome_completo_usuario,"");
        emprestimos[i].codigo_livro = 0;
        strcpy(emprestimos[i].titulo_livro,"");
        strcpy(emprestimos[i].data_emprestimo,"");
        strcpy(emprestimos[i].data_devolucao,"");
        strcpy(emprestimos[i].status,"");
    }
}

//menus
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
            cadastrarEmprestimo();
            break;
        case 4 :
            devolucao();
            break;
        case 5 :
            //Pesquisar Livro
            sub_menu_pesquisa_livro();
            break;
        case 6 :
            //Pesquisar Usuario
            sub_menu_pesquisa_usuario();
            break;
        case 7 :
            sub_menu_listar_emprestimos();
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

void sub_menu_pesquisa_livro()
{
    char validador[50];
    int escolha = 0;
    system("cls");
    printf("===== Pesquisa de Livros =====\n");
    printf("1. Pesquisar por Codigo\n");
    printf("2. Pesquisar por Titulo\n");
    printf("3. Pesquisar por Autor\n");
    printf("4. Voltar ao Menu Principal\n");
    printf("\nEscolha uma opcao: ");
    //Validador de entrada
    fgets(validador, sizeof(validador), stdin);
    validarEntradaInteira(validador, &escolha);
    switch (escolha)
    {
    case 1:
        pesquisarLivroPorCodigo();
        break;
    case 2:
        // Implementar pesquisa por titulo
        pesquisarLivroPorTitulo();
        break;
    case 3:
        pesquisarLivroPorAutor();
        break;
    case 4:
        return;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void sub_menu_pesquisa_usuario()
{
    char validador[50];
    int escolha = 0;
    system("cls");
    printf("===== Pesquisa de Usuarios =====\n");
    printf("1. Pesquisar por Matricula\n");
    printf("2. Pesquisar por Nome\n");
    printf("3. Voltar ao Menu Principal\n");
    printf("\nEscolha uma opcao: ");
    //Validador de entrada
    fgets(validador, sizeof(validador), stdin);
    validarEntradaInteira(validador, &escolha);
    switch (escolha)
    {
    case 1:
        pesquisarUsuarioPorMatricula();
        break;
    case 2:
        pesquisarUsuarioPorNome();
        break;
    case 3:
        return;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void sub_menu_listar_emprestimos()
{
    char validador[50];
    int escolha = 0;
    system("cls");
    printf("===== Listar Emprestimos =====\n");
    printf("1. Listar Todos os Emprestimos\n");
    printf("2. Listar Emprestimos Ativos\n");
    printf("3. Voltar ao Menu Principal\n");
    printf("\nEscolha uma opcao: ");
    //Validador de entrada
    fgets(validador, sizeof(validador), stdin);
    validarEntradaInteira(validador, &escolha);
    switch (escolha)
    {
    case 1:
        listarEmprestimos();
        break;
    case 2:
        listarEmprestimosAtivos();
        break;
    case 3:
        return;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

// validadores
void validarEntradaInteira(char *entrada, int *var_final)
{
    if (sscanf(entrada, "%d", var_final) != 1)
    {
        *var_final = 0; 
    }
    return;
}

void validarFormatoData(char *entrada)
{
    if (
        // tamanho errado
        strlen(entrada) != 10 ||

        // barras nas posições erradas
        entrada[2] != '/' ||
        entrada[5] != '/' ||

        // caracteres que deveriam ser dígitos
        !isdigit(entrada[0]) ||
        !isdigit(entrada[1]) ||
        !isdigit(entrada[3]) ||
        !isdigit(entrada[4]) ||
        !isdigit(entrada[6]) ||
        !isdigit(entrada[7]) ||
        !isdigit(entrada[8]) ||
        !isdigit(entrada[9])
       )
    {
        strcpy(entrada, "invalido");
    }
}

void calcularDevolucao(char *emprestimo, char *devolucao)
{
    struct tm dataentrada = {0};
    struct tm datadevolucao = {0};
    
    sscanf(emprestimo, "%d/%d/%d",
          &dataentrada.tm_mday,
          &dataentrada.tm_mon,
          &dataentrada.tm_year);

    dataentrada.tm_mon -= 1;
    dataentrada.tm_year -= 1900;
    mktime(&dataentrada);
    datadevolucao = dataentrada;
    datadevolucao.tm_mday += 7;
    mktime(&datadevolucao);
    sprintf(devolucao, "%02d/%02d/%04d",
            datadevolucao.tm_mday,
            datadevolucao.tm_mon + 1,
            datadevolucao.tm_year + 1900);
    return;
}

// funcionalidades

void removerQuebradeLinha(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

//livros
void cadastrarLivro()
{
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
    removerQuebradeLinha(entrada);
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
    removerQuebradeLinha(livro_entrada.titulo);
    printf("Autor do livro: ");
    fgets(livro_entrada.autor, sizeof(livro_entrada.autor), stdin);
    removerQuebradeLinha(livro_entrada.autor);
    printf("Editora do livro: ");
    fgets(livro_entrada.editora, sizeof(livro_entrada.editora), stdin);
    removerQuebradeLinha(livro_entrada.editora);
    int ano;
    printf("Ano de publicacao: ");
    fgets(entrada, sizeof(entrada), stdin);
    removerQuebradeLinha(entrada);
    validarEntradaInteira(entrada, &ano);
    if (ano <= 0){
        printf("Ano invalido!\n");
        return;
    }
    livro_entrada.ano_de_publicao = ano;
    int exemplares;
    printf("Quantidade de exemplares: ");
    fgets(entrada, sizeof(entrada), stdin);
    removerQuebradeLinha(entrada);
    validarEntradaInteira(entrada, &exemplares);
    if (exemplares < 0){
        printf("Quantidade invalida!\n");
        return;
    }
    livro_entrada.exemplares = exemplares;
    if (exemplares > 0){
        strcpy(livro_entrada.status, "disponivel");
    } else {
        strcpy(livro_entrada.status, "indisponivel");
    }
    livros[vazio] = livro_entrada;
    printf("Livro cadastrado com sucesso.\n");
    salvarLivrosEmArquivo();
}

void pesquisarLivroPorCodigo()
{
    printf("===== Pesquisa de Livro por Codigo =====\n");
    char entrada[50];
    int codigo;
    int achou = 0;
    printf("Digite o codigo do livro: ");
    fgets(entrada, sizeof(entrada), stdin);
    validarEntradaInteira(entrada, &codigo);
    if(codigo <= 0){
        printf("Codigo invalido!\n");
        return;
    }
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(livros[i].codigo == codigo){
            achou = 1;
            printf("-------------------------------\n");
            printf("Codigo: %d\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Editora: %s\n", livros[i].editora);
            printf("Ano de Publicacao: %d\n", livros[i].ano_de_publicao);
            printf("Exemplares: %d\n", livros[i].exemplares);
            printf("Status: %s\n", livros[i].status);
            return;
        }
    }
    if (!achou) {
        printf("Livro nao encontrado.\n");
    }
}

void pesquisarLivroPorTitulo()
{
    printf("===== Pesquisa de Livro por Titulo =====\n");
    char entrada[100];
    int achou = 0;
    printf("Digite o titulo do livro ou parte do titulo: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;
    strcpy(entrada, strlwr(entrada));
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(strstr(strlwr(livros[i].titulo), entrada) != NULL){
            achou = 1;
            printf("-------------------------------\n");
            printf("Codigo: %d\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Editora: %s\n", livros[i].editora);
            printf("Ano de Publicacao: %d\n", livros[i].ano_de_publicao);
            printf("Exemplares: %d\n", livros[i].exemplares);
            printf("Status: %s\n", livros[i].status);
        }
    }
    if (!achou) {
        printf("Livro nao encontrado.\n");
    }
}

void pesquisarLivroPorAutor()
{
    printf("===== Pesquisa de Livro por Autor =====\n");
    char entrada[80];
    int achou = 0;
    printf("Digite o nome do autor ou parte do nome: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;
    strcpy(entrada, strlwr(entrada));
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(strstr(strlwr(livros[i].autor), entrada) != NULL){
            achou = 1;
            printf("-------------------------------\n");
            printf("Codigo: %d\n", livros[i].codigo);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Editora: %s\n", livros[i].editora);
            printf("Ano de Publicacao: %d\n", livros[i].ano_de_publicao);
            printf("Exemplares: %d\n", livros[i].exemplares);
            printf("Status: %s\n", livros[i].status);
        }
    }
    if (!achou) {
        printf("Livro nao encontrado.\n");
    }
}

void salvarLivrosEmArquivo()
{
    FILE *arquivo = fopen("livros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    // Salva cada livro em uma linha
    for (int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++) {
        if (livros[i].codigo != 0) {
            fprintf(arquivo, "%d;%s;%s;%s;%d;%d;%s\n",
                    livros[i].codigo,
                    livros[i].titulo,
                    livros[i].autor,
                    livros[i].editora,
                    livros[i].ano_de_publicao,
                    livros[i].exemplares,
                    livros[i].status);
            }
    }

    fclose(arquivo);
    printf("Livros salvos com sucesso!\n");
}

void carregarLivros()
{
    FILE *arquivo = fopen("livros.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado. Continuando sem carregar...\n");
        return;
    }

    char linha[300];
    int i_livros = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        linha[strcspn(linha, "\n")] = '\0'; // remover \n

        char *token = strtok(linha, ";");
        livros[i_livros].codigo = atoi(token);

        token = strtok(NULL, ";");
        strcpy(livros[i_livros].titulo, token);

        token = strtok(NULL, ";");
        strcpy(livros[i_livros].autor, token);

        token = strtok(NULL, ";");
        strcpy(livros[i_livros].editora, token);

        token = strtok(NULL, ";");
        livros[i_livros].ano_de_publicao = atoi(token);

        token = strtok(NULL, ";");
        livros[i_livros].exemplares = atoi(token);

        token = strtok(NULL, ";");
        strcpy(livros[i_livros].status, token);

        i_livros++;
    }

    fclose(arquivo);
    printf("Livros carregados do arquivo com sucesso!\n");
}

//usuarios
void cadastrarUsuario()
{
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
    removerQuebradeLinha(entrada);
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
    removerQuebradeLinha(usuario_entrada.nome_completo);
    printf("Curso do usuario: ");
    fgets(usuario_entrada.curso, sizeof(usuario_entrada.curso), stdin);
    removerQuebradeLinha(usuario_entrada.curso);
    printf("Telefone do usuario: ");
    fgets(usuario_entrada.telefone, sizeof(usuario_entrada.telefone), stdin);
    removerQuebradeLinha(usuario_entrada.telefone);
    printf("Data de cadastro (DD/MM/AAAA): ");
    fgets(usuario_entrada.data_cadastro, sizeof(usuario_entrada.data_cadastro), stdin);
    removerQuebradeLinha(usuario_entrada.data_cadastro);
    validarFormatoData(usuario_entrada.data_cadastro);
    if(strcmp(usuario_entrada.data_cadastro, "invalido") == 0){
        printf("Data de cadastro invalida!\n");
        return;
    }
    usuarios[vazio] = usuario_entrada;
    printf("Usuario cadastrado com sucesso.\n");
    salvarUsuariosEmArquivo();
}

void pesquisarUsuarioPorMatricula()
{
    printf("===== Pesquisa de Usuario por Matricula =====\n");
    char entrada[50];
    int matricula;
    int achou = 0;
    printf("Digite a matricula do usuario: ");
    fgets(entrada, sizeof(entrada), stdin);
    removerQuebradeLinha(entrada);
    validarEntradaInteira(entrada, &matricula);
    if(matricula <= 0){
        printf("Matricula invalida!\n");
        return;
    }
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(usuarios[i].matricula == matricula){
            achou = 1;
            printf("-------------------------------\n");
            printf("Matricula: %d\n", usuarios[i].matricula);
            printf("Nome Completo: %s\n", usuarios[i].nome_completo);
            printf("Curso: %s\n", usuarios[i].curso);
            printf("Telefone: %s\n", usuarios[i].telefone);
            printf("Data de Cadastro: %s\n", usuarios[i].data_cadastro);
            return;
        }
    }
    if (!achou) {
        printf("Usuario nao encontrado.\n");
    }
}

void pesquisarUsuarioPorNome()
{
    printf("===== Pesquisa de Usuario por Nome =====\n");
    char entrada[100];
    int achou = 0;
    printf("Digite o nome do usuario ou parte do nome: ");
    fgets(entrada, sizeof(entrada), stdin);
    removerQuebradeLinha(entrada);
    entrada[strcspn(entrada, "\n")] = 0;
    strcpy(entrada, strlwr(entrada));
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(strstr(strlwr(usuarios[i].nome_completo), entrada) != NULL){
            achou = 1;
            printf("-------------------------------\n");
            printf("Matricula: %d\n", usuarios[i].matricula);
            printf("Nome Completo: %s\n", usuarios[i].nome_completo);
            printf("Curso: %s\n", usuarios[i].curso);
            printf("Telefone: %s\n", usuarios[i].telefone);
            printf("Data de Cadastro: %s\n", usuarios[i].data_cadastro);
        }
    }
}

void salvarUsuariosEmArquivo()
{
    FILE *arquivo = fopen("usuarios.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    // Salva cada usuario em uma linha
    for (int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++) {
        if (usuarios[i].matricula != 0) {
            fprintf(arquivo, "%d;%s;%s;%s;%s\n",
                    usuarios[i].matricula,
                    usuarios[i].nome_completo,
                    usuarios[i].curso,
                    usuarios[i].telefone,
                    usuarios[i].data_cadastro);
            }
    }

    fclose(arquivo);
    printf("Usuarios salvos com sucesso!\n");
}

void carregarUsuarios()
{
    FILE *arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado. Continuando sem carregar...\n");
        return;
    }

    char linha[300];
    int i_usuario = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        linha[strcspn(linha, "\n")] = '\0'; // remover \n

        char *token = strtok(linha, ";");
        usuarios[i_usuario].matricula = atoi(token);

        token = strtok(NULL, ";");
        strcpy(usuarios[i_usuario].nome_completo, token);

        token = strtok(NULL, ";");
        strcpy(usuarios[i_usuario].curso, token);

        token = strtok(NULL, ";");
        strcpy(usuarios[i_usuario].telefone, token);

        token = strtok(NULL, ";");
        strcpy(usuarios[i_usuario].data_cadastro, token);

        i_usuario++;
    }

    fclose(arquivo);
    printf("Usuarios carregados do arquivo com sucesso!\n");
}

//emprestimos
void cadastrarEmprestimo()
{
    system("cls");
    int vazio = -1;
    struct Emprestimo emprestimo_entrada;   
    printf("===== Registrando Emprestimo =====\n");
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(emprestimos[i].codigo == 0){
            vazio = i;
            break;
        }
    }
    if(vazio == -1){
        printf("Limite de registro de emprestimos atingido!\n");
        return;
    }
    char entrada[50];
    emprestimo_entrada.codigo = vazio + 1;
    int matricula;
    int achou = 0;
    int achado = -1;
    char devolucao[20];
    printf("Matricula do usuario: ");
    fgets(entrada, sizeof(entrada), stdin);
    removerQuebradeLinha(entrada);
    validarEntradaInteira(entrada, &matricula);
    if(matricula <= 0){
        printf("Matricula invalida!\n");
        return;
    }
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(usuarios[i].matricula == matricula){
            achou = 1;
            achado = i;
            break;
        }
    }
    if(achou == 0){
        printf("Usuario nao cadastrado!\n");
        return;
    }else{
        emprestimo_entrada.matricula_usuario = matricula;
        strcpy(emprestimo_entrada.nome_completo_usuario, usuarios[achado].nome_completo);
        printf("Nome do Usuario: %s\n", emprestimo_entrada.nome_completo_usuario);
        achou = 0;
        achado = -1;
    }
    int codigo_livro;
    printf("Codigo do livro: ");
    fgets(entrada, sizeof(entrada), stdin);
    removerQuebradeLinha(entrada);
    validarEntradaInteira(entrada, &codigo_livro);
    if(codigo_livro <= 0){
        printf("Codigo invalido!\n");
        return;
    }
    int loc_livro = -1;
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(livros[i].codigo == codigo_livro){
            achou = 1;
            loc_livro = i;
            break;
        }
    }
    if(achou == 0){
        printf("Livro nao cadastrado!\n");
        return;
    }else{
        emprestimo_entrada.codigo_livro = codigo_livro;
        strcpy(emprestimo_entrada.titulo_livro, livros[loc_livro].titulo);
        printf("Titulo do Livro: %s\n", emprestimo_entrada.titulo_livro);
        achou = 0;
    }
    if(livros[loc_livro].exemplares <= 0){
        printf("Nao ha exemplares disponiveis para emprestimo!\n");
        return;
    }
    printf("Data do emprestimo (DD/MM/AAAA): ");
    fgets(emprestimo_entrada.data_emprestimo, sizeof(emprestimo_entrada.data_emprestimo), stdin);
    removerQuebradeLinha(emprestimo_entrada.data_emprestimo);
    validarFormatoData(emprestimo_entrada.data_emprestimo);
    if(strcmp(emprestimo_entrada.data_emprestimo, "invalido") == 0){
        printf("Data de emprestimo invalida!\n");
        return;
    }
    calcularDevolucao(emprestimo_entrada.data_emprestimo, devolucao);
    strcpy(emprestimo_entrada.data_devolucao, devolucao);
    printf("Data prevista de devolucao: %s\n", emprestimo_entrada.data_devolucao);
    strcpy(emprestimo_entrada.status, "Ativo");
    emprestimos[vazio] = emprestimo_entrada;
    livros[loc_livro].exemplares -= 1;
    if (livros[loc_livro].exemplares == 0){
        strcpy(livros[loc_livro].status, "indisponivel");
    }
    printf("Emprestimo registrado com sucesso.\n");
    salvarLivrosEmArquivo();
    salvarEmprestimosEmArquivo();
}

void listarEmprestimos()
{
    system("cls");
    printf("===== Lista de Emprestimos Registrados =====\n");
    int achou = 0;
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(emprestimos[i].codigo != 0){
            achou = 1;
            printf("Codigo do Emprestimo: %d\n", emprestimos[i].codigo);
            printf("Matricula do Usuario: %d\n", emprestimos[i].matricula_usuario);
            printf("Codigo do Livro: %d\n", emprestimos[i].codigo_livro);
            printf("Data do Emprestimo: %s\n", emprestimos[i].data_emprestimo);
            printf("Data da Devolucao: %s\n", emprestimos[i].data_devolucao);
            printf("Status: %s\n", emprestimos[i].status);
            printf("-------------------------------\n");
        }
    }
    if(achou == 0){
        printf("Nenhum emprestimo registrado.\n");
    }
}

void listarEmprestimosAtivos()
{
    system("cls");
    printf("===== Lista de Emprestimos Ativos =====\n");
    int achou = 0;
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(emprestimos[i].codigo != 0 && strcmp(emprestimos[i].status, "Ativo") == 0){
            achou = 1;
            printf("Codigo do Emprestimo: %d\n", emprestimos[i].codigo);
            printf("Matricula do Usuario: %d\n", emprestimos[i].matricula_usuario);
            printf("Codigo do Livro: %d\n", emprestimos[i].codigo_livro);
            printf("Data do Emprestimo: %s\n", emprestimos[i].data_emprestimo);
            printf("Data da Devolucao: %s\n", emprestimos[i].data_devolucao);
            printf("Status: %s\n", emprestimos[i].status);
            printf("-------------------------------\n");
        }
    }
    if(achou == 0){
        printf("Nenhum emprestimo ativo registrado.\n");
    }
}

void salvarEmprestimosEmArquivo()
{
    FILE *arquivo = fopen("emprestimos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++) {
        if (emprestimos[i].codigo != 0) {
            fprintf(arquivo, "%d;%d;%s;%d;%s;%s;%s;%s\n",
                    emprestimos[i].codigo,
                    emprestimos[i].matricula_usuario,
                    emprestimos[i].nome_completo_usuario,
                    emprestimos[i].codigo_livro,
                    emprestimos[i].titulo_livro,
                    emprestimos[i].data_emprestimo,
                    emprestimos[i].data_devolucao,
                    emprestimos[i].status);
            }
    }

    fclose(arquivo);
    printf("Emprestimos salvos com sucesso!\n");
}

void carregarEmprestimos()
{
    FILE *arquivo = fopen("emprestimos.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado. Continuando sem carregar...\n");
        return;
    }

    char linha[400];
    int i_emprestimo = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        linha[strcspn(linha, "\n")] = '\0';

        char *token = strtok(linha, ";");
        emprestimos[i_emprestimo].codigo = atoi(token);

        token = strtok(NULL, ";");
        emprestimos[i_emprestimo].matricula_usuario = atoi(token);

        token = strtok(NULL, ";");
        strcpy(emprestimos[i_emprestimo].nome_completo_usuario, token);

        token = strtok(NULL, ";");
        emprestimos[i_emprestimo].codigo_livro = atoi(token);

        token = strtok(NULL, ";");
        strcpy(emprestimos[i_emprestimo].titulo_livro, token);

        token = strtok(NULL, ";");
        strcpy(emprestimos[i_emprestimo].data_emprestimo, token);

        token = strtok(NULL, ";");
        strcpy(emprestimos[i_emprestimo].data_devolucao, token);

        token = strtok(NULL, ";");
        strcpy(emprestimos[i_emprestimo].status, token);

        i_emprestimo++;
    }

    fclose(arquivo);
    printf("Emprestimos carregados do arquivo com sucesso!\n");
}

// Devolucao
void devolucao()
{
    system("cls");
    printf("===== Registrando Devolucao =====\n");
    char entrada[50];
    int codigo_emprestimo;
    int achou = 0;
    printf("Codigo do emprestimo: ");
    fgets(entrada, sizeof(entrada), stdin);
    validarEntradaInteira(entrada, &codigo_emprestimo);
    if(codigo_emprestimo <= 0){
        printf("Codigo invalido!\n");
        return;
    }
    for(int i = 0; i < QTD_MAXIMA_DE_REGISTROS; i++){
        if(emprestimos[i].codigo == codigo_emprestimo){
            achou = 1;
            // Processar devolucao
            if(strcmp(emprestimos[i].status, "Ativo") != 0){
                printf("Emprestimo ja foi devolvido!\n");
                return;
            }
            printf("Emprestimo encontrado para o usuario: %s\n", emprestimos[i].nome_completo_usuario);
            printf("Livro: %s\n", emprestimos[i].titulo_livro);
            printf("Data de Emprestimo: %s\n", emprestimos[i].data_emprestimo);
            printf("Data de Devolucao Prevista: %s\n\n", emprestimos[i].data_devolucao);
            printf("deseja confirmar a devolucao? (S/N): ");
            char confirma[10];
            fgets(confirma, sizeof(confirma), stdin);
            if(confirma[0] != 'S' && confirma[0] != 's'){
                printf("Devolucao cancelada.\n");
                return;
            }
            strcpy(emprestimos[i].status, "Devolvido");
            // Atualizar exemplares do livro
            int codigo_livro = emprestimos[i].codigo_livro;
            for(int j = 0; j < QTD_MAXIMA_DE_REGISTROS; j++){
                if(livros[j].codigo == codigo_livro){
                    livros[j].exemplares += 1;
                    strcpy(livros[j].status, "Disponivel");
                    break;
                }
            }
            printf("Devolucao registrada com sucesso.\n");
            salvarLivrosEmArquivo();
            salvarEmprestimosEmArquivo();
            return;
        }
    }
    if(achou == 0){
        printf("Emprestimo nao encontrado.\n");
    }

}
