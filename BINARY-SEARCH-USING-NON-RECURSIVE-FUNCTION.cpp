#include<stdio.h>
int bs(int a[] , int low , int high , int ele )
{
	while(low<=high)
	{
	    int mid=(high+low)/2;
		if(a[mid]==ele)
		return mid;
		if(a[mid]>ele)
		high=mid-1;
		if(a[mid]<ele)
		low=mid+1;
	}
	return -1;
}
int main()
{
	int a[]={10,12,20,32,50,55,65,80,99},n=9,ele=99;
	int index=bs(a,0,n-1,ele);
	if(index==-1)
	printf("not found\n");
	else
	printf("found at index %d\n",index);
	return 0;
}
