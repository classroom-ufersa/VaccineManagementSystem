#include <stdio.h>
#include <stdlib.h>

typedef struct vacina{
    char nome[50];
    char lote[50];
    char data_fab[50];
    char data_val[50];
}Vacina;

typedef struct vac_celula{
    Vacina *vacinas;
    struct vac_celula* prox;
} Vac_Celula;
//Lista Vac funciona como nó

Vac_Celula* Inicializa_Lista_Vac(void){
    Vac_Celula* lista = (Vac_Celula*) malloc(sizeof(Vac_Celula));
    if(lista == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return(lista);
}

Vac_Celula* Adiciona_Vacina(Vac_Celula* celula){
    if (celula->prox == NULL){
        printf("Primeiro");
        Vac_Celula* outra_vac = (Vac_Celula*) malloc(sizeof(Vac_Celula));
        if(outra_vac == NULL){
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        printf("Insira o nome da vacina:\n");
        scanf("%s", outra_vac->vacinas->nome);
        printf("Insira o lote da vacina %s:\n", outra_vac->vacinas->nome);
        scanf("%s", outra_vac->vacinas->lote);
        printf("Insira a data de fabricação da vacina %s:\n", outra_vac->vacinas->nome);
        scanf("%s", outra_vac->vacinas->data_fab);
        printf("Insira a data de validade da vacina %s:\n", outra_vac->vacinas->nome);
        scanf("%s", outra_vac->vacinas->data_val);
        celula = outra_vac;
        return(celula);
    }
    else{
        printf("Segundo");
        while(celula->prox != NULL){
            celula = celula->prox;
        }
        Vac_Celula* nova_vac = (Vac_Celula*) malloc(sizeof(Vac_Celula));
        if(nova_vac == NULL){
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        printf("Insira o nome da vacina:\n");
        scanf(" %[^\n]", nova_vac->vacinas->nome);
        printf("Insira o lote da vacina %s:\n", nova_vac->vacinas->nome);
        scanf(" %[^\n]", nova_vac->vacinas->lote);
        printf("Insira a data de fabricação da vacina %s:\n", nova_vac->vacinas->nome);
        scanf(" %[^\n]", nova_vac->vacinas->data_fab);
        printf("Insira a data de validade da vacina %s:\n", nova_vac->vacinas->nome);
        scanf(" %[^\n]", nova_vac->vacinas->data_val);
        celula->prox = nova_vac;
        nova_vac->prox = NULL;
        celula = celula->prox;
        return(celula);
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


