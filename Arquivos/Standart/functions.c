#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Dados\dados.h"

int login(char *tipo, char open)
{
  char usuario[user];
  char senha[user];
  char arquivo[100] = "Saves\\";
  
  strcat(arquivo, tipo);
  strcat(arquivo, ".txt");//concatena para ..\\Saves\\'nome'.txt

  printf("(Letras maiusculas e minusculas fazem a diferenca, maximo 8 digitos)\n\nInforme seu usuario de login: ");
  fgets(usuario, 10, stdin);
  printf("Informe sua senha: ");
  fgets(senha, 10, stdin);

  usuario[strlen(usuario) - 1] = '\0';//retira o \n
  senha[strlen(senha) - 1] = '\0';//retira o \n

  FILE *f;
  if((f = fopen(arquivo, "r")) == NULL){
    printf("Erro ao abrir o arquivo! (Confira se há alguém cadastrado)\n");
    return 0;
  }

  char aux[18];
  char *token = NULL;
  int nomes = 0;

  while(fgets(aux, 18, f))
  {//le linha por linha
    token = strtok(aux, ";");//pega o usuario

    if(strcmp(token,usuario) == 0)//checa se foi o digitado
    {
      if(open == 'a')//caso seja para cadastrar
      {
        fclose(f);
        printf("O usuario escolhido ja existe, tente outro!\n");
        return 0;
      }
      while(token != NULL)
      {//continua a checkagem
        token = strtok(NULL, ";");//pega a senha
        token[strlen(token)-2] = '\0';//retira-se os 2 últimos caracteres \r e o \n (colocado ao cadastrar-se)

        if(strcmp(token,senha) == 0)//caso seja a mesma senha
        {
          fclose(f);
          system("clear");
          printf("Logado com sucesso!\n");
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
        }else
        {
          printf("Senha incorreta, Tente novamente!\n");
          return 0;
        }
      }
    }
  }
    fclose(f);
    if(open == 'a')
    {
      f = fopen(arquivo, "a");
      fprintf(f, "%s;%s\r\n", usuario, senha);
      fclose(f);
      printf("Usuario cadastrado com sucesso!");
      return 4;      
    }
    printf("Usuario nao encontrado!\n\n");
    return 0;
}