#include"utils.h"

indexeMMap::indexeMMap()//le consructeur récupere les données dans index
{
/*
  string fi,m;unsigned int i;triplet t;


    f>>fi>>fi>>fi;//la premiere ligne contient les titres
    while((f>>fi>>m>>i)&&(f!="endFlow"))
    {
        t.fichier=fi;t.mot=m;t.occ=i;
        v.push_back(t);

    }

*/
};
multimap<string,stat> indexeMMap::indexer(map<string,int> s,string nomf)//permet de indexer un nouveau fichier
{
stat temp ;
for(map<string,int>::iterator i=s.begin();i!=s.end();i++)
{

   temp.mot=i->first;
   temp.occ=i->second;
   v.insert(multimap<string,stat>::value_type(nomf,temp));

}
 return v ;

};
multimap<string,stat> indexeMMap::reindexer(map<string,int> s,string nomf)//reindexer un fichier qui existe deja
{
stat temp ;
for(map<string,int>::iterator i=s.begin();i!=s.end();i++)
{
bool e=false;
for(multimap<string,stat>::iterator j=v.begin();j!=v.end();j++)
{if ((nomf==j->first)&&(i->first==j->second.mot))
{
j->second.occ=i->second ;
e=true;
break;
}
}
if(!e)
{
temp.mot=i->first;
temp.occ=i->second;
v.insert(multimap<string,stat>::value_type(nomf,temp));
}
}
return v ;
};
