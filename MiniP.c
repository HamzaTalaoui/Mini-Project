#include <stdio.h> 
#include <string.h>

int main() {
    char titres[100][100];
    char auteur[100][50];
    char titre_Recherche[100];
    float prix[100];
    int quantites[100];
    int nombrelivre = 0;
    int i, j, choix, nvquantite;
    float prix;

    do {
        printf("\nSysteme de Gestion de Stock dans une Librairie\n");
        printf("1/ Ajouter un livre au stock.\n");
        printf("2/ Afficher tous les livres disponibles.\n");
        printf("3/ Rechercher un livre par son titre.\n");
        printf("4/ Mettre a jour la quantite d'un livre.\n");
        printf("5/ Supprimer un livre du stock.\n");
        printf("6/ Afficher le nombre total de livres en stock.\n");
        printf("7/ Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:  
                if (nombrelivre >= 100) {
                    printf("Le stock est plein !!\n");
                    break;
                }
                printf("Titre du livre: ");
                getchar();
                fgets(titres[nombrelivre], 100, stdin);
                titres[nombrelivre][strcspn(titres[nombrelivre], "\n")] = '\0';

                printf("Auteur du livre: ");
                fgets(auteur[nombrelivre], 100, stdin);
                auteur[nombrelivre][strcspn(auteur[nombrelivre], "\n")] = '\0';

                printf("Prix du livre: ");
                scanf("%f", &prix[nombrelivre]);

                printf("Quantite en stock: ");
                scanf("%d", &quantites[nombrelivre]);

                nombrelivre++;
                printf("Livre ajoute.\n");
                break;

            case 2:  
                if (nombrelivre == 0) {
                    printf("Aucun livre en stock.\n");
                    break;
                }
                for (i = 0; i < nombrelivre; i++) {
                    printf("\nLivre %d:\n", i + 1);
                    printf("Titre: %s\n", titres[i]);
                    printf("Auteur: %s\n", auteur[i]);
                    printf("Prix: %.2f\n", prix[i]);
                    printf("Quantite en stock: %d\n", quantites[i]);
                }
                break;

            case 3: 
                if (nombrelivre == 0) {
                    printf("Stock est vide !!\n");
                    break;
                }
                printf("Entrer le titre du livre a rechercher: ");
                getchar();
                fgets(titRecherche, 100, stdin);
                titRecherche[strcspn(titRecherche, "\n")] = '\0';

                int livreT = 0;
                for (i = 0; i < nombrelivre; i++) {
                    if (strcmp(titres[i], titRecherche) == 0) {
                        printf("\nLivre trouve:\n");
                        printf("Titre: %s\n", titres[i]);
                        printf("Auteur: %s\n", auteur[i]);
                        printf("Prix: %.2f\n", prix[i]);
                        printf("Quantite en stock: %d\n", quantites[i]);
                        livreT = 1;
                        break;
                    }
                }
                if (livreT == 0) {
                    printf("Livre non trouve !!\n");
                }
                break;

            case 4:  
                if (nombrelivre == 0) {
                    printf("Stock est vide !!\n");
                    break;
                }
                printf("Entrer le titre du livre a mettre a jour: ");
                getchar();
                fgets(titRecherche, 100, stdin);
                titRecherche[strcspn(titRecherche, "\n")] = '\0';

                livreT = 0;
                for (i = 0; i < nombrelivre; i++) {
                    if (strcmp(titres[i], titRecherche) == 0) {
                        printf("Entrer la nouvelle quantite: ");
                        scanf("%d", &nvquantite);
                        quantites[i] = nvquantite;
                        printf("Quantite mise a jour.\n");
                        livreT = 1;
                        break;
                    }
                }
                if (livreT == 0) {
                    printf("Livre non trouve !!\n");
                }
                break;

            case 5:  
                if (nombrelivre == 0) {
                    printf("Stock est vide !!\n");
                    break;
                }
                printf("Entrer le titre du livre a supprimer: ");
                getchar();
                fgets(titRecherche, 100, stdin);
                titRecherche[strcspn(titRecherche, "\n")] = '\0';

                livreT = 0;
                for (i = 0; i < nombrelivre; i++) {
                    if (strcmp(titres[i], titRecherche) == 0) {
                        for (j = i; j < nombrelivre - 1; j++) {
                            strcpy(titres[j], titres[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantites[j] = quantites[j + 1];
                        }
                        nombrelivre--;
                        printf("Livre supprime.\n");
                        livreT = 1;
                        break;
                    }
                }
                if (livreT == 0) {
                    printf("Livre non trouve !!\n");
                }
                break;

            case 6:  
                if (nombrelivre == 0) {
                    printf("Stock est vide !!\n");
                    break;
                }
                int totalStock = 0;
                for (i = 0; i < nombrelivre; i++) {
                    totalStock += quantites[i];
                }
                printf("Le total du stock est: %d\n", totalStock);
                break;

            case 7:  
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Choix invalide !!\n");
        }
    } while (choix != 7);

    return 0;
}