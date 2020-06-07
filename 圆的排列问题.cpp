#include <iostream>
#include<math.h>
#include<algorithm>
#define N 4
using namespace std;
double minlen=10000,x[N],r[N];//分别为最小圆排列长度，先设置一个较大值，x数组中包括所有圆心横坐标，r数组中包括每个圆半径
double bestsort[N];//最小圆排列的半径顺序
 
double center(int m){//计算所有圆的圆心横坐标
    double a=0;
    for(int j=1;j<m;++j){//判断目标圆是否与排在它之前的任一圆相切
        double b=x[j]+2.0*sqrt(r[m]*r[j]);//通过直角三角形的简单定理，就可以计算圆的横坐标
        if(b>a)
            a=b;
    }
    return a;
}
void compute(){//计算当前圆排列的长度
    double low=0,high=0;
    for(int i=1;i<N;++i){//通过比较找出最小的左部坐标和最大的右部坐标，相减就是圆排列的长度。
        if(x[i]-r[i]<low)
            low=x[i]-r[i];//不断通过for循环更新左边的low与右边的high 
        if(x[i]+r[i]>high)
            high=x[i]+r[i];
    }
    if(high-low<minlen){//每次循环都对比之前产生的最小值，如果更小就替换 
        minlen=high-low;
        for(int i=1;i<N;++i)
            bestsort[i]=r[i];
    }
}
void backtrack(int m){
    if(m==N)
        compute();
    else{
        for(int j=m;j<N;++j){
            swap(r[m],r[j]);//交换两个位置 
            double center_x=center(m);
            if(center_x+r[m]+r[1]<minlen){//先判断当前层是否在范围内，如果是那么继续不断搜索下一层，如果不是直接回溯。
                x[m]=center_x;
                backtrack(m+1);
            }
            swap(r[m],r[j]);
        }
    }
}
int main()
{
    r[1]=1,r[2]=1,r[3]=2;//可以任意更换半径数据 
    printf("每个圆半径分别为:");
    for(int i=1;i<N;++i)
        printf("%.2f ",r[i]);
    printf("\n");
    backtrack(1);
    printf("最小圆排列长度为：%.2f\n",minlen);//输出结果 
    printf("最优圆排列的顺序对应的半径分别为：");
    for(int i=1;i<N;++i)
        printf("%.2f ",bestsort[i]);
    printf("\n");
    return 0;
}
