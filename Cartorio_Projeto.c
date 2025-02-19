#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável pelas strings

int RegistrarNomes() // Cria um registro no banco de dados
{
	setlocale(LC_ALL, "Portuguese"); // LC_ALL + "lingua_utilizada" para puxar a biblioteca de texto por região
	
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: \n"); // Coletando informação do usuário
	scanf ("%s", cpf); //%s refere-se a string
	
	strcpy (arquivo, cpf); // Responsável por copiar o CPF para o nome do arquivo
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria e escreve no arquivo - "w" refere-se a write / escrever
	fprintf (file, "\nCPF: ");
	fprintf (file,cpf); // Salva dentro do arquivo a informação da variavel CPF
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" de atualização - para não criar outro
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
	setlocale(LC_ALL, "Portuguese"); // LC_ALL + "lingua_utilizada" para puxar a biblioteca de texto por região

	char cpf [40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // o comando R em fopen refere-se a READ - ler 
	
	if (file == NULL) // comparação para nulo
	{
		printf ("\nNão foi possível abir o arquivo, não localizado!\n");
	}
	else
		printf("\nEssas são as informações do usuário: \n");	
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	printf("\n\n");
	system ("pause");
}
	

int DeletarNomes() // função para deletar usuários
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf, "r"); // "r" refere-se a Ler
	
	if(file != NULL)
	{
		fclose(file); // fechar o arquivo para ele conseguir deletar
		remove(cpf); // deleta o arquivo
		printf ("O usuário foi delatado com êxito!\n");
	}
	else
		printf ("O usuário não se encontra em nosso sistema!\n");
		system ("pause");
	
}
int main()
{
		
	int opcao=0; // definindo a Variavel local (dentro do main)
	int RepetirMenu = 1; // Variável para declarar o inicio do laço de repetição
	
	for (RepetirMenu=1;RepetirMenu=1;) 
	{
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); // LC_ALL + "lingua_utilizada" para puxar a biblioteca de texto por região
	
	
		printf ("========= Cartório da EBAC =========\n\n");	// \n = pular linha - Inicio do nosso menu
		printf ("Escolha a opção deseja do menu:\n\n"); 
		printf ("\t1 - Registrar nomes;\n");// \t = espaçamento de paragrafo
		printf ("\t2 - Consultar nomes;\n");
		printf ("\t3 - Deletar nomes.\n\n");  
		printf ("Opção: ");// Fim do Menu
		
		scanf("%d", &opcao); // %d = armazenamento da variável tipo INT &variavel (para dizer onde é para armazenar a informação)
	
		system ("cls"); // Limpa o prompt (Muda em cada S.O.)
		
		//Inicio da seleção
		switch (opcao) // utilizado para escolhas que não precisam de comparação lógica.
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
				printf("Digite um número válido apresentado no menu de opções.\n"); 
				printf ("======================================================\n");	
				system ("pause");
			break;
			// Fim da seleção
				
		}
	}
}

