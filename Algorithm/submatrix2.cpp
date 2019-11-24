#include <bits/stdc++.h>
using namespace std;
#define FOR(_i,_a,_b) for(int _i = _a; _i <= _b; _i++)
#define FOX(_i,_a,_b) for(int _i = _a; _i >= _b; _i--)
#define ll long long
const ll nmax = 305;
const ll INF = 1e9 + 7;

ll t, n, m, k, c;
ll s[nmax][nmax];
ll a[nmax][nmax][nmax], b[nmax][nmax][nmax];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> m >> n >> k;
        FOR(i, 1, n) FOR(j, 1, m) cin >> s[i][j];
        c = min(m, n);
        FOR(i, 0, c + 1) FOR(j, 0, n + 1) FOR(e, 0, m + 1) {a[j][e][i] = INF;}
        FOR(i, 1, c) FOR(j, 1, n) FOR(e, 1, m)
        {
            a[j][e][i] = min(min(a[j - 1][e - 1][i], a[j][e - 1][i - 1]), min(a[j - 1][e][i - 1], s[j][e]));
            b[j][e][i] = max(max(b[j - 1][e - 1][i], b[j][e - 1][i - 1]), max(b[j - 1][e][i - 1], s[j][e]));
        }
        FOX(i, c, 1)
        {
            FOR(j, 1, n)
            {
                FOR(e, 1, m)
                {
                    if(b[j][e][i] - a[j][e][i] <= k) cout << i, exit(0);
                }
            }
        }
    }
	return 0;
}
