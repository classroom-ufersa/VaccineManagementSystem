#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "vacina.c"

typedef struct cartao{
    char vacina[50];
    int dose;
    char data[20];
}Cartao;

typedef struct pessoa{
    char nome[100];
    int idade;
    int documento;
    struct cartao cartao;
    struct pessoa* prox;
}Pessoa;

void Aplicar_Vacina(){
    Pessoa* nova = (Pessoa*) malloc(sizeof(Pessoa));
    FILE* entrada;

    entrada = fopen("pessoas.txt", "at");
    if(entrada == NULL) {
        printf("\nERRO!\n");
        exit(1);
    }
    printf("Informe o nome da pessoa: ");
    scanf(" %[^\n]s", nova->nome);
    nova->nome[0] = toupper(nova->nome[0]);
    printf("Informe a idade da pessoa: ");
    scanf("%d", &nova->idade);
    printf("Informe o documento da pessoa: ");
    scanf("%d", &nova->documento);
    printf("Insira o nome da vacina aplicada:\n");
    scanf(" %[^\n]", nova->cartao.vacina);
    printf("Insira a dose da vacina aplicada:\n");
    scanf("%i", &nova->cartao.dose);
    printf("Insira a data da aplicação da vacina:\n");
    scanf(" %[^\n]", nova->cartao.data);
    fprintf(entrada, "Nome: %s\tIdade: %d\tDocumento: %d\tVacina: %s\tDose: %i\tData de aplicação: %s\n", nova->nome, nova->idade, nova->documento, nova->cartao.vacina, nova->cartao.dose, nova->cartao.data);
    fclose(entrada);
}


Pessoa* Banco_Dados_Pessoa() {
    char linha[100];

    Pessoa* primeira_celula = NULL;
    FILE* arquivo_entrada = fopen("pessoas.txt", "r");
    if(arquivo_entrada == NULL)
        return(NULL);

    while(fgets(linha, 100, arquivo_entrada) != NULL){
        Pessoa* nova_pes = malloc(sizeof(Pessoa));
        if(nova_pes == NULL){
            printf("Erro na alocação de memória!\n");
            exit(1);
        }
        sscanf(linha, "Nome: %s\tIdade: %d\tDocumento: %d\n", nova_pes->nome, &nova_pes->idade, &nova_pes->documento);
        nova_pes->prox = primeira_celula;
        primeira_celula = nova_pes;
    }

    fclose(arquivo_entrada);

    return(primeira_celula);
}

void listar_pessoas(Pessoa* pessoa) {
    FILE* entrada = fopen("pessoas.txt", "rt");
    if(entrada == NULL) {
        printf("Pessoas não Cadastradas!\n\n");
        return;
    }

    do {
        printf("Nome: %s\tIdade: %d\tDocumento: %d\n", pessoa->nome, pessoa->idade, pessoa->documento);
        pessoa = pessoa->prox;
        if(pessoa->prox == NULL) {
            printf("Nome: %s\tIdade: %d\tDocumento: %d\n", pessoa->nome, pessoa->idade, pessoa->documento);
        }
    }
    while(pessoa->prox != NULL);

    printf("\n");
    fclose(entrada);
}




void CombSort_Pessoa(int n)
{
    int trocado = 1;
    int i, j;
    char temp[200];
    int controle = 0;
    char nomes[10][200];
    int contador = 0;

    FILE* teste;

    teste = fopen("pessoas.txt", "rt");
    if(teste == NULL) {
        printf("\nERRO!\n");
        exit(1);
    }

    while(contador < n) {
        fgets(nomes[contador], 200, teste);
        contador++;
    }
    int lacuna = n;

    while (lacuna > 1 || trocado == 1)
    { 
        lacuna = lacuna / 1.3;
        if (lacuna < 1)
        {
            lacuna = 1;
        }

        trocado = 0;
        for (i = 0, j = i + lacuna; j < n; i++, j++)
        { 
            if (strcmp(nomes[i], nomes[j]) > 0)
            {
                strcpy(temp, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], temp);
                trocado = 1;
            }
        }
    }
    fclose(teste);

    teste = fopen("pessoas.txt", "wt");

    while (controle < n)
    {
        fprintf(teste, "%s", nomes[controle]);
        controle++;
    }

    fclose(teste);
}

int contador_pessoa()
{

    FILE *abre;
    char linha[200];
    int numLinhas = 0;

    abre = fopen("pessoas.txt", "rt");
    if (abre == NULL)
    {
        printf("ERRO ao abrir o arquivo!");
        return 0;
    }

    while (fgets(linha, 200, abre) != NULL)
    {
        numLinhas++;
    }

    fclose(abre);

    return (numLinhas);
}

void qnt_vac(){
    FILE* entrada_pessoas = fopen("pessoas.txt", "r+");
    char nome_vac[50];
    printf("Insira o nome da vacina que deseja se fazer o quantitativo:\n");
    scanf(" %[^\n]", nome_vac);
    char linha[200];
    if(entrada_pessoas == NULL){
        printf("Erro ao abrir o arquivo de pessoas.\n");
        exit(1);
    }
    int qnt_pessoas_vacinadas = 0;
    Pessoa* cont = malloc(sizeof(Pessoa));
    if(cont == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    while(fgets(linha, 100, entrada_pessoas) != NULL){
        sscanf(linha, "Nome: %s\tIdade: %i\tDocumento:%i\tVacina: %s\tDose:%i\tData de aplicação:%s", cont->nome, &cont->idade, &cont->documento, cont->cartao.vacina, &cont->cartao.dose, cont->cartao.data);
        if(strcmp(cont->cartao.vacina, nome_vac) == 0){
            qnt_pessoas_vacinadas++;
        };
    }
    free(cont);
    printf("%i pessoas foram vacinadas com %s.\n", qnt_pessoas_vacinadas, nome_vac);
    fclose(entrada_pessoas);
}