#ifndef _IRA_H_
#define _IRA_H_

#define CIMA 'W'
#define BAIXO 'S'
#define DIREITA 'D'
#define ESQUERDA 'A'
#define ACAO 'J'
#define INVENTARIO 'L'
#define CANCELAR 'K'

#include "personagem.h"

void tela_de_inicio();
int save_slots(int slot);
int le_save(int slot);
void introducao();
void load_save(P* p);
int ehdirecao(char direcao);
void move(char direcao);
int ehcomando(char comando);
#endif