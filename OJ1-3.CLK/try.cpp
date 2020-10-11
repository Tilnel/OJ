#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
  char a[2][3];
  cin.getline(a[0],27);
  cin.getline(a[1],27);
  printf("%c%c%c", a[0][0], a[1][1], a[1][2]);
  return 0;
}
