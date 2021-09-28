#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Variáveis globais
int IDUser[1000]; //Randômico
char nomeUser[1000], sexoUser[1000][100], enderecoUser[1000][100], emailUser[1000[100]];
char adressUser[1000][70];
bool vacinaUser[1000];
double alturaUser[1000];
int quantidadeUser;
int pontoVetorEmail;
int pontoVetorID;
char emailUser[1000];//Checar se há o caractere `@`
char sexoUser[1000];//Apenas palavras completas, sem abreviações - Feminino - Masculino - Não Declarado
float alturaUser[1000];//Entre 1m a 2m
//Fim das variáveis globais

//Declaração das funções
void createID(int *id);
int menu();
void cadastraUser(int *criaIDUser, char *criaNomeUser[][100], char *criaEmailUser[][100], char *criaSexoUser[][100], char *criaEnderecoUser[][100], double *criaAlturaUser, bool *criaVacinaUser);
int editUser(int *editarIdUser, char *editarNomeUser[][100], char *editarEmailUser[][100], char *editarSexoUser[][100], char *editarEnderecoUser[][100], double *editarAlturaUser, bool *editarVacinaUser);
int excludeUser(int *excluirIdUser, char *excluirNomeUser[][100], char *excluirEmailUser[][100], char *excluirSexoUser[][100], char *excluirEnderecoUser[][100], double *excluirAlturaUser, bool *excluirVacinaUser);
int printUser();
int backupUser();
int restoreUser();
int buscaUser();
int validaEmail();
int validaID();
int buscaEmail();
int encerra();
int buscaID();
int userNumeber = 0;
//Término de declaração de variáveis

//Criação das funções
int createID(){//criar o ID randômicamente

    return 0;
}

int menu(){//Menu
    int escolha;

    printf("Bem vindo ao menu\nEscolha a opcao que deseja");
    printf("Digite 1 - Caso queira registrar novos usuarios\nDigite 2 - Caso queira editar algum usuario\nDigite 3 - Caso queira procurar um usuario\nDigite 4 - Caso queira excluir algum usuario\nDigite 5 - Caso queira restaurar algum usuario\nDigite 6 - Caso queira encerrar a sessao");
    scanf("%d", &escolha);

    switch (escolha){
     case 1:
         cadastraUser(IDUser, nomeUser, emailUser, sexoUser, enderecoUser, alturaUser, vacinaUser);
         break;
     case 2:
         editUser(IDUser, nomeUser, emailUser, sexoUser, enderecoUser, alturaUser, vacinaUser);
           break;
    case 3:
         buscaUser(IDUser, nomeUser, emailUser, sexoUser, enderecoUser, alturaUser, vacinaUser);
         break;
    case 4:
        excludeUser(IDUser, nomeUser, emailUser, sexoUser, enderecoUser, alturaUser, vacinaUser);
        break;
    case 5:
        restoreUser(IDUser, nomeUser, emailUser, sexoUser, enderecoUser, alturaUser, vacinaUser);
        break;
    case 6:
        encerra(IDUser, nomeUser, emailUser, sexoUser, enderecoUser, alturaUser, vacinaUser);
        break;
    
    default:
        printf("Opcao invalida\nTente novamente");
        break;
    }

    return 0;
}

