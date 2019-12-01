#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define vll vector<long long>
#define vvll vector<vll>
#define pll pair<long long,long long>
#define vpll vector<pll>
const long long MAXN = 1e5 + 7;
const long long INF  = 1e9 + 7;
using namespace std;

vector<vpll> S(105);
vvll maxMatrix(105);
vvll resMatrix(105);
ll m, n, x, a[105];

bool ss_one(pll a, pll b) {
    return a.fi > b.fi;
}

bool ss_two(pll a, pll b) {
    return a.se < b.se;
}

void viewS() {
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < S.at(i).size(); j++)
            cout << S[i][j].fi <<" ";
        cout << "\n";
    }
}

void getmaxMatrix(vvll &a, vvll b) {
    ll flag = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] < b[i][j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }

    if(flag == 1) {
        for(int i = 1; i <= m; i++)
            for(int j = 0; j < n; j++)
                a[i][j] = b[i][j];
    }
}


ll compareSortRow(ll a, ll b) {
    vll u, v;
    for(int i = 0; i < n; i++) {
        u.push_back(S[a][i].fi);
        v.push_back(S[b][i].fi);
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    for(int i = n - 1; i >= 0; i--) {
        if(u[i] > v[i]) return a;
        if(u[i] < v[i]) return b;
    }
    return a;
}

ll compareRow(ll a, ll b) {
    vll u, v;
    for(int i = 0; i < n; i++) {
        u.push_back(S[a][i].fi);
        v.push_back(S[b][i].fi);
    }

    for(int i = 0; i < n; i++) {
        if(u[i] > v[i]) return a;
        if(u[i] < v[i]) return b;
    }
    return a;
}

void swapRow(ll a, ll b) {
    for(int i = 0; i < n; i++) {
        swap(S[a][i].fi, S[b][i].fi);
        swap(S[a][i].se, S[b][i].se);
    }
}

void swapCol(ll a, ll b) {
    for(int i = 1; i <= m; i++) {
        swap(S[i][a].fi, S[i][b].fi);
        swap(S[i][a].se, S[i][b].se);
    }
}

void solve() {
    ll maxRow = 1;
    for(int i = 2; i <= m; i++)
        if(compareSortRow(maxRow, i) == i)
            maxRow = i;
    swapRow(maxRow, 1);
    sort(S[1].begin(), S[1].end(), ss_one);

    for(int i = 0; i < n; i++) {
        a[S[1][i].se] = i + 1;
        S[1][i].se = i + 1;
    }

    for(int i = 2; i <= m; i++) {
        for(int j = 0; j < n; j++)
            S[i][j].se = a[S[i][j].se];
        sort(S[i].begin(), S[i].end(), ss_two);
    }
    for(int i = 2; i < m; i++) {
        for(int j = i + 1; j <= m; j++)
            if(compareRow(i, j) == j)
                swapRow(i, j);
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            S.at(i).push_back({x, j});
        }
    }
    solve();
    viewS();
    return 0;
}

