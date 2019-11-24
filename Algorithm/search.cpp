#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

ll pow(ll x, ll n, ll mod) {
    ll res = 1;
    ll temp = x;
    while (n > 0) {
        if (n & 1) res = res * temp % mod;
        n >>= 1;
        temp = temp * temp % mod;
    }
    return res;
}

ll n, k, res = 0, mod = 666777;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;
    res -= ((n - k) * (n - k + 1)) / 2;
    res %= mod;

    res += pow(2, n, mod);
    if(res < 0) res += mod;
    res %= mod;
    cout << res;
    return 0;
}
