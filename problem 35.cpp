// Print Each Word In String
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

/*
void PrintEachWordInString(string text)
{
	cout << "\n*******************\n\a";
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ')
		{
			cout << endl;
			continue;
		}
		cout << text[i];
	}
}
*/

void PrintEachWordInString(string text)
{
	cout << "\n*******************\n\a";
	string delimiter = " ";
	string Word = "";
	short Position = 0;

	// use find() function to get the position of the delimiters
	while ((Position = text.find(delimiter)) != std::string::npos)
	{
		Word = text.substr(0, Position);
		if (Word != "")
		{
			cout << Word << endl;
		}
		/* erase() until positon and move to next word. */
		text.erase(0,Position + delimiter.length());
	}
	// it print last word of the string.
	if (text != "")
	{
		cout << text << endl;
	}
}

int main()
{
	PrintEachWordInString(ReadText("\nPlease enter Your String\n"));
	system("@pause>0");
}