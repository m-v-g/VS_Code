#include <iostream>
#include <ctime>

using namespace std;

template <class Type1, class Type2>
class Node
{
    public:
        Type1 kay;
        Type2 value;
        int index = 0;
        Node* prev;
        Node* next;
        

        void set(Type1 k, Type2 v)
        {
            kay = k;
            value = v;
            Node* prev = nullptr;
            Node* next = nullptr;
        }
};


int main()
{
    Node<string, string> a;
    a.set("100", "200");

    return 0;
}