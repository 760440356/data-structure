#include<iostream>
#include"test/test.h"
using namespace std;
int test(){
	//��һ�ִ��룬�ۼӣ�O(n)
	int i,sum=0,n=100;
	for(i = 1; i <= n; i++){
		sum =sum + 1;
	}
    cout<<"��һ��:"<<endl;
	cout<<sum<<endl;
	//�ڶ��ִ��룬��ʽ��O(1)
	//int sum = 0,n = 100;
	sum = (1+n)*n/2;
    cout<<"�ڶ���:"<<endl;
    cout<<sum<<endl;
    cout<<"max:"<<endl;
    cout<<max(1,2)<<endl;

}

