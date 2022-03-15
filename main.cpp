//
// Created by 76044356 on 2022/3/15.
//

#include"5/string.h"
#include<iostream>
//using namespace std;
int main(){
    string a = string("ababc");
    string b = string("abc");
    std::cout<<a.Index_KMP(a,b,0);
}