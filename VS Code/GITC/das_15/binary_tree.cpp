//class Node
//class Binary Serch Tree
//add funkcia peregruzkov
//print funkcia peregruzkov
//destroy funkcia 
//destructor

//konstruktor kopirovaniya 152
//operator prisvoivoniya 199
//operator sravneniya 214
//rekursivnaya funkciya kopirovaniya 130
//rekursivnaya funkciya sravneniya 110
//TODO rekursivnaya funkciya kopirovaniya


#include <iostream>
using namespace std;

class Node
    {
        public:
            int value;
            Node* left;
            Node* right;
                
            Node(int x) //nor terev stexcelu konstruktor
            {
                value = x;
                left = nullptr;
                right = nullptr;
            }
    }; 

    class BST //binarnoe derevo poiska
    {
        private:
            Node* root = nullptr;
            int leavesAmount = 0;

            void print(Node* temp) //rekursivnaya funkciya pechati
            {
                if(!temp) //ete @ntaciki dzax koxm@ banm ka
                {
                    return;
                }
                print(temp->left);
                cout << "VALUE\t" << temp->value << endl;
                print(temp->right);
                
            }

            void destroy(Node* &temp) //rekursivnaya funkciya unichtojeniya
            {
                if(!temp)
                {
                    return;
                }
                destroy(temp->left);
                temp->left = nullptr;
                destroy(temp->right);
                temp->right = nullptr;
                -- leavesAmount;
                delete temp;
                temp = nullptr;
            }

            bool add(int x, Node* &temp) //!peredayom ne ukazatel a ssilku na etot ukazatel
            {
                if(!temp) //!ete khandipenq zroyakan ukazatel
                {
                    ++ leavesAmount;
                    temp = new Node(x);
                    return true;
                }
                else if(x == temp->value)
                {
                    return false;
                }
                else if(x < temp->value) //ete x poqr e @ntaciqi valuic uremn kerdanq dzax
                {
                    return add(x, temp->left); //rekursiv kanchenq es funkcian bayc arden @ntacikic dzax
                }
                else //ete x mec e @ntaciqi valuic uremn kerdanq aj
                {
                    return add(x, temp->right); //rekursiv kanchenq es funkcian bayc arden @ntacikic aj
                }
            }

            Node* find(Node* temp, int copyX) //rekursivnaya funkciya poiska
            {
                if(!temp)
                {
                    return nullptr;
                }
                if(temp->value == copyX)
                {
                    return temp;
                }
                
                if(copyX < temp->value)
                {
                    return find(temp->left, copyX);    //rekursiv erdanq dzax
                }
                if(copyX > temp->value)
                {
                    return find(temp->right, copyX);    //rekursiv erdanq aj
                }
                return nullptr;
            }

            bool compare(Node* temp1, Node* temp2) //rekursivnaya funkciya sravneniya
            {
                if((temp1 && !temp2) || (!temp1 && temp2))
                {
                    return false;
                }
                if(!temp1 && !temp2)
                {
                    return true;
                }
                if(temp1->value != temp2->value)
                {
                    return false;
                }
                //return  compare(temp1->left, temp2->left) && compare(temp1->right, temp2->right);
                bool l = compare(temp1->left, temp2->left);
                bool r = compare(temp1->right, temp2->right);
                return l && r;
            }

             void copyRec(const Node* temp) //rekursivnaya funkciya kopirovaniya
            {
                if(temp)
                {
                    add(temp->value);
                    copyRec(temp->left);
                    copyRec(temp->right);
                }
            }

            Node* delNode(Node* temp, int val) //TODO rekursivnaya funkciya kopirovaniya
            {
                return nullptr;
            }        

        public:

            BST() //konstruktor po umolchaniyu
            {
                cout << "Vizvolsya konstruktor dlya obekta " << this << endl;
            }

            BST(BST& other) //konstruktor kopirovaniya
            {
                cout << "Vizvolsya konstruktor kopirovaniya dlya obekta " << this << endl;
                Node* temp = other.root;
                copyRec(temp);
            }

            ~BST() //destruktor
            {
                cout << "Vizvolsya destruktor dlya obekta " << this << endl;
                destroy(root);
                
            }

            bool is_empty(void) //publichnaya ne rekursivnaya funkciya pusto li
            {
                if(!root)
                {
                    return true;
                }
                else
                {
                    return false;
                } 
            }

            bool add(int x) //publichnaya abeortka dlya funkcii dobavleniya
            {
                return add(x, root);
            }

            void print() //publichnaya abeortka dlya funkcii pechati
            {
                cout << "the trees Leaves Amount " << leavesAmount << endl;
                print(root); //stexic nor krnanq peregruzkov mer iskakan funkciain kanchenq
            }

            bool find(int temp) //publichnaya abeortka dlya funkcii poiska
            {
                return find(root, temp);
            }

            void delValue(int x)//publichnaya abeortka dlya funkcii udaleniya
            {
                delNode(root, x);
            }

            bool operator== (BST& other) //operator sravneniya
            {      
                //cout << "Vizvolsya operator sravneniya dlya obekta " << this->root << endl;
                //cout << "Vizvolsya operator sravneniya dlya obekta " << other.root << endl;
                if(this->root == other.root) //ete hamematum enq 2 nuyn obyektner@
                {
                    return true;
                }      
                if(leavesAmount != other.leavesAmount)
                {
                    return false;
                }
                return compare(root, other.root);
            }
            
            BST& operator= (const BST& other) //operator prisvoivoniya
            {
                //cout << "this root value: " << this->root->value << endl;
                if(root)
                {
                    destroy(root);
                }
                Node* temp = other.root;
                //cout << "other root value: " << temp->value << endl;
                copyRec(temp);
                return *this;   
            }
            
    
    };

    int main()
    {
        BST tree;
        int array1[] = {7, 3, 2, 1, 9, 5, 4, 6, 8};
        for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
        {
            tree.add(array1[i]);
        }
        /*
        BST tsar;
        int array2[] = {70, 30, 20, 10, 90, 50, 40, 60, 80};
        for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); ++i)
        {
            tsar.add(array2[i]);
        }
        */

        //tsar = tree;
        //cout << "TREE" << endl;
        //tree.print();
        
        //cout << "TSAR" << endl;
        //tsar.print();

        //BST derevo = tree;
        //derevo.print();
        //bool b = tree == tsar;
        //cout << endl << b ? "YES\n" : "NO\n"; //ternarny operator
        //cout << endl;
        //tree.delValue(4);
        //tree.print();
        
        //cout << "find " << tree.find(9) << endl;
/*
        string command;
        cout << "ENTER THE COMMAND\t";
        cin >> command;
        if(command == "search")
        {
            int kay;
            cout << "ENTER THE KAY\t";
            cin >>  kay;
            cout << endl << (tree.find(kay)) ? "YES\n" : "NO\n"; //ternarny operator
            cout << endl;
        }
        else if(command == "add")
        {
            int kay;
            cout << "ENTER THE KAY\t";
            cin >>  kay;
            cout << endl << (tree.add(kay)) ? "DONE\n" : "ALREDY\n"; //ternarny operator
            cout << endl;
        }
*/
        return 0;
    }