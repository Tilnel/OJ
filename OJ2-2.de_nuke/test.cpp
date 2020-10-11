
#include <bits/stdc++.h>
using namespace std;
set<int> prime;
int sum(int a) {
  int s = 0;
  while (a) {
    s += a % 10;
    a /= 10;
  }
  return s;
}
int sums(int a) {
  int s = 0;
  while (a) {
    s += (a % 10) * (a % 10);
    a /= 10;
  }
  return s;
}

int main() {
  int T;
  int a, b;
  for (int i = 2; i <= 1458; i++) {
    prime.insert(i);
  }
  for (auto &n : prime) {
    for (int i = 2 * n; i <= 1458; i += n) {
      prime.erase(i);
    }
  }
  scanf("%d", &T);
  while (T--) {

    int cnt = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
      int A = sum(i);
      int B = sums(i);
      if (prime.count(A) && prime.count(B))
        cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
