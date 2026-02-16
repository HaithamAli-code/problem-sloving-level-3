// Palindrome Matrix

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

bool PalindromeMatrix(int Array[3][3], short row, short cols)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols / 2; j++)
		{
			if (Array[i][j] != Array[i][cols - 1 - j])
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

	int Matrix_One[3][3] = {{ 1,2,1 }, { 2,1,2 }, {3,33,3}};

	//FillArrayWithRandomNumber(Matrix_One, 3, 3);
	cout << "\n\nMatrix one : \n\n";
	PrintArray(Matrix_One, 3, 3);

	if (PalindromeMatrix(Matrix_One, 3, 3))
		cout << "\n\nYes, Matrix Is Palindrome\n\n";
	else
		cout << "\n\nNo, Matrix Is Not Palindrome\n\n";

}