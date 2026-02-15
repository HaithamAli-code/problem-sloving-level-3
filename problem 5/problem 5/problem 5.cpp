// Sum Each Col in Matrix In Another Array
#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array2D[3][3], int row, int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array2D[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintArray2D(int Array2D[3][3], int row, int cols) 
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << Array2D[i][j] << "	";
		}
		cout << endl;
	}
}

int SumCol(int Array2D[3][3], int row, int cols)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		sum += Array2D[i][cols];
	}
	return sum;
}

void SumEachColInMatrixInAnotherArray(int Array2D[3][3], int row, int cols, int Array[])
{
	for (int i = 0; i < cols; i++)
	{
		Array[i] = SumCol(Array2D, row,i);
	}
}

void PrintArray(int Array[])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Cols " << i + 1 << "Sum : " << Array[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array2D[3][3];
	FillArrayWithRandomNumber(Array2D, 3, 3);
	PrintArray2D(Array2D, 3, 3);

	cout << "\n\n_________________________________________\n\n";

	int Array_SumEachCol[3];
	SumEachColInMatrixInAnotherArray(Array2D, 3, 3, Array_SumEachCol);
	PrintArray(Array_SumEachCol);
}
