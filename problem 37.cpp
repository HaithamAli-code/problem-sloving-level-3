// Split String

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string ReadText(string message)
{
	string text;
	cout << message;
	getline(cin, text);
	return text;
}



vector<string> SplitString(string text  , string delimiter)
{

	vector<string> TheWWord;

	string word = "";
	short Pos = 0;
	short count = 0;
	while ((Pos = text.find(delimiter)) != std::string::npos)
	{
		word = text.substr(0, Pos);
		if (word != "")
		{
			TheWWord.push_back(word);
		}
		text.erase(0, Pos + delimiter.length());
	}
	if (word != "")
	{
		TheWWord.push_back(text);
	}
	return TheWWord;
}

int main()
{
	vector<string> TheWWord;

	TheWWord = SplitString(ReadText("\nPlease enter Your String\n"), " ");

	cout << "\nTokens = " << TheWWord.size() << endl;

	 for (string& word : TheWWord)
	 {
		 cout << word << endl;
	 }

	system("@pause>0");
}