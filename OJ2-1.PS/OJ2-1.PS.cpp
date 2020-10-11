#include <bits/stdc++.h>
#define MAXM 51
#define MAXK 51
#define MAXN 2501
using namespace std;
int b[MAXM][MAXK];
int v[MAXM][MAXK]; // the value of first K - th plate in the M - th pile
int dp[MAXM][MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < MAXM; i++) {
            for (int j = 0; j < MAXK; j++) {
                v[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                scanf("%d", &b[i][j]);
                v[i][j] = v[i][j - 1] + b[i][j];
            }
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int choice = 0; choice <= min(j, k); choice++) {
                    dp[i][j] =
                        max(dp[i - 1][j - choice] + v[i][choice], dp[i][j]);
                }
            }
        }
        printf("%d\n", dp[m][n]);
    }
    return 0;
}