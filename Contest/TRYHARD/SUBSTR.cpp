#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e6 + 7;
const long long INF  = 1e9 + 7;
const long long MOD  = 1e6 + 7;
const long long base = 263;
using namespace std;

string a, b;
ll Powx[MAXN], hashB, T[MAXN];;

ll gethash(ll i, ll j) {
    return (T[j] - T[i - 1] * Powx[j - i + 1] + MOD * MOD) % MOD;
}


int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> a >> b;
    ll lenA = a.size();
    ll lenB = b.size();
    a = " " + a;
    b = " " + b;

    Powx[0] = 1;
    for(int i = 1; i <= lenB; i++) {
        hashB = (hashB * base + b[i] - 'a' + 1) % MOD;
    }

    for(int i = 1; i <= lenA; i++) {
        T[i] = (T[i - 1] * base + a[i] - 'a' + 1) % MOD;
        Powx[i] = (Powx[i - 1] * base) % MOD;
    }

    for(int i = lenB; i <= lenA; i++) {
        if(hashB == gethash(i - lenB + 1, i)) {
            cout << i - lenB + 1 << " ";
        }
    }
    return 0;
}
