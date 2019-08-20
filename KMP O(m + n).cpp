#include<iostream>
#include <string.h>
using namespace std;
/*result  in compara str ,if(one char == head char) one+1 char be 與上一個字元有關  */
int strStr(const char * haystack,const char * needle){
    int slen,plen,i,j,count;
    j = -1;
    i = count = 0;
    slen = strlen(haystack);
    plen = strlen(needle);
    if(plen == 0) return 0;
    int* next;
    next = (int*)malloc(sizeof(int)*plen);
    next[0] = -1;
    while(i < plen - 1){
        if(j == -1 || needle[i] == needle[j]){
            i++;
            j++;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }
    for(int x=0;x<plen;x++){
    	printf("%d ",next[x]);
	}
    i = j = 0;
    while(i < slen && j < plen){
        if(j == -1|| haystack[i] == needle[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == plen) return i-j;
    else return -1;
}
int main (){
	const char*a="abcabcdababcdad";
	const char*b="abcdad";
	strStr(a,a);
}
