// Invert Charcter Case
#include<iostream>
#include<string>
using namespace std;

char ReadString(string message)
{
	char MyChar;
	cout << message;
	cin >> MyChar;
	return MyChar;
}

char InvertCharcter(char MyChar)
{
	return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
}

int main()
{
	char MyChar = ReadString("\nEnter The Charcter : \n");
	MyChar = InvertCharcter(MyChar);
	cout << "\nChar After Invert Case : \n" << MyChar << endl;
	system("@pause>0");

}