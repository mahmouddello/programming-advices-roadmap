#include <iostream>
#include "homework12.h"


int main()
{   
    // first way to write a new line in c++ with the escape charachter \n
    std::cout << "Mahmoud Dello\n";
    std::cout << "Software Engineering\n";

    // second way to write a new line in c++ by using `endl`
    std::cout << "GitHub: mahmouddello" << std::endl;

    // print multiple message with one cout statement
    std::cout << "M1 " << "M2 " << "M3\n\n";
    std::cout << "- HOMEWORK -\n" << "-----------------------\n";

    questionOne();
    questionTwo();
    questionThree();
    questionFour();


    return 0;
}
