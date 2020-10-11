#include <bits/stdc++.h>
using namespace std;

int a[1000001];
unordered_map<int, int> mp;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int first = 0, second = 0x7fffffff;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      if (mp.find(a[i]) != mp.end()) {
        int tmp = mp[a[i]];
        if (i - tmp < m) {
          int l = tmp % m;
          int r = tmp / m == i / m ? i % m : (i % m) + m;
          first = first > l ? first : l;
          second = second < r ? second : r;
        }
      }
      mp[a[i]] = i;
    }
    if (first < second)
      printf("I'm sorry for being a being.\n");
    else
      printf("I've already became black.\n");
    mp.clear();
  }
  return 0;
}