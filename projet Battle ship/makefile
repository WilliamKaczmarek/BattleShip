all : batailleNavale
	rm -rf *.o

batailleNavale : saisieentier.o voisin.o inc.o affichage.o menuParametres.o niveaudejeu.o grille.o partieSansIA.o partieAvecIA.o partie.o batailleNavale.o
	gcc saisieentier.o voisin.o inc.o affichage.o menuParametres.o niveaudejeu.o grille.o partieSansIA.o partieAvecIA.o partie.o batailleNavale.o -o jeu -lm

saisieentier.o : saisieentier.c saisieentier.h
	gcc -c saisieentier.c -o saisieentier.o -lm

voisin.o : voisin.c voisin.h
	gcc -c voisin.c -o voisin.o -lm

inc.o : inc.c inc.h
	gcc -c inc.c -o inc.o -lm

affichage.o : affichage.c affichage.h
	gcc -c affichage.c -o affichage.o -lm

menuParametres.o : menuParametres.c menuParametres.h
	gcc -c menuParametres.c -o menuParametres.o -lm

niveaudejeu.o : niveaudejeu.c niveaudejeu.h
	gcc -c niveaudejeu.c -o niveaudejeu.o -lm

grille.o : grille.c grille.h
	gcc -c grille.c -o grille.o -lm

partieSansIA.o : partieSansIA.c partieSansIA.h
	gcc -c partieSansIA.c -o partieSansIA.o -lm
	
partieAvecIA.o : partieAvecIA.c partieAvecIA.h
	gcc -c partieAvecIA.c -o partieAvecIA.o -lm

partie.o : partie.c partie.h
	gcc -c partie.c -o partie.o -lm
	
batailleNavale.o : batailleNavale.c
	gcc -c batailleNavale.c -o batailleNavale.o -lm
