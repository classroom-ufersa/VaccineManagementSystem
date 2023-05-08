#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct vacina{
    char nome[50];
    char lote[50];
    char val[50];
    char fab[50];
    struct vacina* prox;
}Vacina;

Vacina* Banco_Dados() {
    char linha[100];

    Vacina* primeira_celula = NULL;
    FILE* arquivo_entrada = fopen("vacinas.txt", "r");
    if(arquivo_entrada == NULL){
        printf("Nenhuma Vacina Cadastrada!\n\n");
        return;
    }

    while(fgets(linha, 100, arquivo_entrada) != NULL){
        Vacina* nova_vac = malloc(sizeof(Vacina));
        if(nova_vac == NULL){
            printf("Erro na alocação de memória!\n");
            exit(1);
        }
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nova_vac->nome, nova_vac->lote, nova_vac->fab, nova_vac->val);
        nova_vac->prox = primeira_celula;
        primeira_celula = nova_vac;
    }

    fclose(arquivo_entrada);

    return(primeira_celula);
}

Vacina* adiciona_vacina(){
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
    nova_vacina->nome[0] = toupper(nova_vacina->nome[0]);
    printf("Insira o lote da vacina %s:\n", nova_vacina->nome);
    scanf(" %[^\n]s", nova_vacina->lote);
    printf("Insira a data de fabricação da vacina %s:\n", nova_vacina->nome);
    scanf(" %[^\n]s", nova_vacina->fab);
    printf("Insira a data de validade da vacina %s:\n", nova_vacina->nome);
    scanf(" %[^\n]s", nova_vacina->val);

    fprintf(entrada, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", nova_vacina->nome, nova_vacina->lote, nova_vacina->fab, nova_vacina->val);

    fclose(entrada);
    
    return(NULL);
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
        printf("Nenhuma Vacina Cadastrada!\n\n");
        return;
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);

        if((strcmp(nome, busca_vac) == 0) && (strcmp(lote, busca_lote) == 0)) {
            printf("Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", nome, lote, data_fab, data_val);

            fclose(entrada);

            return;
        }
    }
    printf("Vacina não Cadastrada!\n\n");

    fclose(entrada);
}

