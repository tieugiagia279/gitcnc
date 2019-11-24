#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e18 + 1;
const long long MOD = 1e9 + 7;
long long prime[10000017], n, element[10000017], result = 1;

void isPrime() {
    prime[0] = prime[1] = 1;
    for(int i = 2; i <= sqrt(n); i++)
        if(prime[i] == 0)
            for(int j = i * i; j <= n; j += i)
                prime[j] = i;

    for(int i = 2; i <= n; i++)
        if(prime[i] == 0)
            prime[i] = i;
}

void process(int k) {
    int u;
    while(k > 1) {
        u = prime[k];
        if(element[u] == 1) {
            element[u] = 0;
            result = (result * u * u) % MOD;
        }
        else {
            element[u] = 1;
        }
        k /= u;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    isPrime();
    if(n < 4) {cout << result; return 0;}

    for(int i = 2; i <= n; i++) {
        process(i);
    }

    cout << result;
    return 0;
}
