#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void getNextArr(string &ms, int* next, int len){
    next[0] =-1;
    next[1] =0;
    int cn=0;
    int pos=2;
    while(pos<len){
        if(ms[pos-1]==ms[cn]){
            next[pos++]= ++cn;
        }
        else if(cn > 0){
            cn = next[cn];
        }
        else{
            next[pos++]=0;
        }
    }
}

int KMP(string &str,string &ms, int* next){
    int len=ms.size();
    int n=str.size();
    getNextArr(ms,next,len);
    int j=0,i=0;
    while(i<n && j< len){
        if(str[i]!=ms[j]){
            j=next[j];
        }
        else{
            j++;
            i++;
        }
    }
    if(j!=len){
            return -1;
        }
        else{
            return i-j;
        }
}
int main()
{
    string str="1123123123b11111";
    string ms="123123b";
    int len=ms.size();
    int *next=(int*)malloc(sizeof(int)*len);
    cout<<KMP(str, ms,next);
    return 0;
}
