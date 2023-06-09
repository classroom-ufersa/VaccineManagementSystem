#include "vacina.h"

typedef struct cartao Cartao;
typedef struct pessoa Pessoa;
void aplica_vacina(Pessoa* pessoa, Vacina* vacina);
Pessoa* Banco_Dados_Pessoa();
Pessoa* add_pessoa();
void listar_pessoas(Pessoa* pessoa);
void remove_pessoa(Pessoa* primeira_celula);
void edita_pessoa(Pessoa* primeira_celula);
void buscar_pessoa();
void CombSort_Pessoa(int n);
int contador_pessoa();