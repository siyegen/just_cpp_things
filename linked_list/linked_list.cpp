#include "linked_list.h"

SingleLinkedList::SingleLinkedList() {
    Head = nullptr;
}

void SingleLinkedList::Add(LinkedNode* node) {
    if (!Head) { // nullptr
        Head = node;
        return;
    }
    LinkedNode* curr = Head;
    while(!curr->Next) {
        curr = curr->Next;
    }
    curr->Next = node;
}