#include<stdio.h>
void swap(int*a ,int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int pivot(int a[] , int low , int high)
{
	int i=low;
	int j=high;
	int pivot_element=a[low];
	while(i<j)
	{
		while(a[i]<=pivot_element)
		i++;
		while(a[j]>pivot_element)
		j--;
		if(i<j)
		swap(&a[i],&a[j]);
	}
	if(i>j)
	swap(&a[low],&a[j]);
	return j;
}
void quicksort(int a[], int low , int high )
{
	if(low<high)
	{
		int pivot_index=pivot(a,low,high);
		quicksort(a,low,pivot_index-1);
		quicksort(a,pivot_index+1,high);
	}
}
int main()
{
	int a[]={51,95,65,72,42,38,39,41,15},i,n=9;
	printf("before sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	quicksort(a,0,n-1);
	printf("\nafter sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
