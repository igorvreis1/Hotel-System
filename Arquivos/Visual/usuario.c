#include "functions.h"
#include "usuario.h"
#include "vars.h"
#include <stdio.h>
#include <stdlib.h>

/*
    cliente deve fazer reservas, cancelar reservas, ver as informações do hotel e do gerente, ver os produtos
    proporcionados pelo hotel, as categorias de quartos e o valor total de suas reservas
*/

void cliente()//
{
    int op;

    if(padrao.logado == 0)
    {
        while(1)
        {
            menu("[1] - Logar\t[2] - Cadastrar\t[3] - Voltar\n");
            scanf("%d", &op);
            cleanBuff();

            if( op == 1 )
            {
                statuslog(logar("cliente"), 1);
                if( padrao.logado == 1)
                    break;
            }else
            if( op == 2 )
            {
                statuscad(cadastrar("cliente"));
            }else
            if( op == 3 )
            {
                break;
            }else
            {
                printf("Opcao invalida, tente novamente!\n");
                continue;
            }
        }
    }
    
    printf("\n\n\n\n\n");
    printf("Logado como (cliente): %s\n\n", padrao.usuario);

}

void funcionario()
{
    int op;
    if(padrao.logado == 0)
    {
        while(1)
        {
            menu("[1] - Login\t[2] - Voltar\n");
            scanf("%d", &op);   
            cleanBuff();

            if( op == 1)
            {
                statuslog(logar("funcionario"), 2);
            }else
            if( op == 2)
            {
                break;
            }else
            {
                printf("Opcao invalida, tente novamente!\n");
                continue;
            }
        }
    }
}

void adm()
{

}

void statuslog(int logged, int nivel)//CONCLUIDO
{
    if( logged == SUCCESS )
    {
        printf("Logado com Sucesso!\n");
        padrao.logado = nivel;
    }else
    if( logged == FAILED)
    {
        printf("Senha incorreta\n");
        padrao.logado = 0;
    }else
    if( logged == UNEXIST )
    {
        printf("Esse usuario nao existe!\n");
    }else
    {
        printf("Pode ser que ainda nao haja usuarios cadastrados!\n\n");
    }
}

void statuscad(int cad)//CONCLUIDO
{
    if( cad == AEXIST )
    {
        printf("Esse nome de usuario ja existe, tente outro!\n");
    }else
    if( cad == EOPEN )
    {
        printf("Erro ao abrir o arquivo, impossivel cadastrar-se no momento\n");
    }else
    if( cad == SUCCESS )
    {
        printf("Cadastrado com sucesso!\n");
    }
}