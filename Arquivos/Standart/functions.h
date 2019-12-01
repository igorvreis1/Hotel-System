#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vars.h"
    //      FUNÇÕES

    /*
        infoLog: pede para que o usuario digite suas informações, retorna uma struct do tipoLogin com os dados
        (sem \n no final)
    */
    tipoLogin infoLog();

    /*
        logar: Utilizada para fazer login de usuarios.
        Espera como parametro o tipo de usuario (cliente, funcionario ou administrador)
        retorna SUCCES caso o login seja feito;
        Erros: EOPEN -> erro ao abrir o arquivo, FAILED -> senha incorreta, UNEXIST -> usuario nao existe
    */
    int logar(char *tipo);

    /*
        cadastrar: utilizada para cadastrar um usuario, espera como parametro o tipo de cadastro
        (cliente, funcionario, administrador)
        returns: EOPEN -> erro ao abrir arquivo, AEXIST -> usuario ja existe, SUCCES -> cadastro efetuado
    */
    int cadastrar(char *tipo);

    /*
        cleanBuff: Função que consome todos os caracteres do buffer, limpando-o
    */
    void cleanBuff(void);

    /*
        checkHorario: Checa se a hora ou os minutos estão no padrao de horas (h < 24 ou m < 60)
        retorna SUCCESS caso estejam, FAILED caso não estejam
        parametros: (hora ou minuto, 'm' ou 'h') onde 'm' para minuto e 'h' para hora
    */
   int checkHorario(int horario, char tipo);

    /*
        checkInfo: Função que checa se o usuario quer prosseguir
        retorna SUCCES caso queira, CANCELED -> caso não
    */
    int checkInfo(void);

    /*
        excluirLog: Apaga um usuario, espera como parametro o tipo (funcionario, cliente, admnistrador),
        o nome de usuario a ser excluido!
        Return: 1 caso de erro na abertura do arquivo, -1 caso o usuario cancele, 2 caso o usuario nao exista,
        0 caso ocorra com sucesso!
    */
    int excluirLog(char *tipo, char *usuario);//REFAZER

    /*
        alteraDir: altera o diretorio padrao de save de acordo com a escolha do usuario 
        retorna CANCELED caso o usuario cancele ou SUCCESS
    */
    int alteraDir();

    /*
        pegaDir: Pega o diretorio padrão dos saves e insere em char dirPadrao[255]
    */
    void pegaDir();

    /*
        inicializa: Inicializao o projeto criando as pastas e dependencias necessarias
    */
    void inicializa();

    /*
        caminhoLog: Concatena o caminho de save para login
        espera como parametro o tipo de login (funcionario, cliente ou administrador)
    */
    char *caminhoLog(char *tipo);

    /*
        tamanhoArq: Pega o tamanho de um arquivo, espera como parametro o caminho do arquivo
        retorna: EOPEN em caso de erro e o tamanho do arquivo no caso de sucesso
    */
    int tamanhoArq(char* nome);

    /*
        pegaCod: pega o código anterior do dado requisitado
        espera como parametro o tipo (ex: produto, fornecedor, etc)
        retorna: EOPEN em caso de erro e o codigo no caso de sucesso
    */
    int pegaCod(char *tipo);

    /*
        op: Printa um menu, necessita como parametro as opçoes do menu
    */
    void menu(char *menu);
#endif