#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int checkInfo(void)//checar informacoes
{
    char op;
    do{
            printf("As informacoes estao corretas? (s - sim / n - nao): ");
            scanf("%c%*c", &op);

            if('S' == toupper(op))
            {
                return 1;
            }else
            if('N' == toupper(op))
            {
                printf("Faca as alteracoes!\n\n");
                return 0;
            }
            printf("Opcao invalida, tente novamente!\n");
        }while(toupper(op) != 'N' && toupper(op) != 'S');
}