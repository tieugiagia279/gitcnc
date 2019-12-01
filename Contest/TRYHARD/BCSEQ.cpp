#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

ll n, m, a[MAXN];
map<ll,ll> Trongso;
deque<ll> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll res = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        s.push_back(i);
        if(Trongso[a[i]] == 0) res++;
        Trongso[a[i]]++;
        while(!s.empty() && res > m) {
            Trongso[a[s.front()]]--;
            if(Trongso[a[s.front()]] == 0) res--;
            s.pop_front();
        }
        ans = max(i - s.front() + 1, ans);
    }
    cout << ans;
    return 0;
}
