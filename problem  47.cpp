// Add Clients to File

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

#include<fstream>
#include<vector>

void AddClientsToFile(string S1)
{
	fstream MyFile;
	MyFile.open("file.txt", ios::app);

	if (MyFile.is_open())
	{
		MyFile << S1 << endl;
	}
	MyFile.close();
}

void AddNewClient()
{
	sClient Client;
	Client = ReadClient();
	AddClientsToFile(ConvertRecordToLine(Client, "#//#"));
}

void AddClient()
{
	char Again = 'Y';
	do
	{
		system("cls");

		AddNewClient();
		cout << "\nDo You Want To Add More?\n";
		cin >> Again;
	} while (Again == 'Y' || Again == 'y');
}

int main()
{


	AddClient();

	system("@pause>0");
}