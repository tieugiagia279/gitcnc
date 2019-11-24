#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main()
{
    cin >> n;
    while(n--)
    {
        cin >> s;
        bool var = next_permutation(s.begin(), s.end());
        if(var == true) cout << s;
        else cout << "no answer";
        cout << "\n";
    }
}