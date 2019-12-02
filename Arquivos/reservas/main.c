#include <stdio.h>
#include <stdlib.h>
#include "reserva.h"//biblioteca para reservar e excluir quartos



int main(void){

    int menu=50;

    while(1){
        printf("Digite a opção desejada\n\t1 - Reserva\n\t2 - Cancelamento de reserva\n\tDigite 0 para sair\n");
        scanf("%d",&menu);
        switch (menu)
        {
        
        case 0:
            exit(0);
        case 1:
            quartos();
        break;
        case 2:
            cancel();
        break;        
        default:
            break;
        }

    }


    return 0;
}

