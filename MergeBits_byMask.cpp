#include <iostream>
using namespace std;
typedef struct{
	char x;
	int y;
	short z;
}ALIGNMENTTEST;

int main() {
	unsigned int a =   0b10101010;    // value to merge in non-masked bits
	unsigned int b =   0b11100000;    // value to merge in masked bits
	unsigned int mask =0b11100011 ; // 1 where bits from b should be selected; 0 where from a.
	unsigned int r;    // result of (a & ~mask) | (b & mask) goes here
	r = a ^ ((a ^ b) & mask); 
	return 0; 
}


