#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "functions.h"
#include "vars.h"

 int main(void)//editar hotel
{ 
  
    inicializa();
    alteraDir();
    printf("%s", padrao.dirPadrao);
    cadastrar("cliente");

    getchar();
}