/*
 * \file menuParametres.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  Menu du jeu
*/

#include "menuParametres.h"


/*-------------Choix adversaire humain ou ordinateur-----------------*/
struct jeu humain_ordi() {
struct jeu plateau;

printf("\e[1;1H\e[2J"); //efface le terminal avant l'affichage
printf("Souhaitez-vous jouer contre un Humain ou un Ordinateur ???\n");
printf("Entrez 1 pour jouer contre un humain\n");
printf("2 pour un Ordinateur\n");

plateau.struc_BateauJr1.int_hum_ia = 1; //le joueur 1 est forcément un humain 
plateau.struc_JeuJr1.int_hum_ia = 1;
int int_tampon = saisieEntier();
plateau.struc_BateauJr2.int_hum_ia = int_tampon;
plateau.struc_JeuJr2.int_hum_ia = plateau.struc_BateauJr2.int_hum_ia;

return(plateau);
}


/*----------Choix des paramètres par defaut--------------- */
struct bateaux param_defaut(struct bateaux struc_BB) {

printf("Vous avez choisi les paramètres par defaut\n");
printf("Chaque joueur possède un porte avion de 6 cases,");
struc_BB.pa.int_npa = 1; //nbr de porte avion
struc_BB.pa.int_tpa = 6; //nbr de cases d un porte avion
printf(" 2 croiseurs de 4 cases,");
struc_BB.c.int_nc = 2; //nbr de croiseurs
struc_BB.c.int_tc = 4; //nbr de cases d un croiseur
printf(" 3 sous-marins de 3 cases");
struc_BB.sm.int_nsm = 3; //nbr de sous-marins
struc_BB.sm.int_tsm = 3; //nbr de cases d un sous-marins
printf("et enfin 4 torpilleurs de 2 cases.\n");
struc_BB.t.int_nt = 4; //nbr de torpilleurs
struc_BB.t.int_tt = 2; //nbr de cases d'un torpilleurs
printf("Vous allez vous affronter sur une grille de 10 par 10\n");
struc_BB.int_taille2 = 10; //taille de la grille du joueur 1
return(struc_BB);
}



int minitaille(struct bateaux struc_BB) {
    int int_t = 0;

    if ((struc_BB.pa.int_tpa != 0 ) &&  (struc_BB.pa.int_npa != 0)){
        int_t = int_t + ((struc_BB.pa.int_tpa * 3 ) + 6) * struc_BB.pa.int_npa;
    }else{
        int_t = int_t;
    }
    
    if ((struc_BB.c.int_tc != 0 ) &&  (struc_BB.c.int_nc != 0)){
        int_t = int_t + ((struc_BB.c.int_tc * 3) + 6 ) * struc_BB.c.int_nc;
    }else{
        int_t = int_t;
    }
    
    if ((struc_BB.sm.int_tsm != 0 ) &&  (struc_BB.sm.int_nsm != 0)){
        int_t = int_t + ((struc_BB.sm.int_tsm * 3) + 6) * struc_BB.sm.int_nsm ;
    }else{
        int_t = int_t;
    }
    
    if ((struc_BB.t.int_tt != 0 ) &&  (struc_BB.t.int_nt != 0)){
        int_t = int_t + ((struc_BB.t.int_tt * 3) + 6) * struc_BB.t.int_nt ;
    }else{
        int_t = int_t;
    }
    
    int_t = (int)(floor(sqrt(int_t)));
    
    return int_t;
    
}



/*----------Choix des paramètres personnalisé TAILLE de la grille et NBR de BATEAU */
struct bateaux param_perso(struct bateaux struc_BB) {
printf("Combien de cases vos porte avion feront ??\n");
struc_BB.pa.int_tpa = saisieEntier(); //nbr de cases d un porte avion
printf("Combien voulez de porte avion dans votre partie ?\n");
struc_BB.pa.int_npa = saisieEntier(); //nbr de porte avion

printf("Combien de cases vos croiseurs feront ??\n");
struc_BB.c.int_tc = saisieEntier(); //nbr de cases d un croiseur
printf("Combien voulez de croiseur dans votre partie ?\n");
struc_BB.c.int_nc = saisieEntier(); //nbr de croiseurs


printf("Combien de cases vos sous-marins feront ??\n");
struc_BB.sm.int_tsm = saisieEntier(); //nbr de cases d un sous-marins
printf("Combien voulez de sous-marins dans votre partie ?\n");
struc_BB.sm.int_nsm = saisieEntier(); //nbr de sous-marins

printf("Combien de cases vos torpilleurs feront ??\n");
struc_BB.t.int_tt = saisieEntier(); //nbr de cases d'un torpilleurs
printf("Combien voulez de torpilleurs dans votre partie ?\n");
struc_BB.t.int_nt = saisieEntier(); //nbr de torpilleurs

printf("Entrez la taille de la grille sur laquelle vous allez vous affronter\n");
printf("ATTENTION RENTRER une taille cohérente avec votre nombre de bateaux et la taille de ceux-ci\n");
struc_BB.int_taille2 = -1;
while ((struc_BB.int_taille2 < 0) && (struc_BB.int_taille2 <= minitaille(struc_BB))) {
    printf("Entrez la taille le grille qui doit etre au minimun = %d \n", minitaille(struc_BB));
    struc_BB.int_taille2 = saisieEntier(); //taille de la grille du joueur 1
}
return(struc_BB);
}


/*-------------Choix des paramètres par defaut ou non-----------------*/
struct bateaux param() {
struct bateaux struc_BB;
int int_temp_param;
    printf("Voulez-vous jouer avec les paramètres par défaut ?\n");
    printf("Entrez 1 pour Jouer avec les paramètres par défaut\n");
    printf("Ou entrez n'importe quel autre chiffre pour personnaliser vos paramètres\n");
int_temp_param = saisieEntier();
if (int_temp_param == 1) {
    struc_BB = param_defaut(struc_BB);
} else {
    struc_BB = param_perso(struc_BB);
} //paramètre personnalisé
return(struc_BB);
}

