struct LinkedNode {
    int data;
    LinkedNode* Next;
};

struct DoubleLinkedNode {
    int data;
    DoubleLinkedNode* Next;
    DoubleLinkedNode* Prev;  
};

class LinkedList {
public:
    virtual ~LinkedList() {};

    virtual void Add(LinkedNode*) = 0;
    virtual void Insert(LinkedNode* target, LinkedNode* toInsert) = 0;
    virtual LinkedNode* Find(int) = 0;
    virtual LinkedNode* Remove(int) = 0;
    virtual bool Remove(LinkedNode*) = 0;
	virtual void Reverse() = 0;

    LinkedNode* Head; // Every Linked list must have a Head pointer
};

class SingleLinkedList: public LinkedList {
public:
    SingleLinkedList();
    ~SingleLinkedList();

    void Add(LinkedNode*);
    void Insert(LinkedNode* target, LinkedNode* toInsert);
    LinkedNode* Find(int);
    LinkedNode* Remove(int);
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

class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    
    void Add(DoubleLinkedNode*);
    void Insert(DoubleLinkedNode* target, DoubleLinkedNode* toInsert);
    DoubleLinkedNode* Find(int);
    DoubleLinkedNode* FindBetter(int);
    DoubleLinkedNode* Remove(int);
    bool Remove(DoubleLinkedNode*);
    void Reverse();
    
    DoubleLinkedNode* Head;
    DoubleLinkedNode* Tail;
};
