#include <iostream>
#include <vector>
#include <stack>

int main() {
    // Create a vector and a stack of integers
    std::vector<int> vec;
    std::stack<int> stk;

    // Add elements
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
        stk.push(i);
    }

    std::cout << "Vector contents: ";
    // Access elements by index and iterate
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Stack contents (top to bottom): ";
    // Access stack elements by popping (no indexing)
    std::stack<int> temp = stk; // copy to print without modifying original
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << "\n";

    // Access the last element (top)
    std::cout << "Vector last element (back): " << vec.back() << "\n";
    std::cout << "Stack top element (top): " << stk.top() << "\n";

    // Remove last element
    vec.pop_back();
    stk.pop();

    std::cout << "After pop_back/pop:\n";

    std::cout << "Vector contents: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::cout << "Stack contents (top to bottom): ";
    temp = stk;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << "\n";

    // Trying to access vector elements by index after pop_back
    std::cout << "Access vector element at index 1: " << vec[1] << "\n";

    // Cannot access stack elements by index, no code for that here

    return 0;
}
