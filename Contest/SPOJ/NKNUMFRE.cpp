#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const int MaxN = 1e5 + 5;


int daonguoc(int a) {
    int b = 0;
    while(a > 0) {
        b = b * 10 + a % 10;
        a /= 10;
    }
    return b;
}
long long a, b, res = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(__gcd(i, daonguoc(i)) == 1) res++;
    }
    cout << res;
    return 0;
}
