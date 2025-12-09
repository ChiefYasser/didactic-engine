/* hadi implemetation dyal biblio dyalna operation.h donc chno had les fnct kifach ki khdmo */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "operations.h"

void filtrer_mots_interdits(char fichier_histoire[50], char fichier_interdit[50]) {
    /* first test dyal file o overture */
FILE *h = fopen(fichier_histoire, "r");  // ouvrir le fichier histoire
FILE *i = fopen(fichier_interdit, "r");  // ouvrir le fichier interdit
 /* i pointe 3la fichier interdit en mode read */
 /* h ela histoir file mode read*/
    if (h == NULL || i == NULL) {
        printf("Erreur d'ouverture des fichiers.\n");
        return;
    } /*  Gestion des erreurs */

    char interdits[200][30];
    int nb_interdits = 0;
    /* lire les mots interdits */
    while (fscanf(i, "%s", interdits[nb_interdits]) != EOF)
        nb_interdits++;

    fclose(i);

    FILE *t = fopen("temp.txt", "w");/* fichier temporaire ghan stockiw fih les mots jdad bla les mots interdies*/
    if (!t) { /*  Gestion des erreurs */
        printf("Erreur : impossible de créer temp.txt\n");
        fclose(h);
        return;
    }

    char mot[50];
    while (fscanf(h, "%s", mot) != EOF) {
        int interdit = 0;

        for (int i = 0; i < nb_interdits; i++) {
            if (strcmp(mot, interdits[i]) == 0) {
                interdit = 1;
                break;
            }
        }

        if (!interdit)
            fprintf(t, "%s ", mot);
    }

    fclose(h);
    fclose(t);

    remove(fichier_histoire);
    rename("temp.txt", fichier_histoire);

    printf("filtration complet .\n");
   
}


void supprimer_lignes_vides(char nom_fichier[50]) {
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erreur de creation du fichier temporaire.\n");
        fclose(f);
        return;
    }

    char ligne[256]; /* m3loma jdida 3liya ligne fiha 256 carracter*/
    while (fgets(ligne, sizeof(ligne), f)) {
        if (strcmp(ligne, "\n") != 0) { // Vérifie si la ligne n'est pas vide
            fputs(ligne, temp);
        }
    }

    fclose(f);
    fclose(temp);

    remove(nom_fichier);
    rename("temp.txt", nom_fichier);

    printf("No more blank lignes .\n");
}


void trier_lignes(char nom_fichier[50]) { /* ghadi ndiro strcmp algotithm howa ghanakhdmo awl carracter o akhir wahed o ghadi nstockihom fhwahed variable 
    had variable hta hiya ghadi tcompara bach nzido nt2kdo o sf ghankbto lfichier dyalna nsit 3la smit algorithm wach bubble sort idk hta t9lbi rask */
     FILE *fin = fopen(nom_fichier, "r");
    if (!fin) {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return;
    }

    char lignes[500][300];
    int nb = 0;

    while (fgets(lignes[nb], sizeof(lignes[nb]), fin))
        nb++;

    fclose(fin);

    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (strcmp(lignes[i], lignes[j]) > 0) {
                char temp[300];
                strcpy(temp, lignes[i]);
                strcpy(lignes[i], lignes[j]);
                strcpy(lignes[j], temp);
            }
        }
    }

    FILE *fout = fopen(nom_fichier, "w");
    for (int i = 0; i < nb; i++)
        fputs(lignes[i], fout);

    fclose(fout);

    printf("✔ Lignes triées.\n");
}


