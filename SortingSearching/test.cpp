#include <iostream>
#include <map>
using namespace std;
int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  // mymap['e']=100;

  itlow=mymap.lower_bound ('e');  // itlow points to b
  itup=mymap.upper_bound ('e');   // itup points to e (not d!)
    itlow++;
    itlow++;
    cout<<(itlow)->second<<endl;
    // itup--;
    cout<<itup->second<<endl;
}
