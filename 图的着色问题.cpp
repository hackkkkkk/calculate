#include <iostream>

int color[100];
bool OK(int k,int c[][100]){           //判断顶点k的着色是否发生冲突

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

        color[i]=0;                     //初始化

    }

    k=1;

    while (k>=1) {

        color[k]=color[k]+1;

        while (color[k]<=m) {

            if(OK(k,c))

                break;

            else

                color[k]=color[k]+1;      //搜索下一个颜色

        }

        if (color[k]<=m&& k==n) {         //输出

            for (i=1; i<=n; i++) {

                printf("%d ",color[i]);

            }

            printf("\n");

            flag=1;

        }

        else if (color[k]<=m&&k<n){

            k=k+1;                       //处理下一个顶点

        }

        else{

            color[k]=0;

            k=k-1;                       //回溯

        }

    }

    if (flag==1) {

        printf("NO\n");

    }

}
int main() {

    int i,j,n,m;

    int c[100][100];

    printf("请输入顶点数n和着色数m：\n");

    scanf("%d%d",&n,&m);

    printf("请输入无向图的邻接矩阵：\n");

    for (i=1; i<=n; i++) {

        for (j=1; j<=n; j++) {

            scanf("%d",&c[i][j]);

        }

    }

    printf("着色可能解m：\n");

    graphcolor(n, m, c);

    return 0;

}

