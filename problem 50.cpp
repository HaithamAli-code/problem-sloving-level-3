// Delete Client By Account Number
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

string ReadAccountNumber()
{
	cout << "\nPlease Enter Your Account Number:\n";
	string text;
	getline(cin, text);
	return text;
}

vector<string> SplitString(string line , string Delimiter = "#//#")
{
	short Pos = 0;
	string word = "";

	vector<string> vString;

	while ((Pos = line.find(Delimiter)) != std::string::npos)
	{
		word = line.substr(0, Pos);
		if (word != "")
		{
			vString.push_back(word);
		}
		line.erase(0, Pos + Delimiter.length());
	}
	if (line != "")
	{
		vString.push_back(line);
	}
	return vString;
}

sClient ConvertFromLineToRecord(string line , string Delimiter = "#//#")
{
	sClient Client;
	vector<string> vString = SplitString(line, Delimiter);

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
		while (getline(MyFile, line))
		{
			Client = ConvertFromLineToRecord(line, "#//#");
			vClient.push_back(Client);
		}
	}
	MyFile.close();
	return vClient;
}

void PrintDataClient(sClient client)
{
	cout << "\nAccount Number: " << client.AccountNumber << endl;
	cout << "Name: " << client.Name << endl;
	cout << "Phone: " << client.Phone << endl;
	cout << "Account Balance: " << client.AccountBalance << endl;
	cout << "Pin Code: " << client.PinCode << endl;
}

bool FindClientByAccountNumber(string MyAccountNumber , sClient &Client , vector<sClient> vClient)
{

	for (sClient C : vClient)
	{
		if (C.AccountNumber == MyAccountNumber)
		{
			Client = C; // All Data Client
			return true;
		}
	}
	return false;
}

bool MarkFroDeleteClient(vector<sClient>& vClient , string MyAccountNumber)
{
	for (sClient& Client : vClient)
	{
		if (Client.AccountNumber == MyAccountNumber)
		{
			Client.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

string ConvertDataFromRecordToLine(sClient Client , string Delimiter = "#//#")
{
	string Line = "";

	Line += Client.PinCode + Delimiter;
	Line += Client.AccountNumber + Delimiter;
	Line += Client.Name + Delimiter;
	Line += Client.Phone + Delimiter;
	Line += to_string(Client.AccountBalance);

	return Line;
}

void SavaClientDataToFile(string NameFile, vector<sClient> vClient)
{
	fstream MyFile;
	MyFile.open(NameFile, ios::out);

	string Line;
	if (MyFile.is_open())
	{
		for (sClient C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				Line = ConvertDataFromRecordToLine(C);
				MyFile << Line << endl;
			}
		}
	}
	MyFile.close();
}

bool DeleteClientFromFile(vector<sClient>& vClient , string MyAccountNumber)
{
	sClient Client;
	char Ansar = 'n';
	if (FindClientByAccountNumber(MyAccountNumber , Client , vClient))
	{
		PrintDataClient(Client);

		cout << "\nAre You Sure You Want Delete This Client? (Y,N)\n";
		cin >> Ansar;
		if (tolower(Ansar) == 'y')
		{
			MarkFroDeleteClient(vClient, MyAccountNumber);
			SavaClientDataToFile("file.txt", vClient);

			vClient = LoadDataFromFile("file.txt");
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << MyAccountNumber << ") is Not Found!";
		return false;
	}
}

int main()
{
	string MyAccountNumber = ReadAccountNumber();
	vector<sClient> vClient = LoadDataFromFile("file.txt");

	DeleteClientFromFile(vClient, MyAccountNumber);;

	system("@pause>0");
	return 0;
}