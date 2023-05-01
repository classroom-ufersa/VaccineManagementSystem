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
}Lista_Vac; 
//Lista Vac funciona como nó

Lista_Vac* Inicia_Lista_Vac(void){
    Lista_Vac* Lista = (Lista_Vac*) malloc(sizeof(Lista_Vac));
    if (Lista == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    Lista->prox = NULL;
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
        return 1;
    }
    else{
        return -1;
    }
}

Lista_Vac* Insere_Vacina_Vazia(Lista_Vac* lista){
    printf("Insira o nome da vacina:\n");
    scanf(" %[^\n]", lista->vacinas->nome);
    printf("Insira o lote da vacina %s:\n", lista->vacinas->nome);
    scanf("%i", &lista->vacinas->lote);
    printf("Insira a data de fabricação da vacina %s:\n", lista->vacinas->nome);
    scanf(" %[^\n]", lista->vacinas->data_fab);
    printf("Insira a data de validade da vacina %s:\n", lista->vacinas->nome);
    scanf(" %[^\n]", lista->vacinas->data_val);
    lista->prox = NULL;
    return (lista);
}

Lista_Vac* Insere_Vacina(Lista_Vac* lista){
    FILE* entrada;
    Lista_Vac* insere_vac = (Lista_Vac*) malloc(sizeof(Lista_Vac));

    entrada = fopen("vacinas.txt", "at");
    if(entrada == NULL) {
        printf("ERRO!\n");
        exit(1);
    }

    if(insere_vac == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    printf("Insira o nome da vacina:\n");
    scanf(" %[^\n]", insere_vac->vacinas->nome);
    printf("Insira o lote da vacina %s:\n", insere_vac->vacinas->nome);
    scanf("%i", &insere_vac->vacinas->lote);
    printf("Insira a data de fabricação da vacina %s:\n", insere_vac->vacinas->nome);
    scanf(" %[^\n]", insere_vac->vacinas->data_fab);
    printf("Insira a data de validade da vacina %s:\n", insere_vac->vacinas->nome);
    scanf(" %[^\n]", insere_vac->vacinas->data_val);

    fprintf(entrada, "Nome: %s\tLote: %d\tData de Fabricacao: %s\tData de Validade: %s\n", insere_vac->vacinas->nome, insere_vac->vacinas->lote, insere_vac->vacinas->data_fab, insere_vac->vacinas->data_val);

    fclose(entrada);

    insere_vac->prox = NULL;
    lista->prox = insere_vac;
    lista = lista->prox;
    return(insere_vac);
}