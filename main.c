#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "programa.h"

int main()
{
    Lista *l;
    Lista *l2;
    int r;
    int b;
    char a[100];
    int i;
    int op = 10;
    int x;
    char y;
    int linha, linha1, linha2;

    printf("Informativo: \n os operadores sao {e,o,n,s,S} \n {e,ou,nao,se entao,se somente se} respectivamente\n");
    printf("Ex: PnQsR\n");
    // criar um menu
    while (op != 0)
    {
        printf("Digite a opcao: \n");
        printf("1 - Operacao logica\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            l = cria_lista();
            printf("Digite uma string: ");
            scanf("%s", a);
            for (i = 0; i < strlen(a); i++)
            {
                insere_lista(l, 0, a[i]);
            }

            printf("Digite os valores logicos de\n");
            printf("OBS: 1 = true, 0 = false\n");
            for (i = 0; i < strlen(a); i++)
            {
                if (a[i] == 'e' || a[i] == 'o' || a[i] == 'n' || a[i] == 's' || a[i] == 'S' || a[i] == '(' || a[i] == ')')
                    valor_logico(l, i, 2);
                else
                {
                    printf("%c :", a[i]);
                    scanf("%d", &b);
                    valor_logico(l, i, b);
                }
            }

            imprime_lista(l);
            printf("\n");
            operacao_final(l, &r);
            printf("Resultado: %d\n", r);

            // coloca a opera��o e seu resultado em um arquivo de texto 'operacoes.txt' e sua posi��o de acordo com a linha no formato 'linha - operacao = resultado'
            FILE *arq;
            arq = fopen("operacoes.txt", "a");
            if (arq == NULL)
            {
                printf("Erro ao abrir arquivo\n");
                exit(1);
            }
            // imprime a linha no arquivo
            fprintf(arq, "%d - ", captura_ultima_linha("operacoes.txt"));
            // imprime a opera��o no arquivo
            fprintf(arq, "(", a);
            for (i = 0; i < strlen(a); i++)
            {
                fprintf(arq, "%c", a[i]);
            }
            fprintf(arq, ") ");
            // imprime o resultado no arquivo
            fprintf(arq, " = %d\n", r);
            fclose(arq);
            libera_lista(l);
            break;

        default:
            break;
        }
    }
}
