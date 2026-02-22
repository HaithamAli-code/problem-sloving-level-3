// Reverse Word In String
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

vector<string> SplitString(string S1 , string Delimiter)
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

string ReverseWordInString(string S1)
{
	vector<string> vString;

	vString = SplitString(S1, " ");

	vector<string>::iterator i = vString.end();

	string S2 = "";
	while (i != vString.begin())
	{
		i--;
		S2 = S2 + *i + " ";
	}
	return (S2.substr(0,S2.length() - 1));
}

int main()
{
	string S1 = ReadString();

	cout << "\n" << ReverseWordInString(S1) << "\n";
}
