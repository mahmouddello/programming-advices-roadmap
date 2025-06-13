#include <iostream>

/*
	Algorithm #2 - O(n) [Input size effects result becuase of looping]
	Assuming each step takes the same time to get executed, and n = 6;
	1. Getting the length of the word
	2. Substracting 1 to get the last index
	3. Defining and assigning the last index to length variable
	4. Defining i = 0
	(4 steps outside of for loop)
	1. i <= length comparision
	2. i++
	3. if (i==length)
		4. passing index i to word
		5. getting the character in the index
		6. returning the value
	(3n + 3 steps inside the loop)

	Big O = 3n + 7 [Remove the factors] -> = Big O = O(n)

*/ 
char getLastCharacter2(const std::string& word)
{
	int length = word.length() - 1;

	for (int i = 0; i <= length; i++)
		if (i == length)
			return word[i];
}

int main()
{
    std::cout << "Hello World!\n";
}

