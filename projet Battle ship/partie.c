/*
 * \file partie.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Fonctions pour l'execution d'une partie avec et sans IA
 */

#include"partie.h"




struct joueur placeBat(struct joueur struc_batJr, int int_lgBat, int int_orientation, struct coordonnees struc_case) {
int int_j;
//ajoute le bateau a la grille
switch (int_orientation) {
    case 1 :
        for (int_j = struc_case.int_ligne; int_j < (struc_case.int_ligne + int_lgBat); int_j++) {
            struc_batJr.ttint_grille[int_j][struc_case.int_colonne] = 1;
        }
    break;
    case 2 :
        for (int_j = struc_case.int_colonne; int_j < (struc_case.int_colonne + int_lgBat); int_j++) {
            struc_batJr.ttint_grille[struc_case.int_ligne][int_j] = 1;
        }
    break;
    default :
        printf("ERREUR\n");
    break;

}
//afficher grille
if (struc_batJr.int_hum_ia == 1)
{
    afficherGrille(struc_batJr.ttint_grille,struc_batJr.int_taille);
}

return(struc_batJr);
}


struct joueur choixPlacemtBat(struct joueur struc_batJr, int int_lgBat) {
struct coordonnees struc_case;
char str_colonne;
int int_j, int_verif = 0;
int int_orientation, int_voisin;

while (int_verif != 1) {  //tant que les coordonner ne sont pas valides recommence
    struc_case.int_ligne = -1;
    struc_case.int_colonne = -1;
    int_orientation = 0;
    switch(struc_batJr.int_hum_ia) {
        case 1 :
            printf("Placement : 1 _ Vertical  2 _ Horizontal\n");
            while ((int_orientation != 1) && (int_orientation != 2)) {
                int_orientation = saisieEntier();
            }
            printf("Coordonnees de la premiere case\n");
            struc_case = choixCaseHum(struc_batJr);
        break;
        case 2 :
            int_orientation = (rand()%2)+1;
            struc_case = choixCaseIA(struc_batJr,struc_batJr,struc_case);
        break;
        default :
            printf("ERREUR\n");
        break;
    }

    int_voisin = 0;
    switch (int_orientation) {
        case 1 :
            for (int_j = struc_case.int_ligne; (int_j < (struc_case.int_ligne + int_lgBat)) && (int_voisin == 0) && (int_j < struc_batJr.int_taille); int_j++) {
                int_voisin = compteCelluleVoisinage(struc_batJr.ttint_grille,struc_batJr.int_taille,int_j,struc_case.int_colonne);
            }
        break;
        case 2 :
            for (int_j = struc_case.int_colonne; (int_j < (struc_case.int_colonne + int_lgBat)) && (int_voisin == 0) && (int_j < struc_batJr.int_taille); int_j++) {
                int_voisin = compteCelluleVoisinage(struc_batJr.ttint_grille,struc_batJr.int_taille,struc_case.int_ligne,int_j);
            }
        break;
        default :
            printf("ERREUR\n");
        break;
    }
    if (((int_j == struc_case.int_colonne + int_lgBat) || (int_j == struc_case.int_ligne + int_lgBat)) && (int_voisin == 0)) {
        int_verif = 1;
    }else{
        if (struc_batJr.int_hum_ia == 1) {
            printf("Erreur dans le placement du bateaux ! Il ne peux pas etre positionner comme voulu (soit en dehors du plateau, soit retourner voir les regles bande de nul !\n");
        }
    }
}
struc_batJr = placeBat(struc_batJr,int_lgBat,int_orientation,struc_case);
return(struc_batJr);
}


