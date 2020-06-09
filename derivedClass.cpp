#include"derivedClass.h"
//class lectureStandard
lectureStandard::lectureStandard()
{
}

bool lectureStandard::useData (string x)
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
istream& lectureStandard::operator>>(istream& flux)
{
string x ;
mots.clear();
while((flux>>x)&&(x!="endFlow"))
{
mots.push_back(x);
}
return flux;
}
void lectureStandard::lire(istream& flux)
{

string x ;
mots.clear();
while((flux>>x)&&(x!="endFlow"))
{
mots.push_back(x);
}
}
lectureStandard::~lectureStandard()
{}
// class AnalyseurVect
AnalyseurVect::AnalyseurVect(string name,vector<string> v):Analyseur(name,v)
{
}
void AnalyseurVect::analyser()
{
st.clear();
stat s;
for(unsigned int i=0;i<getWords().size();i++)
{
bool exist=false;
for(unsigned int j=0;j<st.size();j++)
{
if(getWords().at(i)==st.at(j).mot)
{
st.at(j).occ++;
exist=true;
break;
}
}

if(!exist)
{
s.mot=getWords().at(i);
s.occ=1;
st.push_back(s);
}
}

}
vector<stat> AnalyseurVect::getAnalyse()const
{
return st ;
}

ostream& operator <<(ostream& flux,AnalyseurVect* A)//surcharge de l'operateur <<
{
flux<<"mot"<<","<<"occurence"<<endl;
    for(vector<stat>::iterator i=A->getAnalyse().begin();i!=A->getAnalyse().end();i++)
    {
        flux<<i->mot<<","<<i->occ<<endl;

    }
    return flux ;
    }
AnalyseurVect::~AnalyseurVect()
{}
            //class AnalyseurMap
AnalyseurMap::AnalyseurMap(string name,vector<string> v):Analyseur(name,v)
{}
void AnalyseurMap::analyser()
{
st.clear();

for(vector<string>::iterator i=getWords().begin();i!=getWords().end();i++)
{
bool exist=false;
for(map<string,int>::iterator j=st.begin();j!=st.end();j++)
{
if(*i==j->first)
{
st[j->first]++;
exist=true;
break;
}
}

if(!exist)
{
//st[*i]=1;;
st.insert(map<string,int>::value_type(*i,1));
}
}

}
map<string,int>AnalyseurMap::getAnalyse()const
{
return st  ;
}
AnalyseurMap::~AnalyseurMap()
{}
ostream& operator <<(ostream& flux,AnalyseurMap* A)//surcharge de l'operateur <<
{
flux<<"mot"<<","<<"occurence"<<endl;
    for(map<string,int>::iterator i=A->getAnalyse().begin();i!=A->getAnalyse().end();i++)
    {
        flux<<i->first<<","<<i->second<<endl;

    }
    return flux ;
    }
     //class indexeVect
indexeVect::indexeVect()
{}
void indexeVect::indexer(AnalyseurVect* A)
{

triplet t ;

for(vector<stat>::iterator i=A->getAnalyse().begin();i!=A->getAnalyse().end();i++){
{
   t.fichier=A->getFileName();
   t.mot=i->mot;
   t.occ=i->occ;
   v.push_back(t);

}


}}
void indexeVect::reindexer(AnalyseurVect* A)//reindexer un fichier qui existe deja
{
for(vector<stat>::iterator i=A->getAnalyse().begin();i!=A->getAnalyse().end();i++)
{
for(vector<triplet>::iterator j=v.begin();j!=v.end();j++)
{if ((A->getFileName()==j->fichier)&&(i->mot==j->mot))
{
j->occ=i->occ ;
break;
}
}
}

}
vector<triplet>indexeVect::getIndex()const
{
return v ;
}
indexeVect::~indexeVect()
{}
ostream& operator <<(ostream& flux,indexeVect* ind)//surcharge de l'operateur <<
{
flux<<"fichier"<<","<<"mot"<<","<<"occurence"<<endl;
    for(vector<triplet>::iterator i=ind->v.begin();i!=ind->v.end();i++)
    {
        flux<<i->fichier<<"," <<i->mot<<","<<i->occ<<endl;

    }


return flux ;

};
        //class indexeMMap
