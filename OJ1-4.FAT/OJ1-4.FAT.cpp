#include <bits/stdc++.h>
using namespace std;
int a[100001];
struct pp {
  int val;
  int origin;
} sum[100001];

int compare(const void *a, const void *b) {
  return ((pp *)a)->val - ((pp *)b)->val;
}
bool cmp(pp a,pp b){
    return a.val<b.val;
}

int main() {
  int T, l, r, l0, r0, ans, diff, ruler, l1, r1;
  scanf("%d", &T);
  while (T--) {
    int n, k, q;
    sum[0].origin = 0;
    sum[0].val = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum[i].val = sum[i - 1].val + a[i];
      sum[i].origin = i;
    }
    sort(sum,sum+(n+1),cmp);
    for (int i = 0; i < k; i++) {
      scanf("%d", &q);
      //qsort(sum, n + 1, sizeof(pp), compare);
      l = 0;
      r = 0;
      diff = 0x7fffffff;
      while (r <= n) {
        ruler = sum[r].val - sum[l].val;
        if (abs(ruler - q) < diff) {
          diff = abs(ruler - q);
          ans = ruler;
          r0 = r;
          l0 = l;
        }
        if (abs(ruler) == q) {
          break;
        }
        if (ruler < q)
          r++;
        else
          l++;
        
      }
      l1 = sum[l0].origin;
      r1 = sum[r0].origin;
      if (l1 > r1) {
        int c = r1;
        r1 = l1;
        l1 = c;
      }

      printf("%d %d %d\n", ans, l1 + 1, r1);
    }
  }

  return 0;
}