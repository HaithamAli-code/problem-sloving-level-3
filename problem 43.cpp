#include <iostream>
#include<string>
#include<vector>
using namespace std;

string ReadString()
{
	string S;
	cout << "\nEnter Your String Please \n";
	getline(cin, S);
	return S;
}

vector<string> SplitString(string S1, string Delimiter)
{
	vector<string> vString;

	short Pos = 0;
	string Word = "";

	while ((Pos = S1.find(Delimiter)) != std::string::npos)
	{
		Word = S1.substr(0, Pos);
		if (Word != "")
		{
			vString.push_back(Word);
		}
		S1.erase(0, Pos + Delimiter.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

string LowerAllString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

string JoinString(vector<string> vString, string Delimiter)
{
	string S2 = "";
	for (string& WORD : vString)
	{
		S2 = S2 + WORD + Delimiter;
	}
	return S2.substr(0, S2.length() - Delimiter.length());
}

string ReplaceWordInString(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{
	vector<string> vString = SplitString(S1, " ");

	for (string& Word : vString)
	{
		if (MatchCase)
		{
			if (Word == StringToReplace)
			{
				Word = ReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(Word) == LowerAllString(StringToReplace))
			{
				Word = ReplaceTo;
			}
		}
	}
	return JoinString(vString, " ");
}

int main()
{
	string S1 = ReadString();

	string StringToReplace = "jordan";
	string ReplaceTo = "USA";

	cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo, false);

	system("@pause>0");
}

