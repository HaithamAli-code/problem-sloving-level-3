// Intersected Numbers in Matrices
#include<iostream>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}



void FillArrayWithRandomNumber(int Array[3][3], short row, short cols)
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

bool IsNumberInMatrix(int Array_2[3][3], short row, short cols , short number)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Array_2[i][j] == number)
			{
				return true;
			}
		}
	}
	return false;
}

void PrintIntersectedNumbers(int Array[3][3], short row, short cols, int Array_2[3][3])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int Number = Array[i][j];
			if (IsNumberInMatrix(Array_2,row ,cols,Number))
			{
				cout << Number << "	";
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix_One[3][3] , Matrix_two[3][3];
	
	FillArrayWithRandomNumber(Matrix_One, 3, 3);
	cout << "\n\nMatrix one : \n\n";
	PrintArray(Matrix_One, 3, 3);

	FillArrayWithRandomNumber(Matrix_two, 3, 3);
	cout << "\n\nMatrix two : \n\n";
	PrintArray(Matrix_two, 3, 3);

	cout << "\n\nMatrix three : \n\n";
	PrintIntersectedNumbers(Matrix_One, 3, 3 , Matrix_two);
}