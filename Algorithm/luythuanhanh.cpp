#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M;

ll multi(ll a, ll b)
{
    if(b == 1) return a;
    ll t = multi(a, b / 2) % M;
    return (b & 1) ? (t + t + a) % M : (t + t) % M;
}

ll power(ll a, ll b)
{
    if(b == 1) return a;
    ll t = power(a, b / 2) % M;
    return (b & 1) ? multi(t, multi(t, a)) : multi(t, t);
}

main()
{
    ll a, b;
    cin >> a >> b >> M;
    cout<<power(a, b);
}