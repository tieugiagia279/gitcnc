#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll t, k, a, b, n, w, root[MAXN];
char s;
ll Tim(ll x) {
    while(x != root[x]) {
        x = root[x];
    }
    return x;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);


    cin >> t;
    ll tt = 1;
    while(t--) {
        cout << "Case #" << tt << ":\n";
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> w;
            if(w == 0) root[i] = i;
            else root[i] = w;
        }
        while(k--) {
            cin >> s >> a;
            if(s == 'C') {
                root[a] = a;
            }
            else {
                cin >> b;
                if(Tim(a) == Tim(b)) cout << "YES";
                else cout << "NO";
                cout << "\n";
            }
        }
        tt++;
    }
    return 0;
}
