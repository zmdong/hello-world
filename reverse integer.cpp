#include<climits>
int main() {
	int x=322;
	int div=x/-10;
	int res=x%-10;
    if(x==0)return 0;
    int sign=1;
    if(x<0){
        x*=-1;
        sign=-1;
    }
    int output=0;
    const int base=10,intlimit=INT_MIN,intlimitdivbase=(INT_MIN/base)*-1;
    while(x!=0){
        int mod=x%base;
        if(output>intlimitdivbase)return 0;
        if(output==intlimitdivbase){
            int intlimitmod =intlimit%base;
            if(mod>intlimitmod)return 0;
            if(mod==intlimitmod&&sign==1)return 0;
        }
        output=output*base+mod;
        x/=base; 
    }
    return sign*output;
}
