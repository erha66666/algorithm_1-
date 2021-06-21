#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	
    int W, N, w[100], v[100], dp[100][100];
    scanf("%d %d", &W, &N);
    for(int i = 1; i <= N; i++) scanf("%d", &w[i]);
    for(int i = 1; i <= N; i++) scanf("%d", &v[i]);
    memset(dp, 0, sizeof(dp)); // 初始化为0

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= W; j++){
            if(j < w[i]) dp[i][j] = dp[i - 1][j]; //不装，因为装不下
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]); //在可以装得前提下， 看看装还是不装哪一种情况可以使得价值更大；
        }
    }
    printf("%d\n", dp[N][W]);
    return 0;
}
