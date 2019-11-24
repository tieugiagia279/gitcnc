#include <bits/stdc++.h>
using namespace std;
#define FOR(_i,_a,_b) for(int _i = _a; _i <= _b; _i++)
#define FOX(_i,_a,_b) for(int _i = _a; _i >= _b; _i--)
#define ll long long

string s, a;
int k, sa[2005], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin >> s >> a >> k;
    FOR(i, 0, s.size() - 1)
        if(a[s[i] - 97] == '1') s[i] = '1';
        else s[i] = '0';
    if(s[0] == '1') sa[0] = 1;
    FOR(i, 1, s.size() - 1)
    {
        sa[i] = sa[i - 1];
        if(s[i] == '1') sa[i]++;
    }
    FOR(i, 0, s.size() - 2)
    FOR(j, i, s.size() - 1)
    {
        if(!i && sa[j] <= k) ans++;
        else if(sa[j] - sa[i - 1] <= k) ans++;
    }
    cout << ans;
	return 0;
}
