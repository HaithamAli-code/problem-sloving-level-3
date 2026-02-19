// Check Identity Matrix
#include<iostream>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumber(int Array[][3] , short row , short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = RandomNumber(0, 1);
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

bool CheckIdentityMatrix(int Array[][3], short row, short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ( i == j && Array[i][i] != 1)
				return false;
			else if (i != j && Array[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	//FillMatrixWithRandomNumber(Matrix, 3, 3);

	cout << "\n\nMatrix One : \n\n";
	PrintArray(Matrix, 3, 3);

	if (CheckIdentityMatrix(Matrix, 3, 3))
		cout << "\n\nYES: Matrix is identity.\n\n";
	else
		cout << "\n\nNo: Matrix is Not identity.\n\n";

	system("@pause>0");
}