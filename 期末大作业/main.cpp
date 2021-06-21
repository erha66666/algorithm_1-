#include<stdio.h>
#include<math.h>
#define work 5
int t[] = {1,2,2,5,8};
struct project
{
	int num;
	int time;
};
int max(int a, int b) {
	if (a > b) return a;
	else
	{
		return b;
	}
}
int main() {
	//导入工作时长数据
	project p[work];

	int sum=0;
	for(int i=0;i<work;i++)
	{
		p[i].num = i;
		p[i].time = t[i];
		sum = sum + t[i];
	}
	//对工作时长进行升序排序

	for (int i = 0; i < work; i++)
	{
		int min = p[i].time;
		int c = i;
		for (int j = i + 1; j < work; j++)
		{
			if (p[j].time < min) 
			{
				min = p[j].time;
				c = j;
			}
		}
		if (c != i)
		{
			project a;
			a = p[i];
			p[i] = p[c];
			p[c] = a;
		}
	}
	//动态规划
	static int middle = sum / 2;
	int s[work][12] = { 0 };//用于存放机器一的工作方案
	int a[work] = { 0 };
	for (int i=1 ; i < work; i++)
	{
		for (int j = 1; j <=middle; j++)
		{
			if (j >= p[i-1].time)
			{
				s[i][j]=max(s[i - 1][j], s[i - 1][j - p[i-1].time] + p[i-1].time);

			}
			else
			{
				s[i][j] = s[i - 1][j];
			}
		}
	}
	
	for (int i = 0; i < work; i++) {
		for (int j = 0; j <= middle; j++) {
			printf( "%d ",s[i][j]);
		}	
		printf("\n");
	}
	int re;
	re = sum-s[work - 1][middle];
	printf("%d\n机器一：t%d", re,p[4].num);
	re = re - p[4].time;
	for (int i = 3; i >= 0; i--)
	{
		if ( re> 0) 
		{
			re -= p[i + 1].num;
			printf("--");
			printf("t%d", p[i].num);
		}
	}
	printf("\n剩余工作由机器二完成");
	return 0;
}