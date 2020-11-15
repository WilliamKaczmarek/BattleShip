/*
 * \file niveaudejeu.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Calcul les niveaux d'avancement de la partie
 *  Fichier header
 */

#ifndef __NIVEAUDEJEU_H_
#define __NIVEAUDEJEU_H_

 /* Inclusion des .h */
#include "inc.h"

/*
 * \fct int aGagne(struct joueur struc_jeuJr, struct joueur struc_batAdv);
 * \brief calcule si la partie est fini
 * \param struct joueur struc_jeuJr : grille avec les bateaux du joueur
 * \param struct joueur struc_batAdv :   grille avec les bateaux de l'adversaire
 * \return int : permet de savoir si une joueur a gagne ou si un bateau est coule
 */
int aGagne(struct joueur struc_jeuJr, struct joueur struc_batAdv);

/*
 * \fct int Coule(struct joueur struc_jeuJr, struct joueur struc_batAdv, struct coordonnees struc_case);
 * \brief calcule si le bateau touche a ete coule
 * \param struct joueur struc_jeuJr : grille avec les bateaux du joueur
 * \param struct joueur struc_batAdv : grille avec les bateaux de l'adversaire
 * \param struct coordonnees struc_case : coordonnee de la case
 * \return int : permet de savoir si une joueur a gagne ou si un bateau est coule
 */
int Coule(struct joueur struc_jeuJr, struct joueur struc_batAdv, struct coordonnees struc_case);

/*
 * \fct struct joueur placementCouloire(struct joueur struc_jeuJr, struct coordonnees struc_case);
 * \brief change le bateau coule et l'eau qui l'entour pour l'affichage
 * \param struct joueur struc_jeuJr : grille avec les bateaux du joueur
 * \param struct coordonnees struc_case : coordonnee de la case
 * \return struct joueur : grille avec les couloir d'eau affiches 
 */
struct joueur placementCouloire(struct joueur struc_jeuJr, struct coordonnees struc_case);

#endif