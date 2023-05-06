#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    char nome[100];
    int idade;
    int documento;
    //Cartao de vacina
}Pessoa;

Pessoa* cria_pessoa() {
    return(NULL);
}

Pessoa* add_pessoa() {
    Pessoa* nova = (Pessoa*) malloc(sizeof(Pessoa));
    FILE* entrada;

    entrada = fopen("pessoas.txt", "at");

    printf("Informe o nome da pessoa: ");
    scanf(" %[^\n]s", nova->nome);
    printf("Informe a idade da pessoa: ");
    scanf("%d", &nova->idade);
    printf("Informe o documento da pessoa: ");
    scanf("%d", &nova->documento);

    fprintf(entrada, "Nome: %s\tIdade: %d\tDocumento: %d\n", nova->nome, nova->idade, nova->documento);

    fclose(entrada);

    return(nova);
}

void listar_pessoas() {
    FILE* entrada;
    char linha[100];
    char nome[50];
    int idade;
    int doc;

    entrada = fopen("pessoas.txt", "rt");

    if(entrada == NULL) {
        printf("Pessoas não Cadastradas!\n");
        return;
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tIdade: %d\tDocumento: %d", nome, &idade, &doc);

        printf("Nome: %s\tIdade: %d\tDocumento: %d\n", nome, idade, doc);
    }
    printf("\n");

    fclose(entrada);
}