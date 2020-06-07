#include <iostream>
#include<math.h>
#include<algorithm>
#define N 4
using namespace std;
double minlen=10000,x[N],r[N];//�ֱ�Ϊ��СԲ���г��ȣ�������һ���ϴ�ֵ��x�����а�������Բ�ĺ����꣬r�����а���ÿ��Բ�뾶
double bestsort[N];//��СԲ���еİ뾶˳��
 
double center(int m){//��������Բ��Բ�ĺ�����
    double a=0;
    for(int j=1;j<m;++j){//�ж�Ŀ��Բ�Ƿ���������֮ǰ����һԲ����
        double b=x[j]+2.0*sqrt(r[m]*r[j]);//ͨ��ֱ�������εļ򵥶����Ϳ��Լ���Բ�ĺ�����
        if(b>a)
            a=b;
    }
    return a;
}
void compute(){//���㵱ǰԲ���еĳ���
    double low=0,high=0;
    for(int i=1;i<N;++i){//ͨ���Ƚ��ҳ���С��������������Ҳ����꣬�������Բ���еĳ��ȡ�
        if(x[i]-r[i]<low)
            low=x[i]-r[i];//����ͨ��forѭ��������ߵ�low���ұߵ�high 
        if(x[i]+r[i]>high)
            high=x[i]+r[i];
    }
    if(high-low<minlen){//ÿ��ѭ�����Ա�֮ǰ��������Сֵ�������С���滻 
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
            swap(r[m],r[j]);//��������λ�� 
            double center_x=center(m);
            if(center_x+r[m]+r[1]<minlen){//���жϵ�ǰ���Ƿ��ڷ�Χ�ڣ��������ô��������������һ�㣬�������ֱ�ӻ��ݡ�
                x[m]=center_x;
                backtrack(m+1);
            }
            swap(r[m],r[j]);
        }
    }
}
int main()
{
    r[1]=1,r[2]=1,r[3]=2;//������������뾶���� 
    printf("ÿ��Բ�뾶�ֱ�Ϊ:");
    for(int i=1;i<N;++i)
        printf("%.2f ",r[i]);
    printf("\n");
    backtrack(1);
    printf("��СԲ���г���Ϊ��%.2f\n",minlen);//������ 
    printf("����Բ���е�˳���Ӧ�İ뾶�ֱ�Ϊ��");
    for(int i=1;i<N;++i)
        printf("%.2f ",bestsort[i]);
    printf("\n");
    return 0;
}
