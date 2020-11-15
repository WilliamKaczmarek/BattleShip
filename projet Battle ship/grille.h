/*
 * \file grille.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  initialisation des grilles de jeu
 *  Fichier header
 */
#ifndef __GRILLE_H_
#define __GRILLE_H_

#include "affichage.h"
#include "menuParametres.h"

/*
 * \fct int** creerGrille(int int_t)
 * \brief  creer un tableau dynamique (pointeur de pointeur)
 * \param  int_t : integer (dimension de la grille)
 * \return  pointeur de pointeur d'integer (matrice) initialise par l'utilisateur
 */
int** creerGrille(int int_t);

/*
 * \fct int** initGrille(int** pptr_grille, int int_t)
 * \brief  initialise chaque case de la matrice manuellement par l'utilisateur
 * \param  int_t : integer (dimension de la grille)
 * \param  pptr_grille : pointeur de pointeur d'integer (matrice)
 * \return  pointeur de pointeur d'integer (matrice) initialise par l'utilisateur
 */
int** initGrille(int** ttint_dyn, int int_t);

/*
 * \fct struct jeu initAllPlateau(struct bateaux struc_BB)
 * \brief  initialise les quatres plateaux de jeu
 * \param  int_t : integer (dimension de la grille)
 * \return  struct jeu : regroupe les quatres plateaux de jeu
 */
struct jeu initAllPlateau(struct bateaux struc_BB);


#endif
