//
// Created by 76044356 on 2022/3/15.
//

#ifndef DATA_STRUCTURE_STRING_H
#define DATA_STRUCTURE_STRING_H
#define maxnum  10

class string{
public:
    string(char *a);
//    char data[maxnum];
    char * data;
    int length();
    void get_next(string T,int *next);
    void get_nextval(string T,int *next);
    int Index_KMP(string ts,string tt,int pos);
//    int Index(string ts,string tt,int pos);
};

#endif //DATA_STRUCTURE_STRING_H
