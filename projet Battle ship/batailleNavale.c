#include"partie.h"



int main(int argc, char **argv) {
struct jeu plateau;
struct bateaux struc_BB;

srand(time(NULL));

struc_BB = param();
plateau = initAllPlateau(struc_BB);
Partie(plateau,struc_BB);

printf("MERCI DE VOTRE PARTICIPATION\n");
return(0);
// deroulement correct du programme, renvoie 0 au terminal
}