#include <iostream>

void printFizzBuzz(int, int);
void printFizzBuzz(int);

int main() {
    std::cout << "~FizzBuzz~" << std::endl;
    printFizzBuzz(0,25);
}

void printFizzBuzz(int start, int end) {
    for (; start<=end; start++) {
        printFizzBuzz(start);
    }
}

void printFizzBuzz(int specific) {
    if (specific % 3 == 0 && specific % 5 == 0) {
        std::cout << "FizzBuzz" << std::endl;
    } else if (specific % 3 == 0) {
        std::cout << "Fizz" << std::endl;
    } else if (specific % 5 == 0) {
        std::cout << "Buzz" << std::endl;
    } else {
        std::cout << specific << std::endl;
    }
}