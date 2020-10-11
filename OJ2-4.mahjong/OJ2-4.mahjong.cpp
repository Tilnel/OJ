#include <bits/stdc++.h>
using namespace std;
int mahjong[1000001];
int n, m;
int solve(int id) {
    if (id == m)
        return mahjong[id] / 3;
    if (id == m - 1)
        return mahjong[id] / 3 + solve(id + 1);
    if (mahjong[id] == 0)
        return solve(id + 1);
    int answer = 0;
    if (mahjong[id] >= 3) {
        mahjong[id] -= 3;
        answer = max(answer, solve(id) + 1);
        answer = max(answer, solve(id + 1) + 1);
        mahjong[id] += 3;
    }
    if (mahjong[id] >= 1 && mahjong[id + 1] >= 1 && mahjong[id + 2] >= 1) {
        mahjong[id]--;
        mahjong[id + 1]--;
        mahjong[id + 2]--;
        answer = max(answer, solve(id) + 1);
        answer = max(answer, solve(id + 1) + 1);
        mahjong[id]++;
        mahjong[id + 1]++;
        mahjong[id + 2]++;
    }
    return answer;
}
int main() {
    int tmp;
    memset(mahjong, 0, sizeof(int) * 1000001);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        mahjong[tmp]++;
    }
    printf("%d", solve(1));
    return 0;
}