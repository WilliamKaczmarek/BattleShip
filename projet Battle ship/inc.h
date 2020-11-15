/*
 * \file nnc.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  Structure de notre programmevoisinnage d'une case
 *  Fichier header
 */
#ifndef __INC_H_
#define __INC_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#include "saisieentier.h"
#include "voisin.h"

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ" //constante alphabet
#define EAU 2
#define BATEAU 1
#define TOUCHE -1
#define PLOUF -2
#define COULE -3

struct coordonnees {    //structure coordonnees
    int  int_ligne; //ligne 
    int  int_colonne; //colonne   
    int int_precedent; // nous permet de savoir si le coup précédent a touché ou est tombé dans l'eau
    int int_card; // le cardinal qui nous donne la direction du coup précédent
};


struct joueur{  //structure joueur
    int int_hum_ia; // nous permet de savoir si le joueur est un humain ou un ordinateur
    int int_taille; // stock la taille de la grille
    int** ttint_grille; // stock la grille du joueur qui est un tableau dynamique
};

struct porteavion{
    int int_npa; //nombre sur le plateau
    int int_tpa; //nombre de cae 
};

struct croiseur{
    int int_nc; //nombre sur le plateau
    int int_tc; //nombre d case 
};

struct sousmarin{
    int int_nsm; //nombre sur le plateau
    int int_tsm; //nombre de case 
};

struct torpilleur{
    int int_nt; //nombre sur le plateau
    int int_tt; //nombre de case 
};

struct bateaux{ //Notre structure bateaux est pour chacun des joueurs sont armada de bateauxs
    struct porteavion pa; //
    struct croiseur c;
    struct sousmarin sm;
    struct torpilleur t;
    int int_taille2; // a enlever si possible
};

struct jeu{ //Structure regroupant toutes les grilles d'une partie
    struct joueur struc_BateauJr1; //Grille avec les bateau du joueur1
    struct joueur struc_BateauJr2; //Gille dvec lesbateauxu joueur2
    struct joueur struc_JeuJr1; //grille visible pour l'adversaire du joueur 1
    struct joueur struc_JeuJr2; //ille isible pr 'rsaire joueur 12
};


#endif
