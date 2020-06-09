#ifndef DERIVEDCLASS_H_INCLUDED
#define DERIVEDCLASS_H_INCLUDED
#include"abstractClass.h"
class lectureStandard:public lecture
{
//cette classe permet d'instancer un objet afin de lire un fichier et obtenir les mots qui contient
public:
lectureStandard();//constructeur permettant d'initialiser le nom du fichier
 void lire(istream&);//retourner les mots non traités contenues dans le fichier p
 bool useData(string);//fonction amie se trouve dans utils.h qui permet d'éliminer la ponctuation et les symboles
istream& operator>>(istream&);
~lectureStandard();
};
class AnalyseurVect
{
public:
 AnalyseurVect(string,vector<string>);
void analyser(vector<string>);
vector<stat> getAnalyse();
friend ostream& operator <<(ostream&,AnalyseurVect);
private:
 vector<stat> st;
};
class AnalyseurMap
{
public:
 AnalyseurMap(string);
 void analyser(vector<string>);
 map<string,int> getAnalyse();
friend ostream& operator <<(ostream&,AnalyseurMap);
private:
 map<string,int> st;
};
class indexeVect:indexe
{
public :
indexeVect();
void indexer(AnalyseurVect*) ;
void reindexer(AnalyseurVect*);
vector<triplet> getIndex();
friend ostream& operator <<(ostream&,indexeVect*);
friend ostream& operator>>(ostream&,indexeVect*);
~indexeVect();
private:
vector<triplet> v;
};


class indexeMMap
{
public :
indexeMMap();
multimap<string,stat> indexer(AnalyseurMap*) ;
multimap<string,stat> reindexer(AnalyseurMap*);
multimap<string,stat>getIndexe();
friend ostream& operator <<(ostream&,indexeMMap*);
friend istream& operator>>(istream&,indexeMMap*);
private:
multimap<string,stat> v;

};
class ordonnanceurOcc:public ordonnanceur
{
public:
    ordonnanceurOcc();
    void score(indexe*);//permet de donner un score à chaque fichier à partir des mots cclés
    void trier();//permet de trier les fichiers à partir de leurs scores
    vector<stat> getScore();//retourne les scores des fichiers
    ~ordonnanceurOcc();
private:
vector<stat> tableScore;//score des fichiers

};
class ordonnanceurBinaire:public ordonnanceur
{
public:
    ordonnanceurBinaire();
    void score(indexe*);//permet de donner un score à chaque fichier à partir des mots cclés
    void trier();//permet de trier les fichiers à partir de leurs scores
    vector<stat> getExist();//retourne les scores des fichiers
    ~ordonnanceurBinaire();
private:
vector<stat> tableBinaire;//score des fichiers
};
class MoteurRechercheVOne:public MoteurRecherche
{
public:
MoteurRechercheVOne();
vector<string> rechercher();
~MoteurRechercheVOne();

};
class MoteurRechercheVTwo:public MoteurRecherche
{
public:
MoteurRechercheVTwo();
vector<string> rechercher();
~MoteurRechercheVTwo();

};
#endif // DERIVEDCLASS_H_INCLUDED
