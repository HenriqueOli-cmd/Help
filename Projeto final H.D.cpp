#include <stdio.h> //biblioteca de comunicação com os usuários
#include <stdlib.h> //biblioteca de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // função responsável pelo registro de cada usuário
{
	// inicio da criação das variaveis/string
	
	char arquivo[40]; //número de caracteres para o arqeuivo
	char cpf[40]; //número de caracteres para o cpf
	char nome[40]; //número de caracteres para o nome
	char sobrenome[40]; //número de caracteres para o sobrenome
	char cargo[40]; //número de caracteres para o cargo
	
	//final das variaveis a serem cadastradas
	
	printf("Digite seu CPF a ser cadastrado:"); //coletando as informações do usuário
	scanf("%s", cpf); // "%s" refere-se as strings
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, além de o "w" representar a escrita
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // apenas para separar a escrita
	fclose(file); 
	
	printf("\n Digite o nome a ser cadastrado:"); // coleta de dados 
	scanf("%s",nome); // responsável pelas ações de armazenar e verificar (as strings)
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); // responsável por salvar as variaveis
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
	scanf("%s",cargo); // responsável pelas funções (ações a serguir, após verificação)
	
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
	file = fopen(cpf,"r"); // o programa deverá "ler o arquivo para localiza-lo
	
	if (file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); // em caso de o cpf não ser localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\n Essas são as infromações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];	
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	 
	remove(cpf); // "remove" serve unica e exclusivamente para escluir
	
	FILE *file; 
	file = fopen(cpf, "r"); // "r" para ler e assim localizar o cpf
	
	if(file == NULL); // para caso o resultado seja "nulo", deve aparecer uma mensagem infromando que o usuário nçao foi localizado
	{
		printf("O usuário não se encontra no sistema!\n"); // aparecerá esta mensagem em casos de ter tido ou não o registro apagado (pode ocorrer de não ter registro antes criado)
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
	
	printf("### Cartório da EBAC ### \n \n");
	printf("Login de administrador! \n\n Digite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{	
	
		for(laco=1;laco=1;)
		{

			system("cls"); // responsável por limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); // Definição do idioma
			printf("### Cartório da EBAC ### \n \n"); // Inicio do menu
			printf("Escolha a opção desejada do menu: \n\n"); // Infromadndo a etapa a seguir
			printf("\t1 - Registrar Nomes\n"); // primeira opção
			printf("\t2 - Consultar Nomes\n"); // segunda opção
			printf("\t3 - Deletar Nomes\n"); // terceira opção 
			printf("\t4 - Sair do Sistema\n\n"); // quarta opção e fim do menu
			printf("Opção:");
	
			scanf("%d", &opcao); // armazenando a escolha do usuário 
	
			system("cls");
		
			switch (opcao) // inicio da seleção do menu
			{
	
				case 1:
				registro(); // chamada de funções (string) 
				break;
		
				case 2:
				consulta(); // chamada de funções (string) 
				break;
			
				case 3:
				deletar(); // chamada de funções (string) 
				break;
			
				case 4:
				printf("Voce esta saindo do sistema. Agradecemos sua interação!");
				return 0; //para caso o cliente deseje sair do sistema
				break;
		
				default:
				printf("Voce escolheu uma opçao não catalogada anteriormente, favor verifique sua escolha e tente novamente\n"); // para caso a informação não esteja dentre as possibilidades
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
 // Fim da seleção, após adicionar as possibilidades não constatadas nas opções anteriores