void Remove_Vacina(){
    char linha[100], nome_deleta[50], lote_deleta[50];
    int contador = 0;
    printf("Insira o nome da vacina que você deseja remover:\n");
    scanf(" %[^\n]", nome_deleta);
    printf("Insira o lote da vacina que você deseja remover:\n");
    scanf(" %[^\n]", lote_deleta);
    Vacina* primeira_celula = NULL;
    FILE* arquivo_entrada = fopen("vacinas.txt", "r");
    if(arquivo_entrada == NULL){
        printf("Nenhuma Vacina Cadastrada!\n\n");
        return;
    }

    while(fgets(linha, 100, arquivo_entrada) != NULL){
        Vacina* nova_vac = malloc(sizeof(Vacina));
        if(nova_vac == NULL){
            printf("Erro na alocação de memória!\n");
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
        printf("Erro ao abrir o arquivo de entrada!\n");
        exit(1);
    }
    do{
        if((strcmp(rascunho->nome, nome_deleta) != 0) && (strcmp(rascunho->lote, lote_deleta) != 0)) {
            fprintf(novo_arquivo,"Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome,rascunho->lote,rascunho->fab,rascunho->val);
            anterior = rascunho;
            rascunho = rascunho->prox;
        }
        else if(rascunho->prox == NULL && (strcmp(rascunho->nome, nome_deleta) == 0) && (strcmp(rascunho->lote, lote_deleta) == 0)) {
            anterior->prox = NULL;
            contador++;
            free(rascunho);
        }
        else if((strcmp(rascunho->nome, nome_deleta) == 0) && (strcmp(rascunho->lote, lote_deleta) == 0)) {
            if(anterior == NULL){
                contador++;
                rascunho = rascunho->prox; 
            }
            else{
                anterior->prox = rascunho->prox;
                free(rascunho);
                rascunho = anterior->prox;
                contador++;
            }
        }
        if(rascunho->prox == NULL){
            if((strcmp(rascunho->nome, nome_deleta) != 0) && (strcmp(rascunho->lote, lote_deleta) != 0)) {
                fprintf(novo_arquivo,"Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome,rascunho->lote,rascunho->fab,rascunho->val);
            }
        }

    } 
    while(rascunho->prox != NULL);

    if(contador == 0)
        printf("Esta vacina não está cadastrada!\n\n");
        
    contador = 0;

    fclose(novo_arquivo);
}

void Editar_Vacina()
{
    int opcao, escolha;
    int contador = 0;
    char linha[100], nome_edita[50];
    printf("Insira o nome da vacina que você deseja editar:\n");
    scanf(" %[^\n]s", nome_edita);
    Vacina *primeira_celula = NULL;
    FILE *arquivo_entrada = fopen("vacinas.txt", "r");
    if (arquivo_entrada == NULL)
    {
        printf("Nenhuma Vacina Cadastrada!\n\n");
        return;
    }

    while (fgets(linha, 100, arquivo_entrada) != NULL)
    {
        Vacina *nova_vac = malloc(sizeof(Vacina));
        if (nova_vac == NULL)
        {
            printf("Erro na alocação de memória!\n");
            exit(1);
        }
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nova_vac->nome, nova_vac->lote, nova_vac->fab, nova_vac->val);
        nova_vac->prox = primeira_celula;
        primeira_celula = nova_vac;
    }

    fclose(arquivo_entrada);

    Vacina *rascunho = primeira_celula;
    FILE *novo_arquivo = fopen("vacinas.txt", "w");
    if (novo_arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada!\n");
        exit(1);
    }
    do
    {
        escolha = 0;
        if ((strcmp(rascunho->nome, nome_edita) != 0))
        {
            fprintf(novo_arquivo, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome, rascunho->lote, rascunho->fab, rascunho->val);
            rascunho = rascunho->prox;
        }
        else
        {
            while (escolha != 2)
            {
                printf("Vacina Atual.\nNome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome, rascunho->lote, rascunho->fab, rascunho->val);
                printf("Digite o que deseja editar:\n1-Nome\n2-Lote\n3-Data de Fabricação\n4-Data de Validade\n");
                scanf("%d", &opcao);
                contador++;
                switch (opcao)
                {
                case 1:
                    printf("Digite o novo nome da vacina: ");
                    scanf(" %[^\n]s", rascunho->nome);
                    rascunho->nome[0] = toupper(rascunho->nome[0]);
                    break;
                case 2:
                    printf("Digite o novo lote da vacina: ");
                    scanf(" %[^\n]s", rascunho->lote);
                    break;
                case 3:
                    printf("Digite a nova data de fabricação da vacina: ");
                    scanf(" %[^\n]s", rascunho->fab);
                    break;
                case 4:
                    printf("Digite a nova data de validade da vacina: ");
                    scanf(" %[^\n]s", rascunho->val);
                    break;
                }
                printf("Deseja fazer mais alguma alteração?\n");
                printf("1-Sim\n2-Não: ");
                scanf("%d", &escolha);
            }

            fprintf(novo_arquivo, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome, rascunho->lote, rascunho->fab, rascunho->val);
            rascunho = rascunho->prox;
        }
        if (rascunho->prox == NULL)
        {
            if ((strcmp(rascunho->nome, nome_edita) != 0))
            {
                fprintf(novo_arquivo, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", rascunho->nome, rascunho->lote, rascunho->fab, rascunho->val);
            }
        }
    }while (rascunho->prox != NULL);
    if (contador == 0){
        printf("Esta vacina não está cadastrada!\n\n");
    }
    contador = 0;
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
        printf("Vacinas não Cadastradas!\n\n");
        return;
    }
    while(fgets(linha, 100, entradas) != NULL){
        sscanf(linha, "Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", nome, lote, data_fab, data_val);
        printf("Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s\n", nome, lote, data_fab, data_val);
    }

    printf("\n");
    fclose(entradas);
}