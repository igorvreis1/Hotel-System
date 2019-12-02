#include "dados.h"
#include "functions.h"
#include "vars.h"
#include <stdlib.h>
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
        FILE *p = fopen("C:\\ProgramData\\hotelSystem\\configs\\hotel.bin", "wb");
        if(p == NULL)
        {
            return EOPEN;
        }

        fwrite(&hotel, sizeof(tipoHotel), 1, p);
        fclose(p);
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

    int error = verForn(adProduto.codForn, "a");
    if(error == FAILED || error == EOPEN)//verifica pelo codigo se o fornecedor existe
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
        FILE *p, *j;

        if((p = fopen(caminhoLog("produtos"),"ab+")) == NULL)
        {
            return EOPEN;
        }
        
        adProduto.estoque = quantidade;
        adProduto.codigo = pegaCod("produtos");//pega o codigo do produto

        j = fopen(caminhoLog("nota"), "ab+");
        if (j == NULL)
        {
            printf("Erro ao abrir a nota!\n");
            return EOPEN;
        }

        tipoNota nota;
        nota.totalProduto = adProduto.frete + adProduto.imposto + adProduto.pCusto;
        nota.totalFrete = adProduto.frete;
        nota.totalImposto = adProduto.imposto;
        nota.qntProd = quantidade;
        strcpy(nota.nomeProduto, adProduto.desc);
        fwrite(&nota, sizeof(tipoNota), 1, j);
        fclose(j);

        fwrite(&adProduto, sizeof(tipoProdutos), 1, p);
        fclose(p);
        printf("Informacoes salvas em: %s\n", caminhoLog("produtos"));
        return SUCCESS;
    }else
        return CANCELED;
}

int gerente(void)//CONCLUIDO
{
    tipoGerente gerente;

    printf("Informe o nome do gerente do hotel: ");
    scanf("%100[^\n]", &gerente.telefone);

    do{
        printf("Informe o telefone do gerente do hotel (ddnnnnnnnnn/11 digitos): ");
        scanf("%11[0-9]", &gerente.telefone);
        setbuf(stdin, NULL);            
    }while(strlen(gerente.telefone) != 11);


    if(checkInfo() == SUCCESS)
    {
        FILE *fGerente;
        fGerente = fopen("C:\\ProgramData\\hotelSystem\\configs\\gerente.bin", "wb");
        if(fGerente == NULL)
        {
            printf("Erro ao abrir arquivo do gerente!\n");
            return EOPEN;
        }
        fwrite(&gerente, sizeof(tipoGerente), 1, fGerente);
        fclose(fGerente);
        return SUCCESS;
    }
    return CANCELED;
}

int fornecedores()//CONCLUIDO
{
    tipoFornecedores fornecedor, aux;

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

    p = fopen(caminhoLog("fornecedores"), "rb");
    if(p == NULL)
    {
        return EOPEN;
    }

    while(!feof(p))
    {
        fread(&aux, sizeof(tipoFornecedores), 1, p);

        if(feof(p))
            break;

        if(aux.codigo == num || strcmp(aux.cnpj, cnpj) == 0)
        {
            fclose(p);
            return SUCCESS;
        }
    }
    fclose(p);
    return FAILED;
}

