// Count Letters

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

int CountLetters(string text ,  char TheChar)
{
	int count = 0;
	for (int  i = 0; i < text.length(); i++)
	{
		if (text[i] == TheChar)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	string text = ReadText("\nPlease Enter Your String:\n");
	char TheChar = ReadChar("\nPlease Enter A Character:\n");

	cout << "\nLetter " << TheChar << " count = " << CountLetters(text,TheChar) << endl;

	system("@pause>0");
}