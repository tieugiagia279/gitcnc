#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll n, k, d, f[105][105], cnt[105][105];
int main()
{
    cin >> n >> k >> d;
    for(int i = 0; i <= k; i++) f[0][i] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            f[i][j] = f[i][j - 1];
            cnt[i][j] = cnt[i][j - 1];
            if(i >= j)
            {
                f[i][j] = (f[i][j] + f[i - j][k]) % MOD;
                cnt[i][j] += (j < d) ? cnt[i - j][k] : f[i - j][k];
                cnt[i][j] %= MOD;
            }
        }
    }

    cout << cnt[n][k];
    return 0;
}
