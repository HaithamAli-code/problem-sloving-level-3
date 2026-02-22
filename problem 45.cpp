// ConvertLinetoRecord
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
	getline(cin,Client.AccountNumber);

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

string ConvertRecordToLine(sClient Client , string Seperator = " #//# ")
{
	string ConvertToLine = "";
	ConvertToLine += Client.AccountNumber + Seperator;
	ConvertToLine += Client.PinCode + Seperator;
	ConvertToLine += Client.Name+ Seperator;
	ConvertToLine += Client.Phone+ Seperator;
	ConvertToLine += to_string(Client.AccountBalance) + Seperator;

	return ConvertToLine;
}

int main()
{
	sClient Client = ReadClient();

	cout << "\n" << ConvertRecordToLine(Client) << "\n";

	system("@pause>0");
}