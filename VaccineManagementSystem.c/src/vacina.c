#include <stdio.h>
#include <stdlib.h>

typedef struct vacina{
    char nome[50];
    int lote;
    char data_fab[20];
    char data_val[20];
}Vacina;

Vacina* cria_vacina(){
    char endereco[100] = 'VaccineManagementSystem/VaccineManagementSystem.c/src/vacinas.txt';
    FILE* vacinas = fopen(endereco, 'rt');
    









    //Verificar se já existem vacinas cadastradas
    Vacina* Nova_Vacina = (Vacina*) malloc(sizeof(Vacina));
    if(Nova_Vacina == NULL){
        printf("Erro ao armazenar a nova vacina.\n");
        exit(1);
    }
    printf("Qual o nome da vacina que será cadastrada?");
    scanf(" %[^\n]", Nova_Vacina->nome);
    printf("Qual o lote da vacina %s?\n", Nova_Vacina->nome);
    scanf("%i", &Nova_Vacina->lote);
    printf("Qual a data de fabricação da vacina %s? (Formato: xx-xx-xxxx)\n", Nova_Vacina);
    scanf(" %[^\n]", Nova_Vacina->data_fab);
    printf("Qual a data de validade da vacina %s? (Formato: xx-xx-xxxx)\n", Nova_Vacina);
    scanf(" %[^\n]", Nova_Vacina->data_fab);


    return(NULL);
}

