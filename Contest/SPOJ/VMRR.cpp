#include <bits/stdc++.h>
using namespace std;

string s;
char x, y;
long long a[1000005], b[1000005], res = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    getline(cin, s);
    cin >> x >> y;
    for(int i = 0; i < s.size(); i++)
    {
        b[i + 1] = b[i];
        if(s[i] == x) a[i + 1] = 1;
        if(s[i] == y) b[i + 1]++;
    }
    for(int i = 1; i < s.size(); i++)
    {
        if(a[i])
            res += b[s.size()] - b[i];
    }
    cout << res;
    return 0;
}
