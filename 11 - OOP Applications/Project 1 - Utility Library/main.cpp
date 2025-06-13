#include <iostream>
#include "clsUtil.h"

using namespace std;

int main()
{
	
	int x = 28;

	cout << "x value = " << x << endl;
	cout << "Is x a perfect number? " << clsUtil::isPerfectNumber(x);
	cout << "\nSum of x digits is: " << clsUtil::sumOfDigits(x);

	cout << "\n\nReverse digits of positive number 1234: " << clsUtil::reverseNumber(1234);
	cout << "\nReverse digits of negative number -1234: " << clsUtil::reverseNumber(-1234);

	cout << "\n\nDigit 4 frequnecy in (1241745849): " << clsUtil::countDigitFrequency(4, 1241745849);
	cout << "\nDigit frequnecies in (1241745849)\n";
	clsUtil::countAllDigitsFrequncies(1241745849);

	string encryptedText, decryptedText;
	encryptedText = clsUtil::encryptMessage("Mahmoud Dello", 3);
	decryptedText = clsUtil::decryptMessage(encryptedText, 3);
	cout << "\n\nEncryption of name is: " << encryptedText;
	cout << "\nDecryption of name is: " << decryptedText;

	clsUtil::sRand();
	cout << "\n\nRandom Number: " << clsUtil::randomNumber(20, 50);

	cout << "\nRandom Character: " << clsUtil::getRandomCharacter(clsUtil::capitalLetter);
	cout << "\nRandom Word: " << clsUtil::generateWord(clsUtil::mixChars, 8);
	cout << "\nRandom Key: " << clsUtil::generateKey(clsUtil::mixChars);
	cout << "\n10 Random Keys:\n"; clsUtil::generateKeys(10, clsUtil::mixChars);

	cout << "\n";

	// Swap Int
	int a = 5, b = 10;
	cout << "\nBefore Swap | A = " << a << ", B = " << b;
	clsUtil::swap(a, b);
	cout << "\nAfter Swap | A = " << a << ", B = " << b;

	// Swap String
	string name = "Mahmoud", surname = "Dello";
	cout << "\nBefore Swap | NAME = " << name << ", surname = " << surname;
	clsUtil::swap(name, surname);
	cout << "\nAfter Swap | NAME = " << name << ", surname = " << surname;

	int array[5];
	clsUtil::fillArrayWithRandomNumbers(array, 5, 20, 50);
	cout << "\n\nArrary after fill with random elements:\n";
	clsUtil::printArray(array, 5);

	clsUtil::shuffleArray(array, 5);
	cout << "\nArrary after shuffling elements:\n";
	clsUtil::printArray(array, 5);


	cout << "\nText1 ";  clsUtil::tabs(3);  cout << "Text2" << endl;

	cout << endl;
	return 0;
}