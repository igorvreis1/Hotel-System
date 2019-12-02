#include "functions.h"
#include "usuario.h"
#include "dados.h"
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
                if( padrao.logado == 2)
                {
                    
                    printf("\n\n\n\n\n");
                    printf("Logado como (funcionario): %s\n\n", padrao.usuario);
                    break;
                }
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

void menuFunc()
{
    int op;
    while (1)
    {
        menu("[1] - Reservas\t[2] - Quartos\t[3] - Produtos\t[4] - Fornecedores\n"
            "[5] - Notas\t[6] - Deslogar\n");
        scanop;
        cleanBuff();
        
        if( op == 1)
        {
            //listar reservas
        }else
        if( op == 2)
        {
            while (1)
            {
                menu("[1] - Listar\t[2] - Adicionar\t[3] - Remover\t[4] - Voltar");
                scanop;
                cleanBuff();

                if(op == 1)
                {
                    lista("quartos");
                }else
                if( op == 2)
                {
                    int errcode = addQuarto();

                    if( errcode == SUCCESS )
                        printf("Quarto adicionado com sucesso!\n");
                    else
                    if( errcode == CANCELED )
                        printf("Operacao cancelada!\n");
                    else
                        printf("Erro ao salvar o quarto!\n");
                }else
                if( op == 3)
                {
                    //remover
                }
                else
                if( op == 4)
                {
                    break;
                }else
                {
                    opIn;//opcao invalida
                }
            }
        }else
        if( op == 3)
        {
            while(1)
            {
                menu("[1] - Listar\t[2] - Adicionar de um fornecedor existente\n[3] - Adicionar de um novo fornecedor\t[4] - remover\t [5] - Voltar\n");
                scanop;
                cleanBuff();

                int errcode;
                if( op == 1)
                {
                    lista("produtos");
                }else
                if( op == 2)
                {
                    int errcode = addProd();

                    if( errcode == SUCCESS )
                    {
                        printf("produto adicionado com sucesso!\n");
                    }else
                    if( errcode == CANCELED )
                    {
                        printf("Operacao cancelada!\n");
                    }else
                    if(errcode == EOPEN)
                    {
                        printf("Erro ao abrir arquivo\n");
                    }else
                    {
                        printf("O fornecedor informado nao existe!\n");
                    }
                }else
                if( op == 3)
                {   
                    printf("Primeiro voce deve adicionar um fornecedor:\n");
                    int forn = fornecedores();
                    if( forn == SUCCESS )
                        printf("Fornecedor inserido com sucesso!\n");
                    else 
                    if( forn == EOPEN )
                        printf("Erro ao abrir o arquivo para salvar o fornecedor!\n");
                    else
                    if( forn == CANCELED )
                        printf("Operacao cancelada!\n");
                    else
                    if( forn == AEXIST )
                        printf("ja existe um fornecedor com esse cnpj cadastrado!\n");

                    errcode = addProd();
                    if( errcode == SUCCESS )
                    {
                        printf("Produto adicionado com sucesso!\n");
                    }else
                    if( errcode == EOPEN )
                    {
                        printf("Falha ao salvar os dados!\n");
                    }else 
                    if( errcode == UNEXIST )
                    {
                        printf("O fornecedor informado nao existe!\n");
                    }else
                    {
                        printf("operacao cancelada, nenhuma alteracao foi feita!\n");
                    }
                }else 
                if( op == 4)
                {
                    //remover prod
                }else
                if( op == 5)
                {
                    break;
                }else
                {
                    opIn;//op invalida
                }
            }
        }else
        if( op == 4)
        {
            while(1){
                menu("[1] - Listar\t[2] - Adicionar\t[3] - voltar\n");
                scanop;
                cleanBuff();

                if( op == 1)
                {
                    lista("fornecedores");
                }else
                if( op == 2)
                {
                    int forn = fornecedores();
                    if( forn == SUCCESS )
                        printf("Fornecedor inserido com sucesso!\n");
                    else 
                    if( forn == EOPEN )
                        printf("Erro ao abrir o arquivo para salvar o fornecedor!\n");
                    else
                    if( forn == CANCELED )
                        printf("Operacao cancelada!\n");
                    else
                    if( forn == AEXIST )
                        printf("ja existe um fornecedor com esse cnpj cadastrado!\n");
                }else
                if( op == 3)
                {
                    break;
                }else
                {
                    printf("Opcao invalida!\n");
                }
            }
        }else 
        if( op == 5)
        {
            //feedback
        }else 
        if( op == 6)
        {
            padrao.logado = 0;//zera o login
            padrao.usuario[0] = '\0';//zera o usuario
            padrao.cod = 0;//zera o codigo
            break;
        }else
        {
            printf("Opcao invalida!\n");
        }
    }
}

void adm()
{
    int op;
    while(padrao.logado != 3)
    {
        menu("[1] - Logar\t[2] - Voltar");
        scanf("%d", &op);
        cleanBuff();

        if( op == 1)
        {
            statuslog(logar("administrador"), 3);
        }else
        if( op == 2)
        {
            break;
        }else
        {
            printf("Opcao invalida!\n");
        }
    }
}

void menuAdm()
{
    printf("Cadastrando funcionario: \n\n");
    int errcode = cadastrar("funcionario");

    if( errcode == CANCELED )
    {
        printf("Operacao cancelada!\n");
    }else
    if( errcode == EOPEN)
    {
        printf("Falha ao cadastrar funcionario\n\n");
    }else
    {
        printf("Funcionario cadastrado com sucesso!\n");
    }
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