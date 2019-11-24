#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
int a[200][200], n, last;
stack < int > s;

void euler()
{
	int u, v, cnt;
	s.push(1);
	last = 1;
	while(last != 0)
	{
		u = s.top();
		for(v = 1; v <= n; v++)
		{
			if(a[u][v] > 0)
			{
				a[u][v]--;
				a[v][u]--;
				s.push(v);
				break;
			}
		}
		if(u == s.top())
		{
			cout << (char)(s.top() + 64) << " ";
			s.pop();
			if(cnt % 16 == 0) cout << endl;
		}
	}
}

int main()
{
	freopen("oke.inp", "r", stdin);
	cin >> n;
	int u, v;
	while(cin >> u >> v)
	{
		a[u][v]++;
		a[v][u]++;
	}
	euler();
	return 0;
}