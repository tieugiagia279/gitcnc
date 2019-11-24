#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> factor(ll n) {
	ll s = 0;
	while((n & 1) == 0) {
		s++;
		n >>= 1;
	}
	return {s, n};
}

ll multi_mod(ll a, ll b, ll mod) {
	ll r = 0;
	while(b > 0) {
		if(b % 2 != 0) r = (r + a) % mod;
		a = a * 2 % mod;
		b = b / 2;
	}
	return r;
}

ll power_mod(ll a, ll b, ll mod) {
	ll r = 1;
	a %= mod;
	while(b > 0) {
		if(b & 1) r = multi_mod(r, a, mod);
		b >>= 1;
		a = multi_mod(a, a, mod);
	}
	return r;
}

bool check(ll s, ll d, ll n, ll a) {
    if(n == a) return true;
    ll p = power_mod(a, d, n);
    if(p == 1) return true;
    for(; s > 0; s--) {
        if(p == n - 1) return true;
        p = multi_mod(p, p, n);
    }
    return false;
}

bool miller(ll n) {
    if(n < 2) return false;
    if((n & 1) == 0) return n == 2;
    ll s = factor(n - 1).first;
    ll d = factor(n - 1).second;
    return check(s, d, n, 2) && check(s, d, n, 7) && check(s, d, n, 61);
}

int main() {
	freopen("test.out", "w", stdout);

    for(int i = 2; i <= 10000; i++) if(miller(i) == true) cout << i << endl;

	return 0;
}
