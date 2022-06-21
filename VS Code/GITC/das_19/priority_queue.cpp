#include <iostream>
using namespace std;

class PriorityQueue
{
    private:
        class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
        {
            public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
                int login;  //arjeqi member
                int password;
                Node* prev; //ukazatel tipa Node
                Node* next; //ukazatel tipa Node
                
                Node(int l, int p) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
                {
                    login = l;      //lyuboy Node ira mej kpahe ira arjeq@ 
                    password = p;
                    prev = nullptr; //hajordi hascen defoltov NULL
                    next = nullptr; //naxordi hascen defoltov NULL
                }
        };    
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar

        void push_back(int l, int p) //hetevic grelu funkcia
        {
            Node* temp = new Node(l, p); //stexcenq nor temp anunov Node* tesaki uzel
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
                tail = temp; //mej@ NULL e vorovhetev konstruktor@ defoltov iran nullptr arjeq e tve
            }
            else                     //ete inq@ miak@ che
            {
                tail -> next = temp; //pochi next cuyc ta temp (araj NULL er chnayac hmi el e NULL)
                temp -> prev = tail; //tempi prev cuyc ta arajva pochin(araj NULL er bayc hmi uni hasce)
                tail = temp;         //temp@ darav mer taza poch@
            }
            ++ listsQuantity;
            return;
        } //hetevic grelu funkciai verj
        
        void push_front(int l, int p) //demic grelu funkcia
        {
            Node* temp = new Node(l, p); //stexcenq nor temp anunov Node* tesaki uzel
            if(head == nullptr)       //ete inq@ araji uzeln e
            {
                head = temp;
                tail = temp;
            }
            else
            {
                temp -> next = head; //tempi next cuyc ta glxin (araj NULL er bayc hmi uni hasce)
                head -> prev = temp; //glxi prev cuyc ta tempin (araj NULL er chnayac hmi el e NULL)
                head = temp;         //temp@ darav mer taza glux@
            }
            ++ listsQuantity;
            return;
        } //demic grelu funkciai verj
           
    public: 
        ~ PriorityQueue()
        {
            if(head != nullptr) //ete inq@ datark e hech ban chenenq 
            {
                while(head != tail)      //hertov ertanq araj minchev poch
                {
                    head = head -> next; //me qaylm araj ganq
                    delete head -> prev; //jnjenq ira naxordin
                }
                delete head;             //verjum mnac es me uzel@
            }
        }

        void print(void) //tpelu funkcia
        { 
            Node* temp = head;        //sarqeq nor popoxakan vorpeszi hed@ chpchacnenq
            while(temp != nullptr)    //qani der tempi arjeq@ chi dare nullptr uremn hl@ chenq hase verj
            {
                cout << temp->login << "\t" << temp->password << endl;
                temp = temp->next;  //temp-in veragrenq hajord uzel@
            }
        } //tpelu funkciai verj

        void add(int l, int p)
        {
            if(head == nullptr)
            {
                push_back(l, p);
            }
            else if(l < head->login)
            {
                push_front(l, p);
            }
            else if(l > tail->login)
            {
                push_back(l, p);
            }
            else
            {
                Node* temp = new Node(l, p); //stexcenq nor temp vori mej pahenq arjeq@
                Node* iterator = tail;        //mi hat el or list@ perebor enenq
                while (iterator->login > l)
                {
                    iterator = iterator -> prev;
                    if(l == iterator->login)
                    {
                        return;
                    }
                }
                
                temp->next = iterator->next;
                temp->prev = iterator;
                iterator->next->prev = temp;
                iterator->next = temp;
                ++ listsQuantity;
            }
        }

        void pop(int l, int p)
        {
            Node* iterator = head;        //mi hat el or list@ perebor enenq
            if(l == head->login)
            {
                cout << "55555555555555555555" << endl;
                head = head -> next;
                head -> prev = nullptr;
                delete iterator;
                return;
            }
            if(l == tail->login)
            {
                iterator = tail;
                tail = tail -> prev;
                tail -> next = nullptr;
                delete iterator;
                return;
            }
            while (iterator->login != l)
            {
                if(iterator == tail)
                {
                    return;
                }
                iterator = iterator -> next;
            }
            iterator->next->prev = iterator->prev;
            iterator->prev->next = iterator->next;
            iterator->next = iterator->prev = nullptr;
            delete iterator;
        }
        
};

int main()
{
    PriorityQueue pq;

    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int j = 100;
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        pq.add(array[i], j);
        j += 100;
    }
    
    pq.add(55, 9999);
    pq.print();

    int log = 55;
    int pas = 9999;

    pq.pop(log, pas);
    cout << "============================" << endl;
    pq.print();
}