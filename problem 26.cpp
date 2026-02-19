// Upper/Lower All Letters of a String

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

string LowerAllLetters(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			Text[i] = tolower(Text[i]);
		}
	}
	return Text;
}

string UpperAllLetters(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			Text[i] = toupper(Text[i]);
		}
	}
	return Text;
}
int main()
{
	string MyText = ReadString("\nPlease Enter Your String :\n");

	string AfterLower = LowerAllLetters(MyText);
	string AfterUpper = UpperAllLetters(MyText);

	cout << "\nString After Lower :\n" << AfterLower << "\n";
	cout << "\nString After Upper :\n" << AfterUpper << "\n";

	system("@pause>0");
}