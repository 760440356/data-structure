//
// Created by DELL on 2022/4/7.
//

#include "mysearch.h"


int Sequential_Search(int *a, int n ,int key){
    int i;
    for(i = 1; i <= n; ++i){
        if(a[i] == key)
            return i;
    }
    return 0;
}

int Sequential_Search2(int *a, int n ,int key){
    int i;
    a[0] = key;
    i = n;
    while(a[i] != key){
        i--;
    }
    return i;
}





/*******************折半查找*********************/
int Binary_Search(int *a, int n ,int key){
    int low, high, mid;
    low =1;
    high = n;
    while(low <= high){
        mid = (low+high)/2;
        if(key < a[mid]){
            high = mid - 1;
        }
        else if(key > a[mid]){
            low = mid + 1;
        }
        else return mid;
    }
    return 0;
}
int insert_Search(int *a, int n ,int key){
    int low, high, mid;
    low =1;
    high = n;
    while(low <= high){
        mid = low + (high-low)*(key-a[low])/(a[high]-a[low]);
        if(key < a[mid]){
            high = mid - 1;
        }
        else if(key > a[mid]){
            low = mid + 1;
        }
        else return mid;
    }
    return 0;
}








int test_search(){
    int n,key;
    cin>>n;
    cin>>key;
    int a[n+1];
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
    }
    int i = Sequential_Search(a,n,key);
    cout<<i<<":"<<a[i];
}