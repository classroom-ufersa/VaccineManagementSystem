#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/vladimyr/Documentos/Visual_Studio_Code/GitHub/Vacina/VaccineManagementSystem-1/VaccineManagementSystem.c/src/pessoa.c"

int main(){
    int Opcao;
    int qnt_linhas;
    Vacina* lista_vacina = (Vacina*) malloc(sizeof(Vacina));
    lista_vacina = Banco_Dados_Vacina();
    Pessoa* lista_pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    lista_pessoa = Banco_Dados_Pessoa();

    printf(" _______________________________________________ \n|\tBem vindo ao Gerenciador de Vacinas\t|\n|\tDesenvolvido por:\t\t\t|\n|\t>Abner Gama Torres\t\t\t|\n|\t>Vladimyr de Oliveira Guedes\t\t|\n|_______________________________________________|\n");
    while(Opcao != 13){
        printf("Digite a opção desejada:\n");
        printf("1-Adicionar Vacina\n2-Remover Vacina\n3-Listar Vacinas\n4-Buscar Vacinas\n5-Aplicação de Vacina em Uma Pessoa\n6-Editar Vacina Cadastrada\n7-Consultar Quantidade de Pessoas que Aplicaram Determinada Vacina\n8-Adicionar Pessoa\n9-Listar Pessoas\n10-Remover Pessoa\n11-Editar Pessoa\n12-Buscar Pessoa\n13-Sair do Pograma\n");
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
            aplica_vacina(lista_pessoa, lista_vacina);
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
            break;
            case 8:
            printf("\tAdicionar Pessoa\t\n");
            add_pessoa();
            qnt_linhas = contador_pessoa();
            CombSort_Pessoa(qnt_linhas);
            lista_pessoa = Banco_Dados_Pessoa();
            //função de adicionar pessoa
            break;
            case 9:
            printf("\tListar Pessoas\t\n");
            listar_pessoas(lista_pessoa);
            //função de listar pessoas
            break;    
            case 10:
            printf("\tRemover Pessoas\t\n");
            remove_pessoa(lista_pessoa);
            qnt_linhas = contador_pessoa();
            CombSort_Pessoa(qnt_linhas);
            lista_pessoa = Banco_Dados_Pessoa();
            break;
            case 11:
            printf("\tEditar Pessoa\t\n");
            edita_pessoa(lista_pessoa);
            qnt_linhas = contador_pessoa();
            CombSort_Pessoa(qnt_linhas);
            lista_pessoa = Banco_Dados_Pessoa();
            break;
            case 12:
            printf("\tBuscar Pessoas\t\n");
            buscar_pessoa();
            break;
            case 13:
            break;
        }
    }

    return 0;
}
