#include <stdio.h>
#include <stdlib.h>

typedef struct vacina{
    char nome[50];
    int lote;
    char data_fab[50];
    char data_val[50];
}Vacina;

typedef struct lista_vac{
    Vacina *vacinas;
    struct lista_vac* prox;
} Lista_Vac;
//Lista Vac funciona como nó

Lista_Vac* Inicia_Lista_Vac(void){
    Lista_Vac* Lista = (Lista_Vac*) malloc(sizeof(Lista_Vac));
    if (Lista == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return(Lista);
}

void listar_vacinas() {
    FILE* entrada;
    char linha[100];
    char nome[50];
    int lote;
    char data_fab[50];
    char data_val[50];

    entrada = fopen("vacinas.txt", "rt");

    if(entrada == NULL) {
        printf("ERRO!\n");
        exit(1);
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tLote: %d\tData de Fabricacao: %s\tData de Validade: %s", nome, &lote, data_fab, data_val);

        printf("Nome: %s\tLote: %d\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);
    }

    printf("\n");

    fclose(entrada);
}

int Lista_Vazia(Lista_Vac* lista){
    if(lista->prox == NULL){
        return(1);
    }
    else{
        return(0);
    }
}

Lista_Vac* Cria_Vacina(Lista_Vac* lista, int );