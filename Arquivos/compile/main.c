#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "functions.h"
#include "vars.h"

 int main(void)//editar hotel
{ 
  
  inicializa();
  if(logar("cliente") == SUCCESS)
  {
      printf("Logado com sucesso!");
  }
  getchar();
}