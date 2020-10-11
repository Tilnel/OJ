#include <bits/stdc++.h>
using namespace std;
set<int> v, v_after;
//   _    2
//  |_|  103
//  |_|  654
char times[3][27];

int judge(int num, int LED) { // LED: 0~127

  // 0 for 123456, 01111110=126
  // 1 for 34, 2|02356, 3|02345, 4|0134, 5|01245, 6|012456, 7|234, 8|0123456,
  // 9|012345
  int g[10] = {126, 24, 109, 61, 27, 55, 119, 28, 127, 63};
  if ((LED & g[num]) == LED)
    return 1;
  else
    return 0;
}

int gen(int bit, int s) {
  int c[4];
  if (!s) {
    c[0] = 0;
    c[1] = 3;
    c[2] = 7;
    c[3] = 10;
  } else {
    c[0] = 14;
    c[1] = 17;
    c[2] = 21;
    c[3] = 24;
  }
  int LED = 0;
  if (times[0][c[bit] + 1] == '_')
    LED += 1 << 2;
  if (times[1][c[bit]] == '|')
    LED += 1 << 1;
  if (times[1][c[bit] + 1] == '_')
    LED += 1;
  if (times[1][c[bit] + 2] == '|')
    LED += 1 << 3;
  if (times[2][c[bit]] == '|')
    LED += 1 << 6;
  if (times[2][c[bit] + 1] == '_')
    LED += 1 << 5;
  if (times[2][c[bit] + 2] == '|')
    LED += 1 << 4;
  return LED;
}

int main() {
  int t, i, j;
  scanf("%d", &t);
  getchar();
  while (t--) {
    for (i = 0; i < 3; i++) {
      fgets(times[i],30, stdin);
    }
    for (i = 0; i < 24; i++) {
      if (!judge(i / 10, gen(0, 0))) {
        // i += 9;
        continue;
      }
      if (!judge(i % 10, gen(1, 0)))
        continue;
      for (j = 0; j < 60; j++) {
        if (!judge(j / 10, gen(2, 0))) {
          // j += 9;
          continue;
        }
        if (!judge(j % 10, gen(3, 0)))
          continue;
        v.insert(i * 100 + j);
      }
    }
    for (auto &p : v) {
      int hh, mm;
      mm = (p % 100) - 45 >= 0 ? (p % 100) - 45 : (p % 100) + 15;
      hh = (p % 100) - 45 >= 0 ? p / 100 : p / 100 - 1;
      if (hh == -1)
        hh = 23;
      bool flag = judge(hh / 10, gen(0, 1)) && judge(hh % 10, gen(1, 1)) &&
                  judge(mm / 10, gen(2, 1)) && judge(mm % 10, gen(3, 1));
      if (flag)
        v_after.insert(p);
    }
    int s;
    if (v_after.size() != 1) {
      printf("No\n");
    } else {

      s = *v_after.begin();
      printf("Yes %02d:%02d\n", s / 100, s % 100);
    }
    v.clear();
    v_after.clear();
  }
  return 0;
}