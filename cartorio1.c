#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca que cuida das strings

int registro() //fun��o para registrar os usu�rios no sistema
{
	//inicio da cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o das vari�veis/strings
	
	printf("Digite o cpf a ser cadastrado: "); //coleta o cpf do usu�rio
	scanf("%s", cpf); //%s � referente a string
	
	strcpy(arquivo, cpf); //copia os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" respons�vel por escrever no arquivo
	fprintf(file, "Cpf: ");
	fprintf(file,cpf); //salva valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" respons�vel por adicionar informa��o no arquivo
	fprintf(file, ";\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coleta o nome do usu�rio
	scanf("%s", nome); //salva a resposta do usu�rio na string
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ";\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // coleta o sobrenome do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ";\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	

}

int consulta() //fun��o para consultar informa��es 
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // l� o arquivo
	
	if(file == NULL) //resposta mostrada ao usu�rio quando n�o � poss�vel achar o arquivo
	{
		printf("Nao foi poss�vel localizar o arquivo!\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informa��es do usu�rio
	{
		printf("Essas s�o as informa��es de usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");

}

int deletar() //fun��o para deletar as informa��es do usu�rio
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //respons�vel pela resposta caso n�o seja encontrado o arquivo
	{
		printf("Usu�rio selecionado n�o se encontra mais no sistema!\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //define as vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //define a linguagem
		
		printf("###Cart�rio da EBAC### \n\n"); 
		printf("Escolha a op��o desejada no menu: \n\n"); //inicio do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Selecione uma das op��es acima:"); //fim do menu
		
		scanf("%d", &opcao);
		
		system("cls"); //limpa a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
				registro(); //chama as fun��es
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("Op��o n�o dispon�vel.\n");
				system("pause");
			break;
		} //final da sele��o de op��es
	}
}
