//顺序查找
// 在一个排好序的数组T[1..n]中查找x，如果x在T中，输出x在T的下标j；如果x不在T中，输出j=0
#include<stdio.h>
int n,x;
int T[10000];//定义T数组存放数据 
void search(int x,int n){
    int j=0,i;
    for(i=1;i<=n;i++){
        if(T[i]==x){
            j=i;
            break;  //顺序查找x，如找到，退出循环，输出下标 ，没找到则j=0 
        }
    }
    printf("%d\n",j);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){  //输入排序好的数组数据 
        scanf("%d",&T[i]);
    }
    scanf("%d",&x);
    search(x,n);  //调用search函数 
    return 0;
}
