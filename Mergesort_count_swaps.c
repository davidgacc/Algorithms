
/*--------------------------------------
| 			Algorithms		
|
|Problem :Numbers of swaps in Merge Sort
|Name: David Gutierrez Arias
| 
----------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#define N 100000

/*Merge sort and count*/
int merge(int array[],int temp[],int left,int mid,int right){
	int i=left,j=mid,k=left;
	int count=0;
	while(i<=mid-1 && j<=right){
		if(array[i]<=array[j]){
			temp[k++] = array[i++];
		} else {
			temp[k++] = array[j++];
			count+=(mid-i);
		}
	}
	/*copy elements from left*/
	while (i<=mid-1)temp[k++]=array[i++];
	/*copy elements from right*/
	while(j<=right)temp[k++]=array[j++];
	for(i=left;i<=right;i++)array[i]=temp[i];
	return count;
}

/*partition and count*/
int partition_merge(int array[],int temp[],int left,int right){
	int count=0,count_left=0,count_right=0,count_merge=0;
	int mid;
	if(left<right){
		mid=(right+left)/2;
		count_left=partition_merge(array,temp,left,mid);
		count_right=partition_merge(array,temp,mid+1,right);
		count_merge=merge(array,temp,left,mid+1,right);
		count = count_left + count_right + count_merge;
	}
	return count;
}

/*----------------------
Input : Size of array 
		Array of integers
-------------------------*/
int main(){
	int array[N],temp[N],size,resp;
	int i=0;
	scanf("%d",&size);
	while(i<size)scanf("%d",&array[i++]);
	resp = partition_merge(array,temp,0,size-1);
	printf("%d\n",resp);
	return 0;
}
