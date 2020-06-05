#include"utils.h"
MoteurRecherche::MoteurRecherche(istream& f,istream& g)
{
A=new Analyseur;
index=new indexe(f);
ord=new ordonnanseur(g);


}

