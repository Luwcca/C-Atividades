#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

struct status
{
    int vida;
    int mana;
    int dano;
};

struct inventario
{
    int arma;
    int armadura;
    int pocaovida;
    int pocaomana;
};

struct personagem
{   
    int slot;
    char nome[20];
    char classe;
    struct status stats;
    struct inventario inv; 
    int mapa;   
};



typedef struct personagem P;

void criar_personagem(P* p);
void abre_inventario(P* p);

#endif
