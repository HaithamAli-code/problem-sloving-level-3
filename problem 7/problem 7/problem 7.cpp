// Traspose Matrix

#include <iostream>
#include <iomanip>
using namespace std;

void FillArrayWithOrderNumber(int Array2D[3][3], int row, int cols)
{
	int counter = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array2D[i][j] = counter;
			counter++;
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

void TransposeMatrix(int Array2D[3][3], int row, int cols ,  int Array[3][3])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[j][i] = Array2D[i][j];
		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array2D[3][3];
	FillArrayWithOrderNumber(Array2D, 3, 3);

	cout << "\n\nThe following is a 3x3 ordered matrix:\n";
	PrintArray2D(Array2D, 3, 3);

	int Array[3][3];
	TransposeMatrix(Array2D, 3, 3, Array);
	cout << "\n\nThe following is the transposed matrix:\n";
	PrintArray2D(Array, 3, 3);
}
