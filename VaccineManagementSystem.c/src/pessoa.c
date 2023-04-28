#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacina.h"


struct pessoa{
    char nome[100];
    int idade;
    int documento;
    Vacina* cartao_vac;
};