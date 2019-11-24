#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
const long long MOD  = 1e9 + 7;
using namespace std;
struct matrix{
    ll data[2][2];
};

matrix mult(matrix a, matrix b) {
    matrix c;
    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 1; j++) {
            c.data[i][j] = 0;
            for(int k = 0; k <= 1; k++)
                c.data[i][j] = (c.data[i][j] + a.data[i][k] * b.data[k][j]) % MOD;
        }
    return c;
}

matrix power(matrix a, ll n) {
    if(n == 1) return a;
    matrix b = power(a, n / 2);
    if(n & 1) return mult(b, mult(b, a));
    else return mult(b, b);
}

ll n;
int main() {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdin);

    cin >> n;
    matrix a;
    a.data[0][0] = 0;
    a.data[1][0] = a.data[1][1] = a.data[0][1] = 1;

    matrix b = power(a, n);
    cout << (b.data[1][0]) % MOD;
    return 0;
}
