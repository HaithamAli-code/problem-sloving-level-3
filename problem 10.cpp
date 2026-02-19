// Sum of Matrix
#include <iostream>
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
			Array[i][j] = RandomNumber(1,100);
		}
	}
}

int SumArray(int Array[3][3], int row, int cols)
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

void PrintArray2D(int Array[3][3], int row, int cols)
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

int main()
{
	srand((unsigned)time(NULL));

    int Array[3][3];
	FillArrayWithRandomNumber(Array, 3, 3);

	cout << "\n\nMatrix 1 : \n\n";
	PrintArray2D(Array, 3, 3);

	cout << "\n\nSum of Matrix 1 : " << SumArray(Array, 3, 3) << endl;
	system("@pause>0");
}
