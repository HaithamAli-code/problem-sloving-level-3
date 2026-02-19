// Count Letters (Match Case)

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

int CountLetters(string text, char TheChar , bool MatchCase = true)
{
	int count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (MatchCase)
		{


			if (text[i] == TheChar)
				count++;
		}
		else
		{
			if (tolower(text[i]) == tolower(TheChar))
				count++;
		}
	}
	return count;
}

char InvertLetterCase(char TheChar)
{

	return islower(TheChar) ? toupper(TheChar) : tolower(TheChar);
}

int main()
{
	string text = ReadText("\nPlease Enter Your String:\n");
	char TheChar = ReadChar("\nPlease Enter A Character:\n");

	cout << "\nLetter " << TheChar << " count = " << CountLetters(text, TheChar) << endl;
	cout << "\nLetter " << TheChar << " or " << InvertLetterCase(TheChar)
		<< " count = " << CountLetters(text, TheChar, false) << endl;

	system("@pause>0");
}