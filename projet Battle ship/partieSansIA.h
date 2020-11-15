/*
 * \file partieSansIA.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Fonctions effectuer seulement par un utilisateur
 *  Fichier header
 */

#ifndef __PARITESANSIA_H_
#define __PARITESANSIA_H_
#include "grille.h"

/*
 * \fct struct coordonnees choixCaseHum(struct joueur struc_jr)
 * \brief effectue la saisie de la case a jouer
 * \param struct joueur struc_jr : grille de jeu du joueur
 * \return struct coordonnees : structure avec les coordonnees de la case saisie
 */
 
struct coordonnees choixCaseHum(struct joueur struc_jr);
#endif
