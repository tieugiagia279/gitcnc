#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;
ll a, b, c;

void check(ll x) {
    ll r = 0, k = x, m = 0, n = 0;
    while(k > 0) {
        r += k % 10;
        if(k % 10 == 0) n++;
        m = m * 10 + k % 10;
        k /= 10;
    }
    if(r % 10 == 0) {
        if(n == 0) a++;
        else b++;
    }
    else if(m == x) c++;

}

void make_phone() {
    for(int i = 100000; i <= 999999; i++) {
        check(i);
    }
}


ll t, n, m, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    make_phone();
    cout << a << " " << b << " " << c;
    return 0;
}
