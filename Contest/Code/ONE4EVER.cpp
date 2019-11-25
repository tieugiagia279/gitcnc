#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

const long long MOD  =  1e9 + 7;
const long long INF  = 1e18 + 7;
const long long MAXN =  1e5 + 7;
using namespace std;

ll m, x;
struct matrix{
    ll value[2][2];
};

ll nhan(ll a, ll b, ll m) {
    ll r = 0;
    while(b > 0) {
        if(b & 1) r = (r + a) % m;
        a = a * 2 % m;
        b = b / 2;
    }
    return r;
}

matrix multi(matrix a, matrix b) {
    matrix res;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            res.value[i][j] = 0;
            for(int k = 0; k <= 1; k++) {
                res.value[i][j] = (res.value[i][j] + nhan(a.value[i][k], b.value[k][j], m)) % m;
            }
        }
    }
    return res;
}
matrix power(matrix a, ll n) {
    if(n == 1) return a;
    matrix b = power(a, n / 2);
    if(n & 1) return mult(b, mult(b, a));
    else return mult(b, b);
}

ll t, a, b, k;
int main() {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    matrix res;
    while(t--) {
        cin >> a >> b >> m >> k;
        res.value[0][0] = 1;
        res.value[0][1] = 1;
        res.value[1][0] = 0;
        res.value[1][1] = a;
        if(k == 1) cout << b % m;
        else if(k == 2) cout << (nhan(a, b, m) + b) % m;
        else {
            res = power(res, k - 2);
            cout << nhan(b, (res.value[0][1] + nhan(res.value[1][1], (a + 1), m)), m) % m;
        }
        cout << "\n";
    }
    return 0;
}
