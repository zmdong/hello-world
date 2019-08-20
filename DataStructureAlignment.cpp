#include <iostream>
using namespace std;
typedef struct{
	char x;
	int y;
	short z;
}ALIGNMENTTEST;

int main() {
	ALIGNMENTTEST Alignment1={0,1,2};
	printf("char %d\nint %d\nshort %d\n&char %p\n&int %p\n&short %p\n",Alignment1.x,Alignment1.y,Alignment1.z,&Alignment1.x,&Alignment1.y,&Alignment1.z);
    return 0; 
}


