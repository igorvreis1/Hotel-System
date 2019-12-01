#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "functions.h"
#include "vars.h"
#include "usuario.h"

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
            while(1)
            {
                menu("[1] - Listar informacoes\t[2] - Alterar informacoes\t[3] - Voltar");
                scanop;
                cleanBuff();

                if( op == 1 )
                {
                    printf("\n\n");
                    infotel();
                    printf("\nPressione enter para prosseguir!\n\n");
                    getchar();
                }else
                if( op == 2)
                {
                    if(padrao.logado != 3)
                    {
                        printf("Voce deve ser um administrador para poder alterar as informacoes do hotel!\n");
                        break;
                    }

                    int errcode = hotel();
                    if( errcode == SUCCESS )
                    {
                        printf("Alteracoes salvas com sucesso!\n");
                        break;
                    }else
                    if( errcode == EOPEN )
                    {
                        printf("Erro ao salvar as alteracoes!\n");
                        break;
                    }else
                    {
                        printf("Operacao cancelada! Nenhuma alteracao foi salva!\n");
                        break;
                    }
                }else
                if(op == 3)
                {
                    break;
                }else
                {
                    printf("Opcao invalida!\n\n");
                }
            }
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