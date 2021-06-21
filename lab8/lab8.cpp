#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int p[1005] = { 0 }, m[1005][1005] = { 0 }, s[1005][1005] = { 0 };
void print(int s[][1005], int i, int j) {//括号化方案
	if (i == j) {
		printf("A%d", i);
	}
	else {
		printf("(");
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		printf(")");
	}
}
void MatrixChain(int p[1005], int m[1005][1005], int s[1005][1005], int n) {
	int j,t;
	for (int r = 2; r <= n; r++) {//r为当前问题规模（长度）
		for (int i = 1; i <= n - r + 1; i++) { //i的起点不断变化，各种r长
			j = i + r - 1;  //不同终点
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//划分为Ai(Ai+1...Aj),此时k=i
			s[i][j] = i;//初始化 s位置为i
			for (int k = i + 1; k <= j - 1; k++) {
				t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
int main() {
    int n;
	printf("输入问题规模（长度）: ");
	scanf("%d", &n);
	printf("输入向量p: ");
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}
	MatrixChain(p, m, s, n - 1);
	printf("最小总次数为: %d\n", m[1][n - 1]);
	print(s, 1, n - 1);
}