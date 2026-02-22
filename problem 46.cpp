// Convert Line to Record
#include <iostream>
#include <string>
using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

sClient ReadClient()
{
	sClient Client;

	cout << "\nEnter Account Number? ";
	getline(cin, Client.AccountNumber);

	cout << "\nEnter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "\nEnter Name? ";
	getline(cin, Client.Name);

	cout << "\nEnter Phone? ";
	getline(cin, Client.Phone);

	cout << "\nEnter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string ConvertToLine = "";
	ConvertToLine += Client.AccountNumber + Seperator;
	ConvertToLine += Client.PinCode + Seperator;
	ConvertToLine += Client.Name + Seperator;
	ConvertToLine += Client.Phone + Seperator;
	ConvertToLine += to_string(Client.AccountBalance) + Seperator;

	return ConvertToLine.substr(0, ConvertToLine.length() - Seperator.length());
}

#include<vector>

vector<string> SplitString(string S1, string delimiter = "#//#")
{
	vector<string> vString;

	short Pos = 0;
	string Word = "";

	while ((Pos = S1.find(delimiter)) != std::string::npos)
	{
		Word = S1.substr(0, Pos);
		if (Word != "")
		{
			vString.push_back(Word);
		}
		S1.erase(0, Pos + delimiter.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

sClient ConvertLineToRecord(string S1 ,string Seperator = "#//#")
{
	vector<string> vString = SplitString(S1, Seperator);
	
	sClient Client; 

	Client.AccountNumber = vString.at(0);
	Client.PinCode = vString.at(1);
	Client.Name = vString.at(2);
	Client.Phone = vString.at(3);
	Client.AccountBalance = stod(vString.at(4)); // casting string to Doubal
	
	return Client;
}

void PrintData(sClient Client)
{
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

int main()
{
	sClient Client = ReadClient();

	string Line = ConvertRecordToLine(Client);
	cout << "\n" << Line << "\n";

	sClient ClientAgain = ConvertLineToRecord(Line);

	PrintData(ClientAgain);

	system("@pause>0");
}