#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "programa.h"

typedef struct no
{
  char a;
  int valor; // pode ser 0 ou 1
  int posicao;
  struct no *prox;
  struct no *ant;
} No;

typedef struct lista
{
  No *inicio;
  No *fim;
} Lista;

Lista *cria_lista()
{
  Lista *l = (Lista *)malloc(sizeof(Lista));
  if (l != NULL)
  {
    l->inicio = NULL;
    l->fim = NULL;
  }
  return l;
}

// coloca a posicaoo de cada no na lista
void posicao(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int i = 0;
    while (no != NULL)
    {
      no->posicao = i;
      no = no->prox;
      i++;
    }
  }
}

// captura string e coloca cada a em um n� da lista

void insere_lista(Lista *l, int valor, char a)
{

  if (l != NULL)
  {

    No *no = (No *)malloc(sizeof(No));
    if (no != NULL)
    {
      no->valor = valor;
      no->a = a;
      no->prox = NULL;
      no->ant = NULL;
      if (l->inicio == NULL)
      {
        l->inicio = no;
      }
      else
      {
        No *aux = l->inicio;
        while (aux->prox != NULL)
        {
          aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
      }
    }
    posicao(l);
  }
}

// libera a lista

void libera_lista(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    while (no != NULL)
    {
      No *t = no->prox;
      free(no);
      no = t;
    }
    free(l);
  }
}

// imprime a lista

void imprime_lista(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    printf("{");
    while (no != NULL)
    {
      printf("'%c'", no->a);
      no = no->prox;
    }
    printf("}");
  }
}

// percorre a lista e para num n� em que o char seja igual a: 'e', 'o', 's', 'S', n e retorna sua posi��o
int retorna_lista_posicao(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int i = 0;
    while (no != NULL)
    {
      if (no->a == 'e' || no->a == 'o' || no->a == 's' || no->a == 'S' || no->a == 'n')
      {
        return i;
      }
      no = no->prox;
      i++;
    }
  }
}

// opera��o para mudar valor l�gico ao n� de posi��o especificada
void valor_logico(Lista *l, int posicao, int valor)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        no->valor = valor;
      }
      no = no->prox;
    }
  }
}

// opera��o l�gica que pega o n� anterior e o pr�ximo ao n� da posi��o especificada e retorna o valor l�gico da opera��o e
int operacaoE(Lista *l, int posicao)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int posicao = retorna_lista_posicao(l);
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        return no->ant->valor && no->prox->valor;
      }
      no = no->prox;
    }
  }
}

// opera��o l�gica que pega o n� anterior e o pr�ximo ao n� da posi��o especificada e retorna o valor l�gico da opera��o ou
int operacaoOU(Lista *l, int posicao)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int posicao = retorna_lista_posicao(l);
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        return no->ant->valor || no->prox->valor;
      }
      no = no->prox;
    }
  }
}

// opera��o l�gica que pega o n� anterior e o pr�ximo ao n� da posi��o especificada e retorna o valor l�gico da opera��o se ent�o, ou seja se o anterior for verdadeiro e o pr�ximo for verdadeiro, ent�o retorna verdadeiro
//  se o anterior for verdadeiro e o pr�ximo for falso, retorna falso, se o anterior for falso e o pr�ximo for verdadeiro, retorna falso, se o anterior for falso e o pr�ximo for falso, retorna verdadeiro
int operacaoS(Lista *l, int posicao)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int posicao = retorna_lista_posicao(l);
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        if (no->ant->valor == 1 && no->prox->valor == 1)
        {
          return 1;
        }
        else if (no->ant->valor == 1 && no->prox->valor == 0)
        {
          return 0;
        }
        else if (no->ant->valor == 0 && no->prox->valor == 1)
        {
          return 1;
        }
        else if (no->ant->valor == 0 && no->prox->valor == 0)
        {
          return 1;
        }
      }
      no = no->prox;
    }
  }
}

