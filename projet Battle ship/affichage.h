/*
 * \file affichage.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  affichage des grilles
 *  Fichier header
 */

#ifndef __AFFICHAGE_H_
#define __AFFICHAGE_H_

 /* Inclusion des .h */
#include "inc.h"

/*
 * \prcd void afficherGrille(int** ttint_dyn, int int_t);
 * \prcd void afficherChangementJr(struct jeu plateau, int int_joueur);
 * \prcd void afficherGagnant(struct jeu plateau, int int_joueur);
 * \brief  affiche les differentes grilles des joueurs
 * \param int** ttint_dyn : pointeur de pointeur d'integer (matrice)
 * \param int int_t :   integer (dimensions de la grille)
 * \param struct jeu plateau : jeu avec les diffentes grilles
 * \param int int_joueur : numero du joueur
 * \return  void :
 */

void afficherGrille(int** ttint_dyn, int int_t);

void afficherChangementJr(struct jeu plateau, int int_joueur);
void afficherGagnant(struct jeu plateau, int int_joueur);



#endif
