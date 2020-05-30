#include"utils.h"
MoteurRecherche::MoteurRecherche(ifstream& f,FILE*& g)
{
*A=Analyseur();
*index=indexe(f);
*ord=ordonnanseur(g);

}
