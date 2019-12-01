#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, k, a[MAXN];
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= k;
    }

    deque<ll> s;

    ll res = 0, maxx = 0;
    for(int i = 1; i <= n; i++) {
        s.push_back(i);
        res += a[i];

        while(res < 0) {
            res -= a[s.front()];
            s.pop_front();
        }
        if(!s.empty()) maxx = max(maxx, i - s.front() + 1);
    }

    cout << maxx;
    return 0;
}
