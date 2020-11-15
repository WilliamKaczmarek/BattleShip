/*
 * \file grille.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  initialisation des grilles de jeu
 */

 #include "grille.h"

/* -------------------- Créer une grille carré de taille paramétrable ---------------------*/
int** creerGrille(int int_t) {
int** ttint_dyn;
	ttint_dyn = malloc(int_t*sizeof(int*)); 
	for (int i = 0; i < int_t; ++i) {
		ttint_dyn[i] = malloc(int_t*sizeof(int)); 
	}
	return ttint_dyn;
}

/* ---------- Initialisation de la grille de base TOUTES les cases sont de l' EAU -------------*/
int** initGrille(int** ttint_dyn, int int_t) {  
	for (int i = 0; i < int_t; ++i) {
		for (int j = 0; j < int_t; ++j) {
			ttint_dyn[i][j] = 2;
		}
	}
	return ttint_dyn;
}


struct jeu initAllPlateau(struct bateaux struc_BB) {
struct jeu plateau;

plateau = humain_ordi();
plateau.struc_BateauJr1.int_taille = struc_BB.int_taille2;
plateau.struc_JeuJr1.int_taille = struc_BB.int_taille2;
plateau.struc_BateauJr2.int_taille = struc_BB.int_taille2;
plateau.struc_JeuJr2.int_taille = struc_BB.int_taille2;

plateau.struc_BateauJr1.ttint_grille = creerGrille(plateau.struc_BateauJr1.int_taille);
plateau.struc_BateauJr1.ttint_grille = initGrille(plateau.struc_BateauJr1.ttint_grille,plateau.struc_BateauJr1.int_taille);
plateau.struc_BateauJr2.ttint_grille = creerGrille(plateau.struc_BateauJr2.int_taille);
plateau.struc_BateauJr2.ttint_grille = initGrille(plateau.struc_BateauJr2.ttint_grille,plateau.struc_BateauJr2.int_taille);
plateau.struc_JeuJr1.ttint_grille = creerGrille(plateau.struc_JeuJr1.int_taille);
plateau.struc_JeuJr1.ttint_grille = initGrille(plateau.struc_JeuJr1.ttint_grille,plateau.struc_JeuJr1.int_taille);
plateau.struc_JeuJr2.ttint_grille = creerGrille(plateau.struc_JeuJr2.int_taille);
plateau.struc_JeuJr2.ttint_grille = initGrille(plateau.struc_JeuJr2.ttint_grille,plateau.struc_JeuJr2.int_taille);
return(plateau);
}
