//  Check Sparse Matrix
#include<iostream>
using namespace std;

int RandomNumber(int from , int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array[3][3] ,short row , short cols)
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

int CountNumberInMatrix(int Arr[][3] , short row , short cols , int number)
{
	short EqualZero = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Arr[i][j] == number)
				EqualZero++;
		}
	}
	return EqualZero;
}

bool CheckSparseMatrix(int Array[3][3], short row, short cols)
{
	short MatrixSize = row * cols;
	return CountNumberInMatrix(Array, row, cols, 0) > (MatrixSize / 2);
}

int main()
{
	int Array[3][3];
	FillArrayWithRandomNumber(Array, 3, 3);

	cout << "\n\nMatrix : \n\n";
	PrintArray(Array, 3, 3);

	if (CheckSparseMatrix(Array, 3, 3))
		cout << "\n\nYes, It Is Sparse\n\n";
	else
		cout << "\n\nNo, It Is Not Sparse\n\n";

}