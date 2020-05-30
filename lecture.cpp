//ce code source contients les défintions des méthodes de la classe lecture

#include"utils.h"
lecture::lecture()
{

};
vector<string> lecture::lire(FILE*& f)
{
vector<string> data ;
string x;

if(f)
{

while(!feof(f))
{
data.push_back(x);
}
}
else
cout<<"fichier n'existe pas"<<endl;

return(ProcessData(data));
}

