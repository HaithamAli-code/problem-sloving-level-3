#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector<string> SplitString(string text, string Delimiter = "#//#")
{
	vector<string> vString;

	short Pos = 0;
	string Word = "";

	while ((Pos = text.find(Delimiter)) != std::string::npos)
	{
		Word = text.substr(0, Pos);
		if (Word != "")
			vString.push_back(Word);
		text.erase(0, Pos + Delimiter.length());
	}
	if (text != "")
		vString.push_back(text);
	return vString;
}

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vString = SplitString(Line, Seperator);

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

vector<sClient> LoadDataFromFileToVector(string FileName)
{
	vector<sClient> vString;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string line;
		sClient Client;
		while (getline(MyFile, line))
		{
			Client = ConvertLineToRecord(line);

			vString.push_back(Client);
		}
	}
	MyFile.close();
	return vString;
}

void PrintAllClientData(vector<sClient> vClient)
{
	cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ")Client(s).";
	cout <<"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (sClient Client : vClient)
	{
		cout << "| " << setw(15) << Client.AccountNumber;
		cout << "| " << setw(10) << Client.PinCode;
		cout << "| " << setw(40) << Client.Name;
		cout << "| " << setw(12) << Client.Phone;
		cout << "| " << setw(12) << Client.AccountBalance;
		cout << endl;
	}
}

int main()
{
	vector<sClient> vClient = LoadDataFromFileToVector("file.txt");
	PrintAllClientData(vClient);

	system("pause>0");
	return 0;
}