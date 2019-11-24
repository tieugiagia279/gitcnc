#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minark(vector<ll> a, ll k)
{
    if(k == 0) return 0;
    ll su = a[k - 1];
    for(ll i = k; i < a.size(); i++)
        su = min(su, a[i] - a[i - k]);
    return su;
}

ll n, m, x[105], y, mc[105][105], f[105][100005];
vector<ll> a[105];

int main()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
    {
        cin >> x[i];
        for(ll j = 0; j < x[i]; j++)
        {
            cin >> y;
            a[i].push_back(y);
        }
        for(ll j = 1; j < x[i]; j++)
            a[i][j] += a[i][j - 1];

        for(ll j = 1; j <= x[i]; j++)
            mc[i][j] = a[i][x[i] - 1] - minark(a[i], x[i] - j);
    }

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            for(ll k = 0; k <= min(j, x[i]); k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + mc[i][k]);
            }
        }
    }
    cout << f[n][m];

//    for(ll i = 1; i <= n; i++)
//    {
//        for(ll j = 0; j < a[i].size(); j++)
//            cout << a[i][j] << " ";
//        cout << endl;
//    }
//
//    for(ll i = 1; i <= n; i++)
//    {
//        for(ll j = 1; j <= a[i].size(); j++)
//            cout << mc[i][j] << " ";
//        cout << endl;
//    }
    return 0;
}
