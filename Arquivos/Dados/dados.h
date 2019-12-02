#ifndef _DADOS_H_
#define _DADOS_H_

#include "vars.h"

    /*
     TIPOS DE VARIAVEIS NECESSÁRIAS
    */
   //hotel
   typedef struct
   {
       char nome[str];//nome social
       char razao[str];//nome comercial
       char insc[nums];
       char cnpj[nums];
       char endereco[str];
       char telefone[nums];
       char email[str];

        struct{
            int inicio;
            int termino;
       }checkin;

        int checkout[2];
       float lucro;
   }tipoHotel;

    //gerente
    typedef struct
    {
        char nome[str];
        char telefone[nums];
    }tipoGerente;

    //Acomodações
    typedef struct
    {
        unsigned int codigo; //numero do quarto
        int categoria;
        int tamanho;
        float valor;
        char desc[lstr];
        char facilidade[lstr];
    }tipoQuartos;

    //produtos
    typedef struct
    {
        unsigned int codigo;
        unsigned int codForn;
        char desc[str];
        float frete;
        int estoque;
        int estMin;
        float pCusto;
        float pVenda;
        int imposto;
    }tipoProdutos;

    //fornecedores
    typedef struct
    {
        unsigned int codigo;
        char nome[str];//social
        char insc[nums];
        char razao[str];//nome comercial
        char cnpj[nums];
        char endereco[str];
        char telefone[nums];
        char email[str];
    }tipoFornecedores;

    //funcionario
    typedef struct
    {
        unsigned int codigo;
        char nome[str];
        char usuario[user];
        char senha[user];
        char perm[modulos]; //- -> sem acesso / + -> acesso
    }tipoFuncionarios;
    
    typedef struct
    {
        int codProd;
        int quant;
    }tipoEstoque;
    

    typedef struct 
    {
        char nomeProduto[str];
        int qntProd;
        int codProd;
        float total;
        float totalFrete;
        float totalProduto;
        float totalImposto;
    }tipoNota;
    
    //Funçoes

    /*
        Hotel: Função utilizada para inserir as informações do hotel
        retorna SUCCESS, EOPEN ou CANCELED
    */
    int hotel(void);

    /*

    */
    void infotel();
    /*
        addProd: Função utilizada para adicionar novos produtos ou atualizar
    */
    int addProd(void);

    /*
        gerente: Função que atualiza ou insere informações sobre o gerente
        retorna SUCCES, EOPEN OU CANCELED
    */
    int gerente(void);

    /*
        fornecedores: Função que atualiza ou insere informações sobre os fornecedores
    */
    int fornecedores();

    /*
        verForn: Função que verifica se um fornecedor existe pelo codigo
        espera como parametro o codigo do fornecedor e o cnpj ou um dos dois (preencher com NULL o outro com null
        quando for apenas um);
        retorna SUCCESS caso exista e FAILED caso nao exista
    */
    int verForn(int num, char *cnpj);

    /*
        lista: Lista todos os dados de certa categoria, espera como parametro 
        (o tipo, ex: produto)
        retorna SUCCESS em caso de sucesso, EOPEN em caso de erro de abertura do arquivo ou
        UNEXIST em caso de não haver dados cadastrados
    */
    int lista(char *tipo);

    /*
        calc: Calculo o preço de venda de um produto, espera como parametro 
        o preco de custo, o frete total, o imposto total, o lucro, quantidade
        retorna o preco de venda
    */
   float calc(float pcusto, float frete, float imposto, float lucro, float quantidade);

    /*

    */
   int calcEstoque(int cod);

   /*
   
   */
    int addQuarto();
#endif