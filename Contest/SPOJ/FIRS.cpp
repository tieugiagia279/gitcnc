#include <bits/stdc++.h>
using namespace std;

int n, a[100005], cnt = 0;
pair<int, int> s[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i].first = a[i];
        s[i].second = i;
    }
    sort(s + 1, s + n + 1);
    int i = 0;
    while(n)
    {
        if(a[s[i].second] != 0)
        {
            a[s[i].second] = 0;
            n--;

            if(a[s[i].second - 1] > 0)
            {
                a[s[i].second - 1] = 0;
                n--;
            }
            if(a[s[i].second + 1] > 0)
            {
                a[s[i].second + 1] = 0;
                n--;
            }
            cnt++;
        }
        i++;
    }
    cout << cnt;
    return 0;
}
