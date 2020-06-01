/*#include"utils.h"
vector<string> ProcessData (vector<string> data)
{

vector<string> DataInutiles;
ifstream useless;
vector<string> UselessData;
useless.open("DataInutiles.txt");
string x;
while(useless>>x)
{
UselessData.push_back(x);
}
for(vector<string>::iterator i=data.begin();i!=data.end();i++)
{
for(vector<string>::iterator j=UselessData.begin();i!=UselessData.end();j++)

{
if (*i==*j)
{
data.erase(i);
}
}
}
return data ;
}
ofstream& operator <<(ofstream& flux,indexe ind)//surcharge de l'operateur <<
{
flux<<"fichier"<<","<<"mot"<<","<<"occurence"<<endl;
    for(vector<triplet>::iterator i=ind.v.begin();i!=ind.v.end();i++)
    {
        flux<<i->fichier<<"," <<i->mot<<","<<i->occ<<endl;

    }


return flux ;

};

ostream& operator <<(ostream& flux,Analyseur &A)//surcharge de l'operateur <<
{
flux<<"mot"<<","<<"occurence"<<endl;
    for(vector<stat>::iterator i=A.st.begin();i!=A.st.end();i++)
    {
        flux<<i->mot<<","<<i->occ<<endl;

    }
    return flux ;
    }


return flux ;

};
ofstream& operator<<(ofstream& flux,ordonnanseur ord)
{
for(vector<string>::iterator i=ord.resultat.begin();i!=ord.resultat.end();i++)
{
flux<<*i<<endl;
}
return flux ;
}





template<class T> void enregistrer(T object,ofstream& f)//permet d'enregistrer des données dans un fichier donné
{
f<<object;


}
*/
