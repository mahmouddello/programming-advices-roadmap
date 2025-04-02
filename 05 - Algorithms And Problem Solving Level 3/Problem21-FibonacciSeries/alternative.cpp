//#include <iostream>
//#include <iomanip>
//#include "D:/MyCPP_Libs/InputsLib.h"
//
//using namespace std;
//
//void Print1DArray(int* array, int length) {
//    for (int i = 0; i < length; i++) {
//        cout << setw(4) << array[i];  // Using array[i] instead of *(array + i)
//    }
//    cout << endl;
//}
//
//void FibonacciSeries(int* array, int length) {
//    if (length < 2) return; // Ensure there are at least two elements
//
//    for (int i = 2; i < length; i++) {
//        array[i] = array[i - 2] + array[i - 1];  // Use array[i] for better readability
//    }
//}
//
//int main() {
//    int fibonacci_length = InputsLib::ReadPositiveNumber("Fibonacci of? ");
//
//    if (fibonacci_length < 2) {
//        cout << "Fibonacci sequence requires at least 2 terms.\n";
//        return 1;
//    }
//
//    int* arrayPtr = new int[fibonacci_length] {};  // Ensure it's zero-initialized
//
//    // First 2 elements must be initialized manually
//    arrayPtr[0] = 1;
//    arrayPtr[1] = 1;
//
//    FibonacciSeries(arrayPtr, fibonacci_length);
//    Print1DArray(arrayPtr, fibonacci_length);
//
//    delete[] arrayPtr;  // Prevent memory leak
//
//    return 0;
//}
