// Check Scalar Matrix
#include<iostream>
using namespace std;

int RandomNumber(short from, short to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array[][3] , short row , short cols)
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

bool CheckScalarMatrix(int Array[][3], short row, short cols)
{
	short FirstElement = Array[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && Array[i][j] != FirstElement)
				return false;
			else  if (i != j && Array[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[3][3];
	//int Array[3][3] = { {15,0,0},{0,15,0},{0,0,15} };

	FillArrayWithRandomNumber(Array, 3, 3);

	cout << "\n\nMatrix : \n\n";
	PrintArray(Array, 3, 3);

	if(CheckScalarMatrix(Array,3,3))
		cout << "\n\nYES: Matrix is scalar.\n\n";
	else
		cout << "\nNo: Matrix is Not scalar.";
}