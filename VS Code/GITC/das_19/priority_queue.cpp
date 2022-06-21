#include <iostream>
using namespace std;

class PriorityQueue
{
    private:
        class Node //class-i mej class sarqenq, LinkedLIst-i private sektorum mek e Node -in mainic chbdi sarkenq 
        {
            public: //Node -i memberner@ tox public exnin mek e mainic menq iranc chenq tesni
                int value;  //arjeqi member
                Node* prev; //ukazatel tipa Node
                Node* next; //ukazatel tipa Node
                
                Node(int x) //Node-i konstruktor arjeq@ menq kudalq prev u next inq@ kveragre NULL
                {
                    value = x;      //lyuboy Node ira mej kpahe ira arjeq@ 
                    prev = nullptr; //hajordi hascen defoltov NULL
                    next = nullptr; //naxordi hascen defoltov NULL
                }
        };    
        Node* head = nullptr; //stexcenq Node(ukazatel tipi), head anunov popoxakan inq@ bdi exni arajin uzeli hascen
        Node* tail = nullptr; //stexcenq Node(ukazatel tipi), tail anunov popoxakan inq@ bdi exni verjin uzeli hascen
        int listsQuantity = 0; //lister qanak@ hasvelu hamar

        void push_back(int value) //hetevic grelu funkcia
        {
            Node* temp = new Node(value); //stexcenq nor temp anunov Node* tesaki uzel
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
        
        void push_front(int value) //demic grelu funkcia
        {
            Node* temp = new Node(value); //stexcenq nor temp anunov Node* tesaki uzel
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

        int pop_back(void) //hetevic jnjox funkcia
        {
            if(head == nullptr)
            {
                cout << "List is empty ";
                return 0;
            }
            else
            {
                Node* temp = tail; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                tail = tail -> prev; //pochi mej@ pahenq ira arajva previ hascen
                tail -> next = nullptr; //hmigva pochi next = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
            
        } //hetevic jnjox funkciai verj
        
        int pop_front(void) //demic jnjox funkcia
        {
            if(head == nullptr)
            {
                cout << "List is empty ";
                return 0;
            }
            else
            {
                Node* temp = head; //stexcenq nor temp anunov Node* tesaki popoxakan u inq@ cuyc ta pochi vra 
                head = head -> next;  //glxi mej@ pahenq ira arajva nexti hascen
                head -> prev = nullptr; //hmigva glxi prev = NULL
                -- listsQuantity;
                return temp -> value; //temp arden mer listi het kap chuni bayc ira mej@ arjeq ka veradadznenq
            }
        } //demic jnjox funkciai verj
        
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
                cout << temp -> value << "\t" << endl;
                temp = temp -> next;  //temp-in veragrenq hajord uzel@
            }
        } //tpelu funkciai verj

        void add(int value)
        {
            if(head == tail)
            {
                push_back(value);
            }
            else if(value < head->value)
            {
                push_front(value);
            }
            else if(value > tail->value)
            {
                push_back(value);
            }
            else
            {
                Node* temp = new Node(value); //stexcenq nor temp vori mej pahenq arjeq@
                Node* iterator = head;        //mi hat el or list@ perebor enenq
                while (iterator->value < value)
                {
                    iterator = iterator -> next;
                }
                temp->next = iterator;
                temp->prev = iterator->prev;
                iterator->prev->next = temp;
                iterator->prev = temp;
                ++ listsQuantity;
            }
        }
        
};

int main()
{
    PriorityQueue pq;

    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        pq.add(array[i]);
    }
    
    pq.add(55);
    pq.print();
}