//
// Created by 76044356 on 2022/3/15.
//

#include <cstdlib>
#include "string.h"
//int string::Index(string s, string t, int pos) {
//    int n,m,i;
//    string sub;
//    if(pos > 0){
//        n = StrLength(s);
//    }
//}
string::string(char *a) {
    this->data = a;
}
int string::length() {
    return _mbstrlen(this->data);
}

void string::get_next(string T, int *next) {
    int i,j;
    i=1;
    j=0;
    next[1]=0;
    while(i<T.length()){
        if(j==0||T.data[i]==T.data[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else
            j=next[j];
    }
}

void string::get_nextval(string T, int *next) {
    int i,j;
    i=1;
    j=0;
    next[1]=0;
    while(i<T.length()){
        if(j==0||T.data[i]==T.data[j]){
            ++i;
            ++j;
            if(T.data[i]!=T.data[j])
                next[i]=j;
            else
                next[i]=next[j];
        }
        else
            j=next[j];
    }
}

int string::Index_KMP(string s, string t, int pos) {
    int i = pos;
    int j = 1;
    int len = t.length();
    int next[len];
    get_nextval(t,next);
    while(i<=s.length()&&j<=t.length()){
        if(j==0||s.data[i]==t.data[j]){
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if(j>len)
        return i-len;
    else
        return 0;
}

//int string::Index(string ts, string tt, int pos) {
//    char* s = ts.data;
//    char* t = tt.data;
//    int n,m,i;
//    char* sub;
//    if(pos > 0){
//        n = _mbstrlen(s);
//        m = _mbstrlen(t);
//        i = pos;
//        while(i <= n-m+1){
//            sub=s[i:i+m];
//        }
//    }
//}