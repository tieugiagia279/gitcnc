#include <bits/stdc++.h>
using namespace std;
typedef int ll;

ll multi(ll a, ll b, ll n)
{
    a = a % n; b = b % n;
    if(b == 1) return a;
    ll t = multi(a, b / 2, n) % n;
    return (b & 1) ? (t + t + a) % n : (t + t) % n;
}

ll power(ll a, ll b, ll n)
{
    a = a % n;
    if(b == 1) return a;
    ll t = power(a, b / 2, n) % n;
    return (b & 1) ? multi(t, multi(t, a, n), n) : multi(t, t, n);
}
pair<ll, ll> factor(ll n)
{
    ll s = 0;
    while (n % 2 == 0)
    {
        s++;
        n /= 2;
    }
    return {s, n};
}

bool check(ll s, ll d, ll n, ll a)
{
    if(n == a) return true;
    ll p = power(a, d, n);
    if(p == 1) return true;
    while(s > 0)
    {
        if(p == n - 1) return true;
        p = multi(p, p, n);
        s--;
    }
    return false;
}

bool miller(ll n)
{
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;
    ll s, d; pair<ll,ll> sa;
    sa = factor(n - 1);
    s = sa.first; d = sa.second;
    return check(s, d, n, 2) && check(s, d, n, 7) && check(s, d, n, 61);
}

int main()
{
	ll n;
	cin >> n;
    for(int i = 1; i <= n; i++) if(miller(i)) cout << i << endl;
	return 0;
}
