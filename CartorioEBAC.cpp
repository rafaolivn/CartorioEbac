#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o de mem�ria
#include<locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//Biblioteca respons�vel por cuidas das string


int registro()// Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//Fim da cria��o de variaveis/string
	
	printf("Digite CPF do usu�rio: ");//Coletando informa��o do usu�rio
	scanf("%s", cpf);// "%s" refere-se a string
	
	strcpy(arquivo, cpf);// Responsavel por copiar os valores das string
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo e "w" escreve no arquivo
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o primeiro nome do usu�rio: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o ultimo do usu�rio: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo do usu�rio: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio: ");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL){
		printf("CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL){
		printf("Essas s�o as informa��es cadastradas: \n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
}
int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
	system("cls");//responsavel por limpar a tela

	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escola a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Usu�rio\n");
		printf("\t2 - Consultar Usu�rio\n");
		printf("\t3 - Deletar Usu�rio\n\n"); 
		printf("Op��o: ");//Final do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Limpando o historico
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Op��o inexistente!\n");
			system("pause");
			break;
		}
	
	}
	
}

