#include <stdio.h>
#include "operations.h"

int main() {
    int choix;
    char fichier1[50], fichier2[50];

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Filtrer les mots interdits\n");
        printf("2 - Supprimer les lignes vides\n");
        printf("3 - Trier les lignes du fichier\n");
        printf("4 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Nom du fichier a nettoyer : ");
                scanf("%s", fichier1);
                printf("Nom du fichier des mots interdits : ");
                scanf("%s", fichier2);
                filtrer_mots_interdits(fichier1, fichier2);
                break;

            case 2:
                printf("Nom du fichier : ");
                scanf("%s", fichier1);
                supprimer_lignes_vides(fichier1);
                break;

            case 3:
                printf("Nom du fichier : ");
                scanf("%s", fichier1);
                trier_lignes(fichier1);
                break;

            case 4:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 4);

    return 0;
}
