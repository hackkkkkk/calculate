#include<stdio.h>
void main()
{
int a[10]={1,2,3,4,5,6,7,8,9,10};
int i,x,y;
printf("������Ҫ���ҵ���:\n");
scanf("%d",&x);
y=0;
for(i=0;i<10;i++) 
{
if(x==a[i]) 
{
y=1; 
printf("��Ҫ���ҵ���%d�ڵڸ�%dλ��\n",x,i+1); 
break; 
}
}

} 
