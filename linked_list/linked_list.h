// #pragma once

struct LinkedNode {
    int data;
    LinkedNode* Next;  
};

class SingleLinkedList {
public:
    SingleLinkedList();
    
    void Add(LinkedNode*);
    // void Insert();
    void Find(int);
    void Remove(int);
    void Remove(LinkedNode*);
    
    LinkedNode* Head;
    
};