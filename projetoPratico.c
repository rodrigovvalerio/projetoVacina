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
void mostrarPerfil(int idBuscado, int *mostraId, char *mostraNome[][100], char *mostraEmail[][100], char *mostraSexo[][100], char *mostraEndereco[][100], double *mostraAltura, bool *mostraVacina);
void editar(int *editarId, char *editarNome[][100], char *editarEmail[][100], char *editarSexo[][100], char *editarEndereco[][100], double *editarAltura, bool *editarVacina);
void excluir(int *excluirId, char *excluirNome[][100], char *excluirEmail[][100], char *excluirSexo[][100], char *excluirEndereco[][100], double *excluirAltura, bool *excluirVacina);
int buscarId(int *idBusca, char *nomeBuscar[][100], char *emailBusca[][100], char sexoBuscar[][100], char *enderecoBuscar[][100], double *alturaBuscar, bool *vacinaBusca);
int buscarEmail(int *idBusca, char *nomeBuscar[][100], char *emailBusca[][100], char sexoBuscar[][100], char *enderecoBuscar[][100], double *alturaBuscar, bool *vacinaBusca);
void mostraTodos(int *mostraId, char *mostraNome[][100], char *mostraEmail[][100], char *mostraSexo[][100], char *mostraEndereco[][100], double *mostraAltura, bool *mostraVacina);
void backup(int backupOption, int *id, char *nome[][100], char *email[][100], char *sexo[][100], char *endereco[][100], double *altura, bool *vacina, int *backupId);
int userNumeber = 0;

