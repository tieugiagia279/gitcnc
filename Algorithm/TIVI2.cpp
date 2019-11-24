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

bool check(int a)
{
	for(int i = 2; i * i <= a; i++)
	{
		if(a % i == 0)
			return false;
	}
	return true;
}

int main()
{
	sang();
	unsigned int n, t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n <= 1000000)
		{
			for(int i = n - 1; i >= 0; i--)
			{
				if(prime[i] == i)
				{
					cout << i << endl;
					break;
				}
			}
		}
		else
		{
			for(int i = n - 1; i >= 2; i--)
			{
				if(check(i) == 1)
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}