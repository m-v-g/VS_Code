//class Node
//class Binary Serch Tree
//add funkcia peregruzkov
//print funkcia peregruzkov
//destroy funkcia 
//destructor




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

    class BST
    {
        private:
            Node* root = nullptr;
            int leavesAmount = 0;
/*
            void print(Node* temp) //tpelu funkcia
            {
                if(temp->left) //ete @ntaciki dzax koxm@ banm ka
                {
                    print(temp->left);    //rekursiv erdanq dzax
                }
                cout << "VALUE\t" << temp->value << endl;
                if(temp->right) //ete @ntaciki aj koxm@ banm ka
                {
                    print(temp->right);    //rekursiv erdanq aj
                }
            }
*/
            void print(Node* temp) //tpelu funkcia
            {
                if(!temp) //ete @ntaciki dzax koxm@ banm ka
                {
                    return;
                }
                print(temp->left);
                cout << "VALUE\t" << temp->value << endl;
                print(temp->right);
                
            }

            void destroy(Node* &temp) //
            {
                if(!temp)
                {
                    return;
                }
                destroy(temp->left);    //rekursiv erdanq
                temp->left = nullptr;
                destroy(temp->right);    //rekursiv erdanq aj
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
                    temp = new Node(x); //
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

            Node* find(Node* temp, int copyX) //rekursiv kkanchenq heto kstugenq
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

            Node* delNode(Node* node, int copyX)
            {
                return nullptr;
            }
            

        public:

            BST()
            {
                cout << "Vizvolsya konstruktor dlya obekta " << this << endl;
            }

            ~BST()
            {
                cout << "Vizvolsya destruktor dlya obekta " << this << endl;
                destroy(root);
                
            }

            bool is_empty(void)
            {
                if(!root) return true;
                else return false;
            }

            bool add(int x)
            {
                return add(x, root);
            }

            void print() //es funkcian bdi grvi or karoxananq myus@ rekursiv kanchenq
            {
                cout << "the trees Leaves Amount " << leavesAmount << endl;
                print(root); //stexic nor krnanq peregruzkov mer iskakan funkciain kanchenq
            }

            bool find(int x)
            {
                return find(root, x);
            }

            void delVal(int kay)
            {
                Node* adress = find(root, kay);
                delNode(adress, kay);
            }
    
    };

    int main()
    {
        BST tree;
        int array[] = {7, 3, 2, 1, 9, 5, 4, 6, 8};
        for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        {
            tree.add(array[i]);
        }
       
        //tree.print();
        tree.delVal(6);
        tree.print();
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