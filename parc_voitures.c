#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parc_voitures.h"

/*------------------AFFICHAGE PARC VOITURES------------------------------------------*/

void afficherParc(Voitures* voitures, int nb_voitures)
{
    for(int i=0; i<nb_voitures; i++)
    {
        printf("\nVoitures %d",voitures[i].num);
        printf("\n%s %s",voitures[i].marque,voitures[i].modele);
        printf("\nImmatriculation : %s",(voitures+i)->immatriculation);
        printf("\nKilometrage : %s",(voitures+i)->kilometrage);
        printf("\nDisponibilite :");
        if(voitures[i].dispo==1)
        {
            printf("oui\n");
        }
        else
            {
                printf("non\n");
            }
    }
}

/*---------------------AJOUTER VOITURE(S) AU PARC---------------------------------*/

Voitures* ajouterVoiture(Voitures* voitures, int* ptr_nb_voitures)
{
    int nb_voitures_ajout;
    int nb_voitures_presentes = *ptr_nb_voitures;
    int taille_nom;

    do
    {

        printf("choisir nombre de voiture(s) a ajouter:");
        scanf("%d",&nb_voitures_ajout);
        fflush(stdin);

    }while(nb_voitures_ajout<0 || nb_voitures_ajout>100);

    *ptr_nb_voitures = nb_voitures_ajout + nb_voitures_presentes;

    voitures = (Voitures *) realloc(voitures, (nb_voitures_ajout+nb_voitures_presentes) * sizeof(Voitures));

    for(int i=nb_voitures_presentes; i<(nb_voitures_ajout+nb_voitures_presentes); i++)
    {
       (voitures+i)->num = i+1;
        printf("Voitures %d",i+1);

        printf("\nMarque :");
        gets((voitures+i)->marque);
        fflush(stdin);
        taille_nom = strlen((voitures+i)->marque);
        (voitures+i)->marque[taille_nom]='\0';

        printf("Modele :");
        gets((voitures+i)->modele);
        fflush(stdin);
        taille_nom = strlen((voitures+i)->modele);
        (voitures+i)->modele[taille_nom]='\0';

        printf("Immatriculation :");
        gets((voitures+i)->immatriculation);
        fflush(stdin);
        taille_nom = strlen((voitures+i)->immatriculation);
        (voitures+i)->immatriculation[taille_nom]='\0';

        printf("Kilometrage :");
        gets((voitures+i)->kilometrage);
        fflush(stdin);

        (voitures+i)->dispo=1;

    }

    return voitures;
}

/*------------------------AFFICHER VOITURES DISPONIBLES DU PARC-------------------------------*/

void afficherParcDispo(Voitures* voitures, int n)
{
    for(int i=0; i<n; i++)
    {
        if(voitures[i].dispo==1)
        {
            printf("\n\tVoitures %d",voitures[i].num);
            printf("\n%s %s",voitures[i].marque,voitures[i].modele);
            printf("\nImmatriculation : %s",(voitures+i)->immatriculation);
            printf("\nKilometrage : %s\n",(voitures+i)->kilometrage);

        }
        else
        {
            continue;
        }
    }
}
