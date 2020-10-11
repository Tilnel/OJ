#include <bits/stdc++.h>
using namespace std;

void repeat_char(char a, int times) {
  int i = times;
  while (i--)
    putchar(a);
  return;
}
int main() {
  int i, j, n, maxi, d[100], s[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    maxi = maxi > d[i] ? maxi : d[i];
  }
  for (i = 0; i < n; i++) {
    s[i] = -(-d[i] / maxi * 50);
    printf("+");
    repeat_char('-', s[i]);
    printf("+\n");
    printf("|");
    repeat_char(' ', s[i] - 1);
    printf("*|%d\n", d[i]);
    printf("+");
    repeat_char('-', s[i]);
    printf("+\n");
  }

  return 0;
}