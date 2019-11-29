#include "functions.h" //funcoes padrao
#include "vars.h"      //variaveis padrao
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  //toupper
#include <string.h> //tratamento de strings

#include <sys/stat.h>//diretorios

int logar(char *tipo, char open)//testar o código
{

//   tipoLogin login, aux;
//   char *arquivo = malloc(100);
//   strcat(arquivo ,"Saves\\");
//   strcat(arquivo , tipo);
//   strcat(arquivo ,".bin");

//   do
//   {
//     printf("Digite seu nome de usuario (maximo 8 digitos): ");
//     // fgets(login.usuario, user, stdin);
//     scanf("%9[^\n]s", &login.usuario);
//     cleanBuff();

//     printf("\nDigite sua senha (maximo 8 digitos): ");
//     // fgets(login.senha, user, stdin);
//     scanf("%9[^\n]s", &login.senha);
//     cleanBuff();
//   } while (strlen(login.usuario) > 8 || strlen(login.senha) > 8);

//   login.usuario[strlen(login.usuario)] = '\0';//adicionando \0 no ultimo caractere

//   FILE *p;
//   if ((p = fopen(arquivo, "ab+")) == NULL)
//   {
//     printf("Falha ao abrir o arquivo!\n");
//     return 0;
//   }
//   free(arquivo);         //libera o caminho do arquivo
//   fseek(p, 0, SEEK_SET); //começa a leitura no inicio do arquivo

//   while (!feof(p)) //enquanto nao chegar ao fim do arquivo
//   {
//     fread(&aux, sizeof(tipoLogin), 1, p);
//     aux.usuario[strlen(aux.usuario)] = '\0'; //adiciona \0 no final da

//     if ((strcmp(login.usuario, aux.usuario)) == 0)
//     {
//       fclose(p);       //fecha o arquivo
//       if (open == 'c') //cadastro
//       {
//         printf("Esse usuario ja existe, tente outro!\n");
//         return 0;
//       }
//       if ((strcmp(login.senha, aux.senha)) == 0)
//       {
//         system("clear");
//         printf("Logado com sucesso!\n");
//         if (tipo == "funcionario")
//         {
//           return 2;
//         }
//         else if (tipo == "administrador")
//         {
//           return 3;
//         }
//         else
//         {
//           return 1;
//         }
//       }
//       else
//       {
//         printf("Senha incorreta, Tente novamente!\n");
//         return 0;
//       }
//     }
//   }
//   if (open == 'c') //cadastro
//   {
//     int codigo;
//     fseek(p, -sizeof(tipoLogin), SEEK_END); //retorna para uma posição antes do fim do arquivo
//     fwrite(&codigo, sizeof(int), 1, p);//salva o ultimo codigo em código
//     login.codigo = codigo;//salva o código do proximo usuario
//     fseek(p, 0, SEEK_END);//vai para o fim do arquivo

//     fwrite(&login, sizeof(tipoLogin), 1, p);
//     fclose(p);

//     printf("Usuario cadastrado com sucesso!\nUsuario: %s Senha: %s\n", login.usuario, login.senha);
//     return 0;
//   }
//   printf("Usuario nao encontrado!\n\n");
//   return 0;

  
}
tipoLogin infoCad()//concluido
{
  tipoLogin login;
  do
  {
    printf("Digite seu nome de usuario (maximo 8 digitos): ");
    // fgets(login.usuario, user, stdin);
    scanf("%9[^\n]s", &login.usuario);
    cleanBuff();

    printf("\nDigite sua senha (maximo 8 digitos): ");
    // fgets(login.senha, user, stdin);
    scanf("%9[^\n]s", &login.senha);
    cleanBuff();
  } while (strlen(login.usuario) > 8 || strlen(login.senha) > 8);

  return login;
}

