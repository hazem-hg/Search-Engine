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
     //class
