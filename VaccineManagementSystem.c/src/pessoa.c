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

Pessoa* add_pessoa(Pessoa* p) {
    Pessoa* nova = (Pessoa*) malloc(sizeof(Pessoa));

    printf("Informe o nome da pessoa: ");
    scanf(" %[^\n]s", &p->nome);
    printf("Informe a idade da pessoa: ");
    scanf("%d", &p->idade);
    printf("Informe o documento da pessoa: ");
    scanf("%d", &p->documento);

    return(nova);
}

void listar_pessoas(Pessoa* p) {
    Pessoa* listar;

    for(listar = p; listar != NULL; listar = listar->)
}