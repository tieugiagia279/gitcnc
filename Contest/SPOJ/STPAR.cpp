#include<bits/stdc++.h>
using namespace std;

int n, pos, x, flag = 0;
int main()
{
    while(1)
    {
        stack<int> a;
        queue<int> s;
        cin >> n;
        if(n == 0) break;
        pos = 1;
        flag = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            s.push(x);
        }
        while(!a.empty() || !s.empty())
        {
            if(s.size() != 0 && s.front() == pos)
            {
                pos++;
                s.pop();
            }
            else if(a.size() != 0 && a.top() == pos)
            {
                pos++;
                a.pop();
            }
            else if((a.size() != 0 && s.size() != 0 && s.front() < a.top()) || a.empty())
            {
                a.push(s.front());
                s.pop();
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1) cout << "no";
        else cout << "yes";
        cout << "\n";

    }
    return 0;
}
