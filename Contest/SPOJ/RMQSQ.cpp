#include <bits/stdc++.h>
using namespace std;
int f[100005][20];
void RMQ(int n, int a[])
{
    for(int i = 0; i < n; i++)
        f[i][0] = a[i];

    for(int j = 1; 1 << j <= n; j++)
        for(int i = 0; i + (1 << j) <= n; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int n, a[100005], q, l, r, k;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    RMQ(n, a);

    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        k = log2(r - l + 1);
        cout << min(f[l][k], f[r - (1 << k) + 1][k]) << "\n";
    }
    return 0;
}
