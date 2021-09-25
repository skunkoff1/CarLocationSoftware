#ifndef PARC_VOITURES_H_INCLUDED
#define PARC_VOITURES_H_INCLUDED

#define TAILLE_NOM 100
#define TAILLE_IMMAT 20

typedef struct VOITURES
{
    int num;
   char marque[TAILLE_NOM];
   char modele[TAILLE_NOM];
   char immatriculation[TAILLE_IMMAT];
   char kilometrage[TAILLE_NOM];
   int dispo;
}Voitures;

Voitures* ajouterVoiture(Voitures*, int* );

void afficherParc(Voitures* , int);

void afficherParcDispo(Voitures* , int n);

#endif // PARC_VOITURES_H_INCLUDED
