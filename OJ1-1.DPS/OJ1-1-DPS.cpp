#include <bits/stdc++.h>
using namespace std;

void repeat_char(char a, long long times) {
  if (times < 0)
    return;
  long long i = times;
  while (i--) {
    putchar(a);
  }
  return;
}
int main() {
  int i, j, n, maxi=0, d[100];
  long long s[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    maxi = maxi > d[i] ? maxi : d[i];
  }
  for (i = 0; i < n; i++) {
    s[i] = (50LL * d[i] + maxi - 1) / maxi;
    printf("+");
    repeat_char('-', s[i]);
    printf("+\n");
    printf("|");
    if (d[i]==maxi){
      repeat_char(' ',s[i]-1);
      printf("*|%d\n", d[i]);
    }else{
      repeat_char(' ', s[i]);
      printf("|%d\n", d[i]);
    }
    printf("+");
    repeat_char('-', s[i]);
    printf("+\n");
  }

  return 0;
}