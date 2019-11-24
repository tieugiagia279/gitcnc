#include <bits/stdc++.h>
using namespace std;
int n, x[33], t[33], su = 0;
void init()
{
	cin >> n;
	x[0] = 1;
	t[0] = 0;
}

void in(int k)
{
	int i;
	cout << n << "=";
	for(i = 1; i <= k - 1; i++)
	{
		cout << x[i] << "+";
	}
	cout << x[k];
	cout << endl;
	su++;
}
void tryy(int i)
{
	int j;
	for(j = x[i - 1]; j <= (n - t[i - 1]) / 2; j++)
	{
		x[i] = j;
		t[i] = t[i - 1] + j;
		tryy(i + 1);
	}
	x[i] = n - t[i - 1];
	in(i);
}

int main()
{
	init();
	tryy(1);
	cout << su;
	return 0;
}
