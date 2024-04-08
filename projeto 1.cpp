#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espaco em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
   //in�cio cria��o de vari�veis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final da cria��o de vari�veis/string
  
  printf("Digite o CPF a ser cadastrado:   "); //coletando inform��o do usu�rio
  scanf("%s", cpf); //%s refere-se a string (armazenando)
  
  strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
  
  FILE *file; //cria o arquivo
  file = fopen(arquivo, "w"); //cria o arquivo (w=write,escrever, criar uma nova)
  fprintf(file,"CPF: ");
  fprintf(file,cpf); //salvo o valor da vari�vel
  fclose(file); // fecha o arquivo
  
  file = fopen(arquivo, "a"); // (a= atualizar informa��o)
  fprintf(file,"\nNOME: ");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado:  ");
  scanf("%s",nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose(file);
  
  file = fopen(arquivo, "a"); // (a= atualizar informa��o)
  fprintf(file,"\nSOBRENOME: ");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado:  ");
  scanf("%s", sobrenome);
  
  file = fopen(arquivo,"a");
  fprintf(file,sobrenome);
  fclose(file);
  
  file = fopen(arquivo, "a"); // (a= atualizar informa��o)
  fprintf(file,"\nCARGO: ");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado:   ");
  scanf("%s",cargo);
  
  file = fopen(arquivo,"a");
  fprintf(file,cargo);
  fprintf(file,"\n\n");
  fclose(file);
  
  system("pause");
  
}

int consulta()
{
  setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
  
  char cpf[40]; //vari�vel onde vamos armazenar a resposta do usu�rio para qual ele quer consultar
  char conteudo[200]; //vari�vel onde vamos armazenar o conte�do que esta dentro dese arquivo cpf
  
  printf("Digite o cpf a ser consultado:  ");
  scanf("%s", cpf);
  
  FILE *file; // abre o arquivo
  file = fopen(cpf, "r"); // "r" = read, consulta o arquivo
  
  if(file == NULL) 
  {
  	printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
  }
   
   printf("\nEssas s�o as informa��es do usu�rio: \n\n");
   
  while(fgets(conteudo,200, file) != NULL) // enquanto tiver conte�do dentro desse arquivo
  {
  	printf("%s", conteudo);
  }
  
  system("pause");
}

int deletar()
{
  char cpf[40];
  
  printf("Digite o CPF do usu�rio a ser deletado: ");
  scanf("%s",cpf);
  
  remove(cpf);
  
  FILE *file;
  file = fopen(cpf, "r");
  
  if(file == NULL)
  {
  	 printf("O usu�rio n�o se encontra no sistema!\n");
  	 system("pause");
  }
}



int main() // fun��o principal
{
	int opcao=0; // definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)  // sempre voltar ao menu
	{
	
	  system("cls"); 
	
      setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	  printf("### Car�rio da EBAC\n\n"); //hashtags est�ticas/in�cio do menu
	  printf("Escolha a op��o desejada do menu:\n\n"); // \n pular linha
	  printf("\t1- Registrar nomes\n"); // \t espa�o antes do texto
	  printf("\t2- Consultar nomes\n");
	  printf("\t3- Deletar nomes\n"); 
	  printf("\tOp��o:  "); // fim do menu
	
	  scanf("%d" , &opcao); // armazenando a escolha do usu�rio
	
	  system("cls"); // respons�vel por limpar a tela
	
	  switch(opcao) //in�cio da sele��o do menu
	   {
	  	 case 1:
	  	 registro(); //chamada de fun��es
		 break;
		
		 case 2:
		 consulta();
		 break;
		
		 case 3:
		 deletar();
		 break;
		
		 default:
		 printf("Essa op��o n�o est� dispon�vel!\n");
		 system("pause");
		 break;
	    } //fim da sele��o
	}
}
