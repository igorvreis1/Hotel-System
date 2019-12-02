#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
<<<<<<< HEAD

 int main(void)//editar hotel
{
  int op;

  printf("Bem vindo ao sistema de hotel!\n");
  while(1){

    printf("\nEscolha uma opcao do menu abaixo:\n"
    "1 - Sou funcionario\t2 - Sou Cliente\t3 - Sou Administrador\t4 - Sair\n");
    scanf("%d", &op);
    cleanBuff();

    switch(op){
      case 1:
        login("funcionario", 'r');
        break;
      case 2:
        printf("(1)Fazer login ou (2)cadastrar:  ");
        scanf("%d%*c", &op);
        if(op == 1){
          login("cliente", 'r');
        }else{
          login("cliente", 'a');
        }
        break;
      case 3:
        login("administrador", 'r');
        break;
      case 4:
        exit(0);
      default:
        printf("Opcao invalida, Tente novamente!\n\n");
    }
  }
  return 0;
=======
#include "functions.h"
#include "vars.h"
#include "usuario.h"

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
                menuFunc();
            }else
            if(padrao.logado == 3)//caso seja administrador
            {
                menuAdm();
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
            while(1)
            {
                menu("[1] - Listar informacoes\t[2] - Alterar informacoes\t[3] - Voltar");
                scanop;
                cleanBuff();

                if( op == 1)
                {
                    tipoGerente aux;
                    FILE *p = fopen("C:\\ProgramData\\hotelSystem\\configs\\gerente.bin", "rb");
                    fread(&aux, sizeof(tipoGerente), 1, p);
                    fclose(p);

                    printf("Nome do gerente: %s\nTelefone: %s\n\n", aux.nome, aux.telefone);
                    printf("Pressione enter para prosseguir!\n");
                    getchar();
                }else
                if( op == 2)
                {
                    if(padrao.logado != 3)//caso ele nao seja adm
                    {
                        printf("Voce deve ser administrador para poder editar as informacoes sobre o gerente!\n");
                        break;
                    }

                    int errcode = gerente();
                    if(errcode == SUCCESS )
                    {
                        printf("Alteracoes feitas com sucesso!\n");
                        break;
                    }else
                    if( errcode == EOPEN )
                    {
                        printf("Erro ao salvar as informacoes!\n");
                        break;
                    }else
                    {
                        printf("Operacao cancelada, nenhuma alteracao foi salva!\n");
                        break;
                    }
                }else 
                if( op == 3)
                {
                    break;
                }else
                {
                    printf("Opcao invalida\n");
                }
            }
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
>>>>>>> upstream/master
}