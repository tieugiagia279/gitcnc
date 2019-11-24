#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;

ll n, k, d, a[MAXN], w[30], hero[30];
char x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    while(cin >> n >> k >> d) {
        memset(hero, 0, sizeof(hero));
        ll result = 0;
        for(int i = 1; i <= n; i++) {
            cin >> x;
            a[i] = int(x) - 96;
        }
        for(int i = 1; i <= d; i++) cin >> w[i];


    }
    return 0;
}
