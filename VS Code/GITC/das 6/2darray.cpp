/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <random>
using namespace std;

int main()
{
    int array[4][4];
    
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            array[i][j] = 20 + rand()%80;
        }
    }
    
    for(int i = 0; i < 4; ++i)
    {
        cout << array[i][i] << endl;
    }

    return 0;
}
