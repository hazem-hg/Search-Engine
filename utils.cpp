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






template<class T> void enregistrer(T object,ofstream& f)//permet d'enregistrer des données dans un fichier donné
{
f<<object;


}

