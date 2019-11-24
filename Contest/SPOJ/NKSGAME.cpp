#include <bits/stdc++.h>
#define fi frist
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;

ll res = INF;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    ll n, a[100005], b[100005];
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    sort(b + 1, b + n + 1);
    b[0] = b[n + 1] = INF;
    for(int i = 1; i <= n; i++) {
        ll x = upper_bound(b + 1, b + n + 1, a[i]) - b;
        ll y = upper_bound(b + 1, b + n + 1, -a[i]) - b;
        res = min(res, min(abs(b[x] + a[i]), abs(b[x - 1] + a[i])));
        res = min(res, min(abs(b[y] + a[i]), abs(b[y - 1] + a[i])));
    }
    cout << res;
    return 0;
}
