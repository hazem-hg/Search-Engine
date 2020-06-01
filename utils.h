//ce header contient des types et des fonctions utiles et dont le projet dépend
//#ifndef UTILS_H_INCLUDED
//#define UTILS_H_INCLUDED
/*#include<vector>
#include<iostream>
#include<fstream>
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
class lecture
{
//cette classe permet d'instancer un objet afin de lire un fichier et obtenir les mots qui contient
public:
lecture();//constructeur permettant d'initialiser le nom du fichier
 vector<string> lire(FILE*&);//retourner les mots non traités contenues dans le fichier précisé dans  l'attribut
friend vector<string> ProcessData(vector<string>);//fonction amie se trouve dans utils.h qui permet d'éliminer la ponctuation et les symboles
vector<string> mots;//les mots extraites du fichier
};



class Analyseur
{
public:
 Analyseur();
 vector<stat> analyser(vector<string>&);
 void enregistrer(const char*);//enregistre les statistiques des mots d'un fichier dans un fichier sous le nom donné en argument et sou
friend ostream& operator <<(ostream&,Analyseur&);
//protected:
 vector<stat> st;//cet attribut est un vecteur de mots dont on élimine les mots et les symboles inutiles
};


class indexe
{
public :
indexe(ifstream&);
vector<triplet> indexer(vector<stat>,string) ;
vector<triplet> reindexer(vector<stat>,string);
friend ofstream& operator <<(ofstream&,indexe);


vector<triplet> v;
;
};
class ordonnanseur
{
public:
ordonnanseur(FILE*&);
vector<stat> score(indexe);//permet de donner un score à chaque fichier à partir des mots cclés
vector<string> trier(vector<stat>);//permet de trier les fichiers à partir de leurs scores
friend ofstream& operator<<(ofstream&,ordonnanseur);
 friend vector<string> ProcessData(vector<string>);

vector<string> keywords;
vector<string> resultat;//vecteur des fichiers triées
};
class MoteurRecherche
{
public:
MoteurRecherche(ifstream&,FILE*&);

Analyseur* A;
indexe* index;
ordonnanseur* ord;

};




vector<string> ProcessData (vector<string>);//fonction utile qui processe les donnéés et les prépare pour etre traitées
ofstream& operator <<(ofstream&,Analyseur);//surcharge de l'operateur << pou la classe Analyseur
ofstream& operator <<(ofstream&,indexe ind);//surcharge de l'operateur << pou la classe index
template<class T> void enregistrer(T,ofstream&);//enregistre les donnéées dans un fichier mais il fait la surcharge de l'opérateur <<



#endif // UTILS_H_INCLUDED
*/