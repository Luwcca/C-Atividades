#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Exercicio1(){

	int numeros[100];

	int maior = 0;

	srand(time(0));

	for(int i = 0; i<100; i++)
	{
		numeros[i] = rand() % 1000;

		if(numeros[i] > maior){

			maior = numeros[i];
		}

	}


	return maior;


} 	

void Exercicio2(){

	int numeros[150];

	srand(time(0));

	for(int i = 0; i<150; i++)
	{
		numeros[i] = rand() % 150;

	}
	for(int i = 0; i<150; i++)
	{	
		bool unico = true;
		for(int j = 0; j<150; j++){

			if(numeros[i] == numeros[j] && i!=j)
			{
				unico = false;
			}


		}

		if(unico == true)
		{
			printf("%d eh unico\n",numeros[i] );
		}

	}


} 	

void Exercicio9(){

	int n;
	int m;

	printf("\nDigite n:\n");
	scanf(" %d",&n );
	printf("\nDigite m:\n");
	scanf("%d",&m );

	int nm[n][m];

	for(int i = 0; i<n;i++){

		for (int j = 0; j < m; j++)
		{
			printf("\nDigite o %d numero da %d linha: ",j+1,i+1);
			scanf("%d",&nm[i][j]);
		}

	}

	int cont =0;

	for(int i = 0; i<n;i++){

		for (int j = 0; j < m; j++)
		{
			if(nm[i][j] == 0){
				cont++;
			}
		}
	}

	if(cont > (n*m)/2){
		printf("A matriz eh esparsa");
	}
	else{
		printf("A matriz eh densa");
	}
}


int main(){


	printf("\n###################################\n");

	printf("Exercicio 1 -\n%d\n", Exercicio1());

	printf("\n###################################\n");

	printf("Exercicio 2 -\n");
	Exercicio2();

	printf("\n###################################\n");

	printf("Exercicio 9 -\n");
	Exercicio9();

	return 0;
}





