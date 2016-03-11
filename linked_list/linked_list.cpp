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

LinkedNode* SingleLinkedList::Remove(int value) {
	for (LinkedNode* curr = Head, *prev = nullptr; curr; prev = curr, curr = curr->Next) {
		if (curr->data == value) {
			if (!prev) {
				Head = curr->Next;
				return curr;
			}
			prev->Next = curr->Next;
			return curr;
		}
	}
	return nullptr;
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

void SingleLinkedList::Reverse() {
	LinkedNode* rev = nullptr;
	LinkedNode* curr = Head;

	while (curr) {
		LinkedNode* temp = curr->Next;
		curr->Next = rev;
		rev = curr;
		curr = temp;
	}
	Head = rev;
}


SingleLinkedListWTail::SingleLinkedListWTail() {
    Head = nullptr;
    Tail = nullptr;
}

SingleLinkedListWTail::~SingleLinkedListWTail(){
    while(Head) {
        LinkedNode* temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void SingleLinkedListWTail::Add(LinkedNode* node) {
    if (!Head) { // nullptr
        Head = node;
        Tail = node;
        return;
    }
    Tail->Next = node;
    Tail = node;
}

void SingleLinkedListWTail::Reverse() {
	LinkedNode* rev = nullptr;
	LinkedNode* curr = Head;
	Tail = Head;

	while (curr) {
		LinkedNode* temp = curr->Next;
		curr->Next = rev;
		rev = curr;
		curr = temp;
	}
	Head = rev;
}

DoubleLinkedList::DoubleLinkedList(){
    Head = nullptr;
    Tail = nullptr;
}

DoubleLinkedList::~DoubleLinkedList(){
    while(Head) {
        DoubleLinkedNode* temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void DoubleLinkedList::Add(DoubleLinkedNode* node) {
    if(!Head) {
        Head = node;
        Tail = node;
        return;
    }
    Tail->Next = node;
    node->Prev = Tail;
    Tail = node;
}

void DoubleLinkedList::Insert(DoubleLinkedNode* target, DoubleLinkedNode* toInsert) {
    // if(target == Tail) Tail = toInsert;
    toInsert->Prev = target;
    toInsert->Next = target->Next;
    target->Next->Prev = toInsert;
    target->Next = toInsert;
}

DoubleLinkedNode* DoubleLinkedList::Find(int value) {
	for (DoubleLinkedNode* curr = Head; curr; curr = curr->Next) {
		if (curr->data == value) {
			return curr;
		}
	}
    return nullptr;
}

DoubleLinkedNode* DoubleLinkedList::FindBetter(int value) {
    for (DoubleLinkedNode* curr = Head, *back = Tail; curr && back->Next != curr; curr = curr->Next, back = back->Prev) {
        if (curr->data == value) {
            return curr;
        } else if(back->data == value) {
            return back;
        }
    }
    return nullptr;
}

DoubleLinkedNode* DoubleLinkedList::Remove(int value) {
    DoubleLinkedNode* found = Find(value);
    if(found) { // special case needed for head/tail
        found->Prev->Next = found->Next;
        found->Prev->Next->Prev = found->Prev;
        found->Prev = nullptr, found->Next = nullptr;
        return found;
    }
    return nullptr;
}

bool DoubleLinkedList::Remove(DoubleLinkedNode* node) {
    for(auto curr = Head; curr; curr = curr->Next) {
        if(curr == node) {
            // special case needed for head/tail
            curr->Prev->Next = curr->Next;
            curr->Prev->Next->Prev = curr->Prev;
            curr->Prev = nullptr, curr->Next = nullptr;
            return true;
        }
    }
    return false;
}
