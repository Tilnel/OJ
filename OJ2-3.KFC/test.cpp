#include<bits/stdc++.h>
using namespace std;
int main(){
    union{
        int a[8];
        enum {b,c,d,e};
    };
    return 0; 
}