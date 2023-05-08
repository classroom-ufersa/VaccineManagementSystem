#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct pessoa{
    char nome[100];
    int idade;
    int documento;
    struct pessoa* prox;
    //Cartao de vacina
}Pessoa;

Pessoa* Banco_Dados_Pessoa() {
    char linha[100];

    Pessoa* primeira_celula = NULL;
    FILE* arquivo_entrada = fopen("pessoas.txt", "r");
    if(arquivo_entrada == NULL)
        return(NULL);

    while(fgets(linha, 100, arquivo_entrada) != NULL){
        Pessoa* nova_pes = malloc(sizeof(Pessoa));
        if(nova_pes == NULL){
            printf("Erro na alocação de memória!\n");
            exit(1);
        }
        sscanf(linha, "Nome: %s\tIdade: %d\tDocumento: %d\n", nova_pes->nome, &nova_pes->idade, &nova_pes->documento);
        nova_pes->prox = primeira_celula;
        primeira_celula = nova_pes;
    }

    fclose(arquivo_entrada);

    return(primeira_celula);
}

Pessoa* add_pessoa() {
    Pessoa* nova = (Pessoa*) malloc(sizeof(Pessoa));
    FILE* entrada;

    entrada = fopen("pessoas.txt", "at");
    if(entrada == NULL) {
        printf("\nERRO!\n");
        exit(1);
    }

    printf("Informe o nome da pessoa: ");
    scanf(" %[^\n]s", nova->nome);
    nova->nome[0] = toupper(nova->nome[0]);
    printf("Informe a idade da pessoa: ");
    scanf("%d", &nova->idade);
    printf("Informe o documento da pessoa: ");
    scanf("%d", &nova->documento);

    fprintf(entrada, "Nome: %s\tIdade: %d\tDocumento: %d\n", nova->nome, nova->idade, nova->documento);

    fclose(entrada);

    return(nova);
}

void listar_pessoas(Pessoa* pessoa) {
    FILE* entrada = fopen("pessoas.txt", "rt");
    if(entrada == NULL) {
        printf("Pessoas não Cadastradas!\n\n");
        return;
    }

    do {
        printf("Nome: %s\tIdade: %d\tDocumento: %d\n", pessoa->nome, pessoa->idade, pessoa->documento);
        pessoa = pessoa->prox;
        if(pessoa->prox == NULL) {
            printf("Nome: %s\tIdade: %d\tDocumento: %d\n", pessoa->nome, pessoa->idade, pessoa->documento);
        }
    }
    while(pessoa->prox != NULL);

    printf("\n");
    fclose(entrada);
}

void remove_pessoa(Pessoa* primeira_celula){
    char nome_deleta[50];
    int documento_deleta;
    int contador = 0;
    printf("Insira o nome da pessoa que você deseja remover:\n");
    scanf(" %[^\n]", nome_deleta);
    printf("Insira o documento da pessoa que você deseja remover:\n");
    scanf("%d", &documento_deleta);
    
    Pessoa* rascunho = primeira_celula;
    Pessoa* anterior = NULL;
    FILE* novo_arquivo = fopen("pessoas.txt", "w");
    if(novo_arquivo == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
        exit(1);
    }
    do{
        if((strcmp(rascunho->nome, nome_deleta) != 0) && (rascunho->documento != documento_deleta)){
            fprintf(novo_arquivo,"Nome: %s\tIdade: %d\tDocumento: %d\n", rascunho->nome, rascunho->idade, rascunho->documento);
            anterior = rascunho;
            rascunho = rascunho->prox;
        }
        else if(rascunho->prox == NULL && (strcmp(rascunho->nome, nome_deleta) == 0) && (rascunho->documento == documento_deleta)) {
            anterior->prox = NULL;
            free(rascunho);
            contador++;
        }
        else if((strcmp(rascunho->nome, nome_deleta) == 0) && (rascunho->documento == documento_deleta)) {
            if(anterior == NULL){
                rascunho = rascunho->prox; 
                contador++;
            }
            else{
                anterior->prox = rascunho->prox;
                free(rascunho);
                rascunho = anterior->prox;
                contador++;
            }
        }
        if(rascunho->prox == NULL){
            if((strcmp(rascunho->nome, nome_deleta) != 0) && (rascunho->documento != documento_deleta)) {
                fprintf(novo_arquivo,"Nome: %s\tIdade: %d\tDocumento: %d\n", rascunho->nome, rascunho->idade, rascunho->documento);
            }
        }

    } 
    while(rascunho->prox != NULL);
    if(contador == 0)
        printf("Esta pessoa não está cadastrada!\n\n");

    contador = 0;

    fclose(novo_arquivo);
}

