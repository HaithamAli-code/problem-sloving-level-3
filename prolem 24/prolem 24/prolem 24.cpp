// Upper First Letter of Each Word
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

string UpperFirstLetter(string MyText)
{
	bool isFirstLetter = true;
	for (int i = 0; i < MyText.length(); i++)
	{
		if (MyText[i] != ' ' && isFirstLetter)
		{
			MyText[i] = toupper(MyText[i]);
		}
		isFirstLetter = (MyText[i] == ' ' ? true : false);
	}
	return MyText;
}

int main()
{
	string MyText = ReadString("\nenter your string :\n");
	MyText = UpperFirstLetter(MyText);
	cout << MyText;

	system("@pause>0");
}