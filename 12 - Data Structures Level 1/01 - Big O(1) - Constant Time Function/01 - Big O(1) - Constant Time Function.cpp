#include <iostream>

// Algorithm #1
// 4 [Steps] * O(1) = O(1) [Constant Time]
char getLastCharacter(const std::string& word)
{
	return word[word.length() - 1];
}

// Algorithm #2 - O(n) [Input size effects result becuase of looping]
char getLastCharacter2(const std::string& word)
{
	int length = word.length() - 1;

	for (int i = 0; i <= length; i++)
		if (i == length)
			return word[i];
}

int main()
{

	std::cout << getLastCharacter("Mahmoud") << std::endl;
	std::cout << getLastCharacter2("Mahmoud") << std::endl;

	return 0;
}
