#include <functional>

struct LinkedNode {
    int data;
    LinkedNode* Next;
};

class SingleLinkedList {
public:
    SingleLinkedList();
    ~SingleLinkedList();

    void Add(LinkedNode*);
    void Insert(LinkedNode* target, LinkedNode* toInsert); // add after x node
    LinkedNode* Find(int);
    bool Remove(int);
    bool Remove(LinkedNode*);

    LinkedNode* Head;
};
