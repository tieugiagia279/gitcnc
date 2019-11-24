//To hop do phuc tap O(n^2) theo tam giac Pascal
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll nmax = 1e3 + 1;
const ll base = 1e9 + 7;
ll n, k, ts[nmax][nmax];

void tohop()
{
	ts[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		ts[i][0] = 1;
		ts[i][i] = 1;
		for(int j = 1; j < i; j++)
			ts[i][j] = (ts[i - 1][j - 1] + ts[i - 1][j]) % base;
	}
}

int main()
{
	cin >> n >> k;
    tohop();
	cout << ts[n][k];
	return 0;
}
