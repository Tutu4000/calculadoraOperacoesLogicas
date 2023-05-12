#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED

typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* l);
void insere_lista(Lista* l, int valor ,char a);
void imprime_lista(Lista* l);
void posicao(Lista* l);
int retorna_lista_posicao(Lista* l);
void valor_logico(Lista *l, int posicao, int valor);
int conta_operadores(Lista *l);
int executa_operacao(Lista *l, int posicao);
int substitui_operacao(Lista *l, int *retorno);
int operacaoE(Lista *l, int posicao);
int executa_operacao_parenteses(Lista *l, int *r);
int operacao_final(Lista *l, int *r);
void juntar_listas_antes(Lista *l1, Lista *l2, char y);
void juntar_listas_depois(Lista *l1, Lista *l2, char y);
int validar_formula(Lista *l);
int conta_parenteses(Lista *l);
int captura_ultima_linha(char *nome_arquivo);
int troca_valor(int n);
#endif // PROGRAMA_H_INCLUDED
