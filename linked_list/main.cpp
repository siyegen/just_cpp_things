#include <iostream>
#include <chrono>
#include "linked_list.h"

void printList(const LinkedList&);
void printList(const DoubleLinkedList&);
void printListReverse(const DoubleLinkedList&);
void sampleSingleLinkedList();
void sampleDoubleLinkedList();

int main() {
    std::cout << "Hello world" << std::endl;
    sampleSingleLinkedList();
    // sampleDoubleLinkedList();
}

void sampleDoubleLinkedList() {
    DoubleLinkedList list;
    // DoubleLinkedNode* node = new DoubleLinkedNode{1,nullptr, nullptr};
    // DoubleLinkedNode* node2 = new DoubleLinkedNode{4,nullptr, nullptr}; 
    // list.Add(node);
    // list.Add(node2);
    // list.Add(new DoubleLinkedNode{70,nullptr, nullptr});
    // list.Add(new DoubleLinkedNode{7,nullptr, nullptr});
    // list.Insert(node2, new DoubleLinkedNode{9, nullptr, nullptr});
    // printListReverse(list);
    // DoubleLinkedNode* found = list.Find(70);
    int length = 100000000;
    int idx = length*0.25;
    for(int i=0; i<length; i++) {
        list.Add(new DoubleLinkedNode{i, nullptr, nullptr});
    }
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    start = std::chrono::steady_clock::now();
    DoubleLinkedNode* found = list.Find(idx);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedFind = end-start;
    if (found) std::cout << "Found it" << std::endl;
    
    start = std::chrono::steady_clock::now();
    DoubleLinkedNode* found2 = list.FindBetter(idx);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedFindBetter = end-start;
    if (found2) std::cout << "Found it" << std::endl;
    std::cout << "Finished finding, Find:" << elapsedFind.count() << "s";
    std::cout << " FindBetter:" << elapsedFindBetter.count() << "s" << std::endl;
}

void sampleSingleLinkedList() {
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

void printList(const DoubleLinkedList &list) {
	for (DoubleLinkedNode* curr = list.Head; curr; curr = curr->Next) {
		std::cout << "node data " << curr->data << std::endl;
	}
}

void printListReverse(const DoubleLinkedList &list) {
	for (DoubleLinkedNode* curr = list.Tail; curr; curr = curr->Prev) {
		std::cout << "node data " << curr->data << std::endl;
	}
}
