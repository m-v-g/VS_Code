#include "income.h"

template <class TypeC>
class Comparator
{
    public:
        virtual int hamematel(TypeC a, TypeC b) //or es hamematel@ chkanchvi
        {
            return 111;
        }
};

class SortByTotal : public Comparator<Income> //
{
    public:
        int hamematel(Income objectA, Income objectB)
        {
            if(objectA.total > objectB.total)
            {
                return 1;
            }
            else if(objectA.total < objectB.total)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
};

class SortByName : public Comparator<Income> //
{
    public:
        int hamematel(Income objectA, Income objectB)
        {
            if(objectA.name > objectB.name)
            {
                return 1;
            }
            else if(objectA.name < objectB.name)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
};