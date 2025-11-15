#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void calcularDevolucao(char *emprestimo, char *devolucao);

int main()
{
    char data[20];
    char devolucao[20];
    while (1)
    {
        printf("Digite a data (DD/MM/AAAA): ");
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = 0;
        validarFormatoData(data);
        if (strcmp(data, "invalido") == 0)
        {
            printf("Data invalida\n");
            break;
        }
        calcularDevolucao(data, devolucao);
        printf("Data validada: %s\n", data);
        printf("Data de devolucao: %s\n", devolucao);
        system("pause");
    }
    system("pause");
    return 0;
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