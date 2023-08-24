#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

int main() {
    printf("\n\n************************************\n");
    printf("* Bem vindo ao Jogo de Adivinhacao *\n");
    printf("************************************\n\n");

    int chute;
    int acertou = 0;
    int totaldetentativas;
    int nivel;
    double pontos = 1000;

    srand(time(0));//Altera a seed aleatoria com base no tempo
    int numerosecreto = rand() % 100;//garante que o número é entre 0 e 100

    // escolhendo o nivel de dificuldade
    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");

    scanf("%d", &nivel);

    switch(nivel) {
        case 1: 
            totaldetentativas = 20;
            break;
        case 2:
            totaldetentativas = 15;
            break;
        default:
            totaldetentativas = 6;
            break;
    }

    // loop principal do jogo
    for(int i = 1; i <= totaldetentativas; i++) {

        printf("\n-> Tentativa %d de %d\n", i, totaldetentativas);

        printf("Chute um numero: ");
        scanf("%d", &chute);

        // tratando chute de numero negativo
        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        // verifica se acertou, foi maior ou menor
        acertou = chute == numerosecreto;

        if(acertou) {
            break;
        } else if(chute > numerosecreto) {
            printf("\nSeu chute foi maior do que o numero secreto!\n");
        } else {
            printf("\nSeu chute foi menor do que o numero secreto!\n");
        }

        // calcula a quantidade de pontos
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("\nVoce fez %.2f pontos\n", pontos);
    printf("Obrigado por jogar!\n\n");

}