#include <stdio.h>
#include <stdlib.h>
#include "IRA.h"
#include <string.h>
#include "personagem.h"
#include "mapa.h"

P p;
P_N pn;
MAPA m;
FILE* f;



void tela_de_inicio(){

    char tela[13][58] = {
        {"#########################################################"},
        {"##                                                     ##"},
        {"##                                                     ##"},
        {"##             _____   _____               _           ##"},
        {"##            |_   _| |  __ \\      /\\     | |          ##"},
        {"##              | |   | |__) |    /  \\    | |          ##"},
        {"##              | |   |  _  /    / /\\ \\   | |          ##"},
        {"##             _| |_  | | \\ \\   / ____ \\  |_|          ##"},
        {"##            |_____| |_|  \\_\\ /_/    \\_\\ (_)          ##"},
        {"##                                                     ##"},
        {"##                                                     ##"},
        {"##                                                     ##"},
        {"#########################################################"}
    };

    for(int i = 0; i<13; i++){
        printf("%s\n",tela[i]);
    }

    printf("\nAPERTE UMA TECLA PARA INICIAR");

    getc(stdin);

    system("cls");
}

int save_slots(int slot){

    char banner[7][66] ={
        {"####################   ####################  ####################"},
        {"##                ##   ##                ##  ##                ##"},
        {"##     SLOT 1     ##   ##     SLOT 2     ##  ##     SLOT 3     ##"},
        {"##                ##   ##                ##  ##                ##"},
        {"##                ##   ##                ##  ##                ##"},  
        {"##                ##   ##                ##  ##                ##"},
        {"####################   ####################  ####################"}
    };

    for(int i = 0; i<7; i++){
        printf("%s\n",banner[i]);
    }


    printf("\nSelecione um Slot de jogo, digitando entre 1 e 3\n");

    scanf("%d", &slot);

    if(slot == 1 || slot == 2 || slot == 3){
        printf("\nSelecionado o Slot %d\n\n",slot);
        p.slot = slot;
        return le_save(slot);
    }

    printf("\n################################################\n## Por favor, selecione um numero entre 1 e 3 ##\n################################################\n\n");
    return save_slots(slot);
    
}

int le_save(int slot){
    char file[10];
    int estado = 0;
    switch (slot)
    {
    case 1:
        strcpy(file,"save1.txt");
        break;
    case 2:
        strcpy(file,"save2.txt");
        break;
    default:
        strcpy(file,"save3.txt");
        break;
    }
     
	f = fopen(file, "r+");
	if(f == 0) {
		printf("Erro na leitura save");
		exit(1);
	}

    fscanf(f, "%d", &estado);

    
    return estado;
    
    

}

void salvar(P p){

    rewind(f);
    fprintf(f, "%d\n", p.slot);
    fprintf(f, "%s : nome\n", p.nome);
    fprintf(f, "%c : classe\n", p.classe);
    fprintf(f, "%d : mapa\n", p.mapa);
    fprintf(f, "%d : vida\n", p.stats.vida);
    fprintf(f, "%d : mana\n", p.stats.mana);
    fprintf(f, "%d : dano\n", p.stats.dano);


}

void load_save(P* p){
    fseek(f,1,SEEK_SET);
    fscanf(f, "%s", p->nome);
    fseek(f,9,SEEK_CUR);
    fscanf(f, "%c", &p->classe);
    fseek(f,11,SEEK_CUR);
    fscanf(f, "%d", &p->mapa);
    fseek(f,9,SEEK_CUR);
    fscanf(f, "%d", &p->stats.vida);
    fseek(f,9,SEEK_CUR);
    fscanf(f, "%d", &p->stats.mana);
    fseek(f,9,SEEK_CUR);
    fscanf(f, "%d", &p->stats.dano);
    
    
    


}

void introducao(){
    system("cls");
    printf("############################################################################\n\n");
    getc(stdin);
    printf("A vida era linda e calma, só eram você e seu gatinho\n");
    getc(stdin);
    printf("\nMas um dia, o malvado LICHT roubou o seu precioso amigo!\n");
    getc(stdin);
    printf("\nO Castelo do LITCH é protegido por 3 cristais de defesa");
    getc(stdin);
    printf("\nO cristal do Pantano, é protegido pelo terrivel Lorde Peixarel\n");
    getc(stdin);
    printf("O cristal da Malvadesa, é protegido pelo Conde Malvadoso\n");
    getc(stdin);
    printf("O cristal da Sujeira, é protegido pelo Casção.\n");
    getc(stdin);
    system("cls");
    printf("Destrua os cristais, vá ao castelo e enfrente o LICHT, para recuperar seu gatinho\n");
    getc(stdin);
    printf("Use toda a sua...\n");
    printf("  _____   _____               _ \n");
    printf(" |_   _| |  __ \\      /\\     | |\n");
    printf("   | |   | |__) |    /  \\    | |\n");
    printf("   | |   |  _  /    / /\\ \\   | |\n");
    printf("  _| |_  | | \\ \\   / ____ \\  |_|\n");
    printf(" |_____| |_|  \\_\\ /_/    \\_\\ (_)\n");
    printf("                                \n");
    getc(stdin);
    system("cls");
}

int ehdirecao(char direcao) {
	return
		direcao == ESQUERDA || 
		direcao == CIMA ||
		direcao == BAIXO ||
		direcao == DIREITA;
}

void move(char direcao){
    
    
    int proximox = m.posicaox;
	int proximoy = m.posicaoy;

	switch(direcao) {
		case ESQUERDA:
			proximoy--;
			break;
		case CIMA:
			proximox--;
			break;
		case BAIXO:
			proximox++;
			break;
		case DIREITA:
			proximoy++;
			break;
        default:
            return;

	}
    
    if(m.matriz[proximox][proximoy] == PAREDE){
        return;
    }

    if(m.matriz[proximox][proximoy] == PORTA_VERTICAL){
        
        if (proximoy == 0)
        {  
            p.mapa = pn.esquerda*10;
	        proximoy = proximoy + 26;

        }
        else{
            p.mapa = pn.direita*10;
            proximoy = proximoy - 26;
        }
        carrega_mapa(&p.mapa, &m, &pn);
        
    }

    if(m.matriz[proximox][proximoy] == PORTA_HORIZONTAL){
        if (proximox == 0)
        {
            p.mapa = pn.cima*10;
            proximox = proximox + 3;
        }
        else{
            
            p.mapa = pn.baixo*10;
            proximox = proximox - 3;
        }
        carrega_mapa(&p.mapa, &m, &pn);
       
        
    }

   

    andanomapa(&m, m.posicaox, m.posicaoy, proximox, proximoy);
	m.posicaox = proximox;
	m.posicaoy = proximoy;

}

int ehcomando(char comando){
    return comando == ACAO||
            comando == INVENTARIO ||
            comando == CANCELAR;
}

int main(){


    tela_de_inicio();
    if(save_slots(p.slot) == 0){
        criar_personagem(&p);
        introducao();
        p.mapa = 1000;
        salvar(p);

    }
    else{
        load_save(&p);
    }   

    carrega_mapa(&p.mapa, &m, &pn);
    andanomapa(&m,2,15,2,13);
    encontra_player(&m, HEROI);

    do
    {   
        
        imprime_mapa(&m);
        printf("%d\n",p.mapa);
        char comando;
		scanf(" %c", &comando);

        if(ehdirecao(comando)){
            move(comando);
        } 
        else if(ehcomando(comando)){
            if(comando == INVENTARIO); abre_inventario(&p);
            getc(stdin);
        } 
        
    } while(1);

    

    fclose(f);

    return 0;
    
}