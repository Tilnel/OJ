#include <bits/stdc++.h>
using namespace std;
int a[31][31], r[31];
int area[31][31];
int dp[31][31][31][31];

int solve(int x1, int y1, int x2, int y2) {
    if (dp[x1][y1][x2][y2] != -1)
        return dp[x1][y1][x2][y2];
    int num = area[x2][y2] + area[x1][y1] - area[x1][y2] - area[x2][y1];
    if (num == 0)
        return 0x3fffffff;
    if (num == 1)
        return 0;
    int answer = 0x7fffffff;
    for (int i = x1 + 1; i < x2; i++) {
        answer =
            min(answer, solve(x1, y1, i, y2) + solve(i, y1, x2, y2) + y2 - y1);
    }
    for (int j = y1 + 1; j < y2; j++) {
        answer =
            min(answer, solve(x1, y1, x2, j) + solve(x1, j, x2, y2) + x2 - x1);
    }
    return dp[x1][y1][x2][y2] = answer;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k, tmpx, tmpy;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int r = 0; r <= n; r++) {
                    for (int s = 0; s <= m; s++) {
                        dp[i][j][r][s] = -1;
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                a[i][j] = 0;
            }
        }
        for (int i = 0; i < k; i++) {
            scanf("%d%d", &tmpx, &tmpy);
            a[tmpx][tmpy] = 1;
        }
        for (int i = 0; i <= m; i++) {
            area[0][i] = 0;
        }
        r[0] = 0;
        for (int i = 1; i <= n; i++) {
            area[i][0] = 0;
            for (int j = 1; j <= m; j++) {
                r[j] = r[j - 1] + a[i][j];
                area[i][j] = area[i - 1][j] + r[j];
            }
        }
        printf("%d\n", solve(0, 0, n, m));
    }
    return 0;
}