int main()
{
    int id[1000], option = 0, backupOption, validaBackup = 0, backupId[1000];
    char nome[1000][100], email[1000][100], sexo[1000][100], endereco[1000][100];
    double altura[1000];
    bool vacina[1000];
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
        switch (option)
        {
        case 1:
            cadastro(id, nome, email, sexo, endereco, altura, vacina);
            break;
        case 2:
            editar(id, nome, email, sexo, endereco, altura, vacina);

            break;
        case 3:
            excluir(id, nome, email, sexo, endereco, altura, vacina);
            break;
        case 4:
            buscarId(id, nome, email, sexo, endereco, altura, vacina);
            break;
        case 5:
            buscarEmail(id, nome, email, sexo, endereco, altura, vacina);
            break;
        case 6:
            mostraTodos(id, nome, email, sexo, endereco, altura, vacina);
            break;
        case 7:
            do
            {
                do
                {
                    system("cls");
                    printf("1-Criar Backup\n");
                    printf("2-recuperar Backup\n");
                    printf("3-Voltar\n");
                    printf("Digite um opcao: ");
                    scanf("%d", &backupOption);
                } while (backupOption < 1 || backupOption > 3);
                if (backupOption == 1)
                {
                    printf("backup realizado com sucesso!!!\n");
                    system("pause");
                    backup(backupOption, id, nome, email, sexo, endereco, altura, vacina, backupId);
                    validaBackup == 1;
                }
                else if (backupOption == 2)
                {
                    printf("backup restaurado com sucesso!!!\n");
                    system("pause");
                    backup(backupOption, id, nome, email, sexo, endereco, altura, vacina, backupId);
                }
                else if (backupOption == 2 && validaBackup != 1)
                {
                    printf("Nao tem backup salvo!\n");
                }
                else if (backupOption != 3)
                {
                    system("cls");
                    printf("Opcao invalida!! digite novamente");
                    system("pause");
                }
            } while (backupOption != 3);
            break;
        default:
            printf("Opcao invalida!! digite novamente");
            system("pause");
            system("cls");
            break;
        }
        printf("passou");
    } while (option > 1 || option < 7);
    printf("passou2");
    system("pause");
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
        mostrarPerfil(userNumeber, criaId, criaNome, criaEmail, criaSexo, criaEndereco, criaAltura, criaVacina);
        system("cls");
        userNumeber++;
        do
        {
            printf("Deseja cadastra outro usuario(1-sim, 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
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
    int option = 1;
    do
    {
        printf("Digite o sexo(feminino, masculino e nao declarar): ");
        fflush(stdin);
        fgets(sexo[userCount], 100, stdin);
        if (stricmp(sexo[userCount], "masculino\n") == 0 || stricmp(sexo[userCount], "feminino\n") == 0 || stricmp(sexo[userCount], "nao declarar\n") == 0)
        {
            return;
        }
    } while (option == 1);
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
    int option = 1;
    char validaVacina[10];
    do
    {
        printf("tomou a vacina: ");
        fflush(stdin);
        fgets(validaVacina, 10, stdin);
        if (stricmp(validaVacina, "sim\n") == 0)
        {
            vacina[userCount] = true;
            option = 2;
        }
        else if (stricmp(validaVacina, "nao\n") == 0)
        {
            vacina[userCount] = false;
            option = 2;
        }
    } while (option == 1);
}

void mostrarPerfil(int idBuscado, int *mostraId, char *mostraNome[][100], char *mostraEmail[][100], char *mostraSexo[][100], char *mostraEndereco[][100], double *mostraAltura, bool *mostraVacina)
{
    system("cls");
    printf("_______________________________________________\n");
    printf("O id do usuario: %d\n", mostraId[idBuscado]);
    printf("O nome do usuario: %s\n", mostraNome[idBuscado]);
    printf("O email do usuario: %s\n", mostraEmail[idBuscado]);
    printf("O sexo do usuario: %s\n", mostraSexo[idBuscado]);
    printf("O endereco do usuario: %s\n", mostraEndereco[idBuscado]);
    printf("O altura do usuario: %lf\n", mostraAltura[idBuscado]);
    if (mostraVacina[idBuscado] == true)
    {
        printf("O usuario tomou a vacina\n");
    }
    else
    {
        printf("O usuario nao tomou a vacina\n");
    }
    printf("\n__________________________________________________\n");
    system("pause");
}

void editar(int *editarId, char *editarNome[][100], char *editarEmail[][100], char *editarSexo[][100], char *editarEndereco[][100], double *editarAltura, bool *editarVacina)
{
    int option, userCount;
    do
    {
        system("cls");
        printf("_________________Editar___________________\n");
        do
        {
            printf("buscar usuario:\n");
            printf("1-por ID\n");
            printf("2-por Email\n");
            printf("3-volta\n");
            printf("Digite uma opcao valida:");
            scanf("%d", &option);
        } while (option < 1 || option > 3);
        if (option == 1)
        {
            userCount = buscarId(editarId, editarNome, editarEmail, editarSexo, editarEndereco, editarAltura, editarVacina);
        }
        else if (option == 2)
        {
            userCount = buscarEmail(editarId, editarNome, editarEmail, editarSexo, editarEndereco, editarAltura, editarVacina);
        }
        else
        {
            return;
        }

        do
        {
            system("cls");
            printf("1-Nome\n");
            printf("2-Email\n");
            printf("3-Sexo\n");
            printf("4-Endereco\n");
            printf("5-Altura\n");
            printf("6-Vacina\n");
            printf("7-Volta\n");
            printf("Digite a opcao que deseja alterar:");
            scanf("%d", &option);
        } while (option < 1 || option > 7);
        if (option == 1)
        {
            nome(editarNome, userCount);
        }
        else if (option == 2)
        {
            email(editarEmail, userCount);
        }
        else if (option == 3)
        {
            sexo(editarSexo, userCount);
        }
        else if (option == 4)
        {
            endereco(editarEndereco, userCount);
        }
        else if (option == 5)
        {
            altura(editarAltura, userCount);
        }
        else if (option == 6)
        {
            vacina(editarVacina, userCount);
        }
        else
        {
            return;
        }
        mostrarPerfil(userCount, editarId, editarNome, editarEmail, editarSexo, editarEndereco, editarAltura, editarVacina);
        do
        {
            system("cls");
            printf("deseja edita outro usuario(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
void excluir(int *excluirId, char *excluirNome[][100], char *excluirEmail[][100], char *excluirSexo[][100], char *excluirEndereco[][100], double *excluirAltura, bool *excluirVacina)
{
    int option, userCount;
    do
    {
        do
        {
            printf("buscar usuario:\n");
            printf("1-por ID\n");
            printf("2-por Email\n");
            printf("3-volta\n");
            printf("Digite uma opcao valida: ");
            scanf("%d", &option);
            fflush(stdin);
        } while (option < 1 || option > 3);
        if (option == 1)
        {
            userCount = buscarId(excluirId, excluirNome, excluirEmail, excluirSexo, excluirEndereco, excluirAltura, excluirVacina);
        }
        else if (option == 2)
        {
            userCount = buscarEmail(excluirId, excluirNome, excluirEmail, excluirSexo, excluirEndereco, excluirAltura, excluirVacina);
        }
        else
        {
            return;
        }
        for (userCount; userCount < userNumeber; userCount)
        {
            excluirId[userCount] = excluirId[++userCount];
            strcpy(excluirNome[userCount], excluirNome[++userCount]);
            strcpy(excluirEmail[userCount], excluirEmail[++userCount]);
            strcpy(excluirSexo[userCount], excluirSexo[++userCount]);
            strcpy(excluirEndereco[userCount], excluirEndereco[++userCount]);
            excluirAltura[userCount] = excluirAltura[++userCount];
            excluirVacina[userCount] = excluirVacina[++userCount];
        }
        userNumeber--;
        do
        {
            system("cls");
            printf("deseja edita outro usuario(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
int buscarId(int *idBusca, char *nomeBuscar[][100], char *emailBusca[][100], char sexoBuscar[][100], char *enderecoBuscar[][100], double *alturaBuscar, bool *vacinaBusca)
{
    int idEscolhido, option;
    do
    {
        printf("Digite o ID do usuario: ");
        scanf("%d", &idEscolhido);
        fflush(stdin);
        for (int i = 0; i < userNumeber; i++)
        {
            if (idBusca[i] == idEscolhido)
            {
                mostrarPerfil(i, idBusca, nomeBuscar, emailBusca, sexoBuscar, enderecoBuscar, alturaBuscar, vacinaBusca);
                return i;
            }
        }
        do
        {
            printf("id invalido!");
            printf("Deseja tenta novamente(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
int buscarEmail(int *idBusca, char *nomeBuscar[][100], char *emailBusca[][100], char sexoBuscar[][100], char *enderecoBuscar[][100], double *alturaBuscar, bool *vacinaBusca)
{
    int option;
    char emailEscolido[100];
    do
    {
        printf("Digite o email do usuario: ");
        fflush(stdin);
        fgets(emailEscolido, 100, stdin);
        for (int i = 0; i < userNumeber; i++)
        {
            if (stricmp(emailEscolido, emailBusca[i]) == 0)
            {
                mostrarPerfil(i, idBusca, nomeBuscar, emailBusca, sexoBuscar, enderecoBuscar, alturaBuscar, vacinaBusca);
                return i;
            }
        }
        do
        {
            printf("email invalido!");
            printf("Deseja tenta novamente(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
void mostraTodos(int *mostraId, char *mostraNome[][100], char *mostraEmail[][100], char *mostraSexo[][100], char *mostraEndereco[][100], double *mostraAltura, bool *mostraVacina)
{
    for (int i = 0; i < userNumeber; i++)
    {
        mostrarPerfil(i, mostraId, mostraNome, mostraEmail, mostraSexo, mostraEndereco, mostraAltura, mostraVacina);
    }
}
void backup(int backupOption, int *id, char *nome[][100], char *email[][100], char *sexo[][100], char *endereco[][100], double *altura, bool *vacina, int *backupId)
{
    int backupUserNumber;
    char backupNome[1000][100], backupEmail[1000][100], backupSexo[1000][100], backupEndereco[1000][100];
    double backupAltura[1000];
    bool backupVacina[1000];
    if (backupOption == 1)
    {
        for (int i = 0; i < userNumeber; i++)
        {
            backupId[i] = id[i];
            strcpy(backupNome[i], nome[i]);
            strcpy(backupEmail[i], email[i]);
            strcpy(backupSexo[i], sexo[i]);
            strcpy(backupEndereco[i], endereco[i]);
            backupAltura[i] = altura[i];
            backupVacina[i] = vacina[i];
        }
        backupUserNumber = userNumeber;
    }
    else if (backupOption == 2)
    {
        for (int i = 0; i < userNumeber; i++)
        {
            id[i] = backupId[i];
            strcpy(nome[i], backupNome[i]);
            strcpy(email[i], backupEmail[i]);
            strcpy(sexo[i], backupSexo[i]);
            strcpy(endereco[i], backupEndereco[i]);
            altura[i] = backupAltura[i];
            vacina[i] = backupVacina[i];
        }
        userNumeber = backupUserNumber;
    }
}