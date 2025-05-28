#include <iostream>
#include "text.h"

int main() {
    text t1("Hello");
    text t2(" World");
    text t3 = t1 + t2;

    std::cout << "t1: " << t1 << std::endl;
    std::cout << "t2: " << t2 << std::endl;
    std::cout << "t3 (t1 + t2): " << t3 << std::endl;

    std::cout << "Length of t3: " << t3.length() << std::endl;
    std::cout << "Capacity of t3: " << t3.capacity() << std::endl;

    t3 += "!";
    std::cout << "After adding '!': " << t3 << std::endl;

    t3.pop_back();
    std::cout << "After pop_back(): " << t3 << std::endl;

    std::cout << "Character at position 1: " << t3.at(1) << std::endl;

    t3[0] = 'h';
    std::cout << "Modified first character: " << t3 << std::endl;

    text t4 = t3.substr(0, 5);
    std::cout << "Substring of first 5 characters: " << t4 << std::endl;

    return 0;
}
