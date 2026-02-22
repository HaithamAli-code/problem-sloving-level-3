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

string ReplaceWordInString(string S1 , string StringToReplace , string ReplaceTo)
{
	short Pos = 0;
	while ((Pos = S1.find(StringToReplace)) != std::string::npos)
	{
		S1 = S1.replace(Pos, StringToReplace.length(), ReplaceTo);
	}
	return S1;
}

int main()
{
	string S1 = ReadString();

	string StringToReplace = "jordan";
	string ReplaceTo = "USA";

	cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo);

	system("@pause>0");
}

