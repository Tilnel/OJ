#include<iostream>
using namespace std;

int main(){
	int *p;
	p=0x0000000000000000;
	for (int i=0;i<100;i++){
	cout<<*(int*)(p+i);
	}
	return 0;
}

