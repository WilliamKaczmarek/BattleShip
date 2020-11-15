/*
 * \file partie.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Fonctions pour l'execution d'une partie avec et sans IA
 *  Fichier header
 */

#ifndef __PARITE_H_
#define __PARITE_H_

#include "partieSansIA.h"
#include "partieAvecIA.h"
#include "niveaudejeu.h"


struct joueur placeBat(struct joueur struc_batJr, int int_lgBat, int int_orientation, struct coordonnees struc_case);
struct joueur choixPlacemtBat(struct joueur struc_batJr, int int_lgBat);
struct joueur initPJeu(struct joueur struc_batJr, struct bateaux struc_BB);
struct joueur coupDeCanon(struct joueur struc_batJr, struct joueur struc_jeuJr, struct joueur struc_batAdv, int int_humIA);
void Partie(struct jeu plateau,struct bateaux struc_BB);


#endif