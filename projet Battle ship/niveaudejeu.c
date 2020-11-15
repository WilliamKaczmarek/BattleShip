/*
 * \file niveaudejeu.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Calcul les niveaux d'avancement de la partie
 */

#include "niveaudejeu.h"

int aGagne(struct joueur struc_jeuJr, struct joueur struc_batAdv) {
int int_i, int_j, int_verif = 1;
for (int_i = 0; ((int_i < struc_jeuJr.int_taille) && (int_verif == 1)); int_i++) {
	for (int_j = 0; ((int_j < struc_jeuJr.int_taille) && (int_verif == 1)); int_j++){
		if ((struc_batAdv.ttint_grille[int_i][int_j] == 1) && (struc_jeuJr.ttint_grille[int_i][int_j] != -1)) {
			int_verif = 0;
		}
	}
}
return(int_verif);
}

int Coule(struct joueur struc_jeuJr, struct joueur struc_batAdv, struct coordonnees struc_case) {
	int int_compteur = 0;
	int i, j;
	for (i = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne+i][struc_case.int_colonne] == -1) && (i < struc_batAdv.int_taille)); ++i){}
	if ((i != struc_batAdv.int_taille) || (struc_batAdv.ttint_grille[struc_case.int_ligne+i][struc_case.int_colonne] == 2)) {
		int_compteur = int_compteur +1;
	}

	for (i = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne-i][struc_case.int_colonne] == -1) && (i < struc_batAdv.int_taille)); i++){}
	if ((i != struc_batAdv.int_taille) || (struc_batAdv.ttint_grille[struc_case.int_ligne-i][struc_case.int_colonne] == 2)) {
		int_compteur = int_compteur +1;
	}
	for (j = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne+j] == -1) && (j < struc_batAdv.int_taille)); j++){}
	if ((j != struc_batAdv.int_taille) || (struc_batAdv.ttint_grille[struc_case.int_ligne][struc_case.int_colonne+j] == 2)) {
		int_compteur = int_compteur +1;
	}
	for (j = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne-j] == -1) && (j < struc_batAdv.int_taille)); j++){}
    if ((j != struc_batAdv.int_taille) || (struc_batAdv.ttint_grille[struc_case.int_ligne][struc_case.int_colonne-j] == 2)) {
        int_compteur = int_compteur +1;
    }
   	if (int_compteur == 4) {
		return 3;
	}
	return 0;
}



struct joueur placementCouloire(struct joueur struc_jeuJr, struct coordonnees struc_case) {
    int i, j;
    for (i = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne+i][struc_case.int_colonne] == -1) && (i < struc_jeuJr.int_taille)); ++i) {
        struc_jeuJr.ttint_grille[struc_case.int_ligne+i][struc_case.int_colonne] = -3;
        if ((struc_case.int_colonne+1 ) < struc_jeuJr.int_taille) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne+i][struc_case.int_colonne+1] = -2;
        }
        if (0 <= (struc_case.int_colonne-1)) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne+i][struc_case.int_colonne-1] = -2;
        }
    }
    for (i = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne-i][struc_case.int_colonne] == -1) && (0 <= i)); i++) {
        struc_jeuJr.ttint_grille[struc_case.int_ligne+i][struc_case.int_colonne] = -3;
        if ((struc_case.int_colonne+1) < struc_jeuJr.int_taille) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne-i][struc_case.int_colonne+1] = -2;
        }
        if (0 <= (struc_case.int_colonne-1)) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne-i][struc_case.int_colonne-1] = -2;
        }
    }
    for (j = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne+j] == -1) && (j < struc_jeuJr.int_taille)); j++) {
        struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne+j] = -3;
        if ((struc_case.int_ligne+1) < struc_jeuJr.int_taille) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne+1][struc_case.int_colonne+j] = -2;
        }
        if (0 <= (struc_case.int_ligne-1)) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne-1][struc_case.int_colonne+j] = -2;
        }
    }
    for (j = 0; ((struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne-j] == -1) && (0 <= j)); j++) {
        struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne-j] = -3;
        if ((struc_case.int_ligne+1) < struc_jeuJr.int_taille) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne+1][struc_case.int_colonne-j] = -2;
        }
        if (0 <= (struc_case.int_ligne-1)) {
            struc_jeuJr.ttint_grille[struc_case.int_ligne-1][struc_case.int_colonne-j] = -2;
        }
    }
    return struc_jeuJr;
}