void cadastraUser(int *criaIDUser, char *criaNomeUser[][100], char *criaEmailUser[][100], char *criaSexoUser[][100], char *criaEnderecoUser[][100], double *criaAlturaUser, bool *criaVacinaUser)
{//Cadastrar o usuário 
   int option;
    do
    {
        system("cls");
        printf("******Cadastro******\n");
        id(criaId);
        nome(criaNomeUser, userNumeber);
        email(criaEmailUser, userNumeber);
        sexo(criaSexoUser, userNumeber);
        endereco(criaEnderecoUser, userNumeber);
        altura(criaAlturaUser, userNumeber);
        vacina(criaVacinaUser, userNumeber);
        printf("\n___________________________________________\n");
        mostrarPerfil(userNumeber, criaIDUser, criaNomeUser, criaEmailUser, criaSexoUser, criaEnderecoUser, criaAlturaUser, criaVacinaUser);
        system("cls");
        userNumeber++;
        do
        {
            printf("Gostaria de cadastrar outro usuario?(1-sim, 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
void nomeUser(char *nome[][100], int userCount)
{
    do
    {
        printf("Digite seu nome completo: ");
        fflush(stdin);
        fgets(nome[userCount], 100, stdin);
    } while (strlen(nome[userCount]) < 2);
}
void emailUser (char *email[][100], int userCount)
{
    do
    {
        printf("Digite o email: ");
        fgets(email[userCount], 100, stdin);
    } while (strchr(email[userCount], '@') == NULL);
}
void sexoUser (char *sexo[][100], int userCount)
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
void enderecoUser(char *endereco[][100], int userCount)
{
    do
    {
        printf("Digite seu endereco: ");
        fflush(stdin);
        fgets(endereco[userCount], 100, stdin);
    } while (strlen(endereco[userCount]) < 2);
}
void alturaUser(double *altura, int userCount)
{
    do
    {
        printf("Digite sua altura: ");
        scanf("%lf", &altura[userCount]);
    } while (altura[userCount] < 1 || altura[userCount] > 2);
}
void vacinaUser(bool *vacina, int userCount)
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

int excludeUser(){//Excluir os dados do usuário

    return 0;
}

int printUser(){//Printar na tela limpa os dados do usuário

    return 0;
}

int backupUser(){//Salvar os dados do usuário num backup

    return 0;
}

int restoreUser(){//Restaurar os dados do usuário salvos no backup

    return 0;
}

int buscaUser(){//Responsavel por buscar os dados do usuario
    int escolha;

    printf("Deseja encontrar o usuario atraves do e-mail (1) ou atraves do ID (2)?");
    scanf("%d", &escolha);

    switch (escolha){
    case 1:
        buscaEmail();

        if (buscaEmail == 1){
            printf("E-mail nao presente no banco de dados");
            menu();
        }
        break;
        
    case 2:
        /* code */
        break;
    
    default:
        break;
    }

    return 0;
}

int validaEmail(){//Valida se há @ no email

    return 0;
}

int buscaEmail(){//Busca nos dados se há um email igual
    char emailBusca;
    int escolha;

    do{
        printf("Qual o e-mail?");
        scanf("%s", emailBusca);

        validaEmail();

        if (validaEmail == 1){
            printf("E-mail invalido\n");
            printf("Deseja voltar ao menu (1) ou tentar novamente (2)?");
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1:
                menu();
                break;
            case 2:
                buscaEmail();
                break;
            
            default: 
                break;
            }
        }
        
    } while (validaEmail == 1);

    for (int i = 0; i != quantidadeUser; i++){
        if (emailBusca == emailUser[i]){
            pontoVetorEmail = i;
        }
    }
    return pontoVetorEmail;
}

int buscaID(){//Busca nos dados se há um ID igual
    int IDBusca;

    printf("Qual o ID?");
    scanf("%d", &IDBusca);

    for (int i = 0; i != quantidadeUser; i++){
        if (IDBusca == IDUser[i]){
            pontoVetorID = i;
        }
        else{
        printf("Valor n encontrado");
        }
    }

    return pontoVetorID;
}

int encerra(){//Encerra e se despede
    printf("Agradecemos pela preferencia\n--A lista final de usuarios--");
    for (int i = 0; i < quantidadeUser; i++){
        printf("Cadastro ID: %d\nNome do usuario: %s\nEndereco: %s\nVacinado: %s\nAltura: %d\nE-mail: %s\nSexo: %s\n",IDUser[i], nomeUser[i], adressUser[i], vacina[i],alturaUser[i]);
    }

    return 0;
}
//Término das criações das funções

int main(){


    menu();

    return 0;
}
