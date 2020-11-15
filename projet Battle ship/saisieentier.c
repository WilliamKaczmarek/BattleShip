#include "saisieentier.h"
/*
 * \file saisieentier.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  Permet la saisie d'entier
 */
int saisieEntier(void){
	int int_retour,int_n; //int_retour -> retour des scanf | int_n -> valeur à renvoyer
	float float_n; //float_n -> valeur que l'utilisateur va rentrer
	int_retour = scanf("%f",&float_n); //Rentrée de la valeur de l'utilisateur
	assert(int_retour!=0); //Arrête le programme si la valeur rentrée n'est pas un nombre 
	assert(floor(float_n)==float_n); //Arrête le programme si la valeur rentrée n'est pas un entier
	int_n = floor(float_n); //Transformation d'un réel en entier pour le renvoie de la fonction
	return(int_n); //Renvoie de l'entier correctement entré par l'utilisateur
}