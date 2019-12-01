#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

const long long MOD  =  1e9 + 7;
const long long INF  = 1e18 + 7;
const long long MAXN =  1e4 + 7;
const long long base = 1046527;
using namespace std;
ll TS[MAXN], TX[MAXN], Powx[MAXN];

ll gethashS(ll i, ll j) {
    return (TS[j] - TS[i - 1] * Powx[j - i + 1] + MOD * MOD) % MOD;
}

ll gethashX(ll i, ll j) {
    return (TX[i] - TX[j + 1] * Powx[j - i + 1] + MOD * MOD) % MOD;
}

string s, x;
ll q, xx, Doixung[MAXN];
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    cin >> s >> q;
    ll lenS = s.size();
    s = " " + s;

    Powx[0] = 1;
    for(int i = 1; i <= lenS; i++) {
        Powx[i] = (Powx[i - 1] * base) % MOD;
        TS[i] = (TS[i - 1] * base + s[i] - 'a' + 1) % MOD;
        TX[lenS - i + 1] = (TX[lenS - i + 2] * base + s[lenS - i + 1] - 'a' + 1) % MOD;
    }


    ll chan = 0, le = 0;
    for(ll xx = 1; xx <= lenS; xx++) {
        for(int i = 1; i <= lenS - xx + 1; i++) {
            if(gethashS(i, i + xx - 1) == gethashX(i, i + xx - 1)) {
                Doixung[xx] = 1;
            }
        }
    }

    while(q--) {
        cin >> xx;
        if(Doixung[xx] == 1) cout << 1;
        else cout << 0;
        cout << "\n";
    }
    return 0;
}
