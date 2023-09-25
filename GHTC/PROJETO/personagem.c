#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"



void criar_personagem(P* p){
    system("cls");
    int vida = 10;
    int mana = 10;
    int dano = 5;
    

    printf("\n################################################################\n");
    printf("Save vazio. Iniciando a criacao de personagem:");
    printf("\nInsira o nome do seu personagem\n");
    scanf("%s", p->nome);

    printf("\n Escolha uma das 5 classes:\n");
    printf("\nL - Lutador: +5 de vida, +5 de dano, Armadura média e espadas\n");
    printf("A - Assasino: +10 de dano, Armadura leve e adagas\n");
    printf("M - Mago: +5 de Mana, 5+ dano, Armadura leve e Cajado\n");
    printf("C - Cavaleiro: +10 de vida; Armadura pesada e Machados\n");
    printf("T - Templário: +5 de vida, +5 de mana, Armadura média e Lanças\n");

    scanf(" %c", &p->classe);

    switch(p->classe)
    {
    case 'A':
        dano+=10;
        break;
    case 'M':
        dano += 5;
        mana +=5;
        break;
    case 'C':
        vida += 10;
        break;
    case 'T':
        vida += 5;
        mana += 5;
        break;
    
    default:
        dano += 5;
        vida += 5;
        break;
    }
    
    p->stats.vida = vida;
    p->stats.mana = mana;
    p->stats.dano = dano;

    printf("\nNOVO PERSONAGEM CRIADO");
    getc(stdin);
}

void abre_inventario(P* p){
    system("cls");
    printf("################\n");
    printf("%s\n",p->nome);
    printf("Classe: ");
    switch (p->classe)
    {
    case 'L' :
        printf("Lutador\n");
        break;
    case 'A':
        printf("Assasino\n");
        break;
    case 'M':
        printf("Mago\n");
        break;
    case 'C':
        printf("Cavaleiro\n");
        break;
    case 'T':
        printf("Templario\n");
        break;
    }

    

}
