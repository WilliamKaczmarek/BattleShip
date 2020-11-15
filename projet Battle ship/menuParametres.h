/*
 * \file menuParametres.h
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  Menu du jeu
 *  Fichier header */

#ifndef __MENUPARAMETRES_H_
#define __MENUPARAMETRES_H_


#include "inc.h"	//utiliser nos structure bateaux et joueur


struct jeu humain_ordi(); //Permet le choix entre un adversaire humain ou un ordinateur
struct bateaux param_defaut(struct bateaux struc_BB); //Applique les paramètres par défaut de à la partie
int minitaille(struct bateaux struc_BB); //fonction calculant la taille minimun de la grille selon le nombre et la taille des bateaux
struct bateaux param_perso(struct bateaux struc_BB); //Permet d'appliquer ses paramètres personnalisé s  à la partie
struct bateaux param(); // Demanede à l'utilisateur qu'elle parael paramètre il va apldecider d'appliquer


#endif
