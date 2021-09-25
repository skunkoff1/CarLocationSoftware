#include <stdlib.h>
#include <stdio.h>
#include "fichier_save.h"

/*----------------------------------------------------------------*/

Voitures* load_voitures (char* fichier, int* ptr_nb_voitures)
{
    int nb_voitures;

    FILE* in = fopen(fichier,"r");
    fscanf(in,"%d\n",&nb_voitures);

    *ptr_nb_voitures = nb_voitures;

    Voitures* voitures = (Voitures*)malloc(nb_voitures*sizeof(Voitures));

    for(int i=0;i<nb_voitures;i++)
        fscanf(in,"%d : %s : %s : %s : %s : %d", &voitures[i].num,&voitures[i].marque,&voitures[i].modele,&voitures[i].immatriculation,&voitures[i].kilometrage,&voitures[i].dispo);
    fclose(in);
    return voitures;
}

/*-------------------------------------------------------------------------*/

void saveParc(Voitures* voitures, int n, char* fichier)
{
    FILE* out = fopen(fichier, "w");
    fprintf(out,"%d\n",n);
    for (int i=0; i<n; i++)
    {

        fprintf(out, "%d : %s : %s : %s : %s : %d\n", (voitures+i)->num,(voitures+i)->marque, (voitures+i)->modele, (voitures+i)->immatriculation, (voitures+i)->kilometrage,(voitures+i)->dispo);
    }
    fclose(out);
}

/*--------------------------------------------------------------------------*/

Clients* load_clients (char* fichier, int* ptr_nb_clients)
{
    int nb_clients;

    FILE* in = fopen(fichier,"r");
    fscanf(in, "%d\n",&nb_clients);

    *ptr_nb_clients = nb_clients;

    Clients* clients = (Clients*)malloc(nb_clients*sizeof(Clients));

    for(int i = 0; i < nb_clients; i++)
    {
        fscanf(in, "%d : %s : %s : %s : %s : %s\n", &clients[i].num, &clients[i].nom, clients[i].prenom, &clients[i].marque, &clients[i].modele, &clients[i].immatriculation);
    }
    fclose(in);
    return clients;
}

/*-------------------------------------------------------------------------*/

void saveClients(Clients* clients, int n, char* fichier)
{
    FILE* out = fopen(fichier, "w");
    fprintf(out,"%d\n",n);
    for (int i=0; i<n; i++)
    {

        fprintf(out, "%d : %s : %s : %s : %s : %s\n", (clients+i)->num,(clients+i)->nom, (clients+i)->prenom, (clients+i)->marque, (clients+i)->modele, (clients+i)->immatriculation);
    }
    fclose(out);
}

/*--------------------------------------------------------------------------*/
