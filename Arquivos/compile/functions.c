<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Dados\dados.h"

int login(char *tipo, char open)
{
  char usuario[user];
  char senha[user];
  char arquivo[100] = "Saves\\";
  
  strcat(arquivo, tipo);
  strcat(arquivo, ".txt");//concatena para ..\\Saves\\'nome'.txt

  printf("(Letras maiusculas e minusculas fazem a diferenca, maximo 8 digitos)\n\nInforme seu usuario de login: ");
  fgets(usuario, 10, stdin);
  printf("Informe sua senha: ");
  fgets(senha, 10, stdin);

  usuario[strlen(usuario) - 1] = '\0';//retira o \n
  senha[strlen(senha) - 1] = '\0';//retira o \n

  FILE *f;
  if((f = fopen(arquivo, "r")) == NULL){
    printf("Erro ao abrir o arquivo! (Confira se há alguém cadastrado)\n");
    return 0;
  }

  char aux[18];
  char *token = NULL;
  int nomes = 0;

  while(fgets(aux, 18, f))
  {//le linha por linha
    token = strtok(aux, ";");//pega o usuario

    if(strcmp(token,usuario) == 0)//checa se foi o digitado
    {
      if(open == 'a')//caso seja para cadastrar
      {
        fclose(f);
        printf("O usuario escolhido ja existe, tente outro!\n");
        return 0;
      }
      while(token != NULL)
      {//continua a checkagem
        token = strtok(NULL, ";");//pega a senha
        token[strlen(token)-2] = '\0';//retira-se os 2 últimos caracteres \r e o \n (colocado ao cadastrar-se)

        if(strcmp(token,senha) == 0)//caso seja a mesma senha
        {
          fclose(f);
          system("clear");
          printf("Logado com sucesso!\n");
          if( tipo == "cliente")
          {
            return 1;
          }else
          if( tipo == "funcionario")
          {
            return 2;
          }else
          {
            return 3;
          }
        }else
        {
          printf("Senha incorreta, Tente novamente!\n");
          return 0;
=======
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
  if( strcmp(tipo, "administrador") != 0)//se ele nao for adm
  {
    strcpy(caminho, caminhoLog(tipo));//concatena o caminho do save de login
  }else
  {
    strcpy(caminho, cfg);//concatena o caminho do save de login
    strcat(caminho, "administrador.bin");
  }

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
          strcpy(padrao.usuario, log.usuario);//copia o nome  do usuario logado
          padrao.logado = 1;
          return SUCCESS;
        }else
        {
          padrao.logado = 0;
          return FAILED;
>>>>>>> upstream/master
        }
      }
    }
  }
<<<<<<< HEAD
    fclose(f);
    if(open == 'a')
    {
      f = fopen(arquivo, "a");
      fprintf(f, "%s;%s\r\n", usuario, senha);
      fclose(f);
      printf("Usuario cadastrado com sucesso!");
      return 4;      
    }
    printf("Usuario nao encontrado!\n\n");
    return 0;
=======
  return UNEXIST;
}

