#include <stdio.h>
int binary_search(int key,int a[],int n) 
{
    int low,high,mid,count=0,count1=0;
    low=0;
    high=n-1;
    while(low<high)    
    {
        count++;    
        mid=(low+high)/2;    
        if(key<a[mid])   
            high=mid-1;    
        else if(key>a[mid])    
            low=mid+1;    
        else if(key==a[mid])   
        {
            printf("���ҳɹ�!\n ���� %d ��!a[%d]=%d",count,mid,key);    
            count1++;   
            break;
        }
    }
    if(count1==0)   
        printf("error!");  
    return 0;
}

int main()
{
    int i,key,a[100],n;
    printf("����ĳ��ȣ�\n");
    scanf("%d",&n);  
    printf("����Ԫ�أ�\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);   
    printf("������ҵ�Ԫ�أ�\n");
    scanf("%d",&key);  
    binary_search(key,a,n);  
    printf("\n");
    return 0;
}
