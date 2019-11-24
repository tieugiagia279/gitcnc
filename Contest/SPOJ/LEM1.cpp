#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const long long INF = 1e9;
const double PI = acos(-1.0);
int n;
double r[10005], res = 0;

double coss(double x, double r1, double r2) {
    double m1 = x + r1;
    double m2 = x + r2;
    return ((m1 * m1 + m2 * m2 - (r1 + r2) * (r1 + r2)) / (2.0 * m1 * m2));
}

double sumarc(double x) {
    double result = 0;
    for(int i = 0; i < n; i++) {
        result += acos(coss(x, r[i], r[i + 1]));
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> r[i];
    r[0] = r[n];

    double top = INF, bot = 0, mid;
    while(1) {
        mid = (top + bot) / 2.0;
        if(abs(sumarc(mid) - 2 * PI) <= 1e-4) {
            printf("%0.3lf", mid);
            return 0;
        }
        if(sumarc(mid) < 2 * PI)
           top = mid;
        if(sumarc(mid) > 2 * PI)
           bot = mid;
    }
    return 0;
}
