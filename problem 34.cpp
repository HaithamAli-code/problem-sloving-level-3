// Print All Vowels In String

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


bool IsVowel(char TheChar)
{

	TheChar = tolower(TheChar);
	return (TheChar == 'a') || (TheChar == 'e') || (TheChar == 'i') || (TheChar == 'o') || (TheChar == 'u');
}

void PrintAllVowel(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (IsVowel(text[i]))
		{
			cout << text[i] << "	";
		}
	}
}

int main()
{
	
	string text = ReadText("\nPlease Enter Your Character:\n");

	cout << "\nVowel in String :\n";
	PrintAllVowel(text);

	system("@pause>0");
}