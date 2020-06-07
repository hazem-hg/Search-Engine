
#include"utils.h"
using namespace std;




int main()
{
/*MoteurRecherche m;
lecture l;
l.lire(cin);
m.A->analyser(l.mots);
cout<<*m.A;
m.index->indexer(m.A->st,"F1");
cout<<*m.index;
l.lire(cin);
m.A->analyser(l.mots);
cout<<*m.A;
m.index->indexer(m.A->st,"F2");
cout<<*m.index;
l.lire(cin);
m.A->analyser(l.mots);
cout<<*m.A;
m.index->indexer(m.A->st,"F3");
cout<<*m.index;
l.lire(cin);
m.A->analyser(l.mots);
cout<<*m.A;
m.index->indexer(m.A->st,"F4");
cout<<*m.index;
m.ord->lireRequete(cin);
m.ord->score(*m.index);
/*for(int i=0;i<o.tableScore.size();i++)
cout<<o.tableScore.at(i).mot<<" "<<o.tableScore.at(i).occ<<endl
m.ord->trier();
//for(int i=0;i<o.resultat.size();i++)
//cout<<o.resultat.at(i)<<endl;
cout<<*m.ord;
*/
lecture l;
l.lire(cin);
AnalyseurMap A;
A.analyser(l.mots);
for(map<string,int>::iterator i=A.st.begin();i!=A.st.end();i++)
cout<<i->first<<" "<<i->second<<endl;
indexeMMap in;
in.indexer(A.st,"F1");
l.lire(cin);
A.analyser(l.mots);
in.indexer(A.st,"F2");
for(multimap<string,stat>::iterator i=in.v.begin();i!=in.v.end();i++)
cout<<i->first<<" "<<i->second.mot<<" "<<i->second.occ<<endl;


return 0;

}
