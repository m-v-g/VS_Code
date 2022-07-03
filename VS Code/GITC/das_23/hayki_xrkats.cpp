#include<iostream>
#include<fstream>
using namespace std;
int main(){
        ifstream kardal;
        kardal.open("./text.txt");
        string s;
        while(getline(kardal, s)){
                cout<<s<<endl;
        }
        kardal.close();
        ofstream grel;
        grel.open("./urishfail.txt", ios::app);
        for(int i=0; i<5; i++){
                grel<<"some text \n";
        }
        grel.close();
        return 0;
}