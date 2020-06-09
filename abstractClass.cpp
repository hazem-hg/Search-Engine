#include"abstractClass.h"
//ce header contient les méthodes et les fonctions amies des classes abstraites
//classe lecture
 lecture::lecture()
{

};


vector<string> lecture::getWords()const
{
return mots;
}
ostream& operator<<(ostream& flux,lecture* l)
{
for(unsigned int i=0;i<l->mots.size();i++)
{
flux<<l->mots.at(i)<<" ";
}
return flux;
}
lecture::~lecture()
{}
//class Analyseur
Analyseur::Analyseur(string name,vector<string> v)
{
fichierCourant=name;
words=v;
}
string Analyseur::getFileName()const
{
return fichierCourant;
}
vector<string> Analyseur::getWords()const
{
return words;
}
void Analyseur::setFile(string name,vector<string> v)
{
fichierCourant=name;
words=v;
}
Analyseur::~Analyseur()
{}











/*ostream& operator <<(ostream& flux,indexeVcet* ind)//surcharge de l'operateur <<
{
flux<<"fichier"<<","<<"mot"<<","<<"occurence"<<endl;
    for(vector<triplet>::iterator i=ind.v.begin();i!=ind.v.end();i++)
    {
        flux<<i->fichier<<"," <<i->mot<<","<<i->occ<<endl;

    }


return flux ;

};


ostream& operator<<(ostream& flux,ordonnanceur* ord)
{
for(vector<string>::iterator i=ord->result.begin();i!=ord->result.end();i++)
{
flux<<*i<<endl;
}
return flux ;
}

*/



