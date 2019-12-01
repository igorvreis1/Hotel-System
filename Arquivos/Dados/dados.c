#include "dados.h"
#include "functions.h"
#include "vars.h"
#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

//FUNCOES
int hotel(void)//CONCLUIDO
{
    tipoHotel hotel;

    printf("Informe o nome do Hotel: ");
    scanf("%100[^\n]", &hotel.nome);
    cleanBuff();

    printf("Informe a razao social do hotel: ");
    scanf("%100[^\n]", &hotel.razao);
    cleanBuff();
     

    printf("Informe o endereco do hotel: ");
    scanf("%100[^\n]", &hotel.endereco);
    cleanBuff();


    do{
        printf("Informe a inscricao estadual do hotel (apenas numeros/13 digitos): ");
        scanf("%14[0-9]", &hotel.insc);
        cleanBuff();
    }while(strlen(hotel.insc) != 13);
    
    printf("Informe o email do hotel: ");
    scanf("%100[^\n]", &hotel.email);
    cleanBuff();


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
    }while(checkHorario(hotel.checkin.inicio, 'h') == FAILED);
    
    do{
        printf("Informe as horas que terminam o horario de checkin (Apenas as horas, ex: 16): ");
        scanf("%d", &hotel.checkin.termino);
    }while(checkHorario(hotel.checkin.termino, 'h') == FAILED || hotel.checkin.inicio >= hotel.checkin.termino);
    
    do{
        printf("Informe o horario de checkout do hotel (hh:mm): ");
        scanf("%d:%d", &hotel.checkout[0], &hotel.checkout[1]);
        cleanBuff();
    }while(checkHorario(hotel.checkout[0], 'h') == FAILED || checkHorario(hotel.checkout[1], 'm') == FAILED);


    if(checkInfo() == SUCCESS)
    {
        FILE *p = fopen(caminhoLog("hotel"), "wb");
        if(p == NULL)
        {
            return EOPEN;
        }

        fwrite(&hotel, sizeof(tipoHotel), 1, p);
        fclose(p);
        printf("Informacoes salvas em: %s", caminhoLog("hotel"));
        return SUCCESS;
    }
    else
    {
        return CANCELED;
    }
}

int addProd(void)//CONCLUIDO
{
    tipoProdutos adProduto, aux;
    int quantidade = 0;

    printf("Qual o codigo do fornecedor do produto: ");
    scanf("%d", &adProduto.codForn);
    cleanBuff();

    if((verForn(adProduto.codForn, "a")) == FAILED)//verifica pelo codigo se o fornecedor existe
    {
        return UNEXIST;
    }

    printf("Qual o preco de frete total do fornecedor: R$");
    scanf("%f", &adProduto.frete);
    cleanBuff();

    printf("De uma descricao para o produto: ");
    scanf("%255[^\n]", adProduto.desc);
    cleanBuff();

    printf("Informe quanto e o imposto total cobrado por esse produto (5.30): R$");
    scanf("%d", &adProduto.imposto);
    cleanBuff();

    printf("Informe qual sera o estoque minimo desse produto: ");
    scanf("%d", &adProduto.estMin);
    cleanBuff();

    printf("Informe qual o preco de custo do produto (unitario) (10.20): R$");
    scanf("%f", &adProduto.pCusto);
    cleanBuff();

    printf("Quantas unidades do produto foram compradas: ");
    scanf("%d", &quantidade);
    cleanBuff();

    printf("\nCom base no preco de custo: R$%.2f, o imposto: %d%%\n", adProduto.pCusto, adProduto.imposto);
    printf("O frete: R$%.2f, e a porcentagem de lucro: %.2f%%\n", adProduto.frete, padrao.lucr*100.0);
    adProduto.pVenda = calc(adProduto.pCusto, adProduto.frete, adProduto.imposto, padrao.lucr, quantidade);
    printf("O preco de venda sera: R$%.2f\n", adProduto.pVenda);

    if(checkInfo() == SUCCESS)
    {   
        FILE *p;
        char caminho[255];
        strcpy(caminho, caminhoLog("produtos"));//concatena o caminho de save para produtos

        if((p = fopen(caminho,"ab+")) == NULL)
        {
            return EOPEN;
        }
        
        adProduto.estoque = quantidade;
        adProduto.codigo = pegaCod(0);//pega o codigo do produto

        fwrite(&adProduto, sizeof(tipoProdutos), 1, p);
        fclose(p);
        printf("Informacoes salvas em: %s", caminhoLog("produtos"));
        return SUCCESS;
    }else
        return CANCELED;
}

void gerente(void)//CONCLUIDO
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
        fGerente = fopen(caminhoLog("gerente"), "wb");
        fwrite(&gerente, sizeof(tipoGerente), 1, fGerente);
        fclose(fGerente);

        printf("Informacoes salvas em: %s", caminhoLog("gerente"));//caminho
    }
}

