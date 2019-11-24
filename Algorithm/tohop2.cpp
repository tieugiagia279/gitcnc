
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll nmax = 1e6 + 5;
const ll base = 1e9 + 7;
ll n, k, s[nmax];

void fact()
{
    s[0] = 1;
    for (ll i = 1; i <= 1e6; i++)
    s[i] = s[i - 1] * i % base;
}

ll multi(ll n, ll p)
{
    ll r = 1;
    while (p > 0)
    {
        if (p & 1)
            r = r*n % base;
        p >>= 1;
        n = n * n % base;
    }
    return r;
}
ll tohop(ll k, ll n)
{
    ll a = s[n - k] * s[k] % base;
    ll r = s[n] * multi(a, base - 2) % base;
    return r;
}

int main()
{
	cin >> n >> k;
    fact();
	cout << tohop(k, n);
	return 0;
}
