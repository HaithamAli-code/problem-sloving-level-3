// Count Number in Matrix
#include<iostream>
using namespace std;

int RandomNumber(short from, short to)
{
	return rand() % (to - from + 1) + from;
}

int ReadNumber(string messag)
{
	short number;
	cout << messag;
	cin >> number;
	return number;
}

void FillArrayWithRandomNumber(int Array[][3], short row, short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = RandomNumber(0, 9);
		}
	}
}

void PrintArray(int Array[][3], short row, short cols)
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

int CountNumberInMatrix(int Array[][3], short row, short cols , short count)
{
	short counter = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Array[i][j] == count)
			{
				counter++;
			}
		}
	}
	return counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[3][3];
	//int Array[3][3] = { {15,0,0},{0,15,0},{0,0,15} };

	FillArrayWithRandomNumber(Array, 3, 3);

	cout << "\n\nMatrix : \n\n";
	PrintArray(Array, 3, 3);

	short count = ReadNumber("\n\nEnter the number to count in matrix? \n\n");
	cout << "Number " << count << " Count In Matrix Is " << CountNumberInMatrix(Array, 3, 3, count) << endl;

	system("@pause>0");
}