#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e4 + 5;
const long long MOD  =  1e9 + 7;

ll n, k, a[4 * MAXN];

void readInput() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

void subtask_1() {
    ll x[n + 5], y[n + 5];
    for(int i = 0; i <= n + 1; i++) {x[i] = 0; y[i] = 0;}
    for(int i = 1; i <= n; i++) x[i] = max(x[i - 1], a[i]);
    for(int i = n; i >= 1; i--) y[i] = max(y[i + 1], a[i]);

    ll res = -INF;
    for(int i = 2; i < n; i++) {
        res = max(res, x[i - 1] - a[i] + y[i + 1]);
    }
    cout << res;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("SEQ.inp", "r", stdin);
    freopen("SEQ.out", "w", stdout);

    readInput();
    if(k == 1) {
        subtask_1();
    }
    return 0;
}
