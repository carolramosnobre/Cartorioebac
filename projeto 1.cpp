#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaco em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
   //início criação de variáveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final da criação de variáveis/string
  
  printf("Digite o CPF a ser cadastrado:   "); //coletando informção do usuário
  scanf("%s", cpf); //%s refere-se a string (armazenando)
  
  strcpy(arquivo, cpf); // responsável por copiar os valores das string
  
  FILE *file; //cria o arquivo
  file = fopen(arquivo, "w"); //cria o arquivo (w=write,escrever, criar uma nova)
  fprintf(file,"CPF: ");
  fprintf(file,cpf); //salvo o valor da variável
  fclose(file); // fecha o arquivo
  
  file = fopen(arquivo, "a"); // (a= atualizar informação)
  fprintf(file,"\nNOME: ");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado:  ");
  scanf("%s",nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose(file);
  
  file = fopen(arquivo, "a"); // (a= atualizar informação)
  fprintf(file,"\nSOBRENOME: ");
  fclose(file);
  
  printf("Digite o sobrenome a ser cadastrado:  ");
  scanf("%s", sobrenome);
  
  file = fopen(arquivo,"a");
  fprintf(file,sobrenome);
  fclose(file);
  
  file = fopen(arquivo, "a"); // (a= atualizar informação)
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
  
  char cpf[40]; //variável onde vamos armazenar a resposta do usuário para qual ele quer consultar
  char conteudo[200]; //variável onde vamos armazenar o conteúdo que esta dentro dese arquivo cpf
  
  printf("Digite o cpf a ser consultado:  ");
  scanf("%s", cpf);
  
  FILE *file; // abre o arquivo
  file = fopen(cpf, "r"); // "r" = read, consulta o arquivo
  
  if(file == NULL) 
  {
  	printf("Não foi possível abrir o arquivo, não localizado! \n");
  }
   
   printf("\nEssas são as informações do usuário: \n\n");
   
  while(fgets(conteudo,200, file) != NULL) // enquanto tiver conteúdo dentro desse arquivo
  {
  	printf("%s", conteudo);
  }
  
  system("pause");
}

int deletar()
{
  char cpf[40];
  
  printf("Digite o CPF do usuário a ser deletado: ");
  scanf("%s",cpf);
  
  remove(cpf);
  
  FILE *file;
  file = fopen(cpf, "r");
  
  if(file == NULL)
  {
  	 printf("O usuário não se encontra no sistema!\n");
  	 system("pause");
  }
}



int main() // função principal
{
	int opcao=0; // definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)  // sempre voltar ao menu
	{
	
	  system("cls"); 
	
      setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	  printf("### Carório da EBAC\n\n"); //hashtags estéticas/início do menu
	  printf("Escolha a opção desejada do menu:\n\n"); // \n pular linha
	  printf("\t1- Registrar nomes\n"); // \t espaço antes do texto
	  printf("\t2- Consultar nomes\n");
	  printf("\t3- Deletar nomes\n"); 
	  printf("\tOpção:  "); // fim do menu
	
	  scanf("%d" , &opcao); // armazenando a escolha do usuário
	
	  system("cls"); // responsável por limpar a tela
	
	  switch(opcao) //início da seleção do menu
	   {
	  	 case 1:
	  	 registro(); //chamada de funções
		 break;
		
		 case 2:
		 consulta();
		 break;
		
		 case 3:
		 deletar();
		 break;
		
		 default:
		 printf("Essa opção não está disponível!\n");
		 system("pause");
		 break;
	    } //fim da seleção
	}
}
