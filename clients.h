#ifndef CLIENTS_H_INCLUDED
#define CLIENTS_H_INCLUDED
#include "parc_voitures.h"

#define TAILLE_NOM 100
#define TAILLE_IMMAT 20


typedef struct CLIENTS
{
    int num;
    char nom[TAILLE_NOM];
    char prenom[TAILLE_NOM];
    char marque[TAILLE_NOM];
    char modele[TAILLE_NOM];
    char immatriculation[TAILLE_IMMAT];

}Clients;

void emprunterVoitures (Clients* ,  Voitures*, int, int );

Clients* ajouterClients (Clients*, int*);

void afficherClients (Clients*, int);

void restituerVoitures (Clients* , Voitures* , int , int );


#endif // CLIENTS_H_INCLUDED
