// Multiply Two Matrices

#include<iostream>
#include<iomanip>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumber(int Arr[3][3], int row , int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintArr2D(int Arr[3][3] , int row , int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//printf(" %0*d  ", 2, Arr[i][j]);
			cout << setw(3) << Arr[i][j] << "	";
		}
		cout << endl;
	}
}

void MultiplyTwoMatrices(int Arr_one[3][3], int Arr_two[3][3] , int Multiply[3][3],int row , int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Multiply[i][j] = Arr_one[i][j] * Arr_two[i][j] ;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr_one[3][3], Arr_two[3][3] , Multiply[3][3];

	FillMatrixWithRandomNumber(Arr_one, 3, 3);
	cout << "\n\nMatrix 1 : \n\n";
	PrintArr2D(Arr_one, 3, 3);
	
	FillMatrixWithRandomNumber(Arr_two, 3, 3);
	cout << "\n\nMatrix 2 : \n\n";
	PrintArr2D(Arr_two, 3, 3);

	MultiplyTwoMatrices(Arr_one, Arr_two,Multiply, 3, 3);

	cout << "\n\nMultiply : \n\n";
	PrintArr2D(Multiply, 3, 3);
}