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
        char desc[lstr];
        char facilidade[lstr];
        int categoria[2]; //1 digito == classe / 2 digito == tamanho
    }tipoQuartos;
   
    //Categorias
    typedef struct // Player Solo, luxo casal, luxo familia, normal simples, normal casal, normal familia
    {
        unsigned int codigo[2]; //1 digito -> classe / 2 digito -> tamanho
        char desc[str];
        float valor;
        int tamanho; //1 - 1 pessoa / 2 - casal / 3 familia
        char tipo; //luxo, simples, normal
    }tipoCategoria;

    //produtos
    typedef struct
    {
        unsigned int codigo;
        char desc[str];
        int estoque;
        int estMin;
        float pCusto;
        float pVenda;
    }tipoProdutos;

    //fornecedores
    typedef struct
    {
        unsigned int codigo;
        char nome[str];//social
        char razao[str];//nome comercial
        char insc[13];
        char cnpj[14];
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
    
    //Funçoes

    /*
        Hotel: Função utilizada para atualizar ou inserir as informaçoes do hotel e gerente
    */
    void hotel(void);

    /*
        addProd: Função utilizada para adicionar novos produtos ou atualizar
    */
    int addProd(void);

    /*
        gerente: Função que atualiza ou insere informações sobre o gerente
    */
    void gerente(void);

    /*
        fornecedores: Função que atualiza ou insere informações sobre os fornecedores
    */
    int fornecedores();

#endif