#include<stdio.h> 
int color[100];
int cnt=0;
bool ok(int k,int c[][100]);
void graphcolor(int n,int m,int c[][100]);
int main()
{
    int i,j,n,m;
    int c[100][100];//�洢n�����������ͼ������
    printf("���붥����n����ɫ��m:\n");
    scanf("%d%d",&n,&m);
    printf("��������ͼ���ڽӾ���:\n");
    for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
        	scanf("%d",&c[i][j]);
    printf("��ɫ���п��ܵĽ�:\n");
    graphcolor(n,m,c);
    if(cnt==0){
	    printf("NO\n");
	}
	else{
		printf("һ����%d�ַ���\n",cnt);
	}
}
bool ok(int k,int c[][100])//�ж϶���k����ɫ�Ƿ�����ͻ
{
	int i;
	for(i=1;i<k;i++)
	{
		if(c[k][i]==1&&color[i]==color[k])
	    	return false;
	}
	return true;
}
  
void graphcolor(int n,int m,int c[][100])
{
    int i,k;
    for(i=1;i<=n;i++)
    color[i]=0;
    k=1;
    while(k>=1)
    {
      	color[k]=color[k]+1;
      	while(color[k]<=m)
	        if(ok(k,c))
	          	break;
	        else 
	          	color[k]=color[k]+1;//������һ����ɫ
	        if(color[k]<=m&&k==n)
	        {
	          	for(i=1;i<=n;i++){ 
	            	printf("%d ",color[i]);
	            } 
	          	printf("\n");
	          	cnt++;
	        }
	        else if(color[k]<=m&&k<n)
	          	k=k+1;//������һ������
	        else
	        {
	            color[k]=0;
	          	k=k-1;//����
	        }
    }
}

