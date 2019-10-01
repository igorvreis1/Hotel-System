#include "dados.h"
#include "str/strfuncoes.h"
#include <stdio.h>

//FUNCOES
int hotel(void)//editar hotel
{
    char op;
    tipoHotel hotel;

    while(1)
    {
        printf("Informe o nome do Hotel: ");
        scanf("%[^\n]%*c", &hotel.nome);

        printf("Informe a razao social do hotel: ");
        scanf("%[^\n]%*c", &hotel.razao);

        printf("Informe o endereco do hotel: ");
        scanf("%[^\n]%*c", &hotel.endereco);

        do{
            printf("Informe a inscricao estadual do hotel (apenas numeros/13 digitos): ");
            scanf("%13[0-9]", &hotel.insc);
            setbuf(stdin, NULL);
        }while(strlen(hotel.insc) != 13);

        do
        {
            printf("Informe o cnpj do hotel (apenas numeros/14 digitos): ");
            scanf("%14[0-9]", &hotel.cnpj);
            setbuf(stdin, NULL);
        } while(strlen(hotel.cnpj) != 14);
        

        printf("Informe o email do hotel: ");
        scanf("%s%*c", &hotel.email);


        do
        {
            printf("Informe o telefone do hotel (ddnnnnnnnnn/11 digitos): ");
            scanf("%11[0-9]", &hotel.telefone);
            setbuf(stdin, NULL);
        } while(strlen(hotel.telefone) != 11);


        printf("Informe o nome do gerente do hotel: ");
        scanf("%s%*c", &hotel.gerente);

        do{
            printf("Informe o telefone do gerente do hotel (ddnnnnnnnnn/11 digitos): ");
            scanf("%11[0-9]", &hotel.telGer);
            setbuf(stdin, NULL);            
        }while(strlen(hotel.telGer) != 11);


        printf("Informe o horario de checkin do hotel (hh:mm): ");
        scanf("%d:%d", &hotel.checkin[0], &hotel.checkin[1]);

        printf("Informe o horario de checkout do hotel (hh:mm): ");
        scanf("%d:%d", &hotel.checkout[0], &hotel.checkout[1]);

        if(checkInfo())
        {
            printf("salvo");
            //salva no arquivo
            return 1;
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
            printf("salvo");
            //salvar no arquivo
        }
    }
}