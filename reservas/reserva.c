#include "reserva.h"

int quartos(){

    while (1)
            {
            int qua=0,cat=0;

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

            }else if(cat!=1 && cat!=2 && cat!=3){
                continue;
            }
    }
};