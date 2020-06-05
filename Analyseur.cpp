//ce code source contients les défintions des méthodes de la classe Analyseur
#include"utils.h"
Analyseur::Analyseur()
{


}
vector<stat> Analyseur::analyser(vector<string> &texte)
{
stat s;
for(unsigned int i=0;i<texte.size();i++)
{
bool exist=false;
for(unsigned int j=0;j<st.size();j++)
{
if(texte.at(i)==st.at(j).mot)
{
st.at(j).occ++;
exist=true;
break;
}
}

if(!exist)
{
s.mot=texte.at(i);
s.occ=1;
st.push_back(s);
}
}

return(st);
}