struct joueur initPJeu(struct joueur struc_batJr, struct bateaux struc_BB) {
int int_i;
if (struc_batJr.int_hum_ia == 1) {
	printf("Initialisation du plateau de %");
	printf("\nBateau de type T%i \n", struc_BB.pa.int_tpa);
	for (int_i = 1; int_i <= struc_BB.pa.int_npa; int_i++) {
	    printf("Bateau numero %i\n",int_i);
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.pa.int_tpa);
	}
	printf("\n\nBateau de type T%i \n", struc_BB.c.int_tc);
	for (int_i = 1; int_i <= struc_BB.c.int_nc; int_i++) {
    	printf("Bateau numero %i\n",int_i);
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.c.int_tc);
	}
	printf("\n\nBateau de type T%i \n", struc_BB.sm.int_tsm);
	for (int_i = 1; int_i <= struc_BB.sm.int_nsm; int_i++) {
    	printf("Bateau numero %i\n",int_i);
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.sm.int_tsm);
	}
	printf("\n\nBateau de type T%i \n", struc_BB.t.int_tt);
	for (int_i = 1; int_i <= struc_BB.t.int_nt; int_i++) {
    	printf("Bateau numero %i\n",int_i);
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.t.int_tt);
	}
}else{
	for (int_i = 1; int_i <= struc_BB.pa.int_npa; int_i++) {
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.pa.int_tpa);
	}
	for (int_i = 1; int_i <= struc_BB.c.int_nc; int_i++) {
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.c.int_tc);
	}
	for (int_i = 1; int_i <= struc_BB.sm.int_nsm; int_i++) {
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.sm.int_tsm);
	}
	for (int_i = 1; int_i <= struc_BB.t.int_nt; int_i++) {
    	struc_batJr = choixPlacemtBat(struc_batJr,struc_BB.t.int_tt);
	}
}
printf("\e[1;1H\e[2J"); //efface le terminal avant l'affichage
return(struc_batJr);
}


struct joueur coupDeCanon(struct joueur struc_batJr, struct joueur struc_jeuJr, struct joueur struc_batAdv, int int_humIA) {

struct coordonnees struc_case;
int int_verif = 0, int_batCoule = 0;

    if(int_humIA == 1) {
    	afficherGrille(struc_batJr.ttint_grille,struc_batJr.int_taille);
    	afficherGrille(struc_jeuJr.ttint_grille,struc_jeuJr.int_taille);
    	printf("Coordonnees de la case visee\n");
    	struc_case = choixCaseHum(struc_jeuJr);
    }
    if (int_humIA == 2)
    {
		struc_case = partieavecIA(struc_jeuJr, struc_batAdv, struc_case);
    }
    if (struc_batAdv.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 1) {
    	struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] = -1;
    	printf("TOUCHE !!\n");
    	int_batCoule = Coule(struc_jeuJr,struc_batAdv,struc_case);
        if (int_batCoule == 3) {
    		printf("COULE !\n");
    		struc_jeuJr = placementCouloire(struc_jeuJr,struc_case);
    	}
    }else{
    	struc_jeuJr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] = -2;
    	printf("PLOUF !\n");
    }
    return(struc_jeuJr);
}




void Partie(struct jeu plateau,struct bateaux struc_BB) {
int int_avancement = 0, int_joueur, int_tour = 0;
char str_nike;

afficherChangementJr(plateau,int_tour+1);
afficherGrille(plateau.struc_BateauJr1.ttint_grille,plateau.struc_BateauJr1.int_taille);
plateau.struc_BateauJr1 = initPJeu(plateau.struc_BateauJr1,struc_BB);


if (plateau.struc_BateauJr2.int_hum_ia == 1) {
    afficherChangementJr(plateau,int_tour+1);
    afficherGrille(plateau.struc_BateauJr2.ttint_grille,plateau.struc_BateauJr2.int_taille);
}
plateau.struc_BateauJr2 = initPJeu(plateau.struc_BateauJr2,struc_BB);

printf("DEBUT du la bataille qui appose 1 a 2\n");
sleep(2);
while (int_avancement == 0) {
	if ((plateau.struc_BateauJr2.int_hum_ia == 1) || (int_tour == 0)) {
       afficherChangementJr(plateau,int_joueur);
    }
    int_joueur = ((int_tour)%2)+1;
	switch (int_joueur) {
		case 1 :
			plateau.struc_JeuJr1 = coupDeCanon(plateau.struc_BateauJr1,plateau.struc_JeuJr1,plateau.struc_BateauJr2, plateau.struc_JeuJr2.int_hum_ia);
			int_avancement = aGagne(plateau.struc_JeuJr1,plateau.struc_BateauJr2);
		break;
		case 2 :
			plateau.struc_JeuJr2 = coupDeCanon(plateau.struc_BateauJr2,plateau.struc_JeuJr2,plateau.struc_BateauJr1, plateau.struc_JeuJr2.int_hum_ia);
            int_avancement = aGagne(plateau.struc_JeuJr2,plateau.struc_BateauJr1);
		break;
		default :
			printf("ERREUR\n");
		break;
	}	
	int_tour++;
	
	printf("ENTRER pour continuer\n");
	
};
afficherGagnant(plateau,int_joueur);
}