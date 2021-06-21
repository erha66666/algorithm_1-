#include<stdio.h>
#include<stdlib.h> 
const int maxn=1010;
int a[6]={4,1,6,5,3,2};
void Merge(int list[],int left,int mid,int right){        //归并 
	int mergelist[maxn]; 
	int i=left;
	int j=mid+1;
	int k=left;
	while (i<=mid&&j<=right){
		if(list[i]<list[j]) mergelist[k++]=list[i++];
		else mergelist[k++]=list[j++];
	}
	while (i<=mid){
		mergelist[k++]=list[i++];
	}
	while (j<=right){
		mergelist[k++]=list[j++];
	}
	for(k=left;k<=right;k++)  list[k]=mergelist[k];
} 

void MergeSort(int list[],int left,int right){
	if(left<right){
		int mid = (left+right)/2;            //设定中间值 
		MergeSort(list,left,mid);
		MergeSort(list,mid+1,right);
		Merge(list,left,mid,right);
	}
}
int main(){
	for(int i=0;i<6;i++){
		if(i==5) printf("%d\n",a[i]);
		else printf("%d ",a[i]);                  //输出 
	}
	MergeSort(a,0,5);
	for(int i=0;i<6;i++){
		if(i==5) printf("%d\n",a[i]);
		else printf("%d ",a[i]);
	}
	return 0; 
}
