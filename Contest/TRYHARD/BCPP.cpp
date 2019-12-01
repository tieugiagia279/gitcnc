#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e6 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

bool TongUoc(ll x) {
    ll res = 1;
    if(x == int(sqrt(x)) * int(sqrt(x))) res += int(sqrt(x));
    for(int i = 2; i < sqrt(x); i++) {
        if(x % i == 0) {
            res = res + i + x / i;
            if(res > x) return true;
        }
    }
    return false;
}

void brute(ll L, ll R) {
    ll res = 0;
    for(int i = L; i <= R; i++) {
        if(TongUoc(i) == true)
            res++;
    }
    cout << res;
}
ll a[MAXN];
void solve(ll L, ll R) {
    ll res = 0;
    for(int i = 1; i <= 1e6; i++) {
        ll j = 1;
        while(i * j <= 1e6) {
            a[i * j] += i;
            j++;
        }
    }
    for(int i = L; i <= R; i++) {
        if(a[i] - i > i) res++;
    }
    cout << res;
}

ll L, R;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> L >> R;
    solve(L, R);
    return 0;
}
