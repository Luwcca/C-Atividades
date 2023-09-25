#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"


void carrega_mapa(int* nummapa, MAPA* m, P_N* pn){
    FILE* g;
    g = fopen("mapa.txt", "r"); 
    rewind(g);
    int atual = 0;
    if(g == 0) {
		printf("Erro na leitura do mapa");
		exit(1);
	}

    do
    {   
        
        fscanf(g,"%d", &atual);
        fseek(g,1,SEEK_CUR);

    } while (atual != *nummapa);

    for(int i = 0; i < 5; i++) {
		fscanf(g, "%s", m->matriz[i]);
	}
    
    fscanf(g,"%d %d %d %d", &(pn->esquerda), &(pn->baixo), &(pn->direita), &(pn->cima));

    
    fclose(g);
}

void imprime_mapa(MAPA* m){
        system("cls");
        for(int i = 0; i < 5; i++) {
        printf("%s\n",m->matriz[i]);
	}
}

void encontra_player(MAPA* m,char c){

    for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 29; j++) {
			if (m->matriz[i][j] == c)
            {
                m->posicaox = i;
                m->posicaoy = j;
                return;
            }
            
		}
	}
    
}

void andanomapa(MAPA* m, int xorigem, int yorigem, 
	int xdestino, int ydestino) {

    
	m->matriz[xdestino][ydestino] = HEROI;
	m->matriz[xorigem][yorigem] = VAZIO;

}

