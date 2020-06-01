#include <iostream>
#include<vector>
#include<fstream>
#include<string>
//#include"utils.h"
using namespace std;
typedef struct stat
{
    string mot ;
    unsigned int occ ;
};
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
class lecture
{
//cette classe permet d'instancer un objet afin de lire un fichier et obtenir les mots qui contient
public:
lecture();//constructeur permettant d'initialiser le nom du fichier
 vector<string> lire(istream&);//retourner les mots non traités contenues dans le fichier p
friend vector<string> ProcessData(vector<string>);//fonction amie se trouve dans utils.h qui permet d'éliminer la ponctuation et les symboles
vector<string> mots;//les mots extraites du fichier
};
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



int main()
{
ifstream f ;
f.open("ws.txt");
lecture *l;
l=new lecture ;
l->lire(f);
for (int i=0;i<l->mots.size();i++)
{
cout<<l->mots.at(i)<<"  ";

}
f.close();
return 0 ;
}
