/*
 * \file partieAvecIA.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Fonctions effectuer seulement par un utilisateur
 *  Fichier header
 */

#include "partieAvecIA.h"


struct coordonnees partieavecIA(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case){
	struct coordonnees struc_kase;
    struc_kase.int_ligne = -1;
	struc_kase.int_colonne = -1;
	struc_kase.int_precedent = -1;
	 switch (struc_case.int_precedent){
	        case 0 :
	            struc_kase = choixCaseIA(struc_jeuIA, struc_batAdv, struc_case);
	        break;
	        case 1 :
	            struc_kase = choixCaseIA1(struc_jeuIA, struc_batAdv, struc_case);
	        break;
	        case 2 :
	            struc_kase = choixCaseIA2(struc_jeuIA, struc_batAdv, struc_case);
	        break;
	        case 3 :
	            struc_kase = choixCaseIA3(struc_jeuIA, struc_batAdv, struc_case);
	        break;
	        default :
	            printf("ERREUR");
	        break;
	    }
	return struc_kase;
}

struct coordonnees choixCaseIA(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case) {
int int_verif = 0;
while (int_verif == 0) {
    struc_case.int_ligne = rand()% struc_jeuIA.int_taille;
    struc_case.int_colonne = rand()% struc_jeuIA.int_taille;
    if (struc_jeuIA.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 2) {
        if (struc_batAdv.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 1)
        {
            struc_case.int_precedent = 1;
        }else{
            struc_case.int_precedent = 0;
        }
        int_verif = 1;
    }
}
return(struc_case);
}

struct coordonnees swi(int int_choix, struct coordonnees struc_kase){
	switch (int_choix){
        case 0 :
            struc_kase.int_ligne = struc_kase.int_ligne - 1;
            struc_kase.int_colonne = struc_kase.int_colonne;
        break;
        case 1 :
            struc_kase.int_ligne = struc_kase.int_ligne;
            struc_kase.int_colonne = struc_kase.int_colonne - 1;
        break;
        case 2 :
            struc_kase.int_ligne = struc_kase.int_ligne + 1;
            struc_kase.int_colonne = struc_kase.int_colonne;
        break;
        case 3 :
            struc_kase.int_ligne = struc_kase.int_ligne;
            struc_kase.int_colonne = struc_kase.int_colonne + 1;
        break;
        default :
            printf("ERREUR");
        break;
    }
    struc_kase.int_card = int_choix;
    return struc_kase;
}


struct coordonnees choixCaseIA1(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case) {
struct coordonnees struc_kase;
int int_verif = 0;
int int_voisin = compteCelluleVoisinage(struc_jeuIA.ttint_grille, struc_jeuIA.int_taille, struc_case.int_ligne, struc_case.int_colonne);
struc_kase.int_ligne = -1;
struc_kase.int_colonne = -1;
struc_kase.int_precedent = -1;

while (int_verif == 0) {

    if ((int_voisin ==0)&&(struc_case.int_card == 4)){
        int int_alea = rand()%4;
        struc_kase = swi(int_alea, struc_kase);
    }

    if (struc_jeuIA.ttint_grille[struc_kase.int_ligne][struc_kase.int_colonne] == 2) {
        if (struc_batAdv.ttint_grille[struc_kase.int_ligne][struc_kase.int_colonne] == 1)
        {
            struc_kase.int_precedent = 2;
        }

        int_verif = 1;
    }
}
return(struc_kase);
}

struct coordonnees choixCaseIA2(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case) {
struct coordonnees struc_kase;
int int_verif = 0;

struc_kase.int_ligne = -1;
struc_kase.int_colonne = -1;
struc_kase.int_precedent = -1;

while (int_verif == 0) {

    if (struc_case.int_precedent == 2){
        struc_kase = swi(struc_case.int_card, struc_kase);
    }

    if (struc_jeuIA.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 2) {
        if (struc_batAdv.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 1)
        {
            struc_kase.int_precedent = 2;
        }else{
            struc_kase.int_precedent = 3;
        }

        int_verif = 1;
    }
}
return(struc_kase);
}

struct coordonnees choixCaseIA3(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case) {
struct coordonnees struc_kase;
int int_verif = 0;

struc_kase.int_ligne = -1;
struc_kase.int_colonne = -1;
struc_kase.int_precedent = -1;

while (int_verif == 0) {

    if (struc_case.int_precedent == 2){
        struc_kase = swi((struc_case.int_card + 2) % 4, struc_kase);
    }

    if (struc_jeuIA.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 2) {
        if (struc_batAdv.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 1)
        {
            struc_kase.int_precedent = 3;
        }else{
            struc_kase.int_precedent = 0;
        }

        int_verif = 1;
    }
}
return(struc_kase);
}
