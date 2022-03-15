#include<iostream>
#include"test/test.h"
using namespace std;
int test(){
	//第一种代码，累加，O(n)
	int i,sum=0,n=100;
	for(i = 1; i <= n; i++){
		sum =sum + 1;
	}
    cout<<"第一种:"<<endl;
	cout<<sum<<endl;
	//第二种代码，公式，O(1)
	//int sum = 0,n = 100;
	sum = (1+n)*n/2;
    cout<<"第二种:"<<endl;
    cout<<sum<<endl;
    cout<<"max:"<<endl;
    cout<<max(1,2)<<endl;

}

