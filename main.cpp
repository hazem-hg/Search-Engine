
#include"utils.h"
using namespace std;




int main()
{
MoteurRecherche m;
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
cout<<o.tableScore.at(i).mot<<" "<<o.tableScore.at(i).occ<<endl;*/
m.ord->trier();
//for(int i=0;i<o.resultat.size();i++)
//cout<<o.resultat.at(i)<<endl;
cout<<*m.ord;

return 0;

}
