#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<int> prime;
vector<int> bits;
ll dp[19][163][1459];

void dest(ll a) {
  bits.clear();
  while (a) {
    bits.push_back(a % 10);
    a /= 10;
  }
  return;
}
ll solve(int pos, int flag, int sum1, int sum2) {
  if (pos < 0) {
    return prime.count(sum1) && prime.count(sum2);
  } else {
    if (!flag && (dp[pos][sum1][sum2] != -1))
      return dp[pos][sum1][sum2];
    ll answer = 0;
    int iend = (flag ? bits[pos] : 9);

    for (int i = 0; i <= iend; i++) {
      answer +=
          solve(pos - 1, int(flag && (i == iend)), sum1 + i, sum2 + i * i);
    }
    if (!flag)
      dp[pos][sum1][sum2] = answer;
    return answer;
  }
}
int main() {
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 163; j++) {
      for (int p = 0; p < 1459; p++) {
        dp[i][j][p] = -1;
      }
    }
  }
  // make the prime sheet
  for (int i = 2; i <= 1458; i++) {
    prime.insert(i);
  }
  for (auto &n : prime) {
    for (int i = 2 * n; i <= 1458; i += n) {
      prime.erase(i);
    }
  }

  int cnt = 0;

  int T;
  long long a, b;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld", &a, &b);
    dest(a - 1);
    ll A = solve(bits.size() - 1, 1, 0, 0);
    dest(b);
    ll B = solve(bits.size() - 1, 1, 0, 0);
    printf("%lld\n", B - A);
  }
  return 0;
}