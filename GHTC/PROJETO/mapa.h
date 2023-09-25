#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI 'P'
#define VAZIO '.'
#define PORTA_VERTICAL '|'
#define PORTA_HORIZONTAL '-'
#define PAREDE '#'

struct mapa {
	char matriz[5][29];
	int posicaox;
	int posicaoy; 
};
typedef struct mapa MAPA;

struct prox_nivel {
	int esquerda;
	int direita;
	int cima;
	int baixo;
};
typedef struct prox_nivel P_N;


void carrega_mapa(int* nummapa, MAPA* m, P_N* pn);
void encontra_player(MAPA* m,char c);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void imprime_mapa(MAPA* m);
#endif