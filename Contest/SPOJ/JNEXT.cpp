#include<bits/stdc++.h>
using namespace std;


int n, t, a[1000005], mx, flag;
vector<int> s;
int main()
{
    cin >> t;
    while(t--)
    {
        flag = 0;
        s.clear();
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        s.push_back(a[n - 1]);
        mx = a[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            if(a[i] >= mx)
            {
                mx = a[i];
                s.push_back(a[i]);
            }
            else
            {
                flag = 1;
                for(int j = 0; j < s.size(); j++)
                    if(s[j] > a[i])
                    {
                        swap(s[j], a[i]);
                        break;
                    }
                mx = i;
                break;
            }
        }
        if(flag == 0) cout << -1;
        else
        {
            for(int i = 0; i <= mx; i++)
                cout << a[i];
            for(int i = 0; i < s.size(); i++)
                cout << s[i];
        }
        cout << "\n";
    }
    return 0;
}
