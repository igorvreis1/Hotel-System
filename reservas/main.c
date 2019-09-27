#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "reserva.h"



int main(void){
        while (1)
            {
            int qua=0,cat=0;
            int data[3];
            int hora[2];
            
            printf("Escolha a classe do seu quarto:\n\t1 - Luxo\n\t2 - Normal\n\t3 - Simples\n");
            scanf("%d",&cat);

            if(cat==1 || cat==2 || cat==3){
                if(cat==1){
                    printf("Classe de Luxo selecionada!");
                }else if (cat==2){
                    printf("Classe de Normal selecionada!");
                }else if (cat==3){
                    printf("Classe de Simples selecionada!");
                }
                printf("\nEscolha o tamanho do quarto:\n\t1 - Quarto para uma pessoa\n\t2 - Quarto de casal\n\t3 - Quarto tamanho familía(4 pessoas)\n");
                scanf("%d",&qua);
                    if (qua==1 && cat==1){
                        printf("PLAYER SOLO! Quarto para uma pessoa de Luxo!");
                        return 0;
                    }else if (qua==1 && cat==2){
                        printf("Quarto para um pessoa, categoria normal.");
                        return 0;
                    }else if (qua==1 && cat==3){
                        printf("Quarto para uma pessoa, categoria simples.");
                        return 0;
                    }else if (qua==2 && cat==1){
                        printf("Duo do AMOR! Quarto de casal,categoria Luxo!");
                        return 0;
                    }else if (qua==2 && cat==2){
                        printf("Quarto para um casal, categoria normal.");
                        return 0;
                    }else if (qua==2 && cat==3){
                        printf("Quarto para um casal, categoria simples.");
                        return 0;
                    }else if (qua==3 && cat==1){
                        printf("Quarto tamanho familía,categoria Luxo!");
                        return 0;
                    }else if (qua==3 && cat==2){
                        printf("Quarto para uma familía, categoria normal.");
                        return 0;
                    }else if (qua==3 && cat==3){
                        printf("Quarto para uma familía, categoria simples.");
                        return 0;
                    }
                    while(1){
                        printf("Digite a data que deseja realizar seu check-in:(20/10/1971)\n");
                        scanf("%d/%d/%d",&data[0],&data[1],&data[2]);
                        printf("Digite a hora que deseja realizar seu check-in:(04:20)");
                        scanf("%d:%d",hora[0],hora[1]);
                        verifData(data,hora);
                        // if (data[1]== 1 || data[1] == 3 || data[1]== 5 || 7|| 8 || 10 || 12 ){
                            
                        // }
                        
                    }    

            }else if(cat!=1 && cat!=2 && cat!=3){
                continue;
            }
    }

    // int menu=50;

    // while(1){
    //     printf("Digite a opção desejada\n\t1 - Reserva\n\t2 - Cancelamento de reserva\n\tDigite 0 para sair\n");
    //     scanf("%d",&menu);
    //     switch (menu)
    //     {
        
    //     case 0:
    //         exit;    
    //     case 1:
    //         quartos();
    //     break;
    //     case 2:


    //     break;        
    //     default:
    //         break;
    //     }

    // }


    return 0;
}

int verifData(int *data, int *hora){
    int i;

    for
}

