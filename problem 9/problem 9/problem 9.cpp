// Print Middle Row and Col of Matrix
#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array[3][3] , int row , int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = RandomNumber(1,10);
		}
	}
}

void PrintArray2D(int Array[3][3], int row, int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf(" %0*d  ", 2, Array[i][j]);
		}
		cout << endl;
	}
}

void PrintRow(int Array[3][3], int row, int cols)
{
	short MiddleRow = row / 2;
	for (int j = 0; j < cols; j++)
	{
		printf(" %0*d  ", 2, Array[MiddleRow][j]);
	}
}

void PrintCols(int Array[3][3], int row, int cols)
{

	short MiddleCols = cols / 2;
	for (int j = 0; j < row; j++)
	{
		printf(" %0*d  ", 2, Array[j][MiddleCols]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[3][3];

	FillArrayWithRandomNumber(Array, 3, 3);

	cout << "\n\n3*3 Matrix : \n\n";
	PrintArray2D(Array, 3, 3);

	cout << "\n\nMiddle Row : \n\n";
	PrintRow(Array, 3, 3);

	cout << "\n\nMiddle cols : \n\n";
	PrintCols(Array, 3, 3);

	system("@pause>0");
}