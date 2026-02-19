// 3*3 Random Matrix
#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int from , int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array2D[3][3] , short row , short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array2D[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintArray(int Array2D[3][3], short row, short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << Array2D[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array2D[3][3];

	FillArrayWithRandomNumber(Array2D,3,3);

	cout << "\nThe following is a 3x3 random matrix:\n\n";
	PrintArray(Array2D,3,3);
}

