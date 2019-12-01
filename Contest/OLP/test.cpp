#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e6 + 7;
const long long INF  = 1e18 + 7;
using namespace std;

ll n, m, a[MAXN], b[MAXN], L[MAXN], s[MAXN], res = -INF;

void brute() {
    ll res = -INF;
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            res = max(res, s[b[j]] - s[b[i] - 1]);
        }
    }
    cout << res;
}


map<ll,ll> sz;
int main() {
//    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        sz[b[i]] = 1;
    }

//    if(m <= 1000) {
//        brute();
//        return 0;
//    }

    L[0] = s[b[1] - 1];
    for(int i = 1; i <= n; i++) {
        L[i] = L[i - 1];
        if(sz[i] == 1) {
            L[i] = min(L[i], a[i]);
            res = max(res, s[i] - L[i - 1]);
        }
    }
    cout << res;
    return 0;
}
