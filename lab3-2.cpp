//˳�����
// ��һ���ź��������T[1..n]�в���x�����x��T�У����x��T���±�j�����x����T�У����j=0
#include<stdio.h>
int n,x;
int T[10000];//����T���������� 
void search(int x){
	int j=0;
	int a0=1,a2=n,a1;  //���ö��ַ����ң�a0,a2�ֱ�����С���ֵ��a1����м�ֵ 
	while(a0<=a2){
		a1=(a0+a2)/2;    //�����м�ֵ 
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
    for(int i=1;i<=n;i++){  //��������õ��������� 
        scanf("%d",&T[i]);
    }
    scanf("%d",&x);
    search(x);  //����search���� 
    return 0;
}