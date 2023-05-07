#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.c"
#include "vacina.c"



int main(){
    Lista_Vac* lista = inicializa_lista();
    Pessoa* pessoa;
    int Opcao;

    printf(" _______________________________________________ \n|\tBem vindo ao Gerenciador de Vacinas\t|\n|\tDesenvolvido por:\t\t\t|\n|\t>Abner Gama Torres\t\t\t|\n|\t>Vladimyr de Oliveira Guedes\t\t|\n|_______________________________________________|\n");
    while(Opcao != 13){
        printf("Digite a opção desejada:\n");
        printf("1-Adicionar Vacina\n2-Remover Vacina\n3-Listar Vacinas\n4-Buscar Vacinas\n5-Aplicação de Vacina em Uma Pessoa\n6-Editar Vacina Cadastrada\n7-Consultar Quantidade de Pessoas que Aplicaram Determinada Vacina\n8-Adicionar Pessoa\n9-Listar Pessoas\n10-Remover Pessoa\n11-Editar Pessoa\n12-Buscar Pessoa\n13-Sair do Pograma\n");
        scanf("%i", &Opcao);
        system("clear");
        switch(Opcao){
            case 1:
            printf("\tAdicionar Vacina\t\n");
            adiciona_vacina(lista);
            break;
            case 2:
            printf("\tRemover Vacina\t\n");
            Remove_Vacina();
            break;
            case 3:
            printf("\tListar Vacinas\t\n");  
            Lista_Vacina();    
            break;
            case 4:
            printf("\tBuscar Vacinas\t\n");
            buscar_vacina();
            break;
            case 5:
            printf("\tAplicação de Vacina em uma Pessoa\t\n");
            break;
            case 6:
            printf("\tEditar Vacina Cadastrada\t\n");  
            Editar_Vacina(); 
            break;
            case 7:
            printf("\tConsultar Quantitativo de Pessoas que Aplicaram Determinada Vacina\t\n");
            break;
            case 8:
            printf("\tAdicionar Pessoa\t\n");
            pessoa = cria_pessoa();
            pessoa = add_pessoa();
            //função de adicionar pessoa
            break;
            case 9:
            printf("\tListar Pessoas\t\n");
            listar_pessoas();
            //função de listar pessoas
            break;    
            case 10:
            printf("\tRemover Pessoas\t\n");
            remove_pessoa();
            break;
            case 11:
            printf("\tEditar Pessoa\t\n");
            edita_pessoa();
            break;
            case 12:
            printf("\tBuscar Pessoas\t\n");
            break;
            case 13:
            break;
        }
    }
    
    //free(pessoa);

    return 0;
}
