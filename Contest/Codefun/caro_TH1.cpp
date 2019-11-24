#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const long long INF  = 1e18 + 1;
const long long MAXN =  1e5 + 5;
const long long MOD  =  1e9 + 7;


void caro_ngang() {
    string s = "GOOOO";
    ll n = 1;
    do {
        n = 1;
        for(int j = 1; j <= 5; j++) {
            for(int k = 1; k <= 5; k++) {
                if(k == n) cout << s;
                else cout << "TTTTT";
                cout << endl;
            }
            cout << endl;
            n++;
        }
    } while(next_permutation(s.begin(), s.end()));
}

void caro_doc() {
    string s = "GOOOO";
    char res[7][7];
    ll n = 1;
    do {
        n = 1;
        for(int j = 1; j <= 5; j++) {
            for(int k = 1; k <= 5; k++) {
                for(int m = 1; m <= 5; m++) {
                    if(k == n) res[k][m] = s[m - 1];
                    else res[k][m] = 'T';
                }
            }

            for(int k = 1; k <= 5; k++) {
                for(int m = 1; m <= 5; m++) {
                    cout << res[m][k];
                }
                cout << endl;
            }
            cout << endl;
            n++;
        }
    } while(next_permutation(s.begin(), s.end()));
}

void caro_cheo() {
    string s = "GOOOO";
    char res[7][7];
    do {
        for(int i = 1; i <= 5; i++) {
            for(int j = 1; j <= 5; j++) {
                if(i == j) cout << s[i - 1];
                else cout << "T";
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 1; i <= 5; i++) {
            for(int j = 1; j <= 5; j++) {
                if(i + j == 6) cout << s[i - 1];
                else cout << "T";
            }
            cout << endl;
        }
        cout << endl;

    } while(next_permutation(s.begin(), s.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //freopen("test.inp", "r", stdin);
    freopen("caro_TH1.txt", "w", stdout);

    caro_ngang();
    caro_doc();
    caro_cheo();


    return 0;
}
