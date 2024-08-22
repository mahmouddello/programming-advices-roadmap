#include <iostream>

using namespace std;

// array is passed by reference
void ReadArrayData(int x[3]) {

    cout << "Please enter number 1: ";
    cin >> x[0];

    cout << "Please enter number 2: ";
    cin >> x[1];

    cout << "Please enter number 3: ";
    cin >> x[2];

}

void PrintArrayData(int x[3]) {
    
    cout << x[0] << endl;
    cout << x[1] << endl;
    cout << x[2] << endl;


}

// -------------- HOMEWORK --------------

void ReadGrades(float grades[3])
{
    cout << "Please enter grade 1: ";
    cin >> grades[0];

    cout << "Please enter grade 2: ";
    cin >> grades[1];

    cout << "Please enter grade 3: ";
    cin >> grades[2];
}

float CalculateAverage(float grades[3])
{

    cout << grades[2] << endl;

    return (grades[0] + grades[1] + grades[2]) / 3;

}

int main() {
    float x[3];

    ReadGrades(x);
    
    cout << "The average of grades is = " << CalculateAverage(x) << endl;

    return 0;
}
