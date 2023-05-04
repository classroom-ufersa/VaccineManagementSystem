#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.c"
#include "vacina.c"



int main(){
    //Vacina* primeira_celula_vac = inicializa_vacina();
    Lista_Vac* lista = inicializa_lista();
    Pessoa* pessoa;
    //copiar_vacinas(lista);
    int Opcao;
    //int Condicao;
    printf(" _______________________________________________ \n|\tBem vindo ao Gerenciador de Vacinas\t|\n|\tDesenvolvido por:\t\t\t|\n|\t>Abner Gama Torres\t\t\t|\n|\t>Vladimyr de Oliveira Guedes\t\t|\n|_______________________________________________|\n");
    while(Opcao != 10){
        printf("Digite a opção desejada:\n");
        printf("1-Adicionar vacina\n2-Remover vacina\n3-Listar vacinas\n4-Buscar vacinas\n5-Aplicação de vacina em uma pessoa\n6-Editar vacina cadastrada\n7-Consultar quantidade de pessoas que aplicaram determinada vacina\n8-Adicionar pessoa\n9-Listar pessoas\n10-Sair do programa\n");
        scanf("%i", &Opcao);
        system("clear");
        switch(Opcao){
            case 1:
            printf("\tAdicionar Vacina\t\n");
            adiciona_vacina(lista);
            break;
            case 2:
            printf("\tRemover Vacina\t\n");
            //função remover vacina
            break;
            case 3:
            printf("\tListar Vacinas\t\n");      
            Vacina* teste;
            teste = lista->primeira_vac;
            while(teste->prox != NULL){
                printf("%s\n", teste->nome);
                teste = teste->prox;
            }
                  
            //listar_vacinas();
            //insere_vacina_txt(lista);
            //função listar vacina
            break;
            case 4:
            printf("\tBuscar Vacinas\t\n");
            char nome_vac[50];
            char num_lote[50];
            printf("Digite o nome da vicina: ");
            scanf(" %[^\n]s", nome_vac);
            printf("Digite o numero do lote: ");
            scanf(" %[^\n]s", num_lote);
            Vacina* rascunho = buscar_vacina(nome_vac, num_lote);
            printf("Nome: %s\tLote: %s\tData de Fabricacao: %s\tData de Validade: %s", rascunho->nome, rascunho->lote, rascunho->fab, rascunho->val);
            //função buscar vacina
            break;
            case 5:
            printf("\tAplicação de Vacina em uma Pessoa\t\n");
            //função aplicação vacina
            break;
            case 6:
            printf("\tEditar Vacina Cadastrada\t\n");    
            //função editar vacina
            break;
            case 7:
            printf("\tConsultar Quantitativo de Pessoas que Aplicaram Determinada Vacina\t\n");
            //função a quantidade de pessoa que aplicaram vacina
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
            break;
        }
    }
    
    free(pessoa);

    return 0;
}
