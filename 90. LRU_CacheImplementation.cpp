#include<bits/stdc++.h>
class Node{
    public:
        int key, value;
        Node *next, *prev;
        Node(int key, int value){
            this->key = key;
            this->value = value;
            this->prev = this->next = NULL;
        }
};
class LRUCache
{
public:
    map<int, Node*> mp;
    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);
    int cap;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node * dn){
        Node * delprev = dn->prev;
        Node * delnext = dn->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void addnode(Node * nn){
        Node* temp = head->next;
        nn->next = temp;
        nn->prev = head;
        head->next = nn;
        temp->prev = nn;
    }

    int get(int key)
    {
        if(mp.find(key)!=mp.end()){
            Node * node = mp[key];
            int res = node->value;
            mp.erase(key);
            deletenode(node);
            addnode(node);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            Node * enode = mp[key];
            mp.erase(key);
            deletenode(enode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key, value));
        mp[key] = head->next;
    }
};
