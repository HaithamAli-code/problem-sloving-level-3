// Number Exists In Matrix
#include<iostream>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

int ReadNumber(string Message)
{
	int number;
	cout << Message;
	cin >>number;
	return number;
}

void FillArrayWithRandomNumber(int Array[3][3], short row, short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = RandomNumber(0, 9);
		}
	}
}

void PrintArray(int Array[3][3], short row, short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("  %0*d   ", 2, Array[i][j]);
		}
		cout << endl;
	}
}

bool NumberExistsInMatrix(int Array[3][3], short row, short cols ,short number)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Array[i][j] == number)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[3][3];
	FillArrayWithRandomNumber(Array, 3, 3);

	cout << "\n\nMatrix : \n\n";
	PrintArray(Array, 3, 3);

	short Number = ReadNumber("\n\nPlease Enter the number to look for in matrix?\n\n");

	if (NumberExistsInMatrix(Array, 3, 3 , Number))
		cout << "\n\nYes it is there.\n\n";
	else
		cout << "\n\nNo it is Not there\n\n";

}