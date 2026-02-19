// Count Vowel

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

short CountVowel(string text)
{
	short count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (IsVowel(text[i]))
		{
			count++;
		}
	}
	return count;
}

int main()
{

	string text = ReadText("\nPlease Enter Your String:\n");

	cout << "\ncount Vowel :" << CountVowel(text) << endl;
	
	system("@pause>0");
}	