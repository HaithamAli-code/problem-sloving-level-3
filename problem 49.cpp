// Find Client By Account Number
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "\nPlease Enter Account Number : \n";
	getline(cin, AccountNumber);
	return AccountNumber;
}

vector<string> SplitString(string LineData, string Delimiter = "#//#")
{
	vector<string> vClient;

	short Pos = 0;
	string word;

	while ((Pos = LineData.find(Delimiter)) != std::string::npos)
	{
		word = LineData.substr(0, Pos);
		if (word != "")
		{
			vClient.push_back(word);
		}
		LineData.erase(0, Pos + Delimiter.length());
	}
	if (LineData != "")
	{
		vClient.push_back(LineData);
	}return vClient;
}

sClient ConvertLineToRecord(string LineData , string Delimiter = "#//#")
{
	vector<string> vClient = SplitString(LineData , Delimiter);
	sClient Client;


	Client.PinCode = vClient[0];
	Client.AccountNumber = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]); // casting string to double 

	return Client;
}

vector<sClient> LoadDataFormFile(string NameFile)
{
	vector<sClient> vClient;

	fstream MyFile;
	MyFile.open(NameFile, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line, "#//#");
			vClient.push_back(Client);
		}
	}
	MyFile.close();
	return vClient;
}

bool FindClientByAccountNumber(string MyAccountNumber , sClient &Client)
{
	vector<sClient> vClient = LoadDataFormFile("file.txt");

	for (sClient& c : vClient)
	{
		if (c.AccountNumber == MyAccountNumber)
		{
			Client = c;
			return true;
		}
	}
	return false;
}

void PrintDataClient(sClient client)
{

	cout << "Account Number: " << client.AccountNumber << endl;
	cout << "Name: " << client.Name << endl;
	cout << "Phone: " << client.Phone << endl;
	cout << "Account Balance: " << client.AccountBalance << endl;
	cout << "Pin Code: " << client.PinCode << endl;

}

int main()
{
	string MyAccountNumber = ReadClientAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(MyAccountNumber, Client))
		PrintDataClient(Client);
	else
		cout << "\nClient with Account Number (" << MyAccountNumber <<") is Not Found!";
		
}
