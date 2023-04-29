typedef struct vacina Vacina;

typedef struct lista_vac Lista_Vac;

Lista_Vac* Inicia_Lista_Vac(void);

int Lista_Vazia(Lista_Vac* lista);

Lista_Vac* Insere_Vacina_Vazia(Lista_Vac* lista);

Lista_Vac* Insere_Vacina(Lista_Vac* lista);