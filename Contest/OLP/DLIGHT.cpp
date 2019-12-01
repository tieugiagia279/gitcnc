#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e6 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, t, x, y, res = 0;
map<ll,ll> a;
vector<pair<ll,ll> > s;
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdin);

    cin >> n >> t;
    for(int i = 1; i <= t; i++) {
        cin >> x >> y;
        a[x]++;
        a[y + 1]--;
    }
    s.push_back(make_pair(1, 0));
    for(map<ll,ll>::iterator it = a.begin(); it != a.end(); it++) {
        s.push_back(make_pair(it->first, it->second));
    }

    if(s[s.size() - 1].fi != n + 1) s.push_back(make_pair(n + 1, 0));
    for(int i = 1; i < s.size(); i++) {
        s[i].second += s[i - 1].second;
        if(s[i - 1].se % 3 == 0) {
            res += s[i].fi - s[i - 1].fi;
        }
    }
    cout << res;
    return 0;
}
