#include<stdio.h>
#define MAX 100
int a[MAX];
void GreedyApproach(int x[][2],int n){
	a[1] = 1;//最优解必含有活动1
	int m=2,j = 0;	//m存储有多少个活动，j存储最优解中最后一个的序号
	for (int i = 1; i < n; i++) {
		if (x[i][0] >= x[j][1]) {//如果当前活动的开始时间大于等于最优解中最后一个的结束时间
			a[m++] = i + 1;	//则把当前活动序号放入最优解中
			j = i;	//j换成当前的i
		}
	}
	a[0] = m - 1;	//a[0]存储有多少个最优解
}

int main()
{
	int x[][2] = { {1,4},{2,5},{3,6},{4,7},{4,9},{5,9},{6,10},{8,11},{8,12} };
	GreedyApproach(x,9);
	printf("k=%d\n序号", a[0]);
	for (int i = 1; i <= a[0]; i++) {	//输出最优解
		printf("%d ", a[i]);
	}
	return 0;
}


