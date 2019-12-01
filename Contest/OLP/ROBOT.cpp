#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll m, n, p, k, x, y, s[45][45];
char a[MAXN];

bool check(ll u, ll v) {
    if(u < 1 || u > m || v < 1 || v > n || s[u][v] == 1) return false;
    else return true;
}

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdin);

    cin >> m >> n >> p >> k;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    ll tung = 1, hoanh = 1;
    while(p--) {
        cin >> x >> y;
        s[x][y] = 1;
    }

    char us;
//    for(int i = 1; i <= k; i++) {
//        us = a[i];
//        a[i] = '0';
//        for(int i = 1; i <= k; i++) {
//            if(a[i] == 'U')
//                if(check(tung - 1, hoanh)) tung--;
//            if(a[i] == 'D')
//                if(check(tung + 1, hoanh)) tung++;
//            if(a[i] == 'L')
//                if(check(tung, hoanh - 1)) hoanh--;
//            if(a[i] == 'R')
//                if(check(tung, hoanh + 1)) hoanh++;
//        }
//        if(tung == m && hoanh == n) cout << 1, exit(0);
//        a[i] = us;
//    }
    cout << -1;
    return 0;
}
