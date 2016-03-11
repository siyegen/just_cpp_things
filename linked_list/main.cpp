#include <iostream>
#include "linked_list.h"

void printList(const LinkedList&);

int main() {
    std::cout << "Hello world" << std::endl;
    SingleLinkedListWTail list;
    
	LinkedNode* node = new LinkedNode{ 10, nullptr };
	LinkedNode* node2 = new LinkedNode{ 111, nullptr };
	list.Add(node);
	list.Add(node2);
	list.Add(new LinkedNode{ 22, nullptr });

	printList(list);
	LinkedNode* found = list.Find(22);
	std::cout << "found node " << found->data << std::endl;
	list.Remove(10);
	std::cout << "\nAfter remove 10"<< std::endl;
    
	printList(list);
    list.Add(new LinkedNode{ 89, nullptr });
	std::cout << "\nAdded node 89"<< std::endl;
    
	printList(list);
    list.Remove(node2);
    
	std::cout << "\nAfter remove 111"<< std::endl;
	printList(list);
    
    LinkedNode* toInsert = new LinkedNode{600, nullptr};
    list.Insert(found, toInsert);
    
	std::cout << "\nAfter insert 600"<< std::endl;
	printList(list);
    
    for (int i = 0; i < 10; i++) {
        list.Add(new LinkedNode{i+100, nullptr});
    }
    delete node2;
    delete node;
    
    std::cout << "Before reverse: tail->" << list.Tail->data << std::endl;
	printList(list);
	list.Reverse();
    std::cout << "\n\nReversing: tail->" << list.Tail->data << std::endl;
	printList(list);
}

void printList(const LinkedList &list) {
	for (LinkedNode* curr = list.Head; curr; curr = curr->Next) {
		std::cout << "node data " << curr->data << std::endl;
	}
}
