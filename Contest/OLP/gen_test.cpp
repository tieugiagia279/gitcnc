#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e6 + 7;
const long long INF  = 1e18 + 7;
using namespace std;

ll n, m, x, res = -INF;

int range(int l, int r) {
    return l + rand() % (r - l + 1);
}

ll brute(vector<ll> a, vector<ll> b) {
    int n = a.size(), m = b.size();
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i - 1];
    ll res = -INF;
    for(int i = 0; i < m; i++) {
        for(int j = i; j < m; j++) {
            res = max(res, sum[b[j]] - sum[b[i] - 1]);
        }
    }
    return res;
}

ll solve(vector<ll> a, vector<ll> b) {
    ll res = -INF;
    int n = a.size(), m = b.size();
    vector<ll> sum(n + 1, 0);
    vector<ll> L(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i - 1];
    for (int i = 0; i < m; ++i) res = max(res, sum[b[i]]);
    vector<ll> s(n + 1, 0);
    ll sz = 0;
    for(int i = 1; i < m; i++) {
        sz++;
        s[sz] = sum[b[i]] - sum[b[i - 1] - 1];
        sz++;
        s[sz] = sum[b[i] - 1] - sum[b[i]];
    }
    sz--;
    for(int i = 1; i <= sz; i++) s[i] += s[i - 1];
    for(int i = 1; i <= sz; i++) L[i] = min(L[i - 1], s[i]);

    for(int i = 1; i <= sz; i++) {
        res = max(res, s[i] - L[i - 1]);
    }
    cout << 1;
    return res;
}

void stress_test() {
    for (int t = 0; t < 1000; ++t) {
        int n = range(1, 10);
        int m = range(1, n);
        vector<ll> a(n);
        vector<ll> b(m);
        for (int i = 0; i < n; ++i) a[i] = range(-10, 10);
        for (int i = 0; i < m; ++i) b[i] = range(1, n);
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        if (b.size() == 1) continue;

        ll expect = brute(a, b);
        ll result = solve(a, b);
        // ll result = solve(a, b);
        if (expect != result) {
            cout << n << ' ' << b.size() << endl;
            for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl;
            for (int i = 0; i < b.size(); ++i) cout << b[i] << ' '; cout << endl;
            cerr << "expect = " << expect << endl;
            cerr << "result = " << result << endl;
            return;
        }
    }
    cerr << "passed all" << endl;
}

int main() {
    freopen("wrong.txt", "w", stdout);
    stress_test();
    return 0;
}
