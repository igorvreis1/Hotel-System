#include "dados.h"
#include <stdio.h>

//funções
void hotel(void)//editar hotel
{
    char op;
    tipoHotel hotel;

    while(1)
    {
        printf("Informe o nome do Hotel: ");
        scanf("%s%*c", &hotel.nome);

        printf("Informe a razao social do hotel: ");
        scanf("%s%*c", &hotel.razao);

        do{
            printf("Informe a inscricao estadual do hotel (apenas numeros): ");
            scanf("%13s%*c", &hotel.insc);
        }while(strlen(hotel.insc) != 13);

        do
        {
            printf("Informe o cnpj do hotel (apenas numeros): ");
            scanf("%14s%*c", &hotel.endereco);
        } while(strlen(hotel.cnpj) != 14);
        

        do
        {
            printf("Informe o telefone do hotel (ddd-nnnnnnnnn): ");
            scanf("%12s%*c", &hotel.telefone);
        } while(strlen(hotel.telefone) != nums);
        

        printf("Informe o email do hotel: ");
        scanf("%s%*c", &hotel.email);

        printf("Informe o nome do gerente do hotel: ");
        scanf("%s%*c", &hotel.gerente);

        do{
            printf("Informe o telefone do gerente do hotel (ddd-nnnnnnnnn): ");
            scanf("%12s%*c", &hotel.telGer);
        }while(strlen(hotel.gerente) != nums);
        


        printf("Informe o horario de checkin do hotel (hh:mm): ");
        scanf("%d:%d", &hotel.checkin[0], &hotel.checkin[1]);

        printf("Informe o horario de checkout do hotel (hh:mm): ");
        scanf("%d:%d", &hotel.checkout[0], &hotel.checkout[1]);

        if(checkInfo())
        {
            //salva no arquivo
        }
    }
}

void addProd(void)//adicionar produtos
{
    tipoProdutos adProduto;
    while(1)
    {
        printf("Informe o codigo do produto (0001): ");
        scanf("%d", &adProduto.codigo);
        //checar se o código é único;

        printf("De uma descricao para o produto: ");
        scanf("%[^\n]", &adProduto.desc);

        printf("Informe quanto tem desse produto no estoque: ");
        scanf("%d", &adProduto.estoque);

        printf("Informe qual o estoque minimo desse produto: ");
        scanf("%d", &adProduto.estMin);

        printf("Informe qual o preco de custo do produto (10.20): R$ ");
        scanf("%f", &adProduto.pCusto);


        pritnf("Codigo: %s\nDescricao: %s\n", adProduto.codigo, adProduto.desc);
        printf("Estoque: %d\nEstoque minimo: %d\n", adProduto.estoque, adProduto.estMin);
        printf("Preco de custo: %.2f\n", adProduto.pCusto);
        //calcular o preco de venda
        //printf("O preco de venda baseado no preco de custo e impostos sera: R$%.2f\n\n", adProduto.pVenda);
        if(checkInfo())
        {
            //salvar no arquivo
        }
    }
}

int checkInfo(void)//checar informacoes
{
    char op;
    do{
            printf("As informacoes estao corretas? (s - sim / n - nao): ");
            op = getchar();

            if('S' == toupper(op))
            {
                printf("Informacoes salvas!\n");
                return 1;
            }else
            if('N' == toupper(op))
            {
                printf("Faca as alteracoes!\n");
                return 0;
            }
            printf("Opcao invalida, tente novamente!\n");
        }while(toupper(op) != 'N' && toupper(op) != 'S');
}