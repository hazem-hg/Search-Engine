
#include"utils.h"
using namespace std;




int main()
{
MoteurRecherche* m;
m=new MoteurRecherche(cin,cin);
lecture l;
l.lire(cin);
for(unsigned int i=0;i<l.mots.size();i++)
cout<<l.mots.at(i);
string a="F1";
string b="F1";
m->A->analyser(l.mots);
Analyseur j=*(m->A);
cout<<j;
//for(unsigned int i=0;i<j.st.size();i++)
//cout<<j.st.at(i).mot<<j.st.at(i).occ;
m->index->indexer(m->A->st,"F1");
l.lire(cin);
m->A->analyser(l.mots);
m->index->indexer(m->A->st,"F2");
indexe in=*(m->index);
cout<<in;

/*lecture *l;
l=new lecture;
l->lire(cin);
for(unsigned int i=0;i<l->mots.size();i++)
cout<<l->mots.at(i);
*/
return 0 ;

}
