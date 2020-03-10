#include <stdio.h>
#include <stdlib.h>

#define MAXN 10 
#define INF = 1000

typedef struct struct_graph{
    char vexs[MAXN];
    int vexnum;//������ 
    int edgnum;//���� 
    int matirx[MAXN][MAXN];//�ڽӾ��� 
} Graph;

int pathmatirx[MAXN][MAXN];//��¼��Ӧ�����С·����ǰ���㣬����p(1,3) = 2 ˵������1������3����С·��Ҫ����2 
int shortPath[MAXN][MAXN];//��¼��������С·��ֵ

void short_path_floyd(Graph G, int P[MAXN][MAXN], int D[MAXN][MAXN]){
    int v, w, k;
    //��ʼ��floyd�㷨���������� 
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            D[v][w] = G.matirx[v][w];
            P[v][w] = w;
        }
    }

    //�����Ǹ��������㷨�ĺ��Ĳ��� 
    //kΪ�м�� 
    for(k = 0; k < G.vexnum; k++){
        //vΪ��� 
        for(v = 0 ; v < G.vexnum; v++){
            //wΪ�յ� 
            for(w =0; w < G.vexnum; w++){
                if(D[v][w] > (D[v][k] + D[k][w])){
                    D[v][w] = D[v][k] + D[k][w];//������С·�� 
                    P[v][w] = P[v][k];//������С·���м䶥�� 
                }
            }
        }
    }

    printf("\n��ʼ����D����\n");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            printf("%d ", D[v][w]);
        }
        printf("\n");
    }

    printf("\n��ʼ����P����\n");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            printf("%d", P[v][w]);
        }
        printf("\n");
    }

    v = 0;
    w = 3;
    //�� 0 �� 3����С·��
    printf("\n%d -> %d ����С·��Ϊ��%d\n", v, w, D[v][w]);
    k = P[v][w];
    printf("path: %d", v);//��ӡ���
    while(k != w){
        printf("-> %d", k);//��ӡ�м��
        k = P[k][w]; 
    }
    printf("-> %d\n", w);
}

int main(){
    int v, w;
    Graph G;
    printf("�����붥����:\n");
    scanf("%d", &G.vexnum);
    printf("�������ʼ����ֵ��\n");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            scanf("%d", &G.matirx[v][w]);
        }
    }
    printf("\n����ľ���ֵ��\n");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            printf("%d ", G.matirx[v][w]);
        }
        printf("\n");
    }
    short_path_floyd(G, pathmatirx, shortPath);
}
