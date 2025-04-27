#include<stdio.h>
int bs(int a[] , int low , int high , int ele )
{
	int mid=(high+low)/2;
	if(low<=high)
	{
		if(a[mid]==ele)
		return mid;
		if(a[mid]>ele)
		return bs(a,low,mid-1,ele);
		if(a[mid]<ele)
		return bs(a,mid+1,high,ele);
	}
	return -1;
}
int main()
{
	int a[]={10,12,20,32,50,55,65,80,99},n=9,ele=12;
	int index=bs(a,0,n-1,ele);
	if(index==-1)
	printf("not found\n");
	else
	printf("found at index %d\n",index);
	return 0;
}
