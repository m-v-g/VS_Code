#include <iostream>
using namespace std;

template <class Type1, class Type2, class Type3, class Type4>
class Spec
    {
        public:
            Type1 name;
            Type2 surname;
            Type3 age;
            Type4 iq;
            Node<Type1>* left;
            Node<Type1>* right;
            Node<Type1>* parent;
                
            Node(Type1 name, Type2 surname, Type3 age, Type4 iq) //nor terev stexcelu konstruktor
            {
                this->name = name;
                this->surname = surname;
                this->age = age;
                this->iq = iq;
                left = nullptr;
                right = nullptr;
                parent =nullptr;
            }
    }; 

    template <class TypeN, class TypeS, class TypeA, class TypeI>
    class BST //binarnoe derevo poiska
    {
        private:
            Node<class TypeN, class TypeS, class TypeA, class TypeI>* root = nullptr;
            int leavesAmount = 0;

            void print(auto temp) //rekursivnaya funkciya pechati
            {
                if(!temp)
                {
                    return;
                }
                print(temp->left);
                cout << temp->value << "\t";
                print(temp->right);
            }

            void destroy(auto &temp) //rekursivnaya funkciya unichtojeniya
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

            bool add(int x, auto &temp) //peredayom ne ukazatel a ssilku na etot ukazatel
            {
                if(!temp) //ete khandipenq zroyakan ukazatel
                {
                    ++ leavesAmount;
                    temp = new auto(x);
                    return true;
                }
                else if(x == temp->value)
                {
                    return false;
                }
                else if(x < temp->value) //ete x poqr e @ntaciqi valuic uremn kerdanq dzax
                {
                    bool ret = add(x, temp->left); //rekursiv kanchenq es funkcian bayc arden @ntacikic dzax
                    temp->left->parent = temp; //kanchic het galuc heto 
                    return ret;
                }
                else //ete x mec e @ntaciqi valuic uremn kerdanq aj
                {
                    bool ret = add(x, temp->right); //rekursiv kanchenq es funkcian bayc arden @ntacikic aj
                    temp->right->parent = temp; //kanchic het galuc heto 
                    return ret;
                }
            }

            auto find(auto temp, int copyX) //rekursivnaya funkciya poiska
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

            bool compare(auto temp1, auto temp2) //rekursivnaya funkciya sravneniya
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

             void copyRec(const auto temp) //rekursivnaya funkciya kopirovaniya
            {
                if(temp)
                {
                    add(temp->value);
                    copyRec(temp->left);
                    copyRec(temp->right);
                }
            }

            bool delNodeParent(auto temp, int val) //funkciya udaleniya
            //                      7
            //                     / \
            //                    3   9
            //                   / \  /
            //                  2   5 8
            //                 /   / \
            //                1   4   6
            //                         \
            //                          6.5
            {
                if(temp->left  == nullptr && temp->right == nullptr) //ete inq@ terev e
                { //stugenq te inq@ ira armati vor koxmn e
                    cout << "terev e " << endl;
                    if(temp->value < temp->parent->value) //uremn inq@ dzax terevn e
                    {
                        cout << "dzax terev e" << endl;
                        temp->parent->left = nullptr;
                        destroy(temp);
                        return true;
                    }
                    if(temp->value > temp->parent->value) //uremn inq@ aj terevn e
                    {
                        cout << "aj terev e" << endl;
                        temp->parent->right = nullptr;
                        destroy(temp);
                        return true;
                    }
                }
                else if(temp->left != nullptr && temp->right == nullptr) //ete uni menak dzax terev
                {
                    cout << "armat e dzax cyuxov" << endl;
                    temp->left->parent = temp->parent;
                    temp->parent->left = temp->left;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    return true;
                }
                else if(temp->left == nullptr && temp->right != nullptr) //ete uni menak aj terev
                {
                    cout << "armat e aj cyuxov" << endl;
                    temp->right->parent = temp->parent;
                    temp->parent->right = temp->right;
                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
                    return true;
                }
                else if(temp->left != nullptr && temp->right != nullptr) //ete uni ham aj ham dzax terevner
                { //uremn gtnenq @ntacikic meceric amenapoqr@
                    cout << "armat e 2 cyuxov" << endl;
                    auto minimal = temp->right; //erdanq aj gtnenq edtexac amena dzax@
                    while(minimal->left) //dzax koxmov ijninq minchev verj
                    {
                        minimal = minimal->left;
                    }
                    temp->value = minimal->value; //gtac minimal arjeq@ grenq tempi mej
                    if(temp->right->left == nullptr && temp->right->right == nullptr) //ete temp aj@ terev e
                    {
                        minimal->parent->right = nullptr;
                    }
                    else if(temp->right->left == nullptr && temp->right->right != nullptr) //ete temp ej@ uni aj cyux
                    {
                        minimal->right->parent = minimal->parent;
                        minimal->parent->right = minimal->right;
                        minimal->left = minimal ->right = nullptr; //sranov xzum enq minimali bolor kaper@
                    }
                    else //ete temp->right left uni
                    {
                        minimal->parent->left = nullptr;
                    }
                    destroy(minimal);
                    return true;
                }
                return true;
            }        


        auto delNode(auto temp, int val) // rekursivnaya funkciya udaleniya
            //                      7
            //                     / \
            //                    3   9
            //                   / \  /
            //                  2   5 8
            //                 /   / \
            //                1   4   6
            //                         \
            //                          6.5
            {
                if(!temp) //ete datark e
                {
                    return temp; //zaglushka or hamarvi false
                }
                if(val == temp->value) //ete gtel enq
                {
                    auto tmp; //stexcenq or krnananq erdanq araj
                    if(!temp->right) //ete chuni aj terev
                    {
                        tmp = temp->left; //zaglushka
                    }
                    else //ete uni aj terev
                    {
                        auto ptr = temp->right; //jamanakavor popoxaan sarqenq u ira mej pahenq aj terevin
                        if(!ptr->left) //ete ed aj@ dzax chuni
                        {
                            ptr->left = temp->left; //or hankarc dzax chyux@ chkorcnenq
				            tmp = ptr;//zaglushka
                        }
                        else //ete vseotaki uni
                        {
                            
                            auto minimal = ptr->left;
                            
                            while(minimal->left) //ijnenq dzaxov minchev verj
                            { //ptr misht me qaylm het kexni minimalic (parent)
                                ptr  = minimal;
                                minimal = minimal->left;
                            }
                            temp->value = minimal->value; //gtac minimal arjeq@ grenq tempi mej
                            if(temp->right->left == nullptr && temp->right->right == nullptr) //ete temp aj@ terev e
                            {
                                ptr->right = nullptr;
                            }
                            else //ete temp->right left uni
                            {
                                ptr->left = nullptr;
                            }
                            destroy(minimal);
                            return temp;
                        }
                    }

                    temp->left = temp ->right = nullptr; //sranov xzum enq tempi bolor kaper@
                    destroy(temp);
		            return tmp; //banm het veradardznenq or hamarvi true
                }
                
		        else if(val < temp->value) //ete poqr e
                {
                    temp->left = delNode(temp->left, val); //erdanq dzax
                }

                else //ete mec e
                {
                    temp->right = delNode(temp->right, val); //erdanq aj
                }

                return temp;
            }        

        public:

            BST() //konstruktor po umolchaniyu
            {
            }

            BST(BST& other) //konstruktor kopirovaniya
            {
                auto temp = other.root;
                copyRec(temp);
            }

            ~BST() //destruktor
            {
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
                cout << endl;
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
                if(this == &other) //ete hamematum enq 2 nuyn obyektner@
                {
                    return true;
                }      
                if(leavesAmount != other.leavesAmount)
                {
                    return false;
                }
                return compare(root, other.root);
            }

            bool operator!= (BST& other) //operator sravneniya
            {      
                return !compare(root, other.root);
            }
            
            BST& operator= (const BST& other) //operator prisvoivoniya
            {
                if(root)
                {
                    destroy(root);
                }
                autotemp = other.root;
                copyRec(temp);
                return *this;   
            }
            
    
    };

    int main()
    {
        BST<char, char, int, float> tree;

        char arrayN[] = {'G', 'C', 'B', 'A', 'I', 'E', 'D', 'F', 'H', '?'};
        char arrayS[] = {'g', 'c', 'b', 'a', 'i', 'e', 'd', 'f', 'h', '!'};
        int arrayA[] = {70, 30, 20, 10, 90, 50, 40, 60, 80, 65};
        float arrayI[] = {0.7, 0.3, 0.2, 0.1, 0.9, 0.5, 0.4, 0.6, 0.8, 0.65};
        for (int i = 0; i < sizeof(arrayA) / sizeof(arrayA[0]); ++i)
        {
            tree.add(arrayN[i], arrayS[i], arrayA[i], arrayI[i]);
        }
        //tree.add(65);
        //tree.delValue(65);
        //tree.print();
 
        return 0;
    }