#include<stdio.h>
void main()
{
int a[10]={1,2,3,4,5,6,7,8,9,10};
int i,x,y;
printf("输入你要查找的数:\n");
scanf("%d",&x);
y=0;
for(i=0;i<10;i++) 
{
if(x==a[i]) 
{
y=1; 
printf("你要查找的数%d在第个%d位置\n",x,i+1); 
break; 
}
}

} 
