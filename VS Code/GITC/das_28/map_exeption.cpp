#include <iostream>
#include <ctime>
using namespace std;



template<class type1, class type2>
class Stack
{
    private:  
        template<class Type1, class Type2>
        class Node
        {
            public:
                Type1 kay;
                Type2 val;
                int index = 0;
                Node* prev;
                Node* next;

                Node(Type1 k, Type2 v)
                {
                    kay = k;
                    val = v;
                    prev = nullptr;
                    next = nullptr;
                }
            };

        Node<type1, type2>* head = nullptr;
        Node<type1, type2>* tail = nullptr;
        int userQuantity = 0;

    public:
        ~ Stack()
        {
            if(head != nullptr)
            {
                while(head != tail)
                {
                    head = head -> next;
                    delete head -> prev;
                }
                delete head;
            }
        } 

        void print(void)
        { 
            //Node<type1, type2>* temp = head;
            auto temp = head;
            while(temp != nullptr)
            {
                cout << "User Index\t" << temp->index << endl;
                cout << "User Name\t" << temp->kay << endl;
                cout << "User Password\t" << temp->val << endl;
                temp = temp -> next;
                cout << endl;
            }
                cout << endl << endl;
        }

        void push (int kay, int val)
        {
            //Node<type1, type2>* temp = new Node(kay, val);
            auto temp = new Node(kay, val);

            if(head == nullptr)
            {
                head = temp;
                tail = temp;
            }

            else if(find(kay))
            {
                cout << "-----User is exist-----" << endl;
                delete temp;
                return;
            }

            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }

            ++ userQuantity;
            temp->index = userQuantity;
            return;
        }

        bool find (int kayCopy)
        {
            //Node<type1, type2>* temp = head;
            auto temp = head;
                for(int i = 1; i <= userQuantity; ++ i)
                {
                    if(temp->kay == kayCopy)
                    {
                        return 1;
                    }
                    temp = temp->next;
                }
                return 0;
        }

        bool is_empty(void)
        {
            if(head == nullptr && tail == nullptr)
            {
                return true;
            }
            else return false;
        }


        void destroy ()
        {
            if(head != nullptr) 
            {
                while(is_empty())
                {
                    head = head -> next;
                    delete head -> prev;
                }
                delete head;
            }
        }
};

int main()
{
    Stack<int, int> vkontakte;
    vkontakte.push(55, 5);
    vkontakte.push(66, 6);
    vkontakte.push(77, 7);
    vkontakte.push(77, 8);
    vkontakte.print();
    return 0;
}