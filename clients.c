#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clients.h"
#include "parc_voitures.h"

/*-----------------------FONCTION EMPRUNT VOITURES-----------------------------------------------------------*/

void emprunterVoitures (Clients* ptr_clients, Voitures* voitures, int nb_voitures, int nb_clients)
{
    int chx_voiture = 0;
    int chx_client = 0;

    afficherClients (ptr_clients, nb_clients);

    do
    {
        printf("Choisir client (entrez numero client):\n");
        scanf("%d",&chx_client);
        fflush(stdin);

    }while(chx_client<1 || chx_client>nb_clients);

    if(strcmp((ptr_clients+chx_client-1)->marque, "NULL")!=0)
    {
        printf("vous avez deja une voiture en cours d'emprunt\n");
    }
    else
    {
        printf("\nListe de voitures disponibles :");
        afficherParcDispo(voitures, nb_voitures);

        printf("quelle voiture souhaitez vous louer ? (entrez numero voiture)\n");
        scanf("%d", &chx_voiture);
        fflush(stdin);

        (voitures+chx_voiture-1)->dispo = 0;

        strcpy((ptr_clients+chx_client-1)->marque ,(voitures+chx_voiture-1)->marque);
        strcpy((ptr_clients+chx_client-1)->modele ,(voitures+chx_voiture-1)->modele);
        strcpy((ptr_clients+chx_client-1)->immatriculation ,(voitures+chx_voiture-1)->immatriculation);

        printf("%s %s a loue %s %s",(ptr_clients+chx_client-1)->nom, (ptr_clients+chx_client-1)->prenom,(ptr_clients+chx_client-1)->marque,(ptr_clients+chx_client-1)->modele );
    }


}

/*----------------------FONCTION AJOUTER CLIENT(S) A LA LISTE------------------------------*/

Clients* ajouterClients (Clients* clients, int* ptr_nb_clients)
{
    int nb_clients_ajout;
    int nb_clients_presents = *ptr_nb_clients;
    int taille_nom;

    do
    {

        printf("choisir nombre de client(s) a ajouter:");
        scanf("%d",&nb_clients_ajout);
        fflush(stdin);

    }while(nb_clients_ajout<0 || nb_clients_ajout>100);

    *ptr_nb_clients = nb_clients_ajout + nb_clients_presents;

    clients = (Clients*) realloc(clients, (nb_clients_ajout+nb_clients_presents) * sizeof(Clients));

    for(int i=nb_clients_presents; i<(nb_clients_ajout+nb_clients_presents); i++)
    {
        (clients+i)->num = i+1;
        printf("Clients %d",i+1);

        printf("\nNom :");
        gets((clients+i)->nom);
        fflush(stdin);
        taille_nom = strlen((clients+i)->nom);
        (clients+i)->nom[taille_nom]='\0';

        printf("Prenom :");
        gets((clients+i)->prenom);
        fflush(stdin);
        taille_nom = strlen((clients+i)->prenom);
        (clients+i)->prenom[taille_nom]='\0';

        strcpy((clients+i)->marque,"NULL");
        strcpy((clients+i)->modele,"NULL");
        strcpy((clients+i)->immatriculation,"NULL");

    }

    return clients;
}

/*------------------------FONCTION RESTITUER UNE VOITURE--------------------*/

void restituerVoitures (Clients* ptr_clients, Voitures* voitures, int nb_voitures, int nb_clients)
{
    int chx_client = 0;
    int kilometrage_apres;
    int kilometrage_avant;
    int kilometrage_ok = 0;

    afficherClients (ptr_clients, nb_clients);

    printf("\nChoisir client (entrez numero client):\n");
    scanf("%d",&chx_client);
    fflush(stdin);

    if(strcmp((ptr_clients+chx_client-1)->marque, "NULL")==0)
    {
        printf("Vous n'avez pas de voiture a restituer\n");
    }
    else
    {
        for (int i = 0; i<nb_voitures; i++)
        {
            if(strcmp ((ptr_clients+chx_client-1)->immatriculation,(voitures+i)->immatriculation)==0)
            {
                strcpy((ptr_clients+chx_client-1)->marque,"NULL");
                strcpy((ptr_clients+chx_client-1)->modele,"NULL");
                strcpy((ptr_clients+chx_client-1)->immatriculation,"NULL");
                (voitures+i)->dispo=1;
                kilometrage_avant = atoi ((voitures+i)->kilometrage);

                do{
                printf("indiquez kilometrage actuel de la voiture :\n");
                scanf("%d",&kilometrage_apres);
                fflush(stdin);

                if(kilometrage_apres >= kilometrage_avant)
                {
                    kilometrage_avant = kilometrage_apres;
                    sprintf((voitures+i)->kilometrage, "%d", kilometrage_apres);
                    kilometrage_ok=1;
                }
                else
                {
                    printf("le kilometrage actuel ne peut etre inferieur au kilometrage avant location\n");
                }
                }while(kilometrage_ok!=1);
            }
        }
    }
}

/*------------------------FONCTION AFFICHAGE LISTE CLIENTS------------------------------------*/

void afficherClients(Clients* clients, int nb_clients)
{
    for (int i=0; i < nb_clients; i++)
    {
        printf("\nClient %d",clients[i].num);
        printf("\n%s %s\n",clients[i].nom,clients[i].prenom);

        if (strcmp(clients[i].immatriculation , "NULL") == 0)
        {
            printf("Pas de voiture louee\n");
        }
        else
        {
            printf("Voiture louee : %s %s\n", clients[i].marque, clients[i].modele );
        }
    }
}
