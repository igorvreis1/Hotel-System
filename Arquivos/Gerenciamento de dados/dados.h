#ifndef _DADOS_H_
#define _DADOS_H_

    /*
        CONSTANTES NECESSARIAS
    */
   #define nums 11//telefone 11 - cnpj 14 - insc 13
   #define str 100
   #define lstr 255
   #define modulos 1 //quantidade de modulos que o programa tem
   #define login 8 //quantidade de digitos do login
    /*
     TIPOS DE VARIAVEIS NECESSÁRIAS
    */
   //hotel
   typedef struct
   {
       char nome[str];//nome social
       char razao[str];//nome comercial
       char insc[13];
       char cnpj[14];
       char endereco[str];
       char telefone[nums];
       char email[str];
       char gerente[str];
       char telGer[nums];
       int checkin[2];
       int checkout[2];
       float lucro;
       char *produtos; //atenção
    //    int *qReservados; falta
   }tipoHotel;

   //Hóspedes
   typedef struct
   {
    unsigned int codigo; 
    char nome[str];
    char endereco[str];
    char cpf[12]; //DDDDDDDDD-DD
    char telefone[nums]; //DD-NNNNNNNNN
    char email[str];
    char sexo; //M - masculino; F - feminino
    char estCiv;//C - casado; S - solteiro; D - divorciado; V - viúvo
    int datNas[3];// DD/MM/AAAA
   }tipoHospedes;

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
        int insc[13];
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
        char usuario[login];
        char senha[login];
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
    void addProd(void);

    /*
        checkInfo: Função que checa se as informações estão corretas
    */
    int checkInfo(void);

#endif