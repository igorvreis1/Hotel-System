#ifndef _DADOS_H_
#define _DADOS_H_

    /*
        CONSTANTES NECESSARIAS
    */
   #define tel 12
   #define str 50
   #define ccpf 11
    /*
     TIPOS DE VARIAVEIS NECESSÁRIAS
    */
   //hotel
   typedef struct
   {
       char nome[str];
       char razao[str];// PERGUNTAR AO MANOEL
       char inscricao[10];//Ver na net
       char CNPJ[17]; //VER na net
       char endereco[str];
       char telefone[tel];
       char email[str];
       char gerente[str];
       char telGer[tel];
       int checkin[2];
       int checkout[2];
       float lucro;
       
       int *qReservados;
   }hotel;

   //Hóspedes
   typedef struct
   {
    unsigned int cod; 
    char nome[str];
    char endereco[str];
    char cpf[ccpf]; //tipo char para ficar mais facil a contagem dos digitos
    char telefone[tel]; //DD-NNNNNNNNN
    char email[str];
    char sexo; //M - masculino; F - feminino
    char estCiv;//C - casado; S - solteiro; D - divorciado; V - viúvo
    int datNas[3];// DD/MM/AAAA
   }hospedes;

    //Acomodações
    typedef struct
    {
        unsigned int cod;
        char desc[str];
        char facil[str];
        char cat[2];
    }quartos;
   
    //Categorias
    typedef struct // Player Solo, luxo casal, luxo familia, normal simples, normal casal, normal familia
    {
        unsigned int cod;
        char desc[str];
        int valor;
        int tamanho; 
    }categoria;

#endif