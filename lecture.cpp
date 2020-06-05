//ce code source contients les défintions des méthodes de la classe lecture

#include"utils.h"
lecture::lecture()
{

};
vector<string> lecture::lire(istream &f)
{
mots.clear();
string x;

while((f>>x)&&(x!="endFlow"))
{
if(useData(x))
mots.push_back(x);
}


return(mots);
}




