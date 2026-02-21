// Trim String

#include<iostream>
#include<string>
using namespace std;

string ReadString(string message)
{
	string text;
	cout << message;
	getline(cin, text);
	return text;
}

string TrimStringLeft(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ')
		{
			return text.substr(i, text.length() - i);
		}
	}
	return  "";
}

string TrimStringRight(string text)
{
	for (int i = text.length() -1 ; i >= 0; i--)
	{
		if (text[i] != ' ')
		{
			return text.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string text)
{
	return (TrimStringLeft(TrimStringRight(text)));
}

int main()
{
	string text = ReadString("\nEnter Your String Please:\n");

	cout << "\nTrim Left : " << TrimStringLeft(text) << endl;
	cout << "\nTrim Right : " << TrimStringRight(text) << endl;
}