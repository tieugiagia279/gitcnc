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


ll n, k, a[MAXN];
ll brute() {
    vll binary, solve;
    ll res = INF, ans;
    for(int i = 1; i <= k; i++) binary.push_back(0);
    for(int i = k + 1; i <= n; i++) binary.push_back(1);
    do {
        solve.clear();
        ans = 0;
        for(int i = 1; i <= n; i++) if(binary[i - 1] == 1) solve.push_back(a[i]);
        for(int i = 1; i < solve.size(); i++) ans = max(ans, abs(solve[i] - solve[i - 1]));
        res = min(res, ans);
    } while(next_permutation(binary.begin(), binary.end()));
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n <= 15) cout << brute();
    return 0;
}