int alteraDir()//concluido
{
  char dir[255];
  printf("Alterando diretorio padrao: %s\n", dirPadrao);
  if(!checkInfo())
  {
    printf("Operacao cancelada!\n");
    return 0;
  }

  printf("Informe o caminho do diretorio que sera padrao: ");
  fgets(dir, 255, stdin);

  FILE *p;
  if((p = fopen("C:\\ProgramData\\hotelSystem\\dirPadrao.txt","w")) == NULL)
  {
    printf("Erro ao salvar diretorio padrao!\n");
    return -1;
  }

  if(dir[strlen(dir)] != '\\')//adiciona a \ no ultimo caractere
  {
    dir[strlen(dir)] = '\\';
  }

  fprintf(p, "%s", dir);
  fclose(p);
}
void pegaDir()//CONCLUIDO
{
  FILE *p;
  if((p = fopen("C:\\ProgramData\\hotelSystem\\dirpadrao.txt", "r")) == NULL)
  {
    printf("Falha ao obter o diretorio padrao!\n");
    exit(1);
  }

  char aux[255];
  fgets(aux, 255, p);
  strcpy(dirPadrao, aux);//salva o conteudo de p em dirPadrao
  fclose(p);//fecha o p
}

void inicializa()//CONCLUIDO
{ 
                              //cria o diretorio raiz hotelSystem
  if(mkdir(raiz, 0700) == -1)//caso o diretorio padrao já exista
  {
    pegaDir();
    return;
  }

  FILE *p;
  char caminho[255];
  strcpy(caminho, raiz);
  strcat(caminho, "Saves\\");

  mkdir(caminho, 0700);//cria o diretorio para os saves do cliente padrao

  if((p = fopen("C:\\ProgramData\\hotelSystem\\dirpadrao.txt", "w")) == NULL)
  {
    printf("Falha ao criar diretorios\n");
    exit(1);
  }
  fprintf(p, "%sSaves\\", raiz);
  fclose(p);

  pegaDir();//pega o diretorio e salva na variavel padrao
}

int cadastrar(char *tipo)
{
  tipoLogin log = infoCad(), aux;
  int contador = 0;

  char *caminho = malloc(sizeof(dirPadrao) + sizeof(tipo) + sizeof(".bin"));
  strcpy(caminho, dirPadrao);
  strcat(caminho, tipo);
  strcat(caminho, ".bin");

  FILE *p;
  if((p = fopen(caminho, "ab+")) == NULL)
  {
    printf("Erro ao criar arquivo de cadastro!\n");
    printf("Verifique se o caminho para salvar os dados esta correto!\n");
    return 1;
  }

  fseek(p, 0, SEEK_SET);//comeca a leitura no inicio do arquivo
   while (!feof(p)) //enquanto nao chegar ao fim do arquivo
  {
    if(!feof(p))
    {
      fread(&aux, sizeof(tipoLogin), 1, p);
      if ((strcmp(aux.usuario, log.usuario)) == 0)
      {
        printf("Esse usuario ja existe, tente outro!\n");
        return 2;
      }
      contador++;
    }
  }

    int codigo = 0;

    if(contador = 0)
    {
      codigo = 1;
    }else
    {
      fseek(p, -sizeof(tipoLogin), SEEK_END); //retorna para uma posição antes do fim do arquivo
      fread(&codigo, sizeof(int), 1, p);//salva o ultimo codigo em código
      codigo++;
    }
    
    log.codigo = codigo;//salva o código do proximo usuario
    fseek(p, 0, SEEK_END);//vai para o fim do arquivo

    fwrite(&log, sizeof(tipoLogin), 1, p);
    fclose(p);

    printf("Usuario cadastrado com sucesso!\nUsuario: %s Senha: %s Codigo: %d\n", log.usuario, log.senha, log.codigo);
    return 0;
}

