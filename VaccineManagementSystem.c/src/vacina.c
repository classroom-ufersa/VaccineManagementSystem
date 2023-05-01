#include <stdio.h>
#include <stdlib.h>

typedef struct vacina{
    char nome[50];
    char lote[50];
    char val[50];
    char fab[50];
    struct vacina* prox;
} Vacina;

typedef struct lista_vac{
    Vacina* primeira;
} Lista_Vac;

Vacina* inicializa_vacina(){
    Vacina* vacina = malloc(sizeof(Vacina));
    if(vacina == NULL){
        printf("Erro ao alocar memória.\n");
    }
    vacina->prox = NULL;
    return(vacina);
}

Lista_Vac* inicializa_lista(Vacina* vacina){
    Lista_Vac* primeiro = malloc(sizeof(Lista_Vac));
    if(primeiro == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    primeiro->primeira = vacina; 
    return(primeiro);
}

Vacina* adiciona_vacina(Lista_Vac* primeiro){
    Vacina* nova_vacina = malloc(sizeof(Vacina));
    if(nova_vacina == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    if(primeiro->primeira->prox == NULL){
        printf("Insira o nome da vacina:\n");
        scanf(" %[^\n]", nova_vacina->nome);
        printf("Insira o lote da vacina %s:\n", nova_vacina->nome);
        scanf(" %[^\n]", nova_vacina->lote);
        printf("Insira a data de fabricação da vacina %s:\n", nova_vacina->nome);
        scanf(" %[^\n]", nova_vacina->fab);
        printf("Insira a data de validade da vacina %s:\n", nova_vacina->nome);
        scanf(" %[^\n]", nova_vacina->val);
        primeiro->primeira->prox = nova_vacina;
        nova_vacina->prox = NULL;
        return(primeiro);
    }
    else{
        Vacina *ultima = malloc(sizeof(Vacina));
        if (ultima == NULL)
        {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        ultima = primeiro->primeira->prox;
        while(ultima->prox != NULL){
            ultima = ultima->prox;
        }
        printf("Insira o nome da vacina:\n");
        scanf(" %[^\n]", nova_vacina->nome);
        printf("Insira o lote da vacina %s:\n", nova_vacina->nome);
        scanf(" %[^\n]", nova_vacina->lote);
        printf("Insira a data de fabricação da vacina %s:\n", nova_vacina->nome);
        scanf(" %[^\n]", nova_vacina->fab);
        printf("Insira a data de validade da vacina %s:\n", nova_vacina->nome);
        scanf(" %[^\n]", nova_vacina->val);
        ultima->prox = nova_vacina;
        nova_vacina->prox = NULL;
        
        return(primeiro);
    }
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


