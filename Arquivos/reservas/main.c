#include <stdio.h>
#include <stdlib.h>
//nãe é necessario no main
#include <time.h>
// #include "reserva.h"




    typedef struct
    {
        int dia;
        int mes;
        int ano;
    }tipoData;

    typedef struct
    {
        int hora;
        int minuto;
    }tipoHora;

    typedef struct
    {
        int dia;
        int mes;
        int ano;
    }tipoDataOut;

int verData(tipoData data, tipoHora hora, tipoDataOut dataOut);

int main(void){
            struct tm *data_hora_atual;     
                
            time_t segundos;//variável do tipo time_t para armazenar o tempo em segundos            
          
            time(&segundos);//obtendo o tempo em segundos   
            
              
            data_hora_atual = localtime(&segundos);//para converter de segundos para o tempo local  
                                                  //utilizamos a função localtime  
            
            //para acessar os membros de uma struct usando o ponteiro
            //utilizamos o operador -> no nosso caso temos: 
            //data_hora_atual->membro_da_struct
            
            //Acessando dados convertidos para a struct data_hora_atual  
            printf("\nData Atual: %d/%d/%d\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900);  
            
            //para retornar o mês corretamente devemos adicionar +1 
            //como vemos abaixo
            //printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);
            
            //para retornar o ano corretamente devemos adicionar 1900 
            //como vemos abaixo
            // printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);  
            
            // printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday); 

            printf("\nHora Atual: %d:%d:%d\n",data_hora_atual->tm_hour,data_hora_atual->tm_min,data_hora_atual->tm_sec);//hora,min,seg 
            
                
        while (1)
            {
            int qua=0,cat=0;

            tipoData data;
            tipoHora hora;
            tipoDataOut dataOut;
            
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
                        
                    }else if (qua==1 && cat==2){
                        printf("Quarto para um pessoa, categoria normal.");
                        
                    }else if (qua==1 && cat==3){
                        printf("Quarto para uma pessoa, categoria simples.");
                        
                    }else if (qua==2 && cat==1){
                        printf("Duo do AMOR! Quarto de casal,categoria Luxo!");
                        
                    }else if (qua==2 && cat==2){
                        printf("Quarto para um casal, categoria normal.");
                        
                    }else if (qua==2 && cat==3){
                        printf("Quarto para um casal, categoria simples.");
                        
                    }else if (qua==3 && cat==1){
                        printf("Quarto tamanho familía,categoria Luxo!");
                        
                    }else if (qua==3 && cat==2){
                        printf("Quarto para uma familía, categoria normal.");
                        
                    }else if (qua==3 && cat==3){
                        printf("Quarto para uma familía, categoria simples.");
                        
                    }
                    do{
                        printf("\nDigite a data que deseja realizar seu check-in:(20/10/1971)\n");
                        scanf("%d/%d/%d",&data.dia,&data.mes,&data.ano);
                        printf("\nDigite a hora que deseja realizar seu check-in:(04:20)\n");
                        scanf("%d:%d",&hora.hora,&hora.minuto);
                        printf("\nDigite a data que deseja realizar seu check-Out:(06/02/1945)\n");
                        scanf("%d/%d/%d",&dataOut.dia,&dataOut.mes,&dataOut.ano);
                    }while(verData(data,hora,dataOut));    

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

int verData(tipoData data, tipoHora hora, tipoDataOut dataOut){
   

    int i=8;
    if(data.mes==2 && data.dia<1 && data.dia>28){
        i=1;
    }else if (data.mes!=2 && data.mes<8 && data.mes%2==0 && data.dia<1 && data.dia>30){
        i=1;
    }else if (data.mes<8 && data.mes%2==1 && data.dia<1 && data.dia>31){
        i=1;
    }else if (data.mes>8 && data.mes%2==1 && data.dia<1 && data.dia>30){
        i=1;
    }else if(data.mes>8 && data.mes%2==0 && data.dia<1 && data.dia>31){
        i=1;
    }else i=0;

    return i;
}
    