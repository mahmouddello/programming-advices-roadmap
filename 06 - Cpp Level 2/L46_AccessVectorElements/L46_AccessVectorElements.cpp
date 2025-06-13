#include <iostream>
#include <vector>

using namespace std;

/*
    Using .at() with vectors is better becuase if we got out of range,
    we get an error or exception. accessing through index warns us about of
    range, but gives us garabge data in memory.
*/

int main()
{

    vector<int> num { 1, 2, 3, 4, 5 };

    cout << "Access elements using .at(i)" << endl;
    cout << "Elements at index 0: " << num.at(0) << endl;
    cout << "Elements at index 2: " << num.at(2) << endl;
    cout << "Elements at index 4: " << num.at(4) << endl;

    cout << "\n\nUsing [i]" << endl;
    cout << "Elements at index 0: " << num[0] << endl;
    cout << "Elements at index 2: " << num[2] << endl;
    cout << "Elements at index 4: " << num[4] << endl;

    return 0;
}
