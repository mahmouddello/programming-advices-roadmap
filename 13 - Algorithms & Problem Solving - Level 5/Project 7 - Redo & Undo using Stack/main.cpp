#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
	clsMyString s1;

	s1.value = "";
	cout << "s1 = " << s1.value << endl;

	s1.value = "Mahmoud";
	cout << "\ns1 = " << s1.value << endl;

	s1.value = "Mahmoud2";
	cout << "\ns1 = " << s1.value << endl;

	s1.value = "Mahmoud3";
	cout << "\ns1 = " << s1.value << endl;

	cout << "\n----------------\nUndo:\n----------------";

	s1.undo();
	cout << "\ns1 = " << s1.value << endl;

	s1.undo();
	cout << "\ns1 = " << s1.value << endl;

	s1.undo();
	cout << "\ns1 = " << s1.value << endl;

	s1.undo();

	cout << "\n----------------\nredo:\n----------------";

	s1.redo();
	cout << "\ns1 = " << s1.value << endl;

	s1.redo();
	cout << "\ns1 = " << s1.value << endl;

	s1.redo();
	cout << "\ns1 = " << s1.value << endl;

	s1.redo();


	return 0;
}