//code source de la classe indexe
/*#include"utils.h"
indexe::indexe()//le consructeur récupere les données dans index
{

};
vector<triplet> indexe::indexer(vector<stat> s,string nomf)//permet de indexer un nouveau fichier
{
triplet t ;
for(vector<stat>::iterator i=s.begin();i!=s.end();i++){

   t.fichier=nomf;
   t.mot=i->mot;
   t.occ=i->occ;
   v.push_back(t);

}
 return v ;

};
vector<triplet> indexe::reindexer(vector<stat> s,string nomf)//reindexer un fichier qui existe deja
{
for(vector<stat>::iterator i=s.begin();i!=s.end();i++)
{
for(vector<triplet>::iterator j=v.begin();j!=v.end();j++)
{if ((nomf==j->fichier)&&(i->mot==j->mot))
{
j->occ=i->occ ;
break;
}
}
}
return v ;
};*/

