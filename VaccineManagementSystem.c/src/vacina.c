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
    //primeiro->primeira_vac = nova_vacina;

    fclose(entrada);
    
    return(NULL);
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
        printf("Banco de Dados não existe!\n");
        return;
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);
        
        strcpy(lista->primeira_vac->nome, nome);
        strcpy(lista->primeira_vac->lote, lote);
        strcpy(lista->primeira_vac->fab, data_fab);
        strcpy(lista->primeira_vac->val, data_val);

        lista->primeira_vac = lista->primeira_vac->prox;
    }

    printf("\n");

    fclose(entrada);
}

void buscar_vacina() {
    FILE* entrada;

    char busca_vac[50];
    char busca_lote[50];
    printf("Digite o nome da vacina: ");
    scanf(" %[^\n]s", busca_vac);
    printf("Digite o numero do lote: ");
    scanf(" %[^\n]s", busca_lote);

    char nome[50];
    char lote[50];
    char data_fab[50];
    char data_val[50];
    char linha[100];

    entrada = fopen("vacinas.txt", "r");
    if(entrada == NULL) {
        printf("Nenhuma Vacina Cadastrada!\n");
        return;
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);

        if((strcmp(nome, busca_vac) == 0) && (strcmp(lote, busca_lote) == 0)) {
            printf("Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", nome, lote, data_fab, data_val);

            break;
        }
    }
    fclose(entrada);
}

void Remove_Vacina(){
    char linha[100], nome_deleta[50], lote_deleta[50];
    printf("Insira o nome da vacina que você deseja remover:\n");
    scanf(" %[^\n]", nome_deleta);
    printf("Insira o lote da vacina que você deseja remover:\n");
    scanf(" %[^\n]", lote_deleta);
    Vacina* primeira_celula = NULL;
    FILE* arquivo_entrada = fopen("vacinas.txt", "r");
    if(arquivo_entrada == NULL){
        printf("Erro ao abrir os arquivos de vacinas.\n");
        exit(1);
    }

    while(fgets(linha, 100, arquivo_entrada) != NULL){
        Vacina* nova_vac = malloc(sizeof(Vacina));
        if(nova_vac == NULL){
            printf("Erro na alocação de memória.");
            exit(1);
        }
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nova_vac->nome, nova_vac->lote, nova_vac->fab, nova_vac->val);
        nova_vac->prox = primeira_celula;
        primeira_celula = nova_vac;
    }

    fclose(arquivo_entrada);
    
    Vacina* rascunho = primeira_celula;
    Vacina* anterior = NULL;
    FILE* novo_arquivo = fopen("vacinas.txt", "w");
    if(novo_arquivo == NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }
    while(rascunho->prox != NULL){
        if((strcmp(rascunho->nome, nome_deleta) != 0) && (strcmp(rascunho->lote, lote_deleta) != 0)) {
            fprintf(novo_arquivo,"Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome,rascunho->lote,rascunho->fab,rascunho->val);
            anterior = rascunho;
            rascunho = rascunho->prox;
        }
        else if(rascunho->prox == NULL && (strcmp(rascunho->nome, nome_deleta) == 0) && (strcmp(rascunho->lote, lote_deleta) == 0)) {
            anterior->prox = NULL;
            free(rascunho);
        }
        else if((strcmp(rascunho->nome, nome_deleta) == 0) && (strcmp(rascunho->lote, lote_deleta) == 0)) {
            anterior->prox = rascunho->prox;
            free(rascunho);
            rascunho = anterior->prox;
        }

    }

    fclose(novo_arquivo);
}

void Editar_Vacina(){
    char linha[100], nome_edita[50];
    printf("Insira o nome da vacina que você deseja editar:\n");
    scanf(" %[^\n]s", nome_edita);
    Vacina* primeira_celula = NULL;
    FILE* arquivo_entrada = fopen("vacinas.txt", "r");
    if(arquivo_entrada == NULL){
        printf("Erro ao abrir os arquivos de vacinas.\n");
        exit(1);
    }

    while(fgets(linha, 100, arquivo_entrada) != NULL){
        Vacina* nova_vac = malloc(sizeof(Vacina));
        if(nova_vac == NULL){
            printf("Erro na alocação de memória.");
            exit(1);
        }
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nova_vac->nome, nova_vac->lote, nova_vac->fab, nova_vac->val);
        nova_vac->prox = primeira_celula;
        primeira_celula = nova_vac;
    }

    fclose(arquivo_entrada);
    
    Vacina* rascunho = primeira_celula;
    Vacina* anterior = NULL;
    FILE* novo_arquivo = fopen("vacinas.txt", "w");
    if(novo_arquivo == NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }
    while(rascunho->prox != NULL){
        if(rascunho->nome != nome_edita){
            fprintf(novo_arquivo,"Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome,rascunho->lote,rascunho->fab,rascunho->val);
            anterior = rascunho;
            rascunho = rascunho->prox;
        }
        else if(strcmp(rascunho->nome, nome_edita) == 0) {
            printf("Digite o novo lote da vacina: ");
            scanf(" %[^\n]s", rascunho->lote);
            printf("Digite a nova data de fabricação da vacina: ");
            scanf(" %[^\n]s", rascunho->fab);
            printf("Digite a nova validade da vacina: ");
            scanf(" %[^\n]s", rascunho->val);

            fprintf(novo_arquivo,"Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome,rascunho->lote,rascunho->fab,rascunho->val);
            anterior = rascunho;
            free(rascunho);
            rascunho = anterior;
        }
    }

    fclose(novo_arquivo);
}


void Lista_Vacina(){
    FILE* entradas = fopen("vacinas.txt", "r");
    char linha[100];
    char nome[50];
    char lote[50];
    char data_fab[50];
    char data_val[50];
    if(entradas == NULL){
        printf("Vacinas não Cadastradas!\n");
        return;
    }
    while(fgets(linha, 100, entradas) != NULL){
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);
        printf("Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", nome, lote, data_fab, data_val);
    }
    fclose(entradas);
}