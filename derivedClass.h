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
class AnalyseurVect:public Analyseur
{
public:
 AnalyseurVect(string,vector<string>);
void analyser();
vector<stat> getAnalyse()const;
friend ostream& operator <<(ostream&,AnalyseurVect);
~AnalyseurVect();
private:
 vector<stat> st;
};
class AnalyseurMap:public Analyseur
{
public:
 AnalyseurMap(string,vector<string>);
 void analyser();
 map<string,int> getAnalyse()const;
friend ostream& operator <<(ostream&,AnalyseurMap*);
~AnalyseurMap();
private:
 map<string,int> st;
};
class indexeVect:indexe
{
public :
indexeVect();
void indexer(AnalyseurVect*) ;
void reindexer(AnalyseurVect*);
vector<triplet> getIndex()const;
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
void indexer(AnalyseurMap*) ;
void reindexer(AnalyseurMap*);
multimap<string,stat>getIndex()const;
friend ostream& operator <<(ostream&,indexeMMap*);
friend istream& operator>>(istream&,indexeMMap*);
~indexeMMap();
private:
multimap<string,stat> v;

};
class ordonnanceurOccV:public ordonnanceur
{
public:
    ordonnanceurOccV();
    void score(indexeVect*);//permet de donner un score à chaque fichier à partir des mots cclés
    void trier();//permet de trier les fichiers à partir de leurs scores
    vector<stat> getScore()const;//retourne les scores des fichiers
    ~ordonnanceurOccV();
private:
vector<stat> tableScore;//score des fichiers

};
class ordonnanceurOccM:public ordonnanceur
{
public:
    ordonnanceurOccM();
    void score(indexeMMap*);//permet de donner un score à chaque fichier à partir des mots cclés
    void trier();//permet de trier les fichiers à partir de leurs scores
    map<string,int> getScore()const;//retourne les scores des fichiers
    ~ordonnanceurOccM();
private:
map<string,int> tableScore;//score des fichiers

};
/*class ordonnanceurBinaire:public ordonnanceur
{
public:
    ordonnanceurBinaire();
    void score(indexeMMap*);//permet de donner un score à chaque fichier à partir des mots cclés
    void trier();//permet de trier les fichiers à partir de leurs scores
    map<string,int> getExist();
    ~ordonnanceurBinaire();
private:
map<string,stat> tableBinaire;
map<string,stat> tableScore;
};*/
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
