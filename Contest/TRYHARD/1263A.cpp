#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll solve(ll x, ll y, ll z) {
    ll n = max(x, max(y, z));
    if(x + y + z >= 2 * n)
        return n + (x + y + z - 2 * n) / 2;
    else
        return x + y + z - n;
}

ll t, r, g, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> t;
    while(t--) {
        cin >> r >> g >> b;
        cout << solve(r, g, b) << "\n";
    }
    return 0;
}
