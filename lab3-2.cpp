//顺序查找
// 在一个排好序的数组T[1..n]中查找x，如果x在T中，输出x在T的下标j；如果x不在T中，输出j=0
#include<stdio.h>
int n,x;
int T[10000];//定义T数组存放数据 
void search(int x){
	int j=0;
	int a0=1,a2=n,a1;  //运用二分法查找，a0,a2分别存放最小最大值，a1存放中间值 
	while(a0<=a2){
		a1=(a0+a2)/2;    //计算中间值 
		if(x<T[a1]){
			a2=a1-1;
		}
		else if(x>T[a1]){
			a0=a1+1;
		}
		else if(x==T[a1]){
			j=a1;
			break;
		}
	}
	printf("%d",j);
} 
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){  //输入排序好的数组数据 
        scanf("%d",&T[i]);
    }
    scanf("%d",&x);
    search(x);  //调用search函数 
    return 0;
}
