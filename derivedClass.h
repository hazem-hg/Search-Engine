#ifndef DERIVEDCLASS_H_INCLUDED
#define DERIVEDCLASS_H_INCLUDED
#include"abstractClass.h"

class AnalyseurMap
{
public:
 AnalyseurMap();
 map<string,int> analyser(vector<string>);
friend ostream& operator <<(ostream&,Analyseur);
//protected:
 map<string,int> st;
};
class indexeVect:indexe
{
public :
indexe();
vector<triplet> indexer(vector<stat>,string) ;
vector<triplet> reindexer(vector<stat>,string);
friend ofstream& operator <<(ofstream&,indexe);


vector<triplet> v;
};


};
class indexeMMap
{
public :
indexeMMap();
multimap<string,stat> indexer(map<string,int>,string) ;
multimap<string,stat> reindexer(map<string,int>,string);


multimap<string,stat> v;

};
class ordonnanceurOcc:public ordonnanceur
{
public:
    ordonnanseurOcc();
    void score(indexe);//permet de donner un score à chaque fichier à partir des mots cclés
    void trier();//permet de trier les fichiers à partir de leurs scores
    vector<stat> getScore();//retourne les scores des fichiers
    ~ordonnanceurOcc();
private:
vector<stat> tableScore;//score des fichiers

};
class MoteurRecherche
{
public:
MoteurRecherche();

Analyseur* A;
indexe* index;
ordonnanseur* ord;

};

#endif // DERIVEDCLASS_H_INCLUDED
