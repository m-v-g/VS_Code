Node pop(int l, int p)
        {
            Node* iterator = head;
            if(l == head->login)
            {
                head = head -> next;
                head -> prev = nullptr;
                -- listsQuantity;
                Node temp(iterator->login, iterator->password);
                delete iterator;
                return temp;
            }
            if(l == tail->login)
            {
                iterator = tail;
                tail = tail -> prev;
                tail -> next = nullptr;
                -- listsQuantity;
                Node temp(iterator->login, iterator->password);
                delete iterator;
                return temp;
            }
            while (iterator->login != l)
            {
                if(iterator == tail)
                {
                    Node temp(-1, -1);
                    return temp;
                }
                iterator = iterator -> next;
            }
            iterator->next->prev = iterator->prev;
            iterator->prev->next = iterator->next;
            iterator->next = iterator->prev = nullptr;
            -- listsQuantity;
            Node temp(iterator->login, iterator->password);
            delete iterator;
            return temp;
        }