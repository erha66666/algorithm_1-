#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5;
int Select(int L[],int k,int size)
{
    int pos=L[(size+1)/2];
    int L1[size/2+5],L2[size/2+5];
    int size1=0,size2=0;
    for(int i=1;i<=size;i++)
    {
        if(i!=(size+1)/2){
            if(L[i]<=pos) L1[++size1]=L[i];
            else L2[++size2]=L[i];
        }
    }
    if(k==size1+1){
        return pos;
    }else if(k<size1+1){
        return Select(L1,k,size1);
    }else{
        return Select(L2,k-(size1+1),size2);
    }
}
int main()
{
    int s[maxn];
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    int ans=Select(s,k,n);
    cout<<ans;
}