int fornecedores()//CONCLUIDO
{
    tipoFornecedores fornecedor, aux;

    printf("Fornecedor: \n\n");
    printf("Digite o nome social do fornecedor: ");
    scanf("%100[^\n]", fornecedor.nome);
    cleanBuff();
    
    printf("Digite o nome comercial do fornecedor: ");
    scanf("%100[^\n]", fornecedor.razao);
    cleanBuff();

    do{
        printf("Informe a inscricao estadual do fornecedor (apenas numeros/13 digitos): ");
        scanf("%14[0-9]", fornecedor.insc);
        cleanBuff();
    }while(strlen(fornecedor.insc) != 13);

    do
    {
        printf("Informe o cnpj do fornecedor (apenas numeros/14 digitos): ");
        scanf("%15[0-9]", fornecedor.cnpj);
        cleanBuff();
    } while(strlen(fornecedor.cnpj) != 14);

    printf("Digite o endereco do fornecedor: ");
    scanf("%100[^\n]", fornecedor.endereco);
    cleanBuff();

    do
    {
        printf("Informe o telefone do fornecedor (ddnnnnnnnnn/11 digitos): ");
        scanf("%12[0-9]", fornecedor.telefone);
        cleanBuff();
    } while(strlen(fornecedor.telefone) != 11);

    printf("Digite o email do fornecedor: ");
    scanf("%100[^\n]", fornecedor.email);
    cleanBuff();

    if(checkInfo() == SUCCESS)
    {
        FILE *p;
        char caminho[255];
        strcpy(caminho, caminhoLog("fornecedores"));

        p = fopen(caminho, "ab+");//abre para modo de append
        if(p == NULL)
        {
            return EOPEN;
        }

        if(verForn(-1, fornecedor.cnpj) == SUCCESS)//verifica se ja existe um fornecedor com esse cnpj
        {
            fclose(p);
            return AEXIST;
        }

        if(tamanhoArq(caminho) == 0)//checa se o arquivo esta vazio
        {
            fornecedor.codigo = 1;
        }else
        {
            fseek(p, -sizeof(tipoFornecedores), SEEK_END);//vai para a penultima posicao do arquivo
            fread(&aux, sizeof(tipoFornecedores), 1, p);
            aux.codigo++;//atualiza o codigo de acordo com o codigo anterior
            fornecedor.codigo = aux.codigo;//atualiza o proximo codigo a ser cadastrado
        }

        fwrite(&fornecedor, sizeof(tipoFornecedores), 1, p);
        fclose(p);
        printf("Informacoes salvas em: %s", caminhoLog("fornecedores"));
        return SUCCESS;
    }
    else{
        return CANCELED;
    }
}

int verForn(int num, char *cnpj)//CONCLUIDO
{
    FILE *p;
    tipoFornecedores aux;
    char caminho[255];
    strcpy(caminho, caminhoLog("fornecedores"));

    p = fopen(caminho, "rb");
    if(p == NULL)
    {
        return EOPEN;
    }

    while(!feof(p))
    {
        if(!feof(p))
        {
            fread(&aux, sizeof(tipoFornecedores), 1, p);

            if(aux.codigo == num || strcmp(aux.cnpj, cnpj) == 0)
                return SUCCESS;
        }
    }
    return FAILED;
}

int lista(int tipo)//CONCLUIDO
{
    FILE *p;
    char caminho[255];
    int tamanho;
    strcpy(caminho, caminhoLog("fornecedores"));

    switch (tipo)
    {
        case 0: strcpy(caminho, caminhoLog("produtos"));break;
        
        case 1: strcpy(caminho, caminhoLog("fornecedores"));break;
    }

    if(tamanhoArq(caminho) == 0)
    {
        return UNEXIST;
    }

    p = fopen(caminho, "rb");
    if(p == NULL)
        return EOPEN;

    tipoFornecedores aux;
    tipoProdutos prod;

    while(!feof(p))//le ate que seja o fim do arquivo
    {
        if(tipo == 0)
        {
            fread(&prod, sizeof(tipoProdutos), 1, p);
            if(feof(p))
                break;
            printf("Descricao: %s, Quantia no estoque: %d, Preco de venda: %.2f, Codigo: %d", prod.desc, prod.estoque, prod.pVenda, prod.codigo);
        }
        else 
        if(tipo == 1)
        {
            fread(&aux, sizeof(tipoFornecedores), 1, p);
            if(feof(p))//se ele já leu o fim do arquivo entao para
                break;
            printf("Nome: %s, cnpj: %s, codigo: %d\n", aux.nome, aux.cnpj, aux.codigo);
        }
    }
    fclose(p);
    return SUCCESS;
}

float calc(float pcusto, float frete, float imposto, float lucro, float quantidade)//CONCLUIDO
{
    float total;
    frete = frete/quantidade;
    imposto = imposto/quantidade;
    total = pcusto + frete + imposto;
    lucro *= total;
    total += lucro;
    return total;
}