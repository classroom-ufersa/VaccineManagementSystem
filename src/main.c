#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.c"
#include "vacina.c"

int main(){
    int Opcao;
    int qnt_linhas;
    Vacina* lista_vacina = Banco_Dados_Vacina();

    printf(" _______________________________________________ \n|\tBem vindo ao Gerenciador de Vacinas\t|\n|\tDesenvolvido por:\t\t\t|\n|\t>Abner Gama Torres\t\t\t|\n|\t>Vladimyr de Oliveira Guedes\t\t|\n|_______________________________________________|\n");
    while(Opcao != 8){
        printf("Digite a opção desejada:\n");
        printf("1-Adicionar Vacina\n2-Remover Vacina\n3-Listar Vacinas\n4-Buscar Vacinas\n5-Aplicação de Vacina em Uma Pessoa\n6-Editar Vacina Cadastrada\n7-Consultar Quantidade de Pessoas que Aplicaram Determinada Vacina\n8-Sair do Programa\n");
        scanf("%i", &Opcao);
        system("clear");


        
        switch(Opcao){
            case 1:
            printf("\tAdicionar Vacina\t\n");
            adiciona_vacina();
            qnt_linhas = contador_vacina();
            CombSort_Vacina(qnt_linhas);
            lista_vacina = Banco_Dados_Vacina();
            break;
            case 2:
            printf("\tRemover Vacina\t\n");
            Remove_Vacina(lista_vacina);
            qnt_linhas = contador_vacina();
            CombSort_Vacina(qnt_linhas);
            lista_vacina = Banco_Dados_Vacina();
            break;
            case 3:
            printf("\tListar Vacinas\t\n");  
            Lista_Vacina(lista_vacina);
            lista_vacina = Banco_Dados_Vacina();
            break;
            case 4:
            printf("\tBuscar Vacinas\t\n");
            buscar_vacina();
            break;
            case 5:
            printf("\tAplicação de Vacina em uma Pessoa\t\n");
            Aplicar_Vacina();
            qnt_linhas = contador_pessoa();
            CombSort_Pessoa(qnt_linhas);
            break;
            case 6:
            printf("\tEditar Vacina Cadastrada\t\n");  
            Editar_Vacina(lista_vacina);
            qnt_linhas = contador_vacina();
            CombSort_Vacina(qnt_linhas);
            lista_vacina = Banco_Dados_Vacina();
            break;
            case 7:
            printf("\tConsultar Quantitativo de Pessoas que Aplicaram Determinada Vacina\t\n");
            qnt_vac();
            break; 
            case 8:
            exit(1);
        }
    }

    return 0;
}