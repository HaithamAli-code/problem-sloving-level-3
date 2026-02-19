// Print First Letter of Each Word
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

void ReturnFirstLetter(string text)
{
	bool isFirstLetter = true;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ' && isFirstLetter)
		{
			cout << text[i] << endl;
		}
		isFirstLetter = (text[i] == ' ' ? true : false);
	}
}

int main()
{
	string MyString = ReadString("\nPlease Enter Your String :\n");
	cout << "\nFirst Letter Of The String : \n";
	ReturnFirstLetter(MyString);
}