// opera��o l�gica que pega o n� anterior e o pr�ximo ao n� da posi��o especificada e retorna o valor l�gico da opera��o se somente se ent�o, ou seja se o anterior for igual o pr�ximo retorna verdadeiro, se o anterior for diferente do pr�ximo retorna falso
int operacaoSSE(Lista *l, int posicao)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int posicao = retorna_lista_posicao(l);
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        if (no->ant->valor == no->prox->valor)
        {
          return 1;
        }
        else
        {
          return 0;
        }
      }
      no = no->prox;
    }
  }
}

// opera��o l�gica n que pega o pr�ximo n� e retorna o valor oposto
int operacaoN(Lista *l, int posicao)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int posicao = retorna_lista_posicao(l);
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        if (no->prox->valor == 1)
        {
          return 0;
        }
        else
        {
          return 1;
        }
      }
      no = no->prox;
    }
  }
}

// executa primeira opera��o a partir de uma posi��o especificada
int executa_operacao(Lista *l, int posicao)
{
  if (l != NULL)
  {
    No *no = l->inicio;

    no = l->inicio;
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        if (no->a == 'e')
        {
          return operacaoE(l, posicao);
        }
      }
      no = no->prox;
    }

    no = l->inicio;
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        if (no->a == 'o')
        {
          return operacaoOU(l, posicao);
        }
      }
      no = no->prox;
    }

    no = l->inicio;
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        if (no->a == 's')
        {
          return operacaoS(l, posicao);
        }
      }
      no = no->prox;
    }

    no = l->inicio;
    while (no != NULL)
    {
      if (no->posicao == posicao)
      {
        if (no->a == 'S')
        {
          return operacaoSSE(l, posicao);
        }
      }
      no = no->prox;
    }
  }
}

// conta operadores na lista
int conta_operadores(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int cont = 0;
    while (no != NULL)
    {
      if (no->a == 'e' || no->a == 'o' || no->a == 's' || no->a == 'S' || no->a == 'n')
      {
        cont++;
      }
      no = no->prox;
    }
    return cont;
  }
}

// chama a fun��o que executa a opera��o e substitui o valor do n� anterior e o pr�ximo pelo resultado da opera��o o numero de vezes que o n�mero de operadores na lista e coloca o resultado na posi��o do n� da opera��o
int substitui_operacao(Lista *l, int *r)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int cont = conta_operadores(l);
    while (cont > 0)
    {
      while (no != NULL)
      {
        if (no->a == 'n')
        {
          int resultado = troca_valor(no->prox->valor);
          no->valor = resultado;
          no->prox->valor = resultado;
          no->a = ' ';
          no->prox->a = ' ';
          *r = resultado;
          cont--;
        }
        no = no->prox;
      }
      no = l->inicio;
      while (no != NULL)
      {
        if (no->a == 'e' || no->a == 'o' || no->a == 's' || no->a == 'S')
        {
          int resultado = executa_operacao(l, retorna_lista_posicao(l));
          no->valor = resultado;
          no->ant->valor = resultado;
          no->prox->valor = resultado;
          no->a = ' ';
          no->ant->a = ' ';
          no->prox->a = ' ';
          *r = resultado;
          cont--;
        }
        no = no->prox;
      }
    }
  }
}

// captura posicao do operador entre parenteses
int captura_posicao_operador_parenteses(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    while (no != NULL)
    {
      if (no->a == '(')
      {
        while (no->a != ')')
        {
          if (no->a == 'e' || no->a == 'o' || no->a == 's' || no->a == 'S' || no->a == 'n')
          {
            return no->posicao;
          }
          no = no->prox;
        }
      }
    }
  }
}

// conta o n�mero de operadores dentro de parenteses
int conta_operadores_parenteses(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int cont = 0;
    while (no != NULL)
    {
      if (no->a == '(')
      {
        while (no->a != ')')
        {
          if (no->a == 'e' || no->a == 'o' || no->a == 's' || no->a == 'S' || no->a == 'n')
          {
            cont++;
          }
          no = no->prox;
        }
      }
      no = no->prox;
    }
    return cont;
  }
}

