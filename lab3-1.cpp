//˳�����
// ��һ���ź��������T[1..n]�в���x�����x��T�У����x��T���±�j�����x����T�У����j=0
#include<stdio.h>
int n,x;
int T[10000];//����T���������� 
void search(int x,int n){
    int j=0,i;
    for(i=1;i<=n;i++){
        if(T[i]==x){
            j=i;
            break;  //˳�����x�����ҵ����˳�ѭ��������±� ��û�ҵ���j=0 
        }
    }
    printf("%d\n",j);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){  //��������õ��������� 
        scanf("%d",&T[i]);
    }
    scanf("%d",&x);
    search(x,n);  //����search���� 
    return 0;
}