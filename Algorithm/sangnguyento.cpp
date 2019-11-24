#include <bits/stdc++.h>
using namespace std;
int prime[1000011];

void sang()
{
	prime[0] = 1;
	prime[1] = 1;
	for(int i = 2; i <= 1000; i++)
	{
		if(prime[i] == 0)
		{
			prime[i] = i;
			for(int j = i * i; j <= 1000000; j += i)
			{
				prime[j] = i;
			}
		}
	}
	for(int i = 2; i <= 1000000; i++)
	{
		if(prime[i] == 0)
			prime[i] = i;
	}
}

int main()
{
	sang();
	for(int i = 2; i <= 1000; i++)
	{
		if(prime[i] == i)
			cout << i << endl;
	}
	return 0;
}