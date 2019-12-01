#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e3 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll m, n, a[MAXN][MAXN], ans = 0, res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            ans += a[i][j] * 4 + 2;
            res = res + min(a[i][j], a[i][j + 1]) + min(a[i][j], a[i][j - 1]) + min(a[i][j], a[i - 1][j]) + min(a[i][j], a[i + 1][j]);
        }
    }

    cout << ans - res - m * n;
    return 0;
}
