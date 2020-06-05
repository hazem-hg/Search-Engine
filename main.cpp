#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include"utils.h"
using namespace std;




int main()
{
MoteurRecherche* m;
m=new MoteurRecherche(cin,cin);
lecture l;
vector<string> v=l.lire(cin);
m->A->analyser(v);
vector<string> f=l.lire(cin);



}
