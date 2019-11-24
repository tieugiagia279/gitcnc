#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

ll p[5005], s[5005];

void make_exp() {
    for(int i = 1; i <= 5000; i++) {
        p[i] = i;
    }
    for(int i = 1; i <= 5000; i++) {
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) {
                p[i] = min(p[i], p[j] + p[i / j] + 2);
            }
        }
    }

    for(int i = 1; i <= 5000; i++) {
        s[i] = p[i];
        for(int j = 1; j <= i - 1; j++) {
            s[i] = min(s[i], s[j] + s[i - j] + 2);
        }
    }
}

ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("exp.inp", "r", stdin);
    freopen("exp.out", "w", stdout);

    make_exp();
    while(cin >> n) {
        cout << s[n] << endl;
    }
    return 0;
}
