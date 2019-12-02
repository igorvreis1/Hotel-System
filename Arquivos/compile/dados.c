#include "dados.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//FUNCOES
void hotel(void)//CORRIGIR SAVE DE ARQUIVO
{
    tipoHotel hotel;

    while(1)
    {
        printf("Informe o nome do Hotel: ");
        fgets(hotel.nome, 99, stdin);

        printf("Informe a razao social do hotel: ");
        fgets(hotel.razao, 99, stdin);        

        printf("Informe o endereco do hotel: ");
        fgets(hotel.endereco, 99, stdin);

        do{
            printf("Informe a inscricao estadual do hotel (apenas numeros/13 digitos): ");
            scanf("%14[0-9]", &hotel.insc);
            cleanBuff();
        }while(strlen(hotel.insc) != 13);
        
        printf("Informe o email do hotel: ");
        fgets(hotel.email, 99, stdin);

        do
        {
            printf("Informe o cnpj do hotel (apenas numeros/14 digitos): ");
            scanf("%15[0-9]", &hotel.cnpj);
            cleanBuff();
        } while(strlen(hotel.cnpj) != 14);

        do
        {
            printf("Informe o telefone do hotel (ddnnnnnnnnn/11 digitos): ");
            scanf("%12[0-9]", &hotel.telefone);
            cleanBuff();
        } while(strlen(hotel.telefone) != 11);

        do{
            printf("Informe as horas que comecam o checkin (Apenas as horas, ex: 12): ");
            scanf("%d", &hotel.checkin.inicio);
        }while(checkHorario(hotel.checkin.inicio, 'h'));
        
        do{
            printf("Informe as horas que terminam o horario de checkin (Apenas as horas, ex: 16): ");
            scanf("%d", &hotel.checkin.termino);
        }while(checkHorario(hotel.checkin.termino, 'h') || hotel.checkin.inicio >= hotel.checkin.termino);
        
        do{
            printf("Informe o horario de checkout do hotel (hh:mm): ");
            scanf("%d:%d", &hotel.checkout[0], &hotel.checkout[1]);
        }while(checkHorario(hotel.checkout[0], 'h') || checkHorario(hotel.checkout[1], 'm'));


        if(checkInfo())
        {
            //  SALVA NO ARQUIVO
            printf("Salvo!");
            break;
        }
    }
}

int addProd(void)//Criar função que altera o local de save
{
    tipoProdutos adProduto;
    while(1)
    {
        printf("Informe o codigo do produto (0001): ");
        scanf("%d", &adProduto.codigo);
        cleanBuff();
        //checar se o código é único;

        printf("De uma descricao para o produto: ");
        scanf("%[^\n]", &adProduto.desc);

        printf("Informe quanto tem desse produto no estoque: ");
        scanf("%d", &adProduto.estoque);

        printf("Informe qual o estoque minimo desse produto: ");
        scanf("%d", &adProduto.estMin);

        printf("Informe qual o preco de custo do produto (10.20): R$ ");
        scanf("%f", &adProduto.pCusto);


        printf("Codigo: %d\nDescricao: %s\n", adProduto.codigo, adProduto.desc);
        printf("Estoque: %d\nEstoque minimo: %d\n", adProduto.estoque, adProduto.estMin);
        printf("Preco de custo: %.2f\n", adProduto.pCusto);
        //calcular o preco de venda
        //printf("O preco de venda baseado no preco de custo e impostos sera: R$%.2f\n\n", adProduto.pVenda);
        if(checkInfo())
        {
            FILE *p;
            if((p = fopen("..\\Saves\\produtos.txt", "w")) == NULL){//abre o arquivo para escrita
                printf("Erro ao abrir o arquivo!");
                return 0;
            }
            fprintf(p, "%d\r\n%s\r\n%d\r\n%d\r\n%.2f\r\n%.2f", adProduto.codigo, adProduto.desc, adProduto.estoque, adProduto.estMin,
            adProduto.pCusto, adProduto.pVenda);//salva os dados 1 abaixo do anterior, /r por correção de bug, apenas windows
            fclose(p);

            printf("Salvo!");
            return 1;
        }
    }
}

void addFunc(){
    
}

void gerente(void)//apenas criar função que altera o local de save
{
    tipoGerente gerente;

    printf("Informe o nome do gerente do hotel: ");
    fgets(gerente.nome, 99, stdin);

    do{
        printf("Informe o telefone do gerente do hotel (ddnnnnnnnnn/11 digitos): ");
        scanf("%11[0-9]", &gerente.telefone);
        setbuf(stdin, NULL);            
    }while(strlen(gerente.telefone) != 11);

    printf("Nome: %sTelefone: %s\n\n", gerente.nome, gerente.telefone);

    if(checkInfo())
    {
        FILE *fGerente;
        fGerente = fopen("..\\Saves\\gerente.txt", "w");
        fprintf(fGerente, "%s\r\n%s", gerente.nome, gerente.telefone);
        fclose(fGerente);

        printf("Informacoes salvas em: %s", "Saves\\gerente.txt");//caminho
    }
}

int checkInfo(void)//CONCLUIDA
{
    char op;
    do{
            printf("Deseja continuar? (s - sim / n - nao): ");
            cleanBuff();
            scanf("%c", &op);

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

void cleanBuff(void)//limpa o buffer (CONCLUIDO)
{
    int ch = 0;
    while((ch = getchar()) != '\n' && ch != EOF){}
}

int checkHorario(int horario, char tipo)//concluida
{   
    int r;
    

    switch (tipo)
    {
        case 'h'://hora
            if(horario > 24 || horario < 0)
                r = 1;
            break;
        case 'm'://minuto
            if(horario > 60 || horario < 0)
                r = 1;
            break;
    }
    if(r == 1){
        printf("\nHorario invalido, tente novamente!\n");
        return 1;
    }  
    return 0;
}