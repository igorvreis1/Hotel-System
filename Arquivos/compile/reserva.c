#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// #include "reserva.h"
//#include "../Dados/dados.h"

    typedef struct //struct para data de reserva
    {
        int dia;
        int mes;
        int ano;
    }tipoData;

    typedef struct //struct para hora da reserva
    {
        int hora;
        int minuto;
    }tipoHora;

    typedef struct //struct para data de saida do cliente
    {
        int dia;
        int mes;
        int ano;
    }tipoDataOut;

int verData(tipoData data, tipoHora hora, tipoDataOut dataOut, int diaAtual,int mesAtual ,int anoAtual,int horaAtual,int minAtual);


int quartos(){
    struct tm *data_hora_atual;     
                
            time_t segundos;//variável do tipo time_t para armazenar o tempo em segundos            
          
            time(&segundos);//obtendo o tempo em segundos   
            
              
            data_hora_atual = localtime(&segundos);//para converter de segundos para o tempo local  
                                                  //utilizamos a função localtime  
            
            //para acessar os membros de uma struct usando o ponteiro
            //utilizamos o operador -> no nosso caso temos: 
            //data_hora_atual->membro_da_struct
            
            //Acessando dados convertidos para a struct data_hora_atual e emplementando em uma variavel 
            int diaAtual = data_hora_atual->tm_mday;
            int mesAtual = data_hora_atual->tm_mon+1;
            int anoAtual = data_hora_atual->tm_year+1900; 
            
            //para retornar o mês corretamente devemos adicionar +1 
            //como vemos abaixo
            //printf("\nMes..........: %d\n", data_hora_atual->tm_mon+1);
            
            //para retornar o ano corretamente devemos adicionar 1900 
            //como vemos abaixo
            // printf("\nAno..........: %d\n\n", data_hora_atual->tm_year+1900);  
            
            // printf("\nDia do ano...: %d\n", data_hora_atual->tm_yday);
            int horaAtual = data_hora_atual->tm_hour;
            int minAtual = data_hora_atual->tm_min;
            
            int qua=0;//quarto
            int cat=0;//categoria

            tipoData data;//data de check-in
            tipoHora hora;//hora de check-in
            tipoDataOut dataOut;//data de check-out

            //if para selecionar a categoria do hotel (1,2 ou 3),declaração de um ponto de inicio, caso ocorro algum erro
            inicio: printf("Escolha a classe do seu quarto:\n\t1 - Luxo\n\t2 - Normal\n\t3 - Simples\n");
            scanf("%d",&cat);
            
            //para não deixar o usúario colocar um valor diferante de 1,2 ou 3
            if(cat < 1 || cat > 4)
            {
                printf("Valor invalido!\n");
                goto inicio;//para voltar ao inicio
            }

            
            printf("\nEscolha o tamanho do quarto:\n\t1 - Quarto para uma pessoa\n\t2 - Quarto de casal\n\t3 - Quarto tamanho familía(4 pessoas)\n");
            scanf("%d",&qua);

            //if para filtrar as opções pela categoria do quarto
            if(cat == 1)
            {
                
                switch (qua)
                {
                    case 1: printf("PLAYER SOLO! Quarto para uma pessoa de Luxo!");break;
                    case 2: printf("Quarto para um pessoa, categoria normal.");break;
                    case 3: printf("Quarto para uma pessoa, categoria simples.");break;
                    default: printf("Valor invalido!\n"); goto inicio;
                }

            }else
            if(cat == 2)
            {
                switch (qua)
                {
                    case 1: printf("Duo do AMOR! Quarto de casal,categoria Luxo!");break;
                    case 2: printf("Quarto para um casal, categoria normal.");break;
                    case 3: printf("Quarto para um casal, categoria simples.");break;
                    default: printf("Valor invalido!\n"); goto inicio;
                }  
            }else
            if(cat == 3)
            {
                switch(qua)
                {
                    case 1: printf("Quarto tamanho familía, categoria Luxo!");break;
                    case 2: printf("Quarto para uma familía, categoria normal.");break;
                    case 3: printf("Quarto para uma familía, categoria simples.");break;
                    default: printf("Valor invalido!\n"); goto inicio;
                }
            }else


                setbuf(stdin, NULL);//limpar o buffer

            do
            {
                
                printf("\nDigite a data que deseja realizar seu check-in:(20/10/1971)\n");
                scanf("%d/%d/%d",&data.dia,&data.mes,&data.ano);
                
                printf("\nDigite a hora que deseja realizar seu check-in:(04:20)\n");
                scanf("%d:%d",&hora.hora,&hora.minuto);
                printf("\nDigite a data que deseja realizar seu check-Out:(06/02/1945)\n");
                scanf("%d/%d/%d",&dataOut.dia,&dataOut.mes,&dataOut.ano);

                //chamando a rotina que verifica se o usuario não colocou data invalida
                if(verData(data,hora,dataOut,diaAtual,mesAtual,anoAtual,horaAtual,minAtual))
                {
                    printf("\nData invalida!\n\n");
                    continue;
                }
                break;
            }while(1);
                
            
            FILE *file; //ponteiro para arquivo
            file = fopen("..\\Saves\\reserva.bin","ab+");

            //implementando os dados no arquivo bin
            fwrite(&cat, sizeof(cat), 1, file);
            fwrite(&qua, sizeof(qua), 1, file);
            fwrite(&data, sizeof(data), 1, file);
            fwrite(&hora, sizeof(hora), 1, file);
            fwrite(&dataOut, sizeof(dataOut), 1, file);
            fclose(file);
            printf("Reserva realizada com sucesso!");

            return 0;
    
};

int cancel(){
        
};

/*
        função para verificar a validade dos dados digitados pelo usuario,caso ele coloque datas do passado ou coloque
        datas que não existem como 30 de fevereiro, ou check-in menor que check-out
*/
int verData(tipoData data, tipoHora hora, tipoDataOut dataOut, int diaAtual,int mesAtual ,int anoAtual,int horaAtual,int minAtual){
   
    if(data.dia > 31 || data.dia < 1 || data.ano < anoAtual || data.mes < 1 || data.mes > 12 || hora.hora < 0 || hora.hora > 23|| hora.minuto < 0 || hora.minuto > 60 )
    {
        return 1;
    }else
    {
        if(data.mes < mesAtual)
        {
            return 1;
           
        }else  if(data.dia < diaAtual)
                {

                    return 1;
                            
                }else if(hora.hora < horaAtual)
                        {
                            return 1;
                
                        }else if(hora.minuto < minAtual)
                            {
                                return 1;
                            }



        if(data.mes == 2)
        {
            if(data.dia > 28)
                return 1;
        }
        if( data.mes >= 8)
        {
            if(data.mes % 2 != 0)
            {
                if(data.dia > 30)
                    return 1;
            }
        }else
        {
            if(data.mes % 2 == 0)
            {
                if(data.dia > 30)
                    return 1;
            }
        }
    }
    return 0;
}    