void edita_pessoa(Pessoa* primeira_celula){
    char nome_edita[50];
    int contador = 0, opcao;
    int escolha = 0;
    printf("Insira o nome da pessoa que você deseja editar:\n");
    scanf(" %[^\n]", nome_edita);
    
    Pessoa* rascunho = primeira_celula;
    FILE* novo_arquivo = fopen("pessoas.txt", "w");
    if(novo_arquivo == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n\n");
        exit(1);
    }
    do 
    {
        escolha = 0;
        if(strcmp(rascunho->nome, nome_edita) != 0) 
        {
            fprintf(novo_arquivo, "Nome: %s\tIdade: %d\tDocumento: %d\n", rascunho->nome, rascunho->idade, rascunho->documento);
            rascunho = rascunho->prox;
        }
        else 
        {
            while(escolha != 2)
            {
                printf("Pessoa Atual.\nNome: %s\tIdade: %d\tDocumento: %d\n", rascunho->nome, rascunho->idade, rascunho->documento);
                printf("Digite o que deseja editar:\n1-Nome\n2-Idade\n3-Documento\n");
                scanf("%d", &opcao);
                contador++;
                switch(opcao) 
                {
                    case 1:
                    printf("Digite o novo nome da pessoa: ");
                    scanf(" %[^\n]s", rascunho->nome);
                    rascunho->nome[0] = toupper(rascunho->nome[0]);
                    break;
                    case 2:
                    printf("Digite a nova idade da pessoa: ");
                    scanf("%d", &rascunho->idade);
                    break;
                    case 3:
                    printf("Digite o novo documento da pessoa: ");
                    scanf("%d", &rascunho->documento);
                    break;
                }
                printf("Deseja fazer mais alguma alteração?\n");
                printf("1-Sim\n2-Não: ");
                scanf("%d", &escolha);
            } 
        
            fprintf(novo_arquivo, "Nome: %s\tIdade: %d\tDocumento: %d\n", rascunho->nome, rascunho->idade, rascunho->documento);
            rascunho = rascunho->prox;
        }
    if (rascunho->prox == NULL)
        {
            if ((strcmp(rascunho->nome, nome_edita) != 0))
            {
                fprintf(novo_arquivo, "Nome: %s\tIdade: %d\tDocumento: %d\n", rascunho->nome, rascunho->idade, rascunho->documento);
            }
        } 
    }
    while(rascunho->prox != NULL);
    if(contador == 0)
        printf("Esta pessoa não está cadastrada!\n\n");

    contador = 0;

    fclose(novo_arquivo);
}

void buscar_pessoa() {
    FILE* entrada;

    char busca_pes[50];
    int busca_doc;
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]s", busca_pes);
    printf("Digite o seu numero de documento: ");
    scanf("%d", &busca_doc);

    char nome[50];
    int idade;
    int doc;
    char linha[100];

    entrada = fopen("pessoas.txt", "r");
    if(entrada == NULL) {
        printf("Nenhuma Pessoa Cadastrada!\n\n");
        return;
    }

    while(fgets(linha, 100, entrada) != NULL) {
        sscanf(linha, "Nome: %s\tIdade: %d\tDocumento: %d", nome, &idade, &doc);

        if((strcmp(nome, busca_pes) == 0) && busca_doc == doc) {
            printf("Nome: %s\tIdade: %d\tDocumento: %d\n", nome, idade, doc);

            fclose(entrada);

            return;
        }
    }
    printf("Pessoa não Cadastrada!\n\n");

    fclose(entrada);
}

void CombSort_Pessoa(int n)
{
    int trocado = 1;
    int i, j;
    char temp[200];
    int controle = 0;
    char nomes[10][200];
    int contador = 0;

    FILE* teste;

    teste = fopen("pessoas.txt", "rt");
    if(teste == NULL) {
        printf("\nERRO!\n");
        exit(1);
    }

    while(contador < n) {
        fgets(nomes[contador], 200, teste);
        contador++;
    }
    int lacuna = n;

    while (lacuna > 1 || trocado == 1)
    { 
        lacuna = lacuna / 1.3;
        if (lacuna < 1)
        {
            lacuna = 1;
        }

        trocado = 0;
        for (i = 0, j = i + lacuna; j < n; i++, j++)
        { 
            if (strcmp(nomes[i], nomes[j]) > 0)
            {
                strcpy(temp, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], temp);
                trocado = 1;
            }
        }
    }
    fclose(teste);

    teste = fopen("pessoas.txt", "wt");

    while (controle < n)
    {
        fprintf(teste, "%s", nomes[controle]);
        controle++;
    }

    fclose(teste);
}

int contador_pessoa()
{

    FILE *abre;
    char linha[200];
    int numLinhas = 0;

    abre = fopen("pessoas.txt", "rt");
    if (abre == NULL)
    {
        printf("ERRO ao abrir o arquivo!");
        return 0;
    }

    while (fgets(linha, 200, abre) != NULL)
    {
        numLinhas++;
    }

    fclose(abre);

    return (numLinhas);
}