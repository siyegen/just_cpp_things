#include <iostream>
#include "linked_list.h"

int main() {
    std::cout << "Hello world" << std::endl;
    SingleLinkedList list;
    if (!list.Head) {
        std::cout << "Hey, head is a nullptr" << std::endl;
    }
	LinkedNode* node = new LinkedNode{ 10 };
	LinkedNode* node2 = new LinkedNode{ 111 };
	list.Add(node);
	list.Add(node2);
	list.Add(new LinkedNode{ 22 });

	for (LinkedNode* curr = list.Head; curr; curr = curr->Next) {
		std::cout << "node data " << curr->data << std::endl;
	}
	LinkedNode* found = list.Find(22);
	std::cout << "found node " << found->data << std::endl;
	list.Remove(10);
	std::cout << std::endl;
	for (LinkedNode* curr = list.Head; curr; curr = curr->Next) {
		std::cout << "node data " << curr->data << std::endl;
	}
}
