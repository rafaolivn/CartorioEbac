#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço de memória
#include<locale.h>//biblioteca de alocação de texto por região
#include <string.h>//Biblioteca responsável por cuidas das string


int registro()// Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//Fim da criação de variaveis/string
	
	printf("Digite CPF do usuário: ");//Coletando informação do usuário
	scanf("%s", cpf);// "%s" refere-se a string
	
	strcpy(arquivo, cpf);// Responsavel por copiar os valores das string
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo e "w" escreve no arquivo
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o primeiro nome do usuário: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o ultimo do usuário: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo do usuário: ");
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
	
	printf("Digite o CPF do usuário: ");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL){
		printf("CPF não localizado!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL){
		printf("Essas são as informações cadastradas: \n");
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
		printf("Usuário deletado com sucesso!\n");
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
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escola a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Usuário\n");
		printf("\t2 - Consultar Usuário\n");
		printf("\t3 - Deletar Usuário\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//Final do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Limpando o historico
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Opção inexistente!\n");
			system("pause");
			break;
		}
	
	}
	
}

