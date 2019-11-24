#include <bits/stdc++.h>
using namespace std;
int n, a[105];

void update(int x, int w)
{
    for(int i = x; i <= n; i += (i & -i))
        a[i] += w;
}

int get(int y)
{
    int res = 0;
    for(int i = y; i > 0; i -= (i & - i))
        res += a[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q, x;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        update(i, x);
    }
    while(q--)
    {
        int a, b, x;
        cin >> x;
        if(x == 1)
        {
            cin >> a;
            update(a, 1);
        }
        if(x == 2)
        {
            cin >> a >> b;
            cout << get(b) - get(a - 1) << endl;
        }
    }
    return 0;
}