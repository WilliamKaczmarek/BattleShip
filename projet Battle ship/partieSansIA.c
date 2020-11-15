/*
 * \file partieSansIA.c
 * \author Agnes BLANCHET <blanchetag@eisti.eu> 
 * \author Julien RICHARD <richardjul@eisti.eu> 
 * \author William KACZMAREK <kaczmarekw@eisti.eu>
 * \date 8 Decembre 2019
 * \brief Projet programmation en C
 *  Bataille navale
 *  Fonctions effectuer seulement par un utilisateur
 */
 #include"partieSansIA.h"



struct coordonnees choixCaseHum(struct joueur struc_jr) {
struct coordonnees struc_case;
char str_ligne;
int int_verif, int_verif2 = 0, int_tampon;
struc_case.int_ligne = -1;

while (int_verif2 == 0) {
    int_tampon = -1;
    int_verif = 0;
    struc_case.int_colonne = -1;
    printf("Ligne (lettre entre A et %c) : ",ALPHABET[struc_jr.int_taille-1]);
    while ((int_verif == 0) || (int_tampon < 0) || (struc_jr.int_taille <= int_tampon)) {
        int_verif = scanf("%s", &str_ligne);
        str_ligne = toupper(str_ligne); // transforme une minuscule en majuscule
        int_tampon = strlen(ALPHABET) - strlen(strchr(ALPHABET,str_ligne));
    }
    int_verif = 0;
    printf("Colonne (nombre) : ");
    while ((struc_case.int_colonne < 0) || (struc_jr.int_taille <= struc_case.int_colonne)) {
        struc_case.int_colonne = saisieEntier()-1;
    }
    struc_case.int_ligne = int_tampon;

	if (struc_jr.ttint_grille[struc_case.int_ligne][struc_case.int_colonne] == 2) {
   		int_verif2 = 1;
    }
}
return(struc_case);
}
