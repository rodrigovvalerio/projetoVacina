#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void cadastro(int *criaId, char *criaNome[][100], char *criaEmail[][100], char *criaSexo[][100], char *criaEndereco[][100], double *criaAltura, bool *criaVacina);
void id(int *id);
void nome(char *nome[][100], int userCount);
void email(char *email[][100], int userCount);
void sexo(char *sexo[][100], int userCount);
void endereco(char *endereco[][100], int userCount);
void altura(double *altura, int userCount);
void vacina(bool *vacina, int userCount);
int userNumeber = 0;

int main()
{
    int id[1000], option;
    char nome[1000][100], email[1000][100], sexo[1000][100], endereco[1000][100];
    double altura[1000];
    bool vacina[1000];
    do
    {
        do
        {
            system("cls");
            printf("1-Criar usuario\n");
            printf("2-Edita usuario\n");
            printf("3-Excluir usuario\n");
            printf("4-Buscar por id\n");
            printf("5-Buscar por email\n");
            printf("6-Imprimir todos os usuarios\n");
            printf("7-Backup\n");
            printf("8-Sair\n");
            scanf("%d", &option);
        } while (option < 1 || option > 8);
        switch (option)
        {
        case 1:
            cadastro(id, nome, email, sexo, endereco, altura, vacina);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

        default:
            break;
        }
    } while (true == false);
}
void cadastro(int *criaId, char *criaNome[][100], char *criaEmail[][100], char *criaSexo[][100], char *criaEndereco[][100], double *criaAltura, bool *criaVacina)
{
    int option;
    do
    {
        system("cls");
        printf("_________________Cadastro_________________\n");
        id(criaId);
        nome(criaNome, userNumeber);
        email(criaEmail, userNumeber);
        sexo(criaSexo, userNumeber);
        endereco(criaEndereco, userNumeber);
        altura(criaAltura, userNumeber);
        vacina(criaVacina, userNumeber);
        printf("\n___________________________________________\n");
        system("pause");
        do
        {
            printf("Deseja cadastra outro usuario(1-sim, 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option != 2);
}

void id(int *id)
{
    srand(time(NULL));
    id[userNumeber] = (rand() % (999999 - 100000 + 100000) + 100000);
    for (int i = 0; i < userNumeber; i++)
    {
        if (id[userNumeber] == id[i])
        {
            id[userNumeber] = (rand() % (999999 - 100000 + 100000) + 100000);
            i = 0;
        }
    }
}
void nome(char *nome[][100], int userCount)
{
    do
    {
        printf("Digite seu nome completo: ");
        fflush(stdin);
        fgets(nome[userCount], 100, stdin);
    } while (strlen(nome[userCount]) < 2);
}
void email(char *email[][100], int userCount)
{
    do
    {
        printf("Digite o email: ");
        fgets(email[userCount], 100, stdin);
    } while (strchr(email[userCount], '@') == NULL);
}
void sexo(char *sexo[][100], int userCount)
{
    do
    {
        printf("Digite o sexo(feminino, masculino e nao declarar): ");
        fflush(stdin);
        fgets(sexo[userCount], 100, stdin);
        if (stricmp(sexo[userCount], "masculino\n") == 0 || stricmp(sexo[userCount], "feminino\n") == 0 || stricmp(sexo[userCount], "nao declarar\n") == 0)
        {
            return;
        }
    } while (1 == 2);
}
void endereco(char *endereco[][100], int userCount)
{
    do
    {
        printf("Digite seu endereco: ");
        fflush(stdin);
        fgets(endereco[userCount], 100, stdin);
    } while (strlen(endereco[userCount]) < 2);
}
void altura(double *altura, int userCount)
{
    do
    {
        printf("Digite sua altura: ");
        scanf("%lf", &altura[userCount]);
    } while (altura[userCount] < 1 || altura[userCount] > 2);
}
void vacina(bool *vacina, int userCount)
{
    char validaVacina[10];
    do
    {
        printf("tomou a vacina: ");
        fflush(stdin);
        fgets(validaVacina, 10, stdin);
        if (stricmp(validaVacina, "sim\n") == 0)
        {
            vacina[userCount] = true;
        }
        else if (stricmp(validaVacina, "nao\n") == 0)
        {
            vacina[userCount] = false;
        }
    } while (true == false);
}