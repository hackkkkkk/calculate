#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;


#define n 8           //Ҷ����Ŀ
#define m 2*n-1       //���н������
typedef struct{       //�������
    double weight;    //����Ȩֵ
    int parent,lchild,rchild;//˫��ָ�뼰���Һ���
}HTNode;
typedef HTNode HuffmanTree[m];//HuffmanTree����������
 
typedef struct{       //����SelectMin����������Ľ������
    int id;           //���������������е����
    double weight;    //���������Ȩֵ
}temp;
 
typedef struct{       //������ 
    char bits[n+1];   //��ű���λ��
}CodeNode;
typedef CodeNode HuffmanCode[n];
 
void InitHuffmanTree(HuffmanTree T){
    //��ʼ����������
    //��2n-1������������ָ�����Ϊ��(����Ϊ-1)��Ȩֵ��Ϊ0
    for(int i=0;i<m;i++){
        T[i].lchild=-1;
        T[i].rchild=-1;
        T[i].parent=-1;
        T[i].weight=0;
    }
}
 
bool cmp(temp a,temp b){
    //��������ıȽϺ���
    return a.weight<b.weight;
}
 
void SelectMin(HuffmanTree T,int k,int *p1,int *p2){
    //��ǰk�������ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊp1��p2
    temp x[m];              //x����Ϊtemp���͵�����
    int i,j;
    for(i=0,j=0;i<=k;i++){  //Ѱ����С�ʹ�С���ڵ�Ĺ���
        if(T[i].parent==-1){//����Ǹ��ڵ�,��������²���
            x[j].id=i;      //���ø��ڵ����Ÿ�ֵ��x
            x[j].weight=T[i].weight;//���ø��ڵ��Ȩֵ��ֵ��x
            j++;            //x������ָ�����һλ
        }
    }
    sort(x,x+j,cmp);        //��x����Ȩֵ��С��������
    //������x�����ĵ�һ�͵ڶ���λ���д洢��id�����ҵĸ��ڵ�����ֵ
    *p1=x[0].id;
    *p2=x[1].id;
}
 
void CreateHuffmanTree(HuffmanTree T){
    //�������������T[m-1]Ϊ������
    int i,p1,p2;
    InitHuffmanTree(T);    //��T��ʼ��
    
    T[0].weight=5; 
    T[1].weight=5; 
    T[2].weight=10; 
    T[3].weight=10; 
    T[4].weight=10; 
    T[5].weight=15; 
    T[6].weight=20; 
    T[7].weight=25;  
    
    for(i=n;i<m;i++){
        //�ڵ�ǰɭ��T[0����i-1]�����н���У�ѡȡȨ��С�ʹ�С��
        //���������T[p1]��T[p2]��Ϊ�ϲ�����
        //������n-1�κϲ����½�����δ���T[i]��
 
        SelectMin(T,i-1,&p1,&p2);//ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊp1��p2
 
        //����ΪT[p1]��T[p2]����������Ϊ���������ϲ�Ϊһ���µ���
        //�����ĸ����½��T[i]
        T[p1].parent=T[p2].parent=i;//T[p1]��T[p2]���������ĸ����ָ��i
        T[i].lchild=p1;             //��СȨ�ĸ�������½�������
        T[i].rchild=p2;             //��СȨ�ĸ�������½����Һ���
        T[i].weight=T[p1].weight+T[p2].weight;//�½���Ȩֵ������������Ȩֵ֮��
    }
}
 
void CharSetHuffmanEncoding(HuffmanTree T,HuffmanCode H){
    //���ݹ�������T������������H
    int c,p;//c��p�ֱ�ָʾT�к��Ӻ�˫�׵�λ��
    char cd[n+1];//��ʱ��ű���
    int start;//ָʾ������cd�е���ʼλ��
    cd[n]='\0';//���������
    
    
    for(int i=0;i<n;i++){//������Ҷ��T[i]�ı���
        start=n;//������ʼλ�õĳ�ֵ
        c=i;//��Ҷ��T[i]��ʼ����
        while((p=T[c].parent)>=0){//ֱ�����ݵ�T[c]������Ϊֹ
            //��T[c]��T[p]�����ӣ������ɴ���0���������ɴ���1
            if(T[p].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
            c=p;//��������
        }
        strcpy(H[i].bits,&cd[start]);//���Ʊ���λ��
    }
}
 
 
int main(){
    HuffmanTree T;
    HuffmanCode H;
    
    CreateHuffmanTree(T);
    CharSetHuffmanEncoding(T,H);

    printf("���������룺\n");
    double wpl=0.0;
    for(int i=0;i<n;i++){
        printf("id:%d  value:%.0f\n",i,T[i].weight);
        wpl+=strlen(H[i].bits)*T[i].weight;
    }
    printf("ƽ����Ϊ��%.2lf\n",wpl/100);
    return 0;
}

