// Min/Max Number in Matrix

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
			Array[i][j] = RandomNumber(1, 100);
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

int ReturnMaxNumberFromArray(int Array[3][3] , short row , short cols)
{
	short MaxNumber = 0;
	for (int i = 0; i < row; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (Array[i][j] > MaxNumber)
				MaxNumber = Array[i][j];
		}
	}
	return MaxNumber;
}


int ReturnMinNumberFromArray(int Array[3][3], short row, short cols)
{
	short MinNumber = Array[0][0];
	for (int i = 0; i < row; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (MinNumber > Array[i][j])
				MinNumber = Array[i][j];
		}
	}
	return MinNumber;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix_One[3][3];

	FillArrayWithRandomNumber(Matrix_One, 3, 3);
	cout << "\n\nMatrix one : \n\n";
	PrintArray(Matrix_One, 3, 3);

	cout << "\n\nMax Number = " << ReturnMaxNumberFromArray(Matrix_One, 3, 3) << "\n\n";
	cout << "\n\nMin Number = " << ReturnMinNumberFromArray(Matrix_One, 3, 3) << "\n\n";
	
}