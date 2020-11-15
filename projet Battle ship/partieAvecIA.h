/*
 * \file partieAvecIA.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Fonctions effectuer seulement par un utilisateur
 *  Fichier header
 */#ifndef __PARITEAVECIA_H_
#define __PARITEAVECIA_H_


#include "grille.h"

/*
 * \fct struct coordonnees partieavecIA(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case)
 * \brief effectue la saisie de la case a jouer
 * \param struct joueur struc_jeuIA : grille de jeu de le l'IA
 * \param struct joueur struc_batAdv : grille de bateaux de son adversaire
 * \param struct coordonnees struc_case : coordonnees de la case tire
 * \return struct coordonnees : structure avec les coordonnees de la case saisie
 */
struct coordonnees partieavecIA(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case);

/*
 * \fct struct coordonnees choixCaseIA(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case)
 * \brief effectue la saisie de la case a jouer aleatoirement 
 * \param struct joueur struc_jeuIA : grille de jeu de le l'IA
 * \param struct joueur struc_batAdv : grille de bateaux de son adversaire
 * \param struct coordonnees struc_case : coordonnees de la case tire
 * \return struct coordonnees : structure avec les coordonnees de la case saisie
 */
struct coordonnees choixCaseIA(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case);

/*
 * \fct struct coordonnees swi(int int_choix, struct coordonnees struc_kase)
 * \brief choisi une case autour de la case precedente, si celle-ci avait touche un bateau
 * \param int int_choix : case choisi par l'IA
  * \param struct coordonnees struc_kase : case precedente
 * \return struct coordonnees : structure avec les coordonnees de la case saisie
 */
struct coordonnees swi(int int_choix, struct coordonnees struc_kase);

/*
 * \fct struct coordonnees choixCaseIA1(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case)
 * \brief choisi une case autour de la case precedente, si celle-ci avait touche un bateaucelon l'orientation de la case precedente
  * \param struct joueur struc_jeuIA : grille de jeu de le l'IA
 * \param struct joueur struc_batAdv : grille de bateaux de son adversaire
 * \param struct coordonnees struc_case : coordonnees de la case tire
 * \return struct coordonnees : structure avec les coordonnees de la case saisie
 */
struct coordonnees choixCaseIA1(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case);

/*
 * \fct struct coordonnees choixCaseIA2(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case)
 * \brief choisi une case dans l'axe des cases precedentes, en fin
  * \param struct joueur struc_jeuIA : grille de jeu de le l'IA
 * \param struct joueur struc_batAdv : grille de bateaux de son adversaire
 * \param struct coordonnees struc_case : coordonnees de la case tire
 * \return struct coordonnees : structure avec les coordonnees de la case saisie
 */
struct coordonnees choixCaseIA2(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case);

/*
 * \fct struct coordonnees choixCaseIA3(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case)
 * \brief choisi une case dans l'axe des cases precedentes, en debut
  * \param struct joueur struc_jeuIA : grille de jeu de le l'IA
 * \param struct joueur struc_batAdv : grille de bateaux de son adversaire
 * \param struct coordonnees struc_case : coordonnees de la case tire
 * \return struct coordonnees : structure avec les coordonnees de la case saisie
 */
struct coordonnees choixCaseIA3(struct joueur struc_jeuIA, struct joueur struc_batAdv, struct coordonnees struc_case);


#endif