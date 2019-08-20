/*mod  2exponential number -1*/
#define  SHIFTNUMBER 5
#define MODVAL ((1<<SHIFTNUMBER)-1)
#include<iostream>
using namespace std;
int mod2ExpSub1(int val){
	for(;val>=MODVAL;){
		int sumtemp = 0;
		for(int valtemp=val;valtemp!=0;valtemp>>=SHIFTNUMBER){
			sumtemp += valtemp&MODVAL;
		}
		val = sumtemp;
	}
	return val;
} 

int main(){
	int val ;
	while(1){
		cin>>val;
		printf("%d\n",mod2ExpSub1(val));
	}
}
