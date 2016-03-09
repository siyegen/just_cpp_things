#include "linked_list.h"

SingleLinkedList::SingleLinkedList() {
    Head = nullptr;
}

SingleLinkedList::~SingleLinkedList(){
    while(Head) {
        LinkedNode* temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void SingleLinkedList::Add(LinkedNode* node) {
    if (!Head) { // nullptr
        Head = node;
        return;
    }
    LinkedNode* curr = Head;
    while(curr->Next) {
        curr = curr->Next;
    }
    curr->Next = node;
}

void SingleLinkedList::Insert(LinkedNode* target, LinkedNode* toInsert) {
    toInsert->Next = target->Next;
    target->Next = toInsert;
    return;
}

LinkedNode* SingleLinkedList::Find(int value) {
	for (LinkedNode* curr = Head; curr; curr = curr->Next) {
		if (curr->data == value) {
			return curr;
		}
	}
	return nullptr;
}

bool SingleLinkedList::Remove(int value) {
	for (LinkedNode* curr = Head, *prev = nullptr; curr; prev = curr, curr = curr->Next) {
		if (curr->data == value) {
			if (!prev) {
				Head = curr->Next;
				return true;
			}
			prev->Next = curr->Next;
			return true;
		}
	}
	return false;
}

bool SingleLinkedList::Remove(LinkedNode* node) {
	for (LinkedNode* curr = Head, *prev = nullptr; curr; prev = curr, curr = curr->Next) {
        if (curr == node) {
			if (!prev) {
				Head = curr->Next;
				return true;
			}
            prev->Next = curr->Next;
            return true;
        }
    }
    return false;
}
