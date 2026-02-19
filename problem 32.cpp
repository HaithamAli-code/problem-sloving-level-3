// Is Vowel?

#include<iostream>
#include<string>
using namespace std;

string ReadText(string message)
{
	string text;
	cout << message;
	getline(cin, text);
	return text;
}

char ReadChar(string message)
{
	char TheChar;
	cout << message;
	cin >> TheChar;
	return TheChar;
}

bool IsVowel(char TheChar)
{

	TheChar = tolower(TheChar);
	return (TheChar == 'a') || (TheChar == 'e') || (TheChar == 'i') || (TheChar == 'o') || (TheChar == 'u');
}

int main()
{
	char TheChar = ReadChar("\nPlease Enter A Character:\n");

	if (IsVowel(TheChar))
		cout << "yes, letter " << TheChar << " is Vowel ." << endl;
	else
		cout << "No, letter " << TheChar << " is not Vowel ." << endl;

	system("@pause>0");
}