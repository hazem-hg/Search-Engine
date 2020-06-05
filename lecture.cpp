//ce code source contients les défintions des méthodes de la classe lecture

#include"utils.h"
lecture::lecture()
{

};
vector<string> lecture::lire(istream &f)
{

string x;
if(f)
{

while((f>>x)&&(x!="finFile"))
{
if(useData(x))
mots.push_back(x);
}
}
else
cout<<"fichier n'existe pas"<<endl;
return(mots);
}




