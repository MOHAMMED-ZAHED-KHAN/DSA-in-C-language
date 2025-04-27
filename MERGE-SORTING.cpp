#include<stdio.h>
int merge(int a[],int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	int b[9];
	while(i<=mid && j<=high)
	{
		if(a[j]>a[i])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	if(i>mid)
	{
		while(j<=high)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k];
	}
}
void mergesort(int a[],int low,int high)
{
	int mid=(high+low)/2;
	if(low<high)
	{
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
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
	mergesort(a,0,n-1);
	printf("\nafter sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