tipoLogin infoLog()//CONCLUIDO
{
  tipoLogin login;
  do
  {
    printf("Digite seu nome de usuario (maximo 8 digitos/minimo 4 digitos): ");
    // fgets(login.usuario, user, stdin);
    scanf("%9[^\n]s", &login.usuario);
    cleanBuff();

    printf("\nDigite sua senha (maximo 8 digitos/minimo 4 digitos): ");
    // fgets(login.senha, user, stdin);
    scanf("%9[^\n]s", &login.senha);
    cleanBuff();
    printf("\n");
  } while (strlen(login.usuario) > 8 || strlen(login.senha) > 8 || strlen(login.usuario) < 4 || strlen(login.senha) < 4);

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
  cleanBuff();
  
  FILE *p;
  if((p = fopen("C:\\ProgramData\\hotelSystem\\configs\\dirPadrao.txt","w")) == NULL)
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
  if((p = fopen("C:\\ProgramData\\hotelSystem\\configs\\dirpadrao.txt", "r")) == NULL)
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

  mkdir("C:\\ProgramData\\hotelSystem\\configs\\", 0700);//cria o diretorio de configuração padrao
  mkdir(caminho, 0700);//cria o diretorio para os saves do cliente padrao

  p = fopen("C:\\ProgramData\\hotelSystem\\configs\\dirpadrao.txt", "w");
  if(p == NULL)
  {
    printf("Falha ao criar diretorios\n");
    getchar();
    exit(1);
  }
  fprintf(p, "%sSaves\\", raiz);
  fclose(p);

  p = fopen("C:\\ProgramData\\hotelSystem\\configs\\administrador.bin", "wb");
  if(p == NULL)
  {
    printf("Erro ao iniciar arquivo de administrador!\nEncerrando!");
    getchar();
    exit(1);
  }
  tipoLogin adm;
  strcpy(adm.usuario, "Admin123");
  strcpy(adm.senha, "Admin123");
  fwrite(&adm, sizeof(tipoLogin), 1, p);//salva o usuario de administrador padrao
  fclose(p);

  p = fopen("C:\\ProgramData\\hotelSystem\\configs\\hotel.bin", "rb");
  if(p == NULL)//caso nao existir esse arquivo
  {
    while(1){
      int errcode = hotel();
      if(errcode == SUCCESS)
      {
        printf("Informacoes alteradas com sucesso!\n");
        break;
      }else
      if( errcode == EOPEN)
      {
        printf("Erro ao salvar as configuracoes do hotel!\n");
        exit(1);
      }else
      {
        printf("Voce nao pode deixar de cadastrar o hotel na primeira vez que abre o programa!\n");
      }
    }
  }
  fclose(p);
  printf("\n\n\n");
  while(1)
  {
    int errcode = gerente();

    if( errcode == CANCELED)
    {
      printf("Voce nao pode cancelar a atualizacao do gerente na primeira abertura do programa!\n");
    }else
    if( errcode == SUCCESS )
    {
      printf("Gerente atualizado com sucesso!\n");
      break;
    }else
    {
      printf("Erro ao abrir arquivo de configuracao do gerente!\nSaindo...");
      getchar();
      exit(1);
    }
  }

  int op;
  printf("\n\nDeseja alterar o diretorio padrao de saves\n[1] - sim\t[2] - nao\n");
  printf("Diretorio padrao: %s\nOpcao: ", padrao.dirPadrao);
  scanf("%d", &op);

  if(op == 1)
  {
    if(alteraDir() == CANCELED)
    {
      printf("Operacao cancelada!\n");
    }
  }

  printf("E necessario adicionar ao menos um quarto na primeira inicializacao: ");
  int errcode = addQuarto();
  if( errcode == CANCELED || EOPEN)
  {
    printf("Ocorreu um erro... Tudo bem, voce pode adiciona-los manualmente depois");
  }else
  {
    printf("Quarto adicionado com sucesso!\n");
  }

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

    printf("Usuario: %s Senha: %s Codigo: %d\n", log.usuario, log.senha, log.codigo);
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
    return FAILED;
  }
  return SUCCESS;
}

int tamanhoArq(char* nome)//CONCLUIDO
{
    FILE *file = fopen(nome, "r");

    if(file == NULL)
        return EOPEN;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

int pegaCod(char *tipo)
{
  FILE *p;
  int cod = 0;

  tipoProdutos aux;
  

  if((p = fopen(caminhoLog(tipo), "rb")) == NULL)
  {
    return EOPEN;
  }

  if(tamanhoArq(caminhoLog(tipo)) == 0)//caso o arquivo esteja vazio
  {
    cod = 1;
    return cod;
  }

  if(strcmp(tipo, "produtos") == 0)
  {
    fseek(p, -sizeof(tipoProdutos), SEEK_END);//vai para a penultima posiçao
    fread(&aux, sizeof(tipoProdutos), 1, p);
    aux.codigo++;
    cod = aux.codigo;
  }

  fclose(p);
  return cod;
}

void menu(char *menu)
{
  printf("Escolha uma opcao: \n\n");
  printf("%s\n", menu);
  printf("Opcao: ");
>>>>>>> upstream/master
}