#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

ll n, a, res, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n;
    if(n > 10) exit(0);
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(i % 2 == 1) {
            res += a;
            k++;
        }
    }
    cout << fixed << setprecision(2);
    cout << (float)res / (float)k;
    return 0;
}
