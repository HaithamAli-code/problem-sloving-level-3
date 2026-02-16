#pragma once
#include<iostream>
using namespace std;

namespace myLib
{
	void PrintArray1D(int arr[] , int length)
	{
		for (int i = 0 ; i < length ; i++)
		{
			cout << arr[i] << " ";
		}
	}

	int RandomNumber(short from , short to)
	{
		return rand() % (to - from + 1) + from;
	}

	void FillMatrixWithRandomNumber(int Matrix[3][3] , short row, short cols)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Matrix[i][j] = RandomNumber(1,100);
			}
		}
	}

	void PrintMatrix(int Matrix[3][3], short row, short cols)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				printf("  %0*d   ", 2, Matrix[i][j]);
			}
			cout << endl;
		}
	}

	int SumEachRowInMatrix(int Matrix[3][3], short row, short cols)
	{
		int Sum = 0;
		for (int i = 0; i < cols; i++)
		{
			Sum += Matrix[row][i];
		}
		return Sum;
	}

	void PrintSumEachRowInMatrix(int Matrix[3][3], short row, short cols)
	{
		for (int i = 0; i < row; i++)
		{
			cout << "Sum " << i + 1 << " Row : " << SumEachRowInMatrix(Matrix,i,cols) << endl;
		}
	}

	int SumEachColsInMatrix(int Matrix[3][3], short row, short cols)
	{
		int Sum = 0;
		for (int i = 0; i < row; i++)
		{
			Sum += Matrix[i][cols];

		}
		return Sum;
	}

	void PrintSumEachColsInMatrix(int Matrix[3][3], short row, short cols)
	{
		for (int i = 0; i < cols; i++)
		{
			cout << "Sum " << i + 1 << " cols : " << SumEachColsInMatrix(Matrix,row,i) << endl;
		}
	}

	void TrasposeMatrix(int Matrix[3][3], short row, short cols, int Matrix_tow[3][3])
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Matrix_tow[i][j] = Matrix[j][i];
			}
		}
	}

	void MultiplyTwoMatrices(int Matrix[3][3], short row, short cols, int Matrix_tow[3][3], int Multiply_matrix[3][3])
	{
		for (int i = 0; i < row; i++)
		{
			for (int j  = 0; j < cols; j++)
			{
				Multiply_matrix[i][j] = Matrix[i][j] * Matrix_tow[i][j];
			}
		}
	}

	void PrintMiddleRow(int Matrix[3][3], short row, short cols)
	{
		short MiddleRow = row / 2;
		for (int i = 0; i < cols; i++)
		{
			printf("  %0*d   ", 2, Matrix[MiddleRow][i]);
		}
	}

	void PrintMiddleRow(int Matrix[3][3], short row, short cols)
	{
		short MiddleCols = cols / 2;
		for (int i = 0; i < row; i++)
		{
			printf("  %0*d   ", 2, Matrix[i][MiddleCols]);
		}
	}

	int SumOfMatrix(int Matrix[3][3] , short row , short cols)
	{
		int Sum = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				Sum += Matrix[i][j];
			}
		}
		return Sum;
	}

	bool CheckMatricesEquality(int Matrix[3][3], short row, short cols , int Matrix_tow[3][3])
	{
		return (SumOfMatrix(Matrix, 3, 3)) == (Matrix_tow, 3, 3);
	}

	// نفس الشكل
	bool CheckTypicalMatrices(int Matrix[3][3], short row, short cols, int Matrix_tow[3][3])
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (Matrix[i][j] != Matrix_tow[i][j])
					return false;
			}
		}
		return true;
	}

	// القطر   متشابه في القيمة
	bool CheckIdentityMatrixZ(int Matrix[3][3], short row, short cols)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (i == j && Matrix[i][j] != 1)
					return false;
				else if (i != j && Matrix[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	bool CheckScalaMatrix(int Matrix[3][3], short row, short cols)
	{
		short FirstElement = Matrix[0][0];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (i == j && Matrix[i][j] != FirstElement)
					return false;
				else if (i != j && Matrix[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	int CountNumberInMatrix(int Matrix[3][3], short row, short cols, short count)
	{
		short counter = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (Matrix[i][j] == count)
				{
					counter++;
				}
			}
		}
		return counter;
	}

	int CountNumberInMatrix(int Matrix[][3], short row, short cols, int number)
	{
		short EqualZero = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (Matrix[i][j] == number)
					EqualZero++;
			}
		}
		return EqualZero;
	}

	//  الارقام الموجوده اكثر من الصفر 
	bool CheckSparseMatrix(int Matrix[3][3], short row, short cols)
	{
		short MatrixSize = row * cols;
		return CountNumberInMatrix(Matrix, row, cols, 0) > (MatrixSize / 2);
	}

	//الرقم موجود في المصفوفة
	bool NumberExistsInMatrix(int Array[3][3], short row, short cols, short number)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (Array[i][j] == number)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool IsNumberInMatrix(int Array_2[3][3], short row, short cols, short number)
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

	// الرقم موجد في الماتركس الاول و في الماتركس الثاني
	void PrintIntersectedNumbers(int Array[3][3], short row, short cols, int Array_2[3][3])
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int Number = Array[i][j];
				if (IsNumberInMatrix(Array_2, row, cols, Number))
				{
					cout << Number << "	";
				}
			}
		}
	}

	int ReturnMaxNumberFromArray(int Array[3][3], short row, short cols)
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
}