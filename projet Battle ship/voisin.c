/*
 * \file voisin.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief projet1
 *  bataille navale
 *  voisinnage d'une case
 */
 
 /* Inclusion des .h */
 #include "voisin.h"


int voisinNord(int** ttint_dyn, int int_t, int int_l, int int_c) {  // retourne la valeur (0 ou 1) du voisin (la cellule) au nord					
if (int_l == 0) {
	return 0;
}
return (ttint_dyn[int_l-1][int_c]%2);
}

//----------------------------------------------------------------------

int voisinNordEst(int** ttint_dyn, int int_t, int int_l, int int_c) { // retourne la valeur (0 ou 1) du voisin (la cellule) au nord est
if ((int_l == 0) || (int_c == (int_t-1))) {
	return 0;
}
return(ttint_dyn[int_l-1][int_c+1]%2);
}

//----------------------------------------------------------------------

int voisinEst(int** ttint_dyn, int int_t, int int_l, int int_c) { // retourne la valeur (0 ou 1) du voisin (la cellule) à l'est
if (int_c == (int_t-1)) {
	return(0);
}
return(ttint_dyn[int_l][int_c+1]%2);
}

//----------------------------------------------------------------------

int voisinSudEst(int** ttint_dyn, int int_t, int int_l, int int_c) { // retourne la valeur (0 ou 1) du voisin (la cellule) au sud est
if ((int_l == (int_t-1)) || (int_c == (int_t-1))) {
	return(0);
}
return(ttint_dyn[int_l+1][int_c+1]%2);
}

//----------------------------------------------------------------------

int voisinSud(int** ttint_dyn, int int_t, int int_l, int int_c) { // retourne la valeur (0 ou 1) du voisin (la cellule) au sud
if (int_l == (int_t-1)) {
	return(0);
}
return(ttint_dyn[int_l+1][int_c]%2);
}

//----------------------------------------------------------------------

int voisinSudOuest(int** ttint_dyn, int int_t, int int_l, int int_c) { // retourne la valeur (0 ou 1) du voisin (la cellule) au sud ouest
if ((int_l == (int_t-1)) || (int_c == 0)){
	return(0);
}
return(ttint_dyn[int_l+1][int_c-1]%2);
}

//----------------------------------------------------------------------

int voisinOuest(int** ttint_dyn, int int_t, int int_l, int int_c) { // retourne la valeur (0 ou 1) du voisin (la cellule) à l'ouest
if (int_c == 0) {
	return(0);
}
return(ttint_dyn[int_l][int_c-1]%2);
}

//----------------------------------------------------------------------

int voisinNordOuest(int** ttint_dyn, int int_t, int int_l, int int_c) { // retourne la valeur (0 ou 1) du voisin (la cellule) au nord ouest
if ((int_l == 0) || (int_c == 0)) {
	return(0);
}
return(ttint_dyn[int_l-1][int_c-1]%2);
}


//----------------------------------------------------------------------

int compteCelluleVoisinage(int** ttint_dyn, int int_t, int int_l, int int_c){ //somme la valeur de toutes les cellules voisines pour obtenir le nombre de cellule voisines
	int int_compteur = 0;
	int_compteur += voisinNord(ttint_dyn,int_t,int_l,int_c);
	int_compteur += voisinNordEst(ttint_dyn,int_t,int_l,int_c);
	int_compteur += voisinEst(ttint_dyn,int_t,int_l,int_c);
	int_compteur += voisinSudEst(ttint_dyn,int_t,int_l,int_c);
	int_compteur += voisinSud(ttint_dyn,int_t,int_l,int_c);
	int_compteur += voisinSudOuest(ttint_dyn,int_t,int_l,int_c);
	int_compteur += voisinOuest(ttint_dyn,int_t,int_l,int_c);
	int_compteur += voisinNordOuest(ttint_dyn,int_t,int_l,int_c);
	return(int_compteur);
}
