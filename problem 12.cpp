// Check Typical Matrices
#include <iostream>
using namespace std;

int RandomNumber(int from , int to)
{
	return rand() % (to - from + 1) + from;
}

void FillArrayWithRandomNumber(int Array[3][3], short  int row, short int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintArray(int Array[3][3], short  int row, short int cols)
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

bool CheckTypicalMatrices(int Matrix_1[3][3],int Matrix_2[3][3] , short int row ,short int cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Matrix_1[i][j] != Matrix_2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));
	//+++++++++++++++++++++
	int Matrix_1[3][3], Matrix_2[3][3];
	//+++++++++++++++++++++
	FillArrayWithRandomNumber(Matrix_1, 3, 3);
	cout << "\n\nMatrix One : \n\n";
	PrintArray(Matrix_1, 3, 3);
	//+++++++++++++++++++++
	FillArrayWithRandomNumber(Matrix_2, 3, 3);
	cout << "\n\nMatrix Two : \n\n";
	PrintArray(Matrix_2, 3, 3);
	//+++++++++++++++++++++
	bool TypicalMatrices = CheckTypicalMatrices(Matrix_1,Matrix_2, 3, 3);
	if (TypicalMatrices)
		cout << "\n\nYes: martices are  equal.";
	else
		cout << "\n\nNo: martices are NOT equal.\n\n";
	//+++++++++++++++++++++
	system("@pause>0");
}