indexeMMap::indexeMMap()
{}
void indexeMMap::indexer(AnalyseurMap* A)
{



for(map<string,int>::iterator i=A->getAnalyse().begin();i!=A->getAnalyse().end();i++)
{stat s ;

   s.mot=i->first;
   s.occ=i->second;
   v.insert(map<string,stat>::value_type(A->getFileName(),s));

}


}
void indexeMMap::reindexer(AnalyseurMap* A)//reindexer un fichier qui existe deja
{
for(map<string,int>::iterator i=A->getAnalyse().begin();i!=A->getAnalyse().end();i++)
{
for(multimap<string,stat>::iterator j=v.begin();j!=v.end();j++)
{if ((A->getFileName()==j->first)&&(i->first==j->second.mot))
{
j->second.occ=i->second ;
break;
}
}
}

}
multimap<string,stat>indexeMMap::getIndex()const
{
return v;
}
indexeMMap::~indexeMMap()
{}
ostream& operator <<(ostream& flux,indexeMMap* ind)//surcharge de l'operateur <<
{
flux<<"fichier"<<","<<"mot"<<","<<"occurence"<<endl;
    for(multimap<string,stat>::iterator i=ind->v.begin();i!=ind->v.end();i++)
    {
        flux<<i->first<<"," <<i->second.mot<<","<<i->second.occ<<endl;

    }


return flux ;

};
        //class ordonnanceurOcc
ordonnanceurOccV::ordonnanceurOccV()
{
keywords=new lectureStandard;
}
void ordonnanceurOccV::score(indexeVect* indx)
{
tableScore.clear();
stat Fsc;//aissi attribut mot du stat réprésente le nom du fichier et occ réprésente le score
vector<stat> resulatScore;
for(vector<triplet>::iterator i=indx->getIndex().begin();i!=indx->getIndex().end();i++)//1ere boucle pour parcourir l'index
{
bool e=false;//utilsé pour lavérification de l'existence du fichier dans le vecteur des fichier ayant déja un score
for(vector<string>::iterator j=keywords->getWords().begin();j!=keywords->getWords().end();j++)//2eme boucle pour parcour les mots clés
{
if(*j==i->mot)
{
for(vector<stat>::iterator k=resulatScore.begin();k!=resulatScore.end();k++)//3eme boucle pour parcourir le cecteur des fichiers ayants un score
{
 e=i->fichier==k->mot;
if(e)
{
k->occ=(k->occ)*(1+i->occ);
break;
}
}
if(!e)
{
Fsc.mot=i->fichier;
Fsc.occ=1+i->occ;
resulatScore.push_back(Fsc);
}

}
}
}
tableScore=resulatScore;

}
void ordonnanceurOccV::trier()
{
vector<stat> sc=tableScore;
unsigned int n=sc.size();
while(sc.size()>n/2)
{
vector<stat>::iterator topScore=sc.begin();
for(vector<stat>::iterator i=sc.begin();i!=sc.end();i++)
{
if(i->occ>topScore->occ)
{

topScore=i;

}

}
result.push_back(topScore->mot);
sc.erase(topScore);
}


}
vector<stat>ordonnanceurOccV::getScore()const
{
return tableScore;
}
ordonnanceurOccV::~ordonnanceurOccV()
{}

        //class ordonnanceurOccM
 ordonnanceurOccM::ordonnanceurOccM()
{
keywords=new lectureStandard;
}
void ordonnanceurOccM::score(indexeMMap* indx)
{
tableScore.clear();
stat Fsc;//aissi attribut mot du stat réprésente le nom du fichier et occ réprésente le score

for(multimap<string,stat>::iterator i=indx->getIndex().begin();i!=indx->getIndex().end();i++)//1ere boucle pour parcourir l'index
{
bool e=false;//utilsé pour lavérification de l'existence du fichier dans le vecteur des fichier ayant déja un score
for(vector<string>::iterator j=keywords->getWords().begin();j!=keywords->getWords().end();j++)//2eme boucle pour parcour les mots clés
{
if(*j==i->second.mot)
{
for(map<string,int>::iterator k=tableScore.begin();k!=tableScore.end();k++)//3eme boucle pour parcourir le cecteur des fichiers ayants un score
{
 e=i->second.mot==k->first;
if(e)
{
k->second=(k->second)*(1+i->second.occ);
break;
}
}
if(!e)
{
Fsc.occ=1+i->second.occ;
tableScore[i->first]=1+i->second.occ;
}

}
}
}


}
void ordonnanceurOccM::trier()
{
map<string,int> sc=tableScore;
unsigned int n=sc.size();
while(sc.size()>n/2)
{
map<string,int>::iterator topScore=sc.begin();
for(map<string,int>::iterator i=sc.begin();i!=sc.end();i++)
{
if(i->second>topScore->second)
{

topScore=i;

}

}
result.push_back(topScore->first);
sc.erase(topScore);
}


}
map<string,int>ordonnanceurOccM::getScore()const
{
return tableScore;

}
ordonnanceurOccM::~ordonnanceurOccM()
{}
                //class MoteurVPne







