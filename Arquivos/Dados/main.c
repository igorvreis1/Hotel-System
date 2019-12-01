#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "functions.h"
#include "vars.h"

 int main(void)//editar hotel
{ 

    inicializa();
    int op;

    while(1)
    {
        printf("\t\t  *******************************************\n");
        printf("\t\t  *       Bem vindo ao Hotel-System!        *\n");
        printf("\t\t  *                                         *\n");
        printf("\t\t  *  Escolha uma opcao do menu abaixo:      *\n");
        printf("\t\t  *                                         *\n");
        printf("\t\t  *  [1] Logar\t[2] Informacoes do hotel    *\n");
        printf("\t\t  *  [3] Informacoes do gerente\t[4] Sair    *\n");
        printf("\t\t  *******************************************\n\n");
        printf("\t\t                    opcao: ");

        op = getchar();
        if(op == 1)
        {
            
        }else
        if(op == 2)
        {

        }else
        if(op == 3)
        {

        }else
        if(op == 4)
        {
            printf("Obrigado por usar Hotel-System!\n");
            printf("Pressione enter para sair!\n");
            getchar();
            exit(0);
        }else
        {
            printf("Opcao invalida, tente novamente!\n");
            system("cls");
        }
    }
}