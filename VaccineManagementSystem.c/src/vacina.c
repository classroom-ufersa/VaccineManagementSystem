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

Vacina* buscar_vacina() {
    FILE* entrada;
    Vacina* rascunho = NULL;

    char nome_vac[50];
    char num_lote[50];
    printf("Digite o nome da vacina: ");
    scanf(" %[^\n]s", nome_vac);
    printf("Digite o numero do lote: ");
    scanf(" %[^\n]s", num_lote);

    char nome[50];
    char lote[50];
    char data_fab[50];
    char data_val[50];
    char linha[100];

    entrada = fopen("vacinas.txt", "rt");
    if(entrada == NULL) {
        printf("Nenhuma Vacina Cadastrada!\n");
        return(NULL);
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);

        if((strcmp(nome, nome_vac) == 0) && (strcmp(lote, num_lote) == 0)) {
            strcpy(rascunho->nome, nome);
            strcpy(rascunho->lote, lote);
            strcpy(rascunho->fab, data_fab);
            strcpy(rascunho->val, data_val);

            return(rascunho);
        }
    }
    fclose(entrada);
    free(entrada);
    return(NULL);
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
        if(rascunho->nome != nome_deleta && rascunho->lote != lote_deleta){
            fprintf(novo_arquivo,"Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome,rascunho->lote,rascunho->fab,rascunho->val);
            anterior = rascunho;
            rascunho = rascunho->prox;
        }
        else if(rascunho->prox == NULL && rascunho->nome == nome_deleta && rascunho->lote == nome_deleta){
            anterior->prox = NULL;
            free(rascunho);
        }
        else if(rascunho->nome == nome_deleta && rascunho->lote == nome_deleta){
            anterior->prox = rascunho->prox;
            free(rascunho);
            rascunho = anterior->prox;
        }

    }
    fclose(novo_arquivo);

}
