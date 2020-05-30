#include "utils.h"
ordonnanseur::ordonnanseur(FILE*& f)
{
lecture lec ;
lec.lire(f);
keywords=ProcessData(lec.mots);
}
vector<stat> ordonnanseur::score(indexe indx)
{
stat Fsc;//aissi attribut mot du stat réprésente le nom du fichier et occ réprésente le score
vector<stat> resulatScore;
for(vector<triplet>::iterator i=indx.v.begin();i!=indx.v.end();i++)//1ere boucle pour parcourir l'index
{
bool e=false;//utilsé pour lavérification de l'existence du fichier dans le vecteur des fichier ayant déja un score
for(vector<string>::iterator j=keywords.begin();j!=keywords.end();j++)//2eme boucle pour parcour les mots clés
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
return resulatScore;
}
vector<string>ordonnanseur::trier(vector<stat> st)
{
vector<string> res;
vector<stat>::iterator topScore=st.begin();
while(st.empty())
{
for(vector<stat>::iterator i=st.begin();i!=st.end();i++)
{
if(i->occ>topScore->occ)
{topScore=i;
st.erase(i);
}
}
res.push_back(topScore->mot);
}
return res ;
}
