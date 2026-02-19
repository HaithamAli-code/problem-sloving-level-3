// Count Small/Capital Letters
#include<iostream>
#include<string>
using namespace std;

string ReadText(string message)
{
	string text;
	cout << message;
	getline(cin, text);
	return text;
}

enum EnWhatToCount { Small = 1, Capital = 2 };

short CountLetter(string text , EnWhatToCount WHatToCount)
{
	short count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (WHatToCount == EnWhatToCount::Small && islower(text[i]))
			count++;
		else if (WHatToCount == EnWhatToCount::Capital && isupper(text[i]))
			count++;
	}
	return count;
}

int CountSmallLetter(string text)
{
	int count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (islower(text[i]))
		{
			count++;
		}
	}
	return count;
}

int CountCapitalLetter(string text)
{
	int count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]))
		{
			count++;
		}
	}
	return count;
}

void Print(short Length ,short Small, short Capital )
{
	cout << "\nstring length : " << Length << endl;
	cout << "\nSmall Letter Count : " << Small << endl;
	cout << "\nCapital Letter Count : " << Capital << endl;
}

int main()
{
	string text = ReadText("\nEnter Your Text : \n");
	
	int Small = CountSmallLetter(text);
	int Capital = CountCapitalLetter(text);
	int Length = text.length();

	Print(Length,Small,Capital);
}