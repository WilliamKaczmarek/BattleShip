/*
 * \file voisin.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  voisinnage d'une case
 *  Fichier header
 */
 
#ifndef __VOISIN_H_
#define __VOISIN_H_

/*
 * \fct int voisinNord(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct int voisinNordEst(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct int voisinEst(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct voisinSudEst(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct voisinSud(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct voisinSudOuest(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct voisinOuest(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct voisinNordOuest(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \fct compteCelluleVoisinage(int** ttint_dyn, int int_t, int int_l, int int_c);
 * \brief  calcule le nombre de cellule de bateau dans le voisinnage d'une case
 * \param int** ttint_dyn : pointeur de pointeur d'integer (matrice)
 * \param int int_t :   integer (dimensions de la grille)
 * \param int int_l, int int_c : coordonnee de la case
 * \return  int : nombre de cellule dans le voisinnage
 */
 
int voisinNord(int** ttint_dyn, int int_t, int int_l, int int_c);
int voisinNordEst(int** ttint_dyn, int int_t, int int_l, int int_c);
int voisinEst(int** ttint_dyn, int int_t, int int_l, int int_c);
int voisinSudEst(int** ttint_dyn, int int_t, int int_l, int int_c);
int voisinSud(int** ttint_dyn, int int_t, int int_l, int int_c);
int voisinSudOuest(int** ttint_dyn, int int_t, int int_l, int int_c);
int voisinOuest(int** ttint_dyn, int int_t, int int_l, int int_c);
int voisinNordOuest(int** ttint_dyn, int int_t, int int_l, int int_c);

int compteCelluleVoisinage(int** ttint_dyn, int int_t, int int_l, int int_c);

#endif
