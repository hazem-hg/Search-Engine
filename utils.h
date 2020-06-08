//ce header contient des types et des fonctions utiles et dont le projet dépend
#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>
#include <iostream>
#include<vector>
#include<map>

using namespace std ;
typedef struct stats
{
    string mot ;
    unsigned int occ ;
}stat;
typedef struct trip
{
string fichier;
string mot;
unsigned int occ ;
}triplet;


bool useData (string);//fonction utile qui processe les donnéés et les prépare pour etre traitées

template<class T> void enregistrer(T,ofstream&);//enregistre les donnéées dans un fichier mais il fait la surcharge de l'opérateur <<



#endif // UTILS_H_INCLUDED

