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

ll n, a[MAXN], s = 1, res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        s = max(a[i], s);
        if(s == i) res++;
    }
    cout << res;
    return 0;
}
