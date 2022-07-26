if(!temp) //!ete khandipenq zroyakan ukazatel
                {
                    ++ leavesAmount;
                    temp = new Node<TypeA>(x);
                    return true;
                }
                else if(comparator->hamematel(x, temp->value) == 0)
                //else if(x == temp->value)
                {
                    bool ret = add(x, temp->right); //rekursiv kanchenq es funkcian bayc arden @ntacikic aj
                    temp->right->parent = temp; //kanchic het galuc heto 
                    return false;
                }
                else if(comparator->hamematel(x, temp->value) == -1)
                //else if(x < temp->value) //ete x poqr e @ntaciqi valuic uremn kerdanq dzax
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