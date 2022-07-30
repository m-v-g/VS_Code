#include <iostream>
#include <ctime>
#include "bst.h"
#include "node.h"
#include "income.h"
#include "other_class.h"

//using namespace std;

int main()
{
    SortByTotal sbt;
    BST<Income> gyumri(&sbt);

    std::string arrayN[] = {"Gd", "Ca", "Bv", "Af", "Ij", "Er", "Dd", "Ff", "Hm", "?"};
    double arrayA[] = {70, 30, 20, 10, 90, 50, 40, 60, 80, 65};
    double arrayI[] = {-0.7, -0.3, -0.2, -0.1, -0.9, -0.5, -0.4, -0.6, -0.8, -0.65};

    for (int i = 0; i < sizeof(arrayA) / sizeof(arrayA[0]); ++i)
    {
        gyumri.add(Income(arrayN[i], arrayA[i], arrayA[i]/i, arrayI[i], arrayI[i]/i, arrayA[i]/arrayI[i]));
    }


    return 0;
}