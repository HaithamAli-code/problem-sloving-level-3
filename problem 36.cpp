// Count Each Word In String

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



short CountWords(string text)
{
	cout << "\n*******************\n\a";
	string delimiter = " ";
	string word = "";
	short Pos = 0;
	short count = 0;
	while ((Pos = text.find(delimiter)) != std::string::npos)
	{
		word = text.substr(0, Pos);
		if (word != "")
		{
			count++;
		}
		text.erase(0,Pos + delimiter.length());
	}
	if (word != "")
	{
		count++;
	}
	return count;
}

int main()
{

	short CountWord = CountWords(ReadText("\nPlease enter Your String\n"));

	cout << "\nThe number of words in your string is: " << CountWord << endl;
	system("@pause>0");
}