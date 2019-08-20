int main() {
	int x=121;
    if(x<0)return 0;
    if(x=0)return 1;
    char str[13]={0};
    char cnt=0;
    while(x){
        str[cnt]=(char)(x%10);
        x/=10;
        cnt++;     
    }
    int tar= (cnt&1)?(cnt+1)/2:cnt/2;
    for(int i=0;i<tar;i++){
        if(str[i]!=str[cnt-i-1])return 0;
    }
    return 1;
}


