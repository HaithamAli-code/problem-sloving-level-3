// Sum Each Row in Matrix in Array
#include<iostream>
#include <iomanip>
#include<string>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array[3][3], int row, int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintArray2D(int Array[3][3], int row, int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << Array[i][j] << "   ";
		}
		cout << endl;
	}
}

int SumEachRow(int Array[3][3], int row, int cols)
{
	int Sum = 0;
	for (int i = 0; i < cols; i++)
	{
		Sum += Array[row][i];
	}
	return Sum;
}

void FillSumEachRow(int Array[3][3], int row, int cols , int Array_SumEachRow[3])
{
	for (int i = 0; i < row; i++)
	{
		Array_SumEachRow[i] = SumEachRow(Array , i , cols);
	}
}

void PrintArray(int Array[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum " << i + 1 << " Row : " << Array[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array2D[3][3];
	FillArrayWithRandomNumber(Array2D, 3, 3);
	PrintArray2D(Array2D, 3, 3);

	cout << "\n\n______________________________________\n\n";

	int Array_SumEachRow[3];
	FillSumEachRow(Array2D, 3, 3, Array_SumEachRow);
	PrintArray(Array_SumEachRow);

	system("pause>0");
}
