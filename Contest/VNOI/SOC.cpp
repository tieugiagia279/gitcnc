#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

ll n, res = 0, x, y;
pair<ll, ll> a[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[i].se = x - y;
        a[i].fi = x + y;

    }
    sort(a + 1, a + n + 1);
    x = 1;
    res = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i].se >= a[x].fi) {
            res++;
            x = i;
        }
    }

    cout << res;
    return 0;
}
