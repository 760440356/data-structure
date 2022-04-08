//
// Created by DELL on 2022/4/7.
//

#ifndef DATA_STRUCTURE_MYSEARCH_H
#define DATA_STRUCTURE_MYSEARCH_H
#include "../status.h"

class mysearch {

};
/*3333333333333333顺序表查找333333333333333333*/
/*顺序查找，a为数组，n为数组长度，key为要查找的关键字*/
int Sequential_Search(int *a, int n ,int key);
/*顺序查找优化*/
int Sequential_Search2(int *a, int n ,int key);
/*时间复杂度O(n)*/

/*4444444444444444有序表查找444444444444444444*/
/*************折半查找(二分查找)****************/
int Binary_Search(int *a, int n ,int key);


/**************插值寻找****数据均匀有序使用****************/
int insert_Search(int *a, int n ,int key);

int test_search();
#endif //DATA_STRUCTURE_MYSEARCH_H
