#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

int n, m, a[10005], f[10005];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {cin >> a[i]; a[i] += a[i - 1];}
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        for(int j = 1; j <= m; j++) {
            if(i >= 2 * j) {
                f[i] = max(f[i], f[i - 2 * j] + a[i - j] - a[i - 2 * j]);
            }
        }
    }
    cout << f[n];
    return 0;
}
