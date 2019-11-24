#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

ll make_square(ll n, ll x, ll y) {
    ll num = 0, xx = 1, xy = n + 1, yx = n + 1, yy = 0;
    ll a = 1, b = 0, u = 0, v = 1;
    while(1) {
        if(u == 0 && v == 1) {
            if(b + v < xy) {b += v; num++;}
            else {u = 1; v = 0; xy--;}
        }
        else if(u == 1 && v == 0) {
            if(a + u < yx) {a += u; num++;}
            else {u = 0; v = -1; yx--;}
        }
        else if(u == 0 && v == -1) {
            if(b + v > yy) {b += v; num++;}
            else {u = -1; v = 0; yy++;}
        }
        else if(u == -1 && v == 0) {
            if(a + u > xx) {a += u; num++;}
            else {u = 0; v = 1; xx++;}
        }
        //cout << a << " " << b << " " << num << endl;
        if(a == x && b == y) return num;
    }
}
ll t, n, x, y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    cin >> t;

    while(t--) {
        cin >> n >> x >> y;
        cout << make_square(n, x, y) << endl;
    }
    return 0;
}
