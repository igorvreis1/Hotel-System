#include "functions.h" //funcoes padrao
#include "vars.h"      //variaveis padrao
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  //toupper
#include <string.h> //tratamento de strings

#include "dados.h"

#include <sys/stat.h>//diretorios

char *caminhoLog(char *tipo)//CONCLUIDO
{
  char *caminho = malloc(sizeof(padrao.dirPadrao) + sizeof(tipo) + sizeof(".bin"));
  strcpy(caminho, padrao.dirPadrao);
  strcat(caminho, tipo);
  strcat(caminho, ".bin");
  free(caminho);
  return caminho;
}

int logar(char *tipo)//CONCLUIDO
{
  tipoLogin log = infoLog(), aux;

  char caminho[255];
  strcpy(caminho, caminhoLog(tipo));//concatena o caminho do save de login

  FILE *p;
  if ((p = fopen(caminho, "rb")) == NULL)
  {
    printf("Falha ao abrir o arquivo!\n");
    return EOPEN;
  }

  while(!feof(p))
  {
    if(!feof(p))
    {
      fread(&aux, sizeof(tipoLogin), 1, p);//pega os dados e salva em aux
      if(strcmp(aux.usuario, log.usuario) == 0)//caso o usuario digitado e o login pegado no arquivo sejam iguais
      {
        //passa para o check da senha
        if(strcmp(aux.senha, log.senha) == 0)//caso a senha digitada esteja correta
        {
          return SUCCESS;
        }else
        {
          return FAILED;
        }
      }
    }
  }
  return UNEXIST;
}

tipoLogin infoLog()//CONCLUIDO
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

int alteraDir()//CONCLUIDO
{
  char dir[255];
  printf("Alterando diretorio padrao: %s\n", padrao.dirPadrao);
  if(checkInfo() == CANCELED)
  {
    printf("Operacao cancelada!\n");
    return CANCELED;
  }

  printf("Informe o caminho do diretorio que sera padrao \n(coloque uma \\ no final): ");
  scanf("%255[^\n]s", &dir);

  FILE *p;
  if((p = fopen("C:\\ProgramData\\hotelSystem\\dirPadrao.txt","w")) == NULL)
  {
    printf("Erro ao salvar diretorio padrao!\n");
    return EOPEN;
  }

  fprintf(p, "%s", dir);
  fclose(p);
  pegaDir();//coloca na variavel o novo diretorio padrao
  return SUCCESS;
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
  strcpy(padrao.dirPadrao, aux);//salva o conteudo de p em dirPadrao
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

int cadastrar(char *tipo)//CONCLUIDO
{
  tipoLogin log = infoLog(), aux;
  int contador = 0;

  char caminho[255];
  strcpy(caminho, caminhoLog(tipo));

  FILE *p;
  if((p = fopen(caminho, "ab+")) == NULL)
  {
    printf("Erro ao criar arquivo de cadastro!\n");
    printf("Verifique se o caminho para salvar os dados esta correto!\n");
    return EOPEN;
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
        return AEXIST;
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
    return SUCCESS;
}

int excluirLog(char *tipo, char *usuario)//REFAZER
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

int checkInfo(void) //CONCLUIDO
{
  char op;
  do
  {
    printf("Deseja continuar? (s - sim / n - nao): ");
    scanf("%c%*c", &op);

    if ('S' == toupper(op))
    {
      return SUCCESS;
    }
    else if ('N' == toupper(op))
    {
      return CANCELED;
    }
    printf("Opcao invalida, tente novamente!\n");
  } while (toupper(op) != 'N' && toupper(op) != 'S');
}

void cleanBuff(void) //CONCLUIDO
{
  int ch = 0;
  while ((ch = getchar()) != '\n' && ch != EOF)
  {
  }
}

int checkHorario(int horario, char tipo) //CONCLUIDO
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
    return SUCCESS;
  }
  return FAILED;
}

int tamanhoArq(char* nome)//CONCLUIDO
{
    FILE *file = fopen(nome, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

int pegaCod(int tipo)
{
  FILE *p;
  char caminho[255];
  int cod = 0;

  tipoProdutos aux;
  

  if(tipo == 0)//caso o tipo seja do tipo produto
  {
    strcpy(caminho, caminhoLog("produtos"));
  }

  if((p = fopen(caminho, "rb")) == NULL)
  {
    return EOPEN;
  }

  if(tamanhoArq(caminho) == 0)//caso o arquivo esteja vazio
  {
    cod = 1;
    return cod;
  }

  if(tipo == 0)
  {
    fseek(p, -sizeof(tipoProdutos), SEEK_END);//vai para a penultima posiçao
    fread(&aux, sizeof(tipoProdutos), 1, p);
    aux.codigo++;
    cod = aux.codigo;
  }

  fclose(p);
  return cod;
}