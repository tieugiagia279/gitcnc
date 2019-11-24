#include <bits/stdc++.h>
using namespace std;
int fmn[50005][30], fmx[500005][30];

void RMQ(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        fmn[i][0] = a[i];
        fmx[i][0] = a[i];
    }

    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 0; i + (1 << j) <= n; i++)
        {
            fmn[i][j] = min(fmn[i][j - 1], fmn[i + (1 << (j - 1))][j - 1]);
            fmx[i][j] = max(fmx[i][j - 1], fmx[i + (1 << (j - 1))][j - 1]);
        }
}

int n, q, a[50005], x, y, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    RMQ(a, n);

    while(q--)
    {
        cin >> x >> y;
        k = log2(y - x + 1);
        cout << max(fmx[x - 1][k], fmx[y - (1 << k)][k]) - min(fmn[x - 1][k], fmn[y - (1 << k)][k]) << "\n";
    }
    return 0;
}
