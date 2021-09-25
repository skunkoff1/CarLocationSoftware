#include <stdio.h>
#include <stdlib.h>
#include "parc_voitures.h"
#include "clients.h"
#include "fichier_save.h"


int main(void)
{

    //Declaration des variables-------------------------------------------

    int chx_menu;

    int nb_voitures;
    int* ptr_nb_voitures;
    ptr_nb_voitures = &nb_voitures;

    int nb_clients;
    int* ptr_nb_clients;
    ptr_nb_clients = &nb_clients;

    char* fichier_parc = "parc.txt";
    char* fichier_clients = "clients.txt";

    // Chargement de l'etat du parc----------------------------------------

    Voitures* ptr_voitures = load_voitures(fichier_parc, ptr_nb_voitures);

    //Chargement liste clients----------------------------------------------

    Clients* ptr_clients = load_clients(fichier_clients, ptr_nb_clients);

    do
    {

    printf("\n\n----------- MENU -----------\n0: Voir liste clients\n1: Ajouter client(s)\n2: Louer une voiture\n3: Retour d'une voiture\n4: Etat du parc de voitures\n5: Ajouter une voiture au parc\n6: Sauvegarder l'etat du programme\n7: Fin du programme\n");
    printf("Entrez votre choix\n");
    scanf("%d", &chx_menu);
    fflush(stdin);

        switch(chx_menu)
        {
            case 0 :
                afficherClients(ptr_clients,nb_clients);
                break;

            case 1 :
                ptr_clients = ajouterClients (ptr_clients, ptr_nb_clients);
                break;

            case 2 :
                emprunterVoitures(ptr_clients, ptr_voitures, nb_voitures, nb_clients);
                break;

            case 3 :
                restituerVoitures (ptr_clients, ptr_voitures,  nb_voitures,  nb_clients);
                break;

            case 4 :
                afficherParc(ptr_voitures, nb_voitures);
                break;

            case 5 :
                ptr_voitures = ajouterVoiture(ptr_voitures, ptr_nb_voitures);
                break;

            case 6 :
                saveClients(ptr_clients,nb_clients,fichier_clients);
                saveParc(ptr_voitures,nb_voitures,fichier_parc);
                printf("liste clients et parc de voitures sauvegarde");
                break;

            case 7 :
                printf("fermeture du programme");
                break;

            default: printf("Choix invalide\n");
        }

    }while(chx_menu!=7);
    return 0;
}
