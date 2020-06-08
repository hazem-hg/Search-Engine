
#include"utils.h"
#ifndef ABSTRACTCLASS_H_INCLUDED
#define ABSTRACTCLASS_H_INCLUDED
using namespace std ;
class lecture
{
//cette classe permet d'instancer un objet afin de lire un fichier et obtenir les mots qui contient
public:
lecture();//constructeur permettant d'initialiser le nom du fichier
 virtual bool useData(string)=0;//fonction amie se trouve dans utils.h qui permet d'éliminer la ponctuation et les symboles
 virtual vector<string> lire(istream&)=0;//retourner les mots non traités contenues dans le fichier p
vector<string>getWords();
friend ostream& operator<<(ostream&,lecture*);
virtual ~lecture();
protected:
vector<string> mots;//les mots extraites du fichier
};
class Analyseur
{
public:
 Analyseur(string);
 virtual void analyser()=0;
 string getFileName();
 vector<string> getWords();
 void  setFile(string,vector<string>);
private:
    string fichierCourant ;
    vector<string> words;
};
class indexe
{
public :
indexe();

virtual void indexer(Analyseur*)=0 ;
virtual void reindexer(Analyseur*)=0;


};
class ordonnanceur
{
public:
    void lireRequete(istream&);
    virtual void score(indexe*)=0;//permet de donner un score à chaque fichier à partir des mots cclés
    virtual void trier()=0;//permet de trier les fichiers à partir de leurs scores
    vector<string> getKeywords();//retourne les les mots clés
    vector<string> getResult();//retourne les résulatas
    friend ostream& operator<<(ostream&,ordonnanceur*);//permet de retourner le reustat dans le flux sortant
protected:
    lecture* keywords;
    vector<string> result ;
};
class MoteurRecherche
{
public:
MoteurRecherche();
virtual vector<string> rechercher()=0;
virtual ~MoteurRecherche();
protected:
Analyseur* A;
indexe* index;
ordonnanceur* ord;

};

ostream& operator <<(ostream&,lecture*);//surcharge de l'operateur << pou la classe Analyseur
ostream& operator<<(ostream&,ordonnanceur*);
#endif // ABSTRACTCLASS_H_INCLUDED
