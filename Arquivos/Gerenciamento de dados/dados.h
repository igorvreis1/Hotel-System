#ifndef _DADOS_H_
#define _DADOS_H_

    /*
        CONSTANTES NECESSARIAS
    */
   #define nums 12
    /*
     TIPOS DE VARIAVEIS NECESSÁRIAS
    */
   //hotel
   typedef struct
   {
       char *nome;//nome social
       char *razao;//nome comercial
       char inscricao[nums];
       char CNPJ[nums];//VER na net
       char *endereco;
       char telefone[nums];
       char *email;
       char *gerente;
       char telGer[nums];
       int checkin[2];
       int checkout[2];
       float lucro;
       char *produtos;
    //    int *qReservados; falta
   }hotel;

   //Hóspedes
   typedef struct
   {
    unsigned int cod; 
    char *nome;
    char *endereco;
    char cpf[nums]; //DDDDDDDDD-DD
    char telefone[nums]; //DD-NNNNNNNNN
    char *email;
    char sexo; //M - masculino; F - feminino
    char estCiv;//C - casado; S - solteiro; D - divorciado; V - viúvo
    int datNas[3];// DD/MM/AAAA
   }hospedes;

    //Acomodações
    typedef struct
    {
        unsigned int cod;
        char *desc;
        char *facil;
        char cat[2]; //ATENÇÃO
    }quartos;
   
    //Categorias
    typedef struct // Player Solo, luxo casal, luxo familia, normal simples, normal casal, normal familia
    {
        unsigned int cod;
        char *desc;
        int valor;
        int tamanho;
    }categoria;

#endif