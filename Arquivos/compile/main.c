#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

 int main(void)//editar hotel
{
  int op;

  printf("Bem vindo ao sistema de hotel!\n");
  while(1){

    printf("\nEscolha uma opcao do menu abaixo:\n"
    "1 - Sou funcionario\t2 - Sou Cliente\t3 - Sou Administrador\t4 - Sair\n");
    scanf("%d", &op);
    cleanBuff();

    switch(op){
      case 1:
        login("funcionario", 'r');
        break;
      case 2:
        printf("(1)Fazer login ou (2)cadastrar:  ");
        scanf("%d%*c", &op);
        if(op == 1){
          login("cliente", 'r');
        }else{
          login("cliente", 'a');
        }
        break;
      case 3:
        login("administrador", 'r');
        break;
      case 4:
        exit(0);
      default:
        printf("Opcao invalida, Tente novamente!\n\n");
    }
  }
  return 0;
}