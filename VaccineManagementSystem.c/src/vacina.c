#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vacina{
    char nome[50];
    char lote[50];
    char val[50];
    char fab[50];
    struct vacina* prox;
}Vacina;

typedef struct lista_vac{
    Vacina* primeira_vac;
}Lista_Vac; 

Vacina* inicializa_vacina(){
    Vacina* vacina = malloc(sizeof(Vacina));
    if(vacina == NULL){
        printf("Erro ao alocar memória.\n");
    }
    vacina->prox = NULL;
    return(vacina);
}

Lista_Vac* inicializa_lista(){
    Lista_Vac* primeiro = malloc(sizeof(Lista_Vac));
    if(primeiro == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return(primeiro);
}

Vacina* adiciona_vacina(Lista_Vac* primeiro){
    FILE* entrada;
    entrada = fopen("vacinas.txt", "a+");
    if(entrada == NULL) {
        printf("\nERRO!\n");
        exit(1);
    }
    Vacina *nova_vacina = malloc(sizeof(Vacina));
    if(nova_vacina == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    printf("Insira o nome da vacina:\n");
    scanf(" %[^\n]s", nova_vacina->nome);
    printf("Insira o lote da vacina %s:\n", nova_vacina->nome);
    scanf(" %[^\n]s", nova_vacina->lote);
    printf("Insira a data de fabricação da vacina %s:\n", nova_vacina->nome);
    scanf(" %[^\n]s", nova_vacina->fab);
    printf("Insira a data de validade da vacina %s:\n", nova_vacina->nome);
    scanf(" %[^\n]s", nova_vacina->val);

    fprintf(entrada, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", nova_vacina->nome, nova_vacina->lote, nova_vacina->fab, nova_vacina->val);

    nova_vacina->prox = primeiro->primeira_vac;
    primeiro->primeira_vac = nova_vacina;

    fclose(entrada);
    
    return(NULL);
}

void insere_vacina_txt(Lista_Vac* primeiro_no){
    Vacina* Rascunho = primeiro_no->primeira_vac;
    while(Rascunho->prox != NULL){
        printf("%s\n", Rascunho->nome);
        Rascunho = Rascunho->prox;
    }
    Rascunho = NULL;
    free(Rascunho);
    /*FILE* entrada = fopen("/home/abner/Desktop/Projeto/VaccineManagementSystem/VaccineManagementSystem.c/src/vacina.txt", "a+");
    if(entrada == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }
    Vacina* ponteiro = primeiro_no->primeira;
    while(ponteiro->prox != NULL){
        fprintf(entrada, "\nNome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", ponteiro->nome, ponteiro->lote,ponteiro->fab,ponteiro->val);
        ponteiro = ponteiro->prox;
    }
    ponteiro = NULL;
    free(ponteiro);
    fclose(entrada);*/
}

void copiar_vacinas(Lista_Vac* lista) {
    FILE* entrada;
    char linha[100];
    char nome[50];
    char lote[50];
    char data_fab[50];
    char data_val[50];

    entrada = fopen("vacinas.txt", "rt");

    if(entrada == NULL) {
        printf("ERRO!\n");
        return;
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);
        
        strcpy(nome, lista->primeira_vac->nome);
        strcpy(lote, lista->primeira_vac->lote);
        strcpy(data_fab, lista->primeira_vac->fab);
        strcpy(data_val, lista->primeira_vac->val);

        lista->primeira_vac = lista->primeira_vac->prox;
    }

    printf("\n");

    fclose(entrada);
}

/*Lista_Vac* Insere_Vacina(Lista_Vac* lista){
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
*/

