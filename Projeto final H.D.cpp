#include <stdio.h> //biblioteca de comunica��o com os usu�rios
#include <stdlib.h> //biblioteca de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o respons�vel pelo registro de cada usu�rio
{
	// inicio da cria��o das variaveis/string
	
	char arquivo[40]; //n�mero de caracteres para o arqeuivo
	char cpf[40]; //n�mero de caracteres para o cpf
	char nome[40]; //n�mero de caracteres para o nome
	char sobrenome[40]; //n�mero de caracteres para o sobrenome
	char cargo[40]; //n�mero de caracteres para o cargo
	
	//final das variaveis a serem cadastradas
	
	printf("Digite seu CPF a ser cadastrado:"); //coletando as informa��es do usu�rio
	scanf("%s", cpf); // "%s" refere-se as strings
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, al�m de o "w" representar a escrita
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // apenas para separar a escrita
	fclose(file); 
	
	printf("\n Digite o nome a ser cadastrado:"); // coleta de dados 
	scanf("%s",nome); // respons�vel pelas a��es de armazenar e verificar (as strings)
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); // respons�vel por salvar as variaveis
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\n Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("\n Digite o cargo a ser cadastrado:");
	scanf("%s",cargo); // respons�vel pelas fun��es (a��es a serguir, ap�s verifica��o)
	
	file = fopen(arquivo,"a"); 
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Defini��o do idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // o programa dever� "ler o arquivo para localiza-lo
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); // em caso de o cpf n�o ser localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\n Essas s�o as infroma��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];	
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	 
	remove(cpf); // "remove" serve unica e exclusivamente para escluir
	
	FILE *file; 
	file = fopen(cpf, "r"); // "r" para ler e assim localizar o cpf
	
	if(file == NULL); // para caso o resultado seja "nulo", deve aparecer uma mensagem infromando que o usu�rio n�ao foi localizado
	{
		printf("O usu�rio n�o se encontra no sistema!\n"); // aparecer� esta mensagem em casos de ter tido ou n�o o registro apagado (pode ocorrer de n�o ter registro antes criado)
		system("pause");
	}
	fclose(file);
}

int main()
{
	int opcao=0; // Definindo as variaveis
	int laco=1; // "x" pode ser laco ou qualquer coisa que voce desejar por no nome
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ### \n \n");
	printf("Login de administrador! \n\n Digite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{	
	
		for(laco=1;laco=1;)
		{

			system("cls"); // respons�vel por limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); // Defini��o do idioma
			printf("### Cart�rio da EBAC ### \n \n"); // Inicio do menu
			printf("Escolha a op��o desejada do menu: \n\n"); // Infromadndo a etapa a seguir
			printf("\t1 - Registrar Nomes\n"); // primeira op��o
			printf("\t2 - Consultar Nomes\n"); // segunda op��o
			printf("\t3 - Deletar Nomes\n"); // terceira op��o 
			printf("\t4 - Sair do Sistema\n\n"); // quarta op��o e fim do menu
			printf("Op��o:");
	
			scanf("%d", &opcao); // armazenando a escolha do usu�rio 
	
			system("cls");
		
			switch (opcao) // inicio da sele��o do menu
			{
	
				case 1:
				registro(); // chamada de fun��es (string) 
				break;
		
				case 2:
				consulta(); // chamada de fun��es (string) 
				break;
			
				case 3:
				deletar(); // chamada de fun��es (string) 
				break;
			
				case 4:
				printf("Voce esta saindo do sistema. Agradecemos sua intera��o!");
				return 0; //para caso o cliente deseje sair do sistema
				break;
		
				default:
				printf("Voce escolheu uma op�ao n�o catalogada anteriormente, favor verifique sua escolha e tente novamente\n"); // para caso a informa��o n�o esteja dentre as possibilidades
				system("pause");
				break;
			}
	
		}
	}
	else
		printf("Senha Incorreta! Verifique sua senha e tente novamente.\n\n");
		
		{

		system("pause");

		system("cls");

		main();

	
	
		}
		
}
 // Fim da sele��o, ap�s adicionar as possibilidades n�o constatadas nas op��es anteriores
