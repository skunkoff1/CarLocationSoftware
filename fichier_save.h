#ifndef FICHIER_SAVE_H_INCLUDED
#define FICHIER_SAVE_H_INCLUDED
#include "parc_voitures.h"
#include "clients.h"

void saveParc(Voitures*, int, char*);

Voitures* load_voitures( char*, int*);

void saveClients(Clients*, int, char*);

Clients* load_clients (char* , int* );

#endif // FICHIER_SAVE_H_INCLUDED
