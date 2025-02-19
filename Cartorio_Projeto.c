#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel pelas strings

int RegistrarNomes() // Cria um registro no banco de dados
{
	setlocale(LC_ALL, "Portuguese"); // LC_ALL + "lingua_utilizada" para puxar a biblioteca de texto por regi�o
	
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); // Coletando informa��o do usu�rio
	scanf ("%s", cpf); //%s refere-se a string
	
	strcpy (arquivo, cpf); // Respons�vel por copiar o CPF para o nome do arquivo
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria e escreve no arquivo - "w" refere-se a write / escrever
	fprintf (file, "\nCPF: ");
	fprintf (file,cpf); // Salva dentro do arquivo a informa��o da variavel CPF
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" de atualiza��o - para n�o criar outro
	fprintf(file, ";");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, "\nNome: ");
	fprintf (file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ";");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file, "\nSobrenome: ");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ";");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, "\nCargo: ");
	fprintf(file, cargo);
	fprintf (file, ".");
	fclose(file);
	
	system("pause");
}

int ConsultarNomes() // realiza a consulta de nomes dentro do banco de dados
{
	setlocale(LC_ALL, "Portuguese"); // LC_ALL + "lingua_utilizada" para puxar a biblioteca de texto por regi�o

	char cpf [40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // o comando R em fopen refere-se a READ - ler 
	
	if (file == NULL) // compara��o para nulo
	{
		printf ("\nN�o foi poss�vel abir o arquivo, n�o localizado!\n");
	}
	else
		printf("\nEssas s�o as informa��es do usu�rio: \n");	
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	printf("\n\n");
	system ("pause");
}
	

int DeletarNomes() // fun��o para deletar usu�rios
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf, "r"); // "r" refere-se a Ler
	
	if(file != NULL)
	{
		fclose(file); // fechar o arquivo para ele conseguir deletar
		remove(cpf); // deleta o arquivo
		printf ("O usu�rio foi delatado com �xito!\n");
	}
	else
		printf ("O usu�rio n�o se encontra em nosso sistema!\n");
		system ("pause");
	
}
int main()
{
		
	int opcao=0; // definindo a Variavel local (dentro do main)
	int RepetirMenu = 1; // Vari�vel para declarar o inicio do la�o de repeti��o
	
	for (RepetirMenu=1;RepetirMenu=1;) 
	{
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); // LC_ALL + "lingua_utilizada" para puxar a biblioteca de texto por regi�o
	
	
		printf ("========= Cart�rio da EBAC =========\n\n");	// \n = pular linha - Inicio do nosso menu
		printf ("Escolha a op��o deseja do menu:\n\n"); 
		printf ("\t1 - Registrar nomes;\n");// \t = espa�amento de paragrafo
		printf ("\t2 - Consultar nomes;\n");
		printf ("\t3 - Deletar nomes.\n\n");  
		printf ("Op��o: ");// Fim do Menu
		
		scanf("%d", &opcao); // %d = armazenamento da vari�vel tipo INT &variavel (para dizer onde � para armazenar a informa��o)
	
		system ("cls"); // Limpa o prompt (Muda em cada S.O.)
		
		//Inicio da sele��o
		switch (opcao) // utilizado para escolhas que n�o precisam de compara��o l�gica.
		{
			case 1:
				RegistrarNomes();
			break;
			
			case 2:
				ConsultarNomes();
			break;
			
			case 3:
				DeletarNomes();
			break;
			
			default:
				printf("Digite um n�mero v�lido apresentado no menu de op��es.\n"); 
				printf ("======================================================\n");	
				system ("pause");
			break;
			// Fim da sele��o
				
		}
	}
}

