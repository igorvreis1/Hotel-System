#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "functions.h"
#include "vars.h"
#include "usuario.h"

#if defined(_WIN32) || defined(_WIN64)
    #define cleanscr system("cls");
#elif defined(__linux__) || defined(__unix__)
    #define cleanscr system("clear");
#endif

#define scanop scanf("%d", &op);

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
        printf("\t\t  *  [1] Conta\t[2] Informacoes do hotel    *\n");
        printf("\t\t  *  [3] Informacoes do gerente\t[4] Sair    *\n");
        printf("\t\t  *******************************************\n\n");
        printf("\t\t                    opcao: ");

        scanop;
        cleanBuff();
        printf("\n\n");

        if(op == 1)
        {
            while(padrao.logado == 0)//caso ele esteja deslogado
            { 
                menu("[1] - Sou funcionario\t[2] - Sou Cliente\t[3] - Sou administrador\t[4] - Voltar\n");
                scanop;
                cleanBuff();

                if( op == 1 )
                {
                    funcionario();
                }
                else
                if( op == 2 )
                {
                    cliente();
                }else
                if( op == 3 )
                {
                    adm();
                }else
                if( op == 4 )
                {
                    break;
                }else
                {
                    printf("Opcao invalida, tente novamente!\n\n");
                    continue;
                }
            }

            if(padrao.logado == 1)//caso seja cliente
            {

            }else
            if(padrao.logado == 2)//caso seja funcionario
            {

            }else//caso seja administrador
            {

            }
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
        }
    }
}