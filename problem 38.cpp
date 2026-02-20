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

string TrimLeft(string text)
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

string TrimRight(string text)
{
	for (int i = text.length(); i < 0; i++)
	{
		if (text[i] != ' ')
		{
			return text.substr(0, i + 1); 
		}
	}
	return  "";
}

string Trim(string text)
{
	return  TrimLeft(TrimRight(text));
}

int main()
{
	string text = ReadString("\nEnter Your String Please:\n");

	cout << "\nTrim Left : " << TrimLeft(text) << endl;
	cout << "\nTrim Right : " << TrimRight(text) << endl;
}