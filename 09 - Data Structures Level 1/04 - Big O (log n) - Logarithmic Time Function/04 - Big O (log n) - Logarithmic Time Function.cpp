#include <iostream>
using namespace std;

int count_divisions(int number) {
    // Count how many times we can divide a number by 2
    int count = 0;

    while (number > 1) {
        number = number / 2;  // Integer division
        count++;
        cout << "Step " << count << ": " << number << endl;
    }

    return count;
}

int main() {
    cout << "Dividing 100 by 2 repeatedly:" << endl;
    int steps = count_divisions(100);
    cout << "Total steps: " << steps << endl;

    cout << "\nDividing 1000 by 2 repeatedly:" << endl;
    steps = count_divisions(1000);
    cout << "Total steps: " << steps << endl;

    return 0;
}

// Time complexity analysis:
// - Number 8: takes 3 steps (log2(8) = 3)
// - Number 100: takes ~7 steps (log2(100) = 6.6)
// - Number 1000: takes ~10 steps (log2(1000) = 9.97)
// - Number 1,000,000: takes ~20 steps (log2(1,000,000) = 19.93)