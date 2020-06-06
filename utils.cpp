#include"utils.h"
bool useData (string x)
{

string UselessData[]={"a","an","was","were","so","and",",",";",".",":","/","!","?","%","*","+","=","#","(",")","-","_"};

for(int i=0;i<22;i++)
{

if(UselessData[i]==x)
{
return false;
}
}

return true ;
}

ostream& operator <<(ostream& flux,indexe ind)//surcharge de l'operateur <<
{
flux<<"fichier"<<","<<"mot"<<","<<"occurence"<<endl;
    for(vector<triplet>::iterator i=ind.v.begin();i!=ind.v.end();i++)
    {
        flux<<i->fichier<<"," <<i->mot<<","<<i->occ<<endl;

    }


return flux ;

};

ostream& operator <<(ostream& flux,Analyseur A)//surcharge de l'operateur <<
{
flux<<"mot"<<","<<"occurence"<<endl;
    for(vector<stat>::iterator i=A.st.begin();i!=A.st.end();i++)
    {
        flux<<i->mot<<","<<i->occ<<endl;

    }
    return flux ;
    }


ostream& operator<<(ostream& flux,ordonnanseur ord)
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

