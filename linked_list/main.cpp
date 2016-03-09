#include <iostream>
#include "linked_list.h"

int main() {
    std::cout << "Hello world" << std::endl;
    SingleLinkedList list;
    if (!list.Head) {
        std::cout << "Hey, head is a nullptr" << std::endl;
    }
}