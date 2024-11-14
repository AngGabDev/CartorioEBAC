#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca que cuida das strings

int registro() //função para registrar os usuários no sistema
{
	//inicio da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variáveis/strings
	
	printf("Digite o cpf a ser cadastrado: "); //coleta o cpf do usuário
	scanf("%s", cpf); //%s é referente a string
	
	strcpy(arquivo, cpf); //copia os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" responsável por escrever no arquivo
	fprintf(file, "Cpf: ");
	fprintf(file,cpf); //salva valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo, "a" responsável por adicionar informação no arquivo
	fprintf(file, ";\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coleta o nome do usuário
	scanf("%s", nome); //salva a resposta do usuário na string
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ";\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // coleta o sobrenome do usuário
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

int consulta() //função para consultar informações 
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // lê o arquivo
	
	if(file == NULL) //resposta mostrada ao usuário quando não é possível achar o arquivo
	{
		printf("Nao foi possível localizar o arquivo!\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informações do usuário
	{
		printf("Essas são as informações de usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");

}

int deletar() //função para deletar as informações do usuário
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) //responsável pela resposta caso não seja encontrado o arquivo
	{
		printf("Usuário selecionado não se encontra mais no sistema!\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //define as variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //define a linguagem
		
		printf("###Cartório da EBAC### \n\n"); 
		printf("Escolha a opção desejada no menu: \n\n"); //inicio do menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Selecione uma das opções acima:"); //fim do menu
		
		scanf("%d", &opcao);
		
		system("cls"); //limpa a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
				registro(); //chama as funções
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("Opção não disponível.\n");
				system("pause");
			break;
		} //final da seleção de opções
	}
}
