#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pll pair<ll,ll>
const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;


bool pooled(pll &x, pll y) {
    pll s;
    if(x.fi == y.fi) {
        s.fi = x.fi;
        s.se = x.se + y.se;
    }
    else if(x.fi == y.se) {
        s.fi = x.fi;
        s.se = x.se + y.fi;
    }
    else if(x.se == y.fi) {
        s.fi = x.se;
        s.se = x.fi + y.se;
    }
    else if(x.se == y.se) {
        s.fi = x.se;
        s.se = x.fi + y.fi;
    }
    else return false;
    x = s;
    return true;
}


vector<pair<ll,ll> > a, s;
ll x, y, n;
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n;
    while(n--) {
        while(!a.empty()) a.pop_back();
        for(int i = 1; i <= 4; i++) {
            cin >> x >> y;
            a.push_back(make_pair(x, y));
        }
        sort(a.begin(), a.end());
        ll w = 10;
        ll flag = 0;
        while(w--) {
            s.clear();
            for(int i = 1; i <= 4; i++) {
                s[i].fi = a[i].fi;
                s[i].se = s[i].se;
            }
            for(int i = 0; i < s.size() - 1; i++) {
                for(int j = i + 1; j < s.size(); j++) {
                    if(pooled(s[i], s[j]) == true) {
                        s.erase(s.begin() + j);

                    }
                }
            }
            if(s.size() == 1) break;
        }
        if(s.size() == 1) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
