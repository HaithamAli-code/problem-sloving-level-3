// Lower First Letter of Each Word

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

string LowerFirstLetter(string MyText)
{
	bool isFirstLetter = true;
	for (int i = 0; i < MyText.length(); i++)
	{
		if (MyText[i] != ' ' && isFirstLetter)
		{
			MyText[i] = tolower(MyText[i]);
		}
		isFirstLetter = (MyText[i] == ' ' ? true : false);
	}
	return MyText;
}

int main()
{
	string MyText = ReadString("\nPlease Enter Your String :\n");

	MyText = LowerFirstLetter(MyText);
	cout << "\n" << MyText << "\n";

	system("@pause>0");
}