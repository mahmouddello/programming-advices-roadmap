#include <iostream>

using namespace std;

string ReadMessage()
{
	string message;

	cout << "Please enter a message to encrypt: ";
	cin >> message;

	return message;
}

string EncryptMessage(string& message, short encryptionKey)
{

	for (int i = 0; i < message.length(); i++)
	{
		
		char encryptedChar = char(message[i]) + encryptionKey;

	/*	if (int(encryptedChar) > 90)
			encryptedChar = char(encryptedChar - 26);*/

		message[i] = encryptedChar;
	}

	return message;
}

string DecryptMessage(string& message, short encryptionKey)
{

	for (int i = 0; i < message.length(); i++)
	{

			char encryptedChar = char(message[i]) - encryptionKey;

			//if (int(encryptedChar) < 65)
			//	encryptedChar = char(encryptedChar + 26);

			message[i] = encryptedChar;
	}

	return message;
}

int main()
{
	string message = ReadMessage();

	short encryptionKey = 2;

	cout << "Text before encryption: " << message << endl;

	cout << "Text after encryption: " << EncryptMessage(message, encryptionKey) << endl;

	cout << "Text after decryption: " << DecryptMessage(message, encryptionKey) << endl;

	return 0;
}