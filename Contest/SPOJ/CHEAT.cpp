#include <bits/stdc++.h>
using namespace std;

int n, x, s[100005];
stack<int> a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];

    x = 1;
    for(int i = 1; i <= n; i++)
    {
        a.push(i);
        while(!a.empty() && a.top() == s[x])
        {
            x++;
            a.pop();
        }
    }
    if(a.empty()) cout << "NO";
    else cout << "YES";
    return 0;
}
