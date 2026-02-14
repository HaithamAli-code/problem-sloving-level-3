// Sum Each Col in Matrix
#include <iostream>
#include<iomanip>
using namespace std;


int RandomNumber(int from , int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array2D[3][3] , int row , int cols)
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
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << Array2D[i][j] << "	";
		}
		cout << endl;
	}
}

int SumNumber(int Array2D[3][3], int row, int cols)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		sum += Array2D[i][cols];
	}
	return sum;
}

void PrintSumEachColInMatrix(int Array2D[3][3], int row, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		cout << "Sum " << i + 1 << "cols : " << SumNumber(Array2D , row , i) << endl;
	}
}

int main()
{

	srand((unsigned)time(NULL));

	int Array2D[3][3];
	FillArrayWithRandomNumber(Array2D, 3, 3);
	PrintArray2D(Array2D, 3, 3);
	
	cout << "\n\n__________________________________\n\n";

	PrintSumEachColInMatrix(Array2D, 3, 3);
	system("@pause>0");
}