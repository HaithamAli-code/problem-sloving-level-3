// Print Fibonacci Using Recursion
#include <iostream>
using namespace std;

void PrintFibonacciUsingRecursion(short Number , int prev1 , int prev2 )
{
	int FebNumber = 0;
	if (Number > 0)
	{
		FebNumber = prev1 + prev2;
		cout << FebNumber << "  ";
		prev1 = prev2;
		prev2 = FebNumber;
		PrintFibonacciUsingRecursion(Number - 1, prev1, prev2);
	}
	//for (int i = 0; i < Number; i++)
	//{
	//	FebNumber = prev1 + prev2;
	//	cout << FebNumber << "  ";
	//	prev1 = prev2;
	//	prev2 = FebNumber;
	//}
}

int main()
{
	cout << "1  ";
	PrintFibonacciUsingRecursion(12 , 0 , 1);
	system("@pause>0");
}
