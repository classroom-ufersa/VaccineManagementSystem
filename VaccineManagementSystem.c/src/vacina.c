#include <stdio.h>
#include <stdlib.h>

typedef struct vacina{
    char nome[50];
    int lote;
    char data_fab[50];
    char data_val[50];
    struct vacina* prox_vac;
}Vacina;

Vacina *cria_vacina(Vacina *vac)
{
    Vacina *outro_vac;
    char entrada;
    vac = (Vacina *)malloc(sizeof(Vacina));
    if (vac == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    printf("Insira o nome da vacina:\n");
    scanf(" %[^\n]", vac->nome);
    printf("Insira o lote da vacina %s:\n", vac->nome);
    scanf("%i", &vac->lote);
    printf("Insira a data de fabricação da vacina %s:(Formato: xx-xx-xxxx)\n", vac->nome);
    scanf("%s", vac->data_fab);
    printf("Insira o data de validade da vacina %s:(Formato: xx-xx-xxxx)\n", vac->nome);
    scanf("%s", vac->data_val);

    vac->prox_vac = NULL;
    Vacina *primeira = vac;

    printf("Deseja adicionar outra vacina ao sistema?[S/N]\n");
    scanf(" %[^\n]", &entrada);
    while (entrada == 's' || entrada == 'S')
    {
        outro_vac = (Vacina *)malloc(sizeof(Vacina));
        if (outro_vac == NULL)
        {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        printf("Insira o nome da vacina:\n");
        scanf(" %[^\n]", outro_vac->nome);
        printf("Insira o lote da vacina %s:\n", outro_vac->nome);
        scanf("%i", &outro_vac->lote);
        printf("Insira a data de fabricação da vacina %s:(Formato: xx-xx-xxxx)\n", outro_vac->nome);
        scanf(" %[^\n]", outro_vac->data_fab);
        printf("Insira o data de validade da vacina %s:(Formato: xx-xx-xxxx)\n", outro_vac->nome);
        scanf(" %[^\n]", outro_vac->data_val);
        printf("Deseja adicionar outra vacina ao sistema?[S/N]\n");
        scanf(" %[^\n]", &entrada);
        outro_vac->prox_vac = NULL;
        vac->prox_vac = outro_vac;
        vac = vac->prox_vac;
    }

    return (primeira);
}
