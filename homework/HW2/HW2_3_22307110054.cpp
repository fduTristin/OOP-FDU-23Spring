#include <iostream>
#include <vector>

int main()
{
	std::cout<<"Enter n(1<=n<=50): ";
	int i, n, j;
	std::vector<int> A(110,0), B(110,0);
	A[0] = B[0] = 1;

	std::cin >> n;

	for (i = 2; i <= n; i++)
	{
		for (j = 0; j < 100; j++)
			B[j] *= i;
		for (j = 0; j < 100; j++)
			if (B[j] > 9)
			{
				B[j + 1] += B[j] / 10;
				B[j] %= 10;
			}
		for (j = 0; j < 100; j++)
		{
			A[j] += B[j];
			if (A[j] > 9)
			{
				A[j + 1] += A[j] / 10;
				A[j] %= 10;
			}
		}
	}
	std::cout<<"1!";
	for(i=1;i!=n;++i)
	{
		std::cout<<'+'<<i+1<<'!';
	}
	std::cout<<'=';
	for (i = 100; i >= 0 && A[i] == 0; i--);
	for (j = i; j >= 0; j--)
		std::cout << A[j];
	return 0;
}