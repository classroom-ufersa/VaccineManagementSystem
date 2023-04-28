#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.c"
#include "vacina.c"



int main(){
    Vacina* vacina = NULL;
    Pessoa* pessoa = NULL;
    int Opcao;
    printf(" _______________________________________________ \n|\tBem vindo ao Gerenciador de Vacinas\t|\n|\tDesenvolvido por:\t\t\t|\n|\t>Abner Gama Torres\t\t\t|\n|\t>Vladimyr de Oliveira Guedes\t\t|\n|_______________________________________________|\n");
    while(Opcao != 9){
        printf("Digite a opção desejada:\n");
        printf("1-Adicionar vacina\n2-Remover vacina\n3-Listar vacinas\n4-Buscar vacinas\n5-Aplicação de vacina em uma pessoa\n6-Editar vacina cadastrada\n7-Consultar quantidade de pessoas que aplicaram determinada vacina\n8-Adicionar pessoa\n9-Sair do programa\n");
        scanf("%i", &Opcao);
        system("clear");
        switch(Opcao){
            case 1:
            printf("\tAdicionar Vacina\t\n");
            //função adicionar vacina
            break;
            case 2:
            printf("\tRemover Vacina\t\n");
            //função remover vacina
            break;
            case 3:
            printf("\tListar Vacinas\t\n");
            //função listar vacina
            break;
            case 4:
            printf("\tBuscar Vacinas\t\n");
            //função buscar vacina
            break;
            case 5:
            printf("\tAplicação de Vacina em uma Pessoa\t\n");
            //função aplicação vacina
            break;
            case 6:
            printf("\tEditar Vacina Cadastrada\t\n");    
            //função
            break;
            case 7:
            printf("\tConsultar Quantidade de Pessoas que Aplicaram Determinada Vacina\t\n");
            //função
            break;
            case 8:
            printf("\tAdicionar Pessoat\t\n");
            //função
            break;
            case 9:
            break;    
        }
    }
    

    return 0;
}