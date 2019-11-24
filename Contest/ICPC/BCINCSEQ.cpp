#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;
ll T[1000005];
vector<ll> a;
vector<pair<ll,ll> > s;
void prime() {
    for(int i = 2; i <= 1e3; i++) if(T[i] == 0)
    for(int j = i * i; j <= 1e6; j += i) T[j] = 1;

    for(int i = 2; i <= 1e6; i++)
        if(T[i] == 0) a.push_back(i);
}

ll t, n, m;
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdin);

    prime();

    cin >> t;
    while(t--) {
        cin >> n;
        m = n;
        for(int i = 0; i < a.size(); i++) {
            if(m % a[i] == 0) {
                m /= a[i];

            }
        }
    }
    return 0;
}
