#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

ll n, a[MaxN], k, mn = INF, x, y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for(int i = k; i <= n; i++) {
        x = abs(a[i]);
        y = abs(a[i - k + 1]);
        if(a[i] * a[i - k + 1] >= 0) {
            mn = min(mn, max(x, y));
        }
        mn = min(mn, min(x * 2 + y, y * 2 + x));
    }

    cout << mn;
    return 0;
}
