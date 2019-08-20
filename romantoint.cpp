int translate(char t){
    switch(t){
            case 7:
                return 1000;
            case 6:
                return 500;
            case 5:
                return 100;
            case 4:
                return 50;
            case 3:
                return 10;
            case 2:
                return 5;
            case 1:
                return 1;
            default:
                 return 0;
    }
}
int romanToInt(char* s) {
    unsigned int tho=0;
    long output=0;
    while(*s=='M'){
        s++;
        tho++;
    }
    char str[13]={0};
    unsigned char i=0;
    while(*s!='\0'){
        switch(*s){
            case'I':
                str[i]=1;
                break;
            case'V':
                str[i]=2;
                break;
            case'X':
                str[i]=3;
                break;
            case'L':
                str[i]=4;
                break;
            case'C':
                str[i]=5;
                break;
            case'D':
                str[i]=6;
                break;
            case'M':
                str[i]=7;
                break;
                
        }
        i++;
        s++;
    }
    str[i]=0;
    for(int j=0;j<i;j++){
        output+=translate(str[j])*(str[j]<str[j+1])?(-1):1;
    }
    return (unsigned int)output+tho*1000;
}
int main() {
	char str[99]={'I','V'};
	romanToInt(str);
    return 1;
}


