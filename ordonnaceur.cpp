#include "utils.h"
ordonnanseur::ordonnanseur()
{
keywords=new lecture;

}
void ordonnanseur::lireRequete(istream& flux)
{
keywords->lire(flux);
}
vector<stat> ordonnanseur::score(indexe indx)
{
stat Fsc;//aissi attribut mot du stat réprésente le nom du fichier et occ réprésente le score
vector<stat> resulatScore;
for(vector<triplet>::iterator i=indx.v.begin();i!=indx.v.end();i++)//1ere boucle pour parcourir l'index
{
bool e=false;//utilsé pour lavérification de l'existence du fichier dans le vecteur des fichier ayant déja un score
for(vector<string>::iterator j=keywords->mots.begin();j!=keywords->mots.end();j++)//2eme boucle pour parcour les mots clés
{
if(*j==i->mot)
{
for(vector<stat>::iterator k=resulatScore.begin();k!=resulatScore.end();k++)//3eme boucle pour parcourir le cecteur des fichiers ayants un score
{
 e=i->fichier==k->mot;
if(e)
{
k->occ=(k->occ)*(1+i->occ);
break;
}
}
if(!e)
{
Fsc.mot=i->fichier;
Fsc.occ=1+i->occ;
resulatScore.push_back(Fsc);
}

}
}
}
tableScore=resulatScore;
return resulatScore;
}
vector<string>ordonnanseur::trier()
{
vector<stat> sc=tableScore;
unsigned int n=sc.size();
while(sc.size()>n/2)
{
vector<stat>::iterator topScore=sc.begin();
for(vector<stat>::iterator i=sc.begin();i!=sc.end();i++)
{
if(i->occ>topScore->occ)
{

topScore=i;

}

}
resultat.push_back(topScore->mot);
sc.erase(topScore);
}


return resultat ;
}
