#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

 int main(void)//editar hotel
{
  char op;
  printf("Bem vindo ao sistema de hotel!\nEscolha uma opcao do menu abaixo:\n"
  "\t1 - Sou funcionario\t2 - Sou Cliente\t3 - Sou Administrador");
  op = getchar();

  switch(op){
    case '1':
      printf("Informe seu usuario de login (Letras maiusculas e minusculas fazem a diferenca): ");

  }
  return 0;
}