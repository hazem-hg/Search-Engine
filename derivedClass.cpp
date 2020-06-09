#include"derivedClass.h"
//class lectureStandard
lectureStandard::~lectureStandard()
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
