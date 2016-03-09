#include <functional>

struct LinkedNode {
    int data;
    LinkedNode* Next;
};

class SingleLinkedList {
public:
    SingleLinkedList();

    void Add(LinkedNode*);
    // void Insert(); // add after x node
    LinkedNode* Find(int);
    bool Remove(int);
    void Remove(LinkedNode*);

    LinkedNode* Head;

};
