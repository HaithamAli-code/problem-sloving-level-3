// Join String
#include<vector>
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

string JoinString(vector<string> TheWord , string Delimiter)
{
	string text = "";
	for (int i = 0; i < TheWord.size(); i++)
	{
		text.append(TheWord.at(i) + Delimiter);
	}
	text = text.substr(0, text.length() - Delimiter.length());
	return text;
}

int main()
{
	vector<string> TheWord = { "haitham" , "ali" , "bara" , "ali" };
	cout << "\n\nThe Join String : " << JoinString(TheWord , "@");
	system("@pause>0");
}