/*
 * \file affichage.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  affichage des grilles
 *  Fichier header
 */
 
  /* Inclusion des .h */

#include"affichage.h"

/* Definition constante */
#define couleur(param) printf("\033[%sm",param)
#define DEFAUT "00"
#define NOIR "30"
#define ROUGE "31"
#define BLEU "36"
#define VERT "32"




void afficherGrille(int** ttint_dyn, int int_t) { // affiche la grille avec le quadrillage et le cellules vides et pleines
int int_i, int_j;

	printf("\n    ");
	for (int_i = 0; int_i < int_t; int_i++) {
		if (int_i < 9) {		
			printf("  %d ",int_i+1);
		}else{
			printf(" %d ",int_i+1);
		}
	}
	printf("\n    ");
	couleur(BLEU);
	for (int_i = 0; int_i < int_t; int_i++) {
		printf("+---");
	}
	printf("+\n");

	for (int_i = 0; int_i < int_t; int_i++) {
		couleur(DEFAUT);
		printf("  %c ",ALPHABET[int_i]);
		for (int_j = 0; int_j < int_t; int_j++){
			couleur(BLEU);
			printf("|");
			switch (ttint_dyn[int_i][int_j]) {
				case EAU :
					printf("   ");
				break;
				case BATEAU :
					couleur(DEFAUT);
					printf(" B ");
				break;
				case TOUCHE :
					couleur(ROUGE);
					printf(" X ");
				break;
				case PLOUF :
					printf(" O ");
				break;
				case COULE :
					couleur(VERT);
					printf(" X ");
				break;
				default :
					printf("ERREUR");
				break;
			}
		}
		couleur(BLEU);
		printf("|\n    ");
		for (int_j = 0; int_j < int_t; ++int_j) {
			printf("+---");
		}
		printf("+\n");
	}
	printf("\n");
	couleur(DEFAUT);
}




void afficherChangementJr(struct jeu plateau, int int_joueur) {
printf("\n\n ENTRER pour continuer\n\n");
scanf("");
printf("\e[1;1H\e[2J"); //efface le terminal avant l'affichage
printf("\nATTENTION changement de joueur !\n\n");
switch (int_joueur) {
	case 1 :
		printf("%i, c'est bien toi ?\n Si oui appuie sur entrer pour pouvoir voir ton jeu\n",int_joueur);
	break;
	case 2 :
		printf("%i, c'est bien toi ?\n Si oui appuie sur entrer pour pouvoir voir ton jeu\n",int_joueur);
	break;
	default :
		printf("ERREUR");
	break;
}
sleep(2);
printf("\e[1;1H\e[2J"); //efface le terminal avant l'affichage
}


void afficherGagnant(struct jeu plateau, int int_joueur) {
printf("\e[1;1H\e[2J"); //efface le terminal avant l'affichage
printf("Plateau des bateaux de %i",1);
afficherGrille(plateau.struc_BateauJr1.ttint_grille,plateau.struc_BateauJr1.int_taille);
printf("Plateau de jeu de %i",1);
afficherGrille(plateau.struc_JeuJr1.ttint_grille,plateau.struc_JeuJr1.int_taille);
printf("Plateau des bateaux de %i",2);
afficherGrille(plateau.struc_BateauJr2.ttint_grille,plateau.struc_BateauJr2.int_taille);
printf("Plateau de jeu de %i",2);
afficherGrille(plateau.struc_JeuJr2.ttint_grille,plateau.struc_JeuJr2.int_taille);
sleep(2);
switch (int_joueur) {
	case 1 :
		printf("Le joueur %d a gagne !\n",int_joueur);
	break;
	case 2 :
		printf("Le joueur %d a gagne !\n",int_joueur);
	break;
	default :
		printf("ERREUR");
	break;
}
}
