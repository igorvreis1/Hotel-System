#ifndef VARS_H
#define VARS_H

    /*
        CONSTANTES NECESSARIAS
    */
    #define raiz "C:\\ProgramData\\hotelSystem\\" // raiz principal do programa
    #define nums 15//telefone 11 - cnpj 14 - insc 13
    #define str 100
    #define lstr 255
    #define modulos 1 //quantidade de modulos que o programa tem
    #define user 10 //quantidade de digitos do login (máximo 8) +1 \n


    #define SUCCESS 1//quando a operação for concluida
    #define FAILED -1//quando ocorrer falha na operação (exemplo uma senha incorreta)
    #define EOPEN -2 //erro ao abrir arquivo
    #define UNEXIST -3//quando a informação não existir
    #define AEXIST -4 // quando a informação já existir
    #define CANCELED -5//quando o usuario cancelar a operação


    /*
        TIPOS DE VARIAVEIS NESCESSARIAS
    */

     typedef struct
    {
        char codigo;
        char usuario[user];
        char senha[user];
    }tipoLogin;

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


    //QUANTIDADES para ter o controle de quanto de cada coisa tem
   typedef struct
   {
       unsigned int clientes;
       unsigned int funcionarios;
       unsigned int fornecedores;
       unsigned int produtos;
       unsigned int quartos;
       unsigned int reservas;
   }tipoQuantidade;


    typedef struct
    {
        char dirPadrao[255];
        float lucr;
        int logado; //1 para logado, 0 para deslogado
        char usuario[8];//o nome do usuario logado
    }tipoPadrao;

    /*
        variaveis importantes globais (serao inicializadas com o inicio do programa)
    */
    tipoPadrao padrao;
   
#endif