int excluirLog(char *tipo, char *usuario)
{
  FILE *f;
  int tamanho = 0, existe = 0;
  char *caminho = malloc(sizeof(tipo) + sizeof(".bin"));

  strcat(caminho, "..\\Saves\\");
  strcat(caminho, tipo);
  strcat(caminho, ".bin");
  caminho[strlen(caminho)] = '\0';

  printf("%s", caminho);
  getchar();

  int cont = 0;
  tipoLogin *final = malloc(sizeof(tipoLogin));//aloca um espaco na memoria para o final
  tipoLogin *p = malloc(sizeof(tipoLogin));//aloca um espaco na memoria para o auxiliar p
  tipoLogin aux;

  f = fopen(caminho, "rb");//abrindo o arquivo
  if(f == NULL)//verifica se nao houve erro
  {  
    printf("Erro ao abrir o arquivo!");
    return 1;
  }

  // while(!feof(f))//copia todos os dados do arquivo para a struct (menos o que se deseja apagar)
  // {
  //   if(!feof(f))
  //   {
  //     fread(&aux, sizeof(tipoLogin), 1, f);//lê do arquivo
  //     if(strcmp(aux.usuario, usuario) == 0)
  //     {
  //       printf("Usuario encontrado!\nNome: %s\tCodigo: %d", aux.usuario, aux.codigo);
  //       if(!checkInfo())
  //       {
  //         printf("Operacao cancelada!");
  //         return -1;
  //       }
  //       existe = 1;
  //     }
  //     if(strcmp(aux.usuario, usuario) != 0)//caso o usuario inserido nao seja igual ao usuario no arquivo
  //     {
  //       //caso seja diferente copia para o vetor novo de struct e no fim passa para o arquivo
  //       p = realloc(final, sizeof(tipoLogin)*(cont+1));//realoca o espaço em memoria de final, aumentando seu tamanho
  //       final[cont] = aux;
  //       cont++;
  //     }
  //   }
  //   fclose(f);//fecha o f
  //   if(existe == 1)
  //   {
  //     printf("O usuario não foi encontrado!\n");
  //     return 2;
  //   }
  // }

  //   f = fopen("..\\Saves\\aux.bin", "wb");//cria um arquivo auxiliar de segurança
  //   if(f == NULL)
  //   {
  //     printf("Erro ao abrir o arquivo!");
  //     return 1;
  //   }
  //   fwrite(&final, sizeof(tipoLogin), cont+1, f);//salva o conteudo de tipoLlogin x vezes no arquivo
  //   fclose(f);

  //   caminho = realloc(caminho, sizeof("erase ..\\Saves\\")+sizeof(tipo)+sizeof(".bin"));
  //   caminho = concat("erase ..\\Saves\\", tipo, ".bin");
  //   system(caminho);
  //   caminho = realloc(caminho, sizeof("rename ..\\Saves\\aux.bin ..\\Saves\\")+sizeof(tipo)+sizeof(".bin"));
  //   caminho = concat("rename ..\\Saves\\aux.bin ..\\Saves\\", tipo, ".bin");
  //   system(caminho);
  //   return 0;
}

int checkInfo(void) //CONCLUIDA
{
  char op;
  do
  {
    printf("Deseja continuar? (s - sim / n - nao): ");
    scanf("%c%*c", &op);

    if ('S' == toupper(op))
    {
      return 1;
    }
    else if ('N' == toupper(op))
    {
      return 0;
    }
    printf("Opcao invalida, tente novamente!\n");
  } while (toupper(op) != 'N' && toupper(op) != 'S');
}

void cleanBuff(void) //limpa o buffer (CONCLUIDO)
{
  int ch = 0;
  while ((ch = getchar()) != '\n' && ch != EOF)
  {
  }
}

int checkHorario(int horario, char tipo) //concluida
{
  int r;
  switch (tipo)
  {
  case 'h': //hora
    if (horario > 24 || horario < 0)
      r = 1;
    break;
  case 'm': //minuto
    if (horario > 60 || horario < 0)
      r = 1;
    break;
  }
  if (r == 1)
  {
    printf("\nHorario invalido, tente novamente!\n");
    return 1;
  }
  return 0;
}