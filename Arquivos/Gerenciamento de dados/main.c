#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

int login(char *tipo);

 int main(void)//editar hotel
{
  char op;

  printf("Bem vindo ao sistema de hotel!\n");
  while(1){

    printf("\nEscolha uma opcao do menu abaixo:\n"
    "1 - Sou funcionario\t2 - Sou Cliente\t3 - Sou Administrador\t4 - Sair");
    op = getchar();
    cleanBuff();

    switch(op){
      case '1':
        login("funcionario");
        break;
      case '2':
        printf("(1)Fazer login ou (2)cadastrar? ");
        op = getchar();
        if(op == '1'){
          login("cliente");
        }else{
          // cadastro("cliente");
        }
        break;
      case '3':
        login("administrador");
        break;
      case '4':
        exit(0);
      default:
        printf("Opcao invalida, Tente novamente!\n\n");
    }
  }
  return 0;
}

int login(char *tipo){
  char usuario[user];
  char senha[user];
  char arquivo[100] = "..\\Saves\\";

  strcat(arquivo, tipo);
  strcat(arquivo, ".txt");

  printf("(Letras maiusculas e minusculas fazem a diferenca)\n\nInforme seu usuario de login: ");
  scanf("%9s", &usuario);
  cleanBuff();//limpa o buffer
  printf("Informe sua senha: ");
  scanf("%9s", &senha);
  cleanBuff();//limpa o buffer

  FILE *f;
  if((f = fopen(arquivo, "r")) == NULL){
    printf("Erro ao abrir o arquivo!\n");
    return 0;
  }
  char aux[18];
  char *token;

  while(fgets(aux, 18, f))
  {//le linha por linha
    token = strtok(aux, ";");//pega o usuario
    if(strcmp(token, usuario))//checa se foi o digitado
      continue;//pula a linha caso nao for
    while(token != NULL)
    {//continua a checkagem
      token = strtok(NULL, ";");//pega a senha
      if(!strcmp(token, senha))
      {//caso diferente
        printf("Senha incorreta!");
        return 0;
      }else
      {
        free(token);
        fclose(f);
        if( tipo == "cliente")
        {
          return 1;
        }else
        if( tipo == "funcionario")
        {
          return 2;
        }else
        {
          return 3;
        }
      }
    }
  }
    printf("Usuario nao encontrado!\n\n");
    return 0;
}