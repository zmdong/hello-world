#include <stdlib.h>
#define LENGTH 5
using namespace std;
char* longestCommonPrefix(char ** strs, int strsSize){
    //char* pstr = malloc(sizeof(char*)*LENGTH);
    char* str= (char*)malloc(sizeof(char)*LENGTH);
    int a=sizeof(char);
    for(int j =0;j<0;j++){
        int i=0;
        char temp=*(*(strs+i)+j);
        for(;i<strsSize;i++){
            if(temp!=*(*(strs+i)+j)){
                temp='\0';
                break;
            }
        }
        *(str+j)=temp;
        if(temp=='\0')return str;
    }
    return str;
}

int main() {
	char* s1="[]",*s2=0;
	char* strs[2]={s1,s2};
	longestCommonPrefix(strs,1);
    return 0; 
}


