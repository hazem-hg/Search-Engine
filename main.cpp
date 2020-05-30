#include <iostream>
#include"utils.h"
using namespace std;

int main()
{
ifstream f;
FILE* fichier;
int choix;
char ch;
MoteurRecherche mr(f,stdin);
while (true)
{
cout<<"taper 1 pour analyser un fichier"<<endl;
cout<<"taper 2 pour consulter votre repertoire"<<endl;
cout<<"taper 3 pour chercher "<<endl;
cout<<"taper 0 pour sortir"<<endl;
cin>>choix;
switch(choix)
{
case 1:
{cout<<"donnner le nom du fichier à analyser"<<endl;
cin>>ch;
fichier=fopen("nouveau.txt","r");
lecture read ;
read.lire(fichier);
f.close();
mr.A->analyser(read.mots);
}
break;
case 2:
{cout<<mr.index;
break;
case 3:

mr.ord->trier(mr.ord->score(*mr.index));
for(vector<string>::iterator i=mr.ord->resultat.begin();i!=mr.ord->resultat.end();i++)
{
cout<<*i<<endl;
}
}
break;
case 0:
return 0;
default:
cout<<"choix invalid"<<endl;


}



}


return 0;
}
