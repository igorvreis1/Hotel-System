#ifndef _DADOS_H_
#define _DADOS_H_

<<<<<<< HEAD
    /*
        CONSTANTES NECESSARIAS
    */
   #define nums 15//telefone 11 - cnpj 14 - insc 13
   #define str 100
   #define lstr 255
   #define modulos 1 //quantidade de modulos que o programa tem
   #define user 10 //quantidade de digitos do login (máximo 8) +1 \n
=======
#include "vars.h"
>>>>>>> upstream/master

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
<<<<<<< HEAD
    //    int *qReservados; falta
=======
>>>>>>> upstream/master
   }tipoHotel;

    //gerente
    typedef struct
    {
        char nome[str];
        char telefone[nums];
    }tipoGerente;

<<<<<<< HEAD
   //Hóspedes
   typedef struct
   {
    unsigned int codigo; 
    char nome[str];
    char endereco[str];
    char cpf[nums]; //DDDDDDDDD-DD
    char telefone[nums]; //DD-NNNNNNNNN
    char email[str];
    char sexo; //M - masculino; F - feminino
    char estCiv;//C - casado; S - solteiro; D - divorciado; V - viúvo
    int datNas[3];// DD/MM/AAAA
   }tipoHospedes;

=======
>>>>>>> upstream/master
    //Acomodações
    typedef struct
    {
        unsigned int codigo; //numero do quarto
<<<<<<< HEAD
        char desc[lstr];
        char facilidade[lstr];
        int categoria[2]; //1 digito == classe / 2 digito == tamanho
        char *reservados;//ATENÇÃO
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
=======
        int categoria;
        int tamanho;
        float valor;
        char desc[lstr];
        char facilidade[lstr];
    }tipoQuartos;
>>>>>>> upstream/master

    //produtos
    typedef struct
    {
        unsigned int codigo;
<<<<<<< HEAD
        char desc[str];
=======
        unsigned int codForn;
        char desc[str];
        float frete;
>>>>>>> upstream/master
        int estoque;
        int estMin;
        float pCusto;
        float pVenda;
<<<<<<< HEAD
        char *produtos;//ATENÇÃO
=======
        int imposto;
>>>>>>> upstream/master
    }tipoProdutos;

    //fornecedores
    typedef struct
    {
        unsigned int codigo;
        char nome[str];//social
<<<<<<< HEAD
        char razao[str];//nome comercial
        int insc[13];
        char cnpj[14];
=======
        char insc[nums];
        char razao[str];//nome comercial
        char cnpj[nums];
>>>>>>> upstream/master
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
    
<<<<<<< HEAD
    //Funçoes

    /*
        Hotel: Função utilizada para atualizar ou inserir as informaçoes do hotel e gerente
    */
    void hotel(void);

=======
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
>>>>>>> upstream/master
    /*
        addProd: Função utilizada para adicionar novos produtos ou atualizar
    */
    int addProd(void);

    /*
<<<<<<< HEAD
        checkInfo: Função que checa se as informações estão corretas
        retorna 1 caso estejam
    */
    int checkInfo(void);

    /*
        gerente: Função que atualiza ou insere informações sobre o gerente
    */
    void gerente(void);

    /*
        cleanBuff: Função que consome todos os caracteres do buffer, limpando-o
    */
    void cleanBuff(void);

    /*
        checkHorario: Checa se a hora ou os minutos estão no padrao de horas (h < 24 ou m < 60)
        retorna 0 caso estejam
        parametros: (hora ou minuto, 'm' ou 'h') onde 'm' para minuto e 'h' para hora
    */
   int checkHorario(int horario, char tipo);

=======
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
>>>>>>> upstream/master
#endif