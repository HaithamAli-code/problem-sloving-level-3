// Invert All Letters Case
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

char InvertCharcter(char MyChar)
{
	return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
}

string InvertAllLetters(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = InvertCharcter(text[i]);
	}
	return text;
}

int main()
{
	string text = ReadString("\nEnter The Charcter : \n");
	text = InvertAllLetters(text);
	cout << "\nText After Invert Case : \n" << text << endl;
	system("@pause>0");

}

