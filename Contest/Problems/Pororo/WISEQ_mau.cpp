#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;
#define int64 long long

const int N_MAX = 510;

int64 F[N_MAX][N_MAX];
int64 W;
int A[N_MAX];
int n;

void outerInit() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.rdbuf((new ifstream("WISEQ.inp"))->rdbuf());
    cout.rdbuf((new ofstream("WISEQ.out"))->rdbuf());
}

void readData() {
    cin >> n >> W;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
}

void solveData() {
    fill(F[1], F[n + 2], LLONG_MAX);
    int bestLength = 0;

    for (int i = 1; i <= n; ++i) {
        F[i][1] = A[i];

        for (int j = 1; j <= i; ++j) {
            if (F[i][j] < LLONG_MAX) {
                for (int k = i + 1; k <= n; ++k) {
                    if (A[i] < A[k]) {
                        F[k][j + 1] = min(F[k][j + 1], F[i][j] + A[k]);
                    }
                }

                if (j > bestLength && F[i][j] <= W) {
                    bestLength = j;
                }
            }
        }
    }

    cout << bestLength << "\n";
}

int main() {
    outerInit();
    readData();
    solveData();
}
