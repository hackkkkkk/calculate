#include<stdio.h>
#define MAX 100
int a[MAX];
void GreedyApproach(int x[][2],int n){
	a[1] = 1;//���Ž�غ��л1
	int m=2,j = 0;	//m�洢�ж��ٸ����j�洢���Ž������һ�������
	for (int i = 1; i < n; i++) {
		if (x[i][0] >= x[j][1]) {//�����ǰ��Ŀ�ʼʱ����ڵ������Ž������һ���Ľ���ʱ��
			a[m++] = i + 1;	//��ѵ�ǰ���ŷ������Ž���
			j = i;	//j���ɵ�ǰ��i
		}
	}
	a[0] = m - 1;	//a[0]�洢�ж��ٸ����Ž�
}

int main()
{
	int x[][2] = { {1,4},{2,5},{3,6},{4,7},{4,9},{5,9},{6,10},{8,11},{8,12} };
	GreedyApproach(x,9);
	printf("k=%d\n���", a[0]);
	for (int i = 1; i <= a[0]; i++) {	//������Ž�
		printf("%d ", a[i]);
	}
	return 0;
}


