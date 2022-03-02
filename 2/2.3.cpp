#include<cstdio>
int main(){
	//第一种代码，累加，O(n)
	int i,sum=0,n=100;
	for(i = 1; i <= n; i++){
		sum =sum + 1;
	}
	printf("%d",sum);
	//第二种代码，公式，O(1)
	//int sum = 0,n = 100;
	sum = (1+n)*n/2;
	printf("%d",sum);
}

