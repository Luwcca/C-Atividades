#include <stdio.h>

int main(){

	
	struct Aluno
	{
		char nome[50];
		char data_de_nascimento[11];
		char sexo;
		int registro;
	};

	struct Aluno Aluno;

	printf("\n---------- Cadastro de aluno -----------\n\n\n");
  
  	printf("Nome do aluno ......: ");
	scanf("%s",Aluno.nome);
	printf("Data de nascimento do aluno ......: ");
	scanf("%s",Aluno.data_de_nascimento);
	printf("Sexo do aluno ......: ");
	scanf(" %c",&Aluno.sexo);
	printf("Registro do aluno ......: ");
	scanf(" %d",&Aluno.registro);

	printf("\n---------- Cadastro de alunodigitado-----------\n\n\n");

	printf("Nome do aluno ......: %s",Aluno.nome);
	printf("\nData de nascimento do aluno ......: %s",Aluno.data_de_nascimento);
	printf("\nSexo do aluno ......: %c",Aluno.sexo);
	printf("\nRegistro do aluno ......: %d",Aluno.registro);




  return 0;
}
