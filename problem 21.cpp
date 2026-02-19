// Print Fibonacci Using Loop
#include <iostream>
using namespace std;

void PrintFibonacciUsingLoop(short Number)
{
	int FebNumber = 0;
	int prev1 = 0, prev2 = 1;
	cout << "1  ";
	for (int i = 0; i < Number; i++)
	{
		FebNumber = prev1 + prev2;
		cout << FebNumber  << "  ";
		prev1 = prev2;
		prev2 = FebNumber;
	}
}

int main()
{
	PrintFibonacciUsingLoop(12);
	system("@pause>0");
}
