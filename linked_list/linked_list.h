#include <functional>

struct LinkedNode {
    int data;
    LinkedNode* Next;
};

class LinkedList {
public:
    virtual ~LinkedList() {};

    virtual void Add(LinkedNode*) = 0;
    virtual void Insert(LinkedNode* target, LinkedNode* toInsert) = 0; // add after x node
    virtual LinkedNode* Find(int) = 0;
    virtual bool Remove(int) = 0;
    virtual bool Remove(LinkedNode*) = 0;
	virtual void Reverse() = 0;

    LinkedNode* Head; // Every Linked list must have a Head pointer
};

class SingleLinkedList: public LinkedList {
public:
    SingleLinkedList();
    ~SingleLinkedList();

    void Add(LinkedNode*);
    void Insert(LinkedNode* target, LinkedNode* toInsert); // add after x node
    LinkedNode* Find(int);
    bool Remove(int);
    bool Remove(LinkedNode*);
	void Reverse();
};

class SingleLinkedListWTail: public SingleLinkedList {
public:
    SingleLinkedListWTail();
    ~SingleLinkedListWTail();

    void Add(LinkedNode*);
	void Reverse();
    
    LinkedNode* Tail;
};
