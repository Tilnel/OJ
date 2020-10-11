#include <bits/stdc++.h>
using namespace std;
int mahjong[1000002];
int dp[1000002][3][3];

int main() {
    int tmp, n, m;

    memset(mahjong, 0, sizeof(int) * 1000002);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        mahjong[tmp]++;
    }
    for (int id = 0; id <= n + 1; id++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dp[id][i][j] = 0;
            }
        }
    }
    for (int id = 1; id <= n + 1; id++) {
        for (int stra1 = 0; stra1 <= 2; stra1++) {         // id-1, id, id+1
            for (int stra2 = 0; stra2 <= 2; stra2++) {     // id, id+1, id+2
                for (int stra3 = 0; stra3 <= 2; stra3++) { // id-2, id-1, id
                    if (mahjong[id] < stra1 + stra2 + stra3)
                        continue;
                    dp[id][stra1][stra2] =
                        max(dp[id][stra1][stra2],
                            dp[id - 1][stra2][stra3] + stra1 +
                                (mahjong[id] - stra1 - stra2 - stra3) / 3);
                }
            }
        }
    }

    printf("%d", dp[n + 1][0][0]);
    return 0;
}