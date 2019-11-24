#include<bits/stdc++.h>
using namespace std;

int n, a[1005], f[1005], res = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[1] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = i - 1; j >= 0; j--)
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);

    for(int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res;
    return 0;
}
