#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
#define vpll vector<pll>

const long long MAXN = 1e6 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, m, x;
ll a[MAXN], b[MAXN], Summ[MAXN], Left[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Summ[i] = Summ[i - 1] + a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    Left[1] = Summ[b[1] - 1];
    for(int i = 2; i <= m; i++) {
        Left[i] = min(Left[i - 1], Summ[b[i] - 1]);
    }

    ll res = -INF;
    for(int i = 1; i <= m; i++) {
        res = max(res, Summ[b[i]] - Left[i]);
    }
    cout << res;
    return 0;
}
