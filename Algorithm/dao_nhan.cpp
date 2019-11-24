#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  =  1e9 + 7;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;


void dao_nhan() {
    //f[i][d] = oo;
    for(i, 1, n) {
        for(d, 1, n) {
            f[i][d] = 1e9;
        }
    }
    for(i, 1, n) f[i][1] = a[i];
    for(i, 1, n) {
        for(d, 1, i) if(f[i][d] < 1e9) {
            for(j, i + 1, n) {
                if(f[i][d + 1] > f[i][d] + a[j])
                    f[i][d + 1] = f[i][d] + a[j];
            }
        }
    }

    best = 0;
    for(i, 1, n) {
        for(d, 1, i) {
            if(f[i][d] <= W && d > best) {
                best = d;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);


    return 0;
}
