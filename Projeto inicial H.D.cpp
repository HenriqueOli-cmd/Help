#include <stdio.h> //biblioteca de comunicação com os usuários
#include <stdlib.h> //biblioteca de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu CPF a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definição do idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\n Essas são as infromações do usuário:");
		printf("%s", conteudo);
		
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
		printf("Voce escolheu deletar o nome!\n");
		system("pause");
}

int main()
{
	int opcao=0; // Definindo as variaveis
	int laco=1; // "x" pode ser laco ou qualquer coisa que voce desejar por no nome
	
	for(laco=1;laco=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definição do idioma
		printf("### Cartório da EBAC ### \n \n"); // Inicio do menu
		printf("Escolha a opção desejada do menu: \n\n"); // Infromadndo a etapa a seguir
		printf("\t1 - Registrar Nomes\n"); // primeira opção
		printf("\t2 - Consultar Nomes\n"); // segunda opção
		printf("\t3 - Deletar Nomes\n\n"); // terceira opção e fim do menu
		printf("Opção:");
	
		scanf("%d", &opcao); // armazenando a escolha do usuário 
	
		system("cls");
		switch (opcao)
		{
	
			case 1:
			registro();
			break;
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
		
			default:
			printf("Voce escolheu uma opçao não catalogada anteriormente, favor verifique sua escolha e tente novamente\n");
			system("pause");
			break;
		}
	
	}
}
 // Fim da seleção, após adicionar as possibilidades não constatadas nas opções anteriores