int executa_operacao_parenteses(Lista *l, int *r)
{
  int resultado;
  if (l != NULL)
  {
    No *no = l->inicio;
    while (no != NULL)
    {
      if (no->a == '(')
      {
        int pos = captura_posicao_operador_parenteses(l);
        resultado = executa_operacao(l, pos);
        while (no != NULL)
        {
          if (no->a == '(' || no->a == ')')
          {
            no->a = ' ';
            no->valor = resultado;
          }
          no = no->prox;
        }
        no = l->inicio;
      }
      else
      {
        no = no->prox;
      }
    }
    *r = resultado;
  }
}

// conta o n�mero de opera��es entre parenteses
int conta_operacoes_parenteses(Lista *l)
{
  if (l != NULL)
  {
    No *no = l->inicio;
    int cont = 0;
    while (no != NULL)
    {
      if (no->a == '(')
      {
        cont++;
      }
      no = no->prox;
    }
    return cont;
  }
}

// executa as opera��es entre parenteses
int executa_todas_operacoes_parenteses(Lista *l, int *r)
{
  if (l != NULL)
  {

    No *no = l->inicio;
    int cont = conta_operacoes_parenteses(l);
    while (cont > 0)
    {
      while (no != NULL)
      {
        if (no->a == '(')
        {
          executa_operacao_parenteses(l, r);
          cont--;
        }
        if (no->a == '(' && no->ant->a == 'n')
        {
          executa_operacao_parenteses(l, r);
          cont--;
        }
        no = no->prox;
        return *r;
      }
    }
  }
}

int operacao_final(Lista *l, int *r)
{
  if (l != NULL)
  {
    if (conta_operacoes_parenteses(l) > 0)
    {
      executa_todas_operacoes_parenteses(l, r);
      if (conta_operadores(l) > 0)
      {
        substitui_operacao(l, r);
      }
    }
    else
    {
      substitui_operacao(l, r);
    }
  }
}

// fun��o que troca 1 por 0 e 0 por 1
int troca_valor(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int conta_parenteses(Lista *l)
{
  int cont = 0;
  No *no = l->inicio;
  while (no != NULL)
  {
    if (no->a == '(')
      cont++;
    else if (no->a == ')')
    {
      cont--;
      if (cont < 0)
        return 1;
    }
    no = no->prox;
  }
  if (cont == 0)
    return 0;
  return 1;
}



void juntar_listas_depois(Lista *l1, Lista *l2, char y)
{
  if (l1 != NULL && l2 != NULL)
  {
    No *no;
    no->a = y;
    no->valor = 2;
    No *aux = l1->inicio;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = no;
    no->ant = aux;
    no->prox = l2->inicio;
    l2->inicio->ant = no;
  }
}

void juntar_listas_antes(Lista *l1, Lista *l2, char y)
{
  if (l1 != NULL && l2 != NULL)
  {
    No *no;
    no->a = y;
    no->valor = 2;
    No *temp = l1->inicio;
    l1->inicio = l2->inicio;
    l2->inicio = temp;
    No *aux = l1->inicio;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = no;
    no->ant = aux;
    no->prox = l2->inicio;
    l2->inicio->ant = no;
  }
}

void concatena_listas(Lista *l1, Lista *l2, char y) // essa fun��o concatena duas listas e coloca um operador entre elas
{
  if (l1 != NULL && l2 != NULL)
  {
    No *no;
    no->a = y;
    no->valor = 2;
    No *aux = l1->inicio;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = no;
    no->ant = aux;
    no->prox = l2->inicio;
    l2->inicio->ant = no;
  }
}

// captura o numero da ultima linha n�o escrita de um arquivo desconsiderando o que j� foi escrito
int captura_ultima_linha(char *nome_arquivo)
{
  FILE *arquivo;
  arquivo = fopen(nome_arquivo, "r");
  int cont = 0;
  char c;
  while ((c = fgetc(arquivo)) != EOF)
  {
    if (c == '\n')
      cont++;
  }
  fclose(arquivo);
  return cont;
}
