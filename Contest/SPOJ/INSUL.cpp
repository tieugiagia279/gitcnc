#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;

int n, a[MaxN], res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {cin >> a[i]; res += a[i];}

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n / 2; i++) {
        res += a[n - i + 1] - a[i];
    }
    cout << res;
    return 0;
}
