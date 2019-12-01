#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 5e4 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll m, n, k, a[MAXN], b[MAXN];
map<ll,ll> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];


    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            s[a[i]+b[j]]++;
        }
    }
    for(map<ll,ll>::iterator it = s.begin(); it != s.end(); it++) {
        for(int i = 1; i <= it->second; i++) {
            cout << it->first << "\n";
            k--;
            if(k == 0) return 0;
        }
    }
    return 0;
}
