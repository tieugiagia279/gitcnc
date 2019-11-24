#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, t, a[MAXN], v[MAXN], res[MAXN], root[MAXN], value[MAXN];

ll Tim(ll x) {
    if(root[x] != x) root[x] = Tim(root[x]);
    return root[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RSEQ.inp", "r", stdin);
    freopen("RSEQ.out", "w", stdout);

    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        root[i] = i;
    }
    root[n + 1] = 0;
    for(int i = 1; i <= t; i++) {
        cin >> v[i];
        root[v[i]] = 0;
    }
    ll x = 1;
    for(int i = 1; i <= n; i++) {
        if(root[i] == 0) {
            x = i + 1;
        }
        else {
            root[i] = x;
            value[x] += a[i];
        }
        res[t] = max(res[t], value[x]);
    }
    for(int i = t; i >= 1; i--) {
        if(root[v[i] - 1] == 0) {
            root[v[i]] = v[i];
            value[v[i]] = a[v[i]];
            if(root[v[i] + 1] != 0) {
                root[v[i] + 1] = v[i];
                value[v[i]] += value[v[i] + 1];
            }
            res[i - 1] = max(res[i], value[v[i]]);
        }
        else {
            x = Tim(v[i] - 1);
            root[v[i]] = x;
            value[x] += a[v[i]];

            if(root[v[i] + 1] != 0) {
                root[v[i] + 1] = x;
                value[x] += value[v[i] + 1];
            }
        res[i - 1] = max(res[i], value[x]);
        }
    }
    for(int i = 1; i <= t; i++)
        cout << res[i] << "\n";
    return 0;
}
