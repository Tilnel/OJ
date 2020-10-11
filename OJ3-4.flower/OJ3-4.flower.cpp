#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[60001];
ll s[60001];
int n, k;
bool cmp(ll a, ll b) { return a <= b; }

bool solve(int b) {
    int cnt = 1;
    int left = 0, right = k - 1;
    for (int i = 0; i < b; i++) {
        s[i] = a[i];
    }
    while (cnt < k) {
        left = right + 1;
        while (a[left] < 2 * s[0] && left < n) {
            left++;
        }
        if (left == n)
            return false;
        right = left;
        int id = 0;
        while (right < n && id < b) {
            if (a[right] >= 2 * s[id]) {
                s[id] = a[right];
                id++;
                right++;
            } else {
                right++;
            }
        }
        if (id != b && right == n)
            return false;
        cnt++;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a, a + n, cmp);
        int l = 0, r = n / k + 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (solve(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        printf("%d\n", l - 1);
    }
    return 0;
}