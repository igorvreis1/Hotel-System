#include "dados.h"
#include <stdio.h>

//funções
void hotel(void)
{
    char op;
    tipoHotel hotel;

    while(1)
    {
        inicio: printf("Informe o nome do Hotel: ");
        scanf("%s%*c", &hotel.nome);

        printf("Informe a razao social do hotel: ");
        scanf("%s%*c", &hotel.razao);

        do{
            printf("Informe a inscricao estadual do hotel (apenas numeros): ");
            scanf("%13s%*c", &hotel.insc);
        }while(strlen(hotel.insc) != 13);

        do
        {
            printf("Informe o cnpj do hotel (apenas numeros): ");
            scanf("%14s%*c", &hotel.endereco);
        } while(strlen(hotel.cnpj) != 14);
        

        do
        {
            printf("Informe o telefone do hotel (ddd-nnnnnnnnn): ");
            scanf("%12s%*c", &hotel.telefone);
        } while(strlen(hotel.telefone) != nums);
        

        printf("Informe o email do hotel: ");
        scanf("%s%*c", &hotel.email);

        printf("Informe o nome do gerente do hotel: ");
        scanf("%s%*c", &hotel.gerente);

        do{
            printf("Informe o telefone do gerente do hotel (ddd-nnnnnnnnn): ");
            scanf("%12s%*c", &hotel.telGer);
        }while(strlen(hotel.gerente) != nums);
        


        printf("Informe o horario de checkin do hotel (hh:mm): ");
        scanf("%d:%d", &hotel.checkin[0], &hotel.checkin[1]);

        printf("Informe o horario de checkout do hotel (hh:mm): ");
        scanf("%d:%d", &hotel.checkout[0], &hotel.checkout[1]);

        do{
            printf("As informacoes estao corretas? (s - sim / n - nao): ");
            op = getchar();

            if('S' == toupper(op))
            {
                //salva no arquivo
                return;//sai da funcao
            }else
            if('N' == toupper(op))
                break;//volta para o topo

            printf("Opcao invalida, tente novamente!\n");
        }while(toupper(op) != 'N' && toupper(op) != 'S')
    }
}