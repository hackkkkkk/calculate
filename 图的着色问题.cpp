#include <iostream>

int color[100];
bool OK(int k,int c[][100]){           //�ж϶���k����ɫ�Ƿ�����ͻ

    int i;

    for (i=1; i<k; i++)

        if (c[k][i]==1 && color[i]==color[k])

            return false;

        return true;

}
void graphcolor(int n,int m,int c[][100]){

    int i,k;

    int flag=0;

    for (i=1; i<=n; i++) {

        color[i]=0;                     //��ʼ��

    }

    k=1;

    while (k>=1) {

        color[k]=color[k]+1;

        while (color[k]<=m) {

            if(OK(k,c))

                break;

            else

                color[k]=color[k]+1;      //������һ����ɫ

        }

        if (color[k]<=m&& k==n) {         //���

            for (i=1; i<=n; i++) {

                printf("%d ",color[i]);

            }

            printf("\n");

            flag=1;

        }

        else if (color[k]<=m&&k<n){

            k=k+1;                       //������һ������

        }

        else{

            color[k]=0;

            k=k-1;                       //����

        }

    }

    if (flag==1) {

        printf("NO\n");

    }

}
int main() {

    int i,j,n,m;

    int c[100][100];

    printf("�����붥����n����ɫ��m��\n");

    scanf("%d%d",&n,&m);

    printf("����������ͼ���ڽӾ���\n");

    for (i=1; i<=n; i++) {

        for (j=1; j<=n; j++) {

            scanf("%d",&c[i][j]);

        }

    }

    printf("��ɫ���ܽ�m��\n");

    graphcolor(n, m, c);

    return 0;

}