int lista(char *tipo)//CONCLUIDO
{
    FILE *p;

    if(strcmp(tipo, "quartos") == 0)
    {
        p = fopen("C:\\ProgramData\\hotelSystem\\configs\\quartos.bin", "rb");
    }else
    {
        if(tamanhoArq(caminhoLog(tipo)) == 0)
        {
            return UNEXIST;
        }
        p = fopen(caminhoLog(tipo), "rb");
    }

    if(p == NULL)
        return EOPEN;

    tipoFornecedores aux;
    tipoProdutos prod;
    tipoQuartos q;


    if( strcmp(tipo, "produtos") == 0)
    {
        while(!feof(p))
        {
            fread(&prod, sizeof(tipoProdutos), 1, p);
            if(feof(p))
                break;
            printf("Descricao: %s, Quantia no estoque: %d, Preco de venda: %.2f, Codigo: %d\n\n", prod.desc, prod.estoque, prod.pVenda, prod.codigo);
        }
    }else
    if(strcmp(tipo, "fornecedores") == 0)
    {

        while(!feof(p))
        {
            fread(&aux, sizeof(tipoFornecedores), 1, p);
            if(feof(p))//se ele já leu o fim do arquivo entao para
                break;
            printf("Nome: %s, cnpj: %s, codigo: %d\n\n", aux.nome, aux.cnpj, aux.codigo);
        }
    }else
    if(strcmp(tipo, "quartos") == 0)
    {
        while(!feof(p))//le ate que seja o fim do arquivo
        {
            fread(&q, sizeof(tipoQuartos), 1, p);
            if(feof(p))
                break;
            printf("Descricao: %s\nTamanho: %d\tCategoria: %d\tValor: %.2f\nFacilidades: %s\tCodigo: %d\n\n", q.desc, q.tamanho, q.categoria, q.valor, q.facilidade, q.codigo);
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

void infotel()
{
    FILE *p = fopen("C:\\ProgramData\\hotelSystem\\configs\\hotel.bin", "rb");
    if( p == NULL )
    {
        printf("Erro ao ler os dados do hotel\n");
        return;
    }
    tipoHotel hotel;
    fread(&hotel, sizeof(tipoHotel), 1, p);
    fclose(p);

    printf("Nome: %s\tRazao: %s\t", hotel.nome, hotel.razao);
    printf("Horario de checkin: %d as %d horas\n", hotel.checkin.inicio, hotel.checkin.termino);
    printf("Inscricao estadual: %s\tEndereco: %s\n", hotel.insc, hotel.endereco);
    printf("Telefone: %s\tCnpj: %s\tEmail: %s\n", hotel.telefone, hotel.cnpj, hotel.email);
    printf("O horario de checkout maximo e: %d horas e %d minutos!\n", hotel.checkout[0], hotel.checkout[1]);
}

int calcEstoque(int cod)
{
    FILE *p = fopen(caminhoLog("nota"), "rb");   
    if( p == NULL )
    {
        return EOPEN;
    }

    int total = 0;

    tipoNota nota;
    while(!feof(p))
    {
        fread(&nota, sizeof(tipoNota), 1, p);
        if( nota.codProd == cod )
        {
            total += nota.qntProd;//calcula o total do produto no estoque
            break;
        }
    }
    fclose(p);
    
    int linhas = 0;
    tipoEstoque aux;
    p = fopen(caminhoLog("estoque"), "ab");
    if( p == NULL )
        return EOPEN;

    while(!feof(p))
    {
        fread(&aux, sizeof(tipoEstoque), 1, p);
        if(feof(p))
            break;
            linhas++;
    }
    fseek(p, 0, SEEK_SET);//volta para o inicio
    
    tipoEstoque est[linhas];
    linhas = 0;
    while(!feof(p))
    {
        fread(est+linhas, sizeof(tipoEstoque), 1, p);
        if( feof(p) )
            break;
            linhas++;
    }

    for( int i = 0; i <= linhas; i++)//remove onde o cod for repetido
    {
        if(est[i].codProd == cod)
        {
            for(int a = i; a < linhas; a++)
            {
                est[a].codProd = est[1+a].codProd;
                est[a].quant = est[1+a].quant;
            }
            linhas--;
        }
    }

    fwrite(est, sizeof(tipoEstoque), linhas, p);
    fclose(p);
}

int addQuarto()
{
    tipoQuartos q, aux;
    printf("Qual a categoria do quarto (1,2,3): ");
    scanf("%d", &q.categoria);
    cleanBuff();

    printf("Qual o numero de pessoas que o quarto comporta: ");
    scanf("%d", &q.tamanho);
    cleanBuff();

    printf("Qual o valor da diaria do quarto (75.00): R$");
    scanf("%f", &q.valor);
    cleanBuff();

    printf("De uma descricao rapida para o quarto: ");
    scanf("%255[^\n]", &q.desc);
    cleanBuff();

    printf("Informe o que tem no quarto (ex: ventilador, ar condicionado, etc): ");
    scanf("%255[^\n]", &q.facilidade);
    cleanBuff();

    if( checkInfo() == CANCELED )
        return CANCELED;

    FILE *p = fopen("C:\\ProgramData\\hotelSystem\\configs\\quartos.bin", "ab+");
    if ( p == NULL)
        return EOPEN;

    if(tamanhoArq("C:\\ProgramData\\hotelSystem\\configs\\quartos.bin") == 0)
    {
        q.codigo = 1;

    }else
    {
        fseek(p, -sizeof(tipoQuartos), SEEK_END);//vai pro penultimo dado salvo
        fread(&aux, sizeof(tipoQuartos), 1, p);
        aux.codigo++;
        q.codigo = aux.codigo;
        fseek(p, 0, SEEK_END);//volta para o final
    }


    fwrite(&q, sizeof(tipoQuartos), 1, p);
    fclose(p);
    return SUCCESS;
}