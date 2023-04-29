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

int Lista_Vazia(Lista_Vac* lista){
    if(lista->prox == NULL){
        return(1);
    }
    else{
        return(0);
    }
}

Lista_Vac* Cria_Vacina(Lista_Vac* lista, int );