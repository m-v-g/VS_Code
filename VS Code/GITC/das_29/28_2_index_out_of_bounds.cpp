#include <iostream>
#include <ctime>

using namespace std;

class IndexOutOfBounds
{
    public:
        string prichina;
        string reshenie;
        int index;
        time_t kogda; //time_t tipi popoxakan vori mej kphenq 01.01.1970-ic mincev hmi varkyanneri qanak@

        IndexOutOfBounds(string prichina, string reshenie, int index, time_t kogda)
        {
            this->prichina = prichina; //"this->patchar" global membern e isk "patchar" stex stexcvac popoxakann e
            this->reshenie = reshenie;
            this->index = index;
            this->kogda = kogda;
        }

        void display()
        {
            cout << "-------------------------------------------" << endl;
            cout << "cause: " << prichina << endl;
            cout << "solution: " << reshenie << endl;
            cout << "because of the number is: " << index << endl;
            cout << "when happened: " << ctime(&kogda) << endl;// ctime funkcia vor@ k@ndune erbi hascen u het
                                                             // kveradardzne normal formati berac amis amsativ@
            cout << "-------------------------------------------" << endl;
        } 
        };

int main()
{
    try
    {
        IndexOutOfBounds ex("wrong nuber inserted", "inser the number differ from 0", 0, time(0));
        throw ex; //                                                                      ^ fiqsenq es pah@
    }
        
    catch(IndexOutOfBounds k)
    {
            
    }
    
    return 0;
}