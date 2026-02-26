// 
#include<iostream>
#include<string>
#include<fstream>
#include <limits>
#include<vector>
using namespace std;

string Name_File = "file.txt";

string ReadString(string Message)
{
	string text;
	cout << Message;
	getline(cin, text);
	return text;
}

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector<string> SplitString(string line, string Delimiter = "#//#")
{
	vector<string> vString;

	short pos = 0;
	string word = "";

	while ((pos = line.find(Delimiter)) != std::string::npos)
	{
		word = line.substr(0, pos);
		if (word !="")
		{
			vString.push_back(word);
		}
		line.erase(0, pos + Delimiter.length());
	}
	if (line != "")
		vString.push_back(line);

	return vString;
}

sClient ConvertDataFromLineToRecord(string line , string Delimiter = "#//#")
{
	vector<string> vString = SplitString(line , Delimiter);

	sClient Client;
	Client.PinCode = vString[0];
	Client.AccountNumber = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

vector<sClient> LoadDataFromFile(string NameFile)
{
	vector<sClient> vClient;

	fstream MyFile;
	MyFile.open(NameFile, ios::in);

	if (MyFile.is_open())
	{
		string line;
		sClient Client;
		while (getline(MyFile,line))
		{
			Client = ConvertDataFromLineToRecord(line, "#//#");
			vClient.push_back(Client);
		}
	}
	MyFile.close();
	return vClient;
}

bool FindClintByAccountNumber(string MyAccountNumber , vector<sClient> vClient  , sClient &Client)
{
	for (sClient C : vClient)
	{
		if (C.AccountNumber == MyAccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintDataClient(sClient Client)
{
	cout << "\n| Account Number:" << Client.AccountNumber;
	cout << "\n| Pin Code:" << Client.PinCode;
	cout << "\n| Client Name:" << Client.Name;
	cout << "\n| Phone:" << Client.Phone;
	cout << "\n| AccountBalance:" << Client.AccountBalance;
	cout << "\n";
}

sClient ReadClientData(string AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n| Enter The Pin Code : ";
	getline(cin, Client.PinCode);

	cout << "\n| Enter The Name Client : ";
	getline(cin, Client.Name);

	cout << "\n| Enter The Phone : ";
	getline(cin, Client.Phone);

	cout << "\n| Enter The AccountBalance: ";
	cin >> Client.AccountBalance;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return Client;
}

string ConvertDataFromLRecordToLine(sClient Client , string Delimiter = "#//#")
{
	string line = "";
	line += Client.PinCode + Delimiter;
	line += Client.AccountNumber + Delimiter;
	line += Client.Name + Delimiter;
	line += Client.Phone + Delimiter;
	line += to_string(Client.AccountBalance);

	return line;
}

void LoadDataFromVectorToFile( string NameFile , vector<sClient> vClient)
{
	fstream MyFile;
	MyFile.open(NameFile, ios::out);

	if (MyFile.is_open())
	{
		string line;		
		for (sClient C : vClient)
		{
			line = ConvertDataFromLRecordToLine(C);
			MyFile << line << endl;
		}
	}
	MyFile.close();

}

void UpdateDataClient(string MyAccountNumber)
{
	vector<sClient> vClient = LoadDataFromFile(Name_File);
	sClient Client;

	if (FindClintByAccountNumber(MyAccountNumber , vClient , Client))
	{
		PrintDataClient(Client);

		char Answer = 'y';
		cout << "\nAre you sure you want update this client? y/n ?";
		cin >> Answer;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (tolower(Answer) == 'y')
		{
			for (sClient& C : vClient)
			{
				if (C.AccountNumber == MyAccountNumber)
				{
					C = ReadClientData(MyAccountNumber);
					break;
				}
			}
			LoadDataFromVectorToFile(Name_File,vClient);
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << MyAccountNumber << ") Not Found!\n";
	}
}

int main()
{
	string MyAccountNumber = ReadString("\nPlease Enter Your Account Number: ");
	UpdateDataClient(MyAccountNumber);

	system("@pause>0");
}