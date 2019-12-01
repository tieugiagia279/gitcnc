#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, a[MAXN], L[MAXN], R[MAXN], LX[MAXN], RX[MAXN], res[MAXN];
char h[MAXN];
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdin);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        if(h[i] == 'E') res[i] = n - i;
        else res[i] = i - 1;
    }

    stack<ll> s;
    s.push(1);
    for(int i = 2; i <= n; i++) {
        while(!s.empty() && a[i] > a[s.top()]) {
            R[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        R[s.top()] = n + 1;
        s.pop();
    }
    s.push(n);
    for(int i = n - 1; i >= 1; i--) {
        while(!s.empty() && a[i] > a[s.top()]) {
            L[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        L[s.top()] = 0;
        s.pop();
    }

    for(int i = 1; i <= n; i++) {
        RX[R[i] + 1]--;
        RX[i] += RX[i - 1];
    }

    for(int i = n; i >= 1; i--) {
        LX[L[i] - 1]--;
        LX[i] += LX[i + 1];
    }
    for(int i = 1; i <= n; i++) {
        if(h[i] == 'E') res[i] += LX[i];
        else res[i] += RX[i];
        cout << res[i] << " ";
    }
    return 0;
}
