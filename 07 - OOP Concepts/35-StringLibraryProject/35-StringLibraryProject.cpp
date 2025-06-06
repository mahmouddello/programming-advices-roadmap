#include <iostream>
#include "clsString.h"

using namespace std;

int main()
{
	clsString s1("Mahmoud Dello");
	cout << s1.length() << endl;
	cout << s1.countWords() << endl;
	s1.printFirstLetterOfEachWord();

	clsString s2("all the stars are closer");
	s2.upperFirstLetterOfEachWord();
	cout << s2.getValue() << endl;

	cout << clsString::upperFirstLetterOfEachWord("stars can't shine without darkness!") << endl;

	clsString s3("I am the danger skylar!");
	s3.upperFirstLetterOfEachWord();
	cout << s3.getValue() << endl;

	s3.lowerFirstLetterOfEachWord();
	cout << s3.getValue() << endl;

	clsString s4("hEy ChIcAgO!");

	s4.invertAllLettersCase();
	cout << s4.getValue() << endl;

	s2.printEachWordInString();

	vector<string> v1 = s2.split();

	clsString s5  = clsString::join(v1,"-");
	cout << s5.getValue() << endl;

	clsString s6 ("----Mohammed Abu Hadhoud----");
	s6.trim('-');

	cout << s6.getValue() << endl;

	s1.replaceAll("mahmoud", "Omar", true);
	cout << s1.getValue() << endl;

	return 0;
}