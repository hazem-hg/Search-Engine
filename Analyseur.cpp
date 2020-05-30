//ce code source contients les défintions des méthodes de la classe Analyseur
#include"utils.h"
Analyseur::Analyseur()
{


}
vector<stat> Analyseur::analyser(vector<string> texte)
{ stat s;
      vector<stat> st;
    vector<string>::iterator i=texte.begin();
    while(i!=texte.end())
      {  int x=1;
         s.mot=*i;
         for(vector<string>::iterator j=i+1;i!=texte.end();i++)
           {
               if (*i==*j)
                 {
                     x++;
                 };
           };
           s.occ=x;
         st.push_back(s);
        };
       return st;
       }

