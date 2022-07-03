#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
main()
{
ifstream ifs("ip.txt");
string s;
while(ifs)
{
          ifs >> s;
          cout << s;
}

 
cin.get();
}