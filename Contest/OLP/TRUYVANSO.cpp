#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, q, x, y, a[MAXN], b[MAXN];

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        if(a[i + 1] - a[i] > 1) b[i] = a[i] + 1;
    }
    b[n] = a[n] + 1;
    for(int i = n; i >= 1; i--) if(b[i] == 0) b[i] = b[i + 1];
    while(q--) {
        cin >> x >> y;
        cout << min(b[x], a[y] + 1) << "\n";
    }
    return 0;
}
