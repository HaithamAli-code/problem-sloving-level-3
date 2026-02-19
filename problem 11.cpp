// Check Matrices Equality
#include <iostream>
using namespace std;
int RandomNumber(short int from, short int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array[][3], short int row, short int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintArray(int Array[][3], short int row, short int cols)
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

int SumMatrix(int Array[][3], int row, int cols)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += Array[i][j];
		}
	}
	return sum;
}

bool CheckMatricesEquality(int Matrix_1[3][3],int Matrix_2[3][3] ,short int row , short int cols)
{
	return (SumMatrix(Matrix_1, row, cols) == SumMatrix(Matrix_2, row, cols));
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix_1[3][3], Matrix_2[3][3];

	FillArrayWithRandomNumber(Matrix_1, 3, 3);
	cout << "\n\nMatrix One : \n\n";
	PrintArray(Matrix_1, 3, 3);

	FillArrayWithRandomNumber(Matrix_2, 3, 3);
	cout << "\n\nMatrix Two : \n\n";
	PrintArray(Matrix_2, 3, 3);

	bool EqualMatrix = CheckMatricesEquality(Matrix_1, Matrix_2, 3, 3);

	if (EqualMatrix)
		cout << "\n\nYes, Matrices Are Equal\n\n";
	else
		cout << "\n\nNo, Matrices Are Not Equal\n\n";
}
