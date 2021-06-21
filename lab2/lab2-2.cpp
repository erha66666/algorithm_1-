#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 100;
int A[maxn];
int dis[maxn];
int M[maxn][maxn];
int way[maxn];
int n;

void Dijkstra(int s){
    memset(way,-1,sizeof(way));
    memset(dis,0x3f,sizeof(dis));
    memset(A,0,sizeof(A));
    dis[s] = 0;
    while(1){
        int k = 0;
        for(int j = 1; j <= n; j++){
            if(!A[j] && dis[j]<dis[k])
                k=j;
        }
        if(!k){
        	return;
		}
        A[k] = 1;
        for(int j = 1; j <= n; j++){
            if(dis[j]>dis[k]+M[k][j]){
                dis[j]=dis[k]+M[k][j];
                way[j]=k;
            }
        }
    }
}

int main(){
    int m,x,y,z,Point;
    printf("请输入共有几个点，几条边："); 
    scanf("%d%d",&n,&m);
    memset(M,0x3f,sizeof(M));
    printf("请输入每条边的x,y,z,代表x到y的距离为z（用数字表示字母，从1开始）：\n"); 
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&x,&y,&z);
        M[x][y] = z;
    }
    
    Dijkstra(1);
    printf("起始点为a，请输入终止点（数字）：");
    scanf("%d",&Point);
    printf("a到该点的最短路径为：%d\n",dis[Point]);
    return 0;
}
