#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vars.h"
    //      FUNÇÕES

    /*
        infoCad: pede para que o usuario digite suas informações, retorna uma struct do tipoLogin com os dados
        (sem \n no final)
    */
    tipoLogin infoCad();

    /*
        login: Pode ser utilizada para fazer login ou cadastrar um novo cliente.
        Espera como parametro o tipo de usuario (cliente, funcionario ou administrador) e o tipo de abertura
        (cadastro = c / login = l)
        Retorna a struct com o nome e senha do usuario logado ou cadastrado
    */
    int logar(char *tipo, char open);

    /*
        cadastro: utilizada para cadastrar um usuario, espera como parametro o tipo de cadastro
        (cliente, funcionario, administrador)
    */
    int cadastrar(char *tipo);

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

    /*
        checkInfo: Função que checa se as informações estão corretas
        retorna 1 caso estejam
    */
    int checkInfo(void);

    /*
        excluir: Apaga um usuario, espera como parametro o tipo (funcionario, cliente, admnistrador),
        o nome de usuario a ser excluido!
        Return: 1 caso de erro na abertura do arquivo, -1 caso o usuario cancele, 2 caso o usuario nao exista,
        0 caso ocorra com sucesso!
    */
    int excluirLog(char *tipo, char *usuario);//REFAZER

    /*
        alteraDir: altera o diretorio padrao de save de acordo com a escolha do usuario 
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

#endif