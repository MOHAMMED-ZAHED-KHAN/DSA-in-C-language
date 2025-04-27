#include<stdio.h>
int main()
{
	int a[5]={5,4,3,2,1},i,j,n=5,temp,min;
	printf("before sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	for(i=0;i<n-1;i++)
	{
	    min=i;
	    for(j=i+1;j<n;j++)
	    {
	        if(a[j]<a[min])
	        {
	            min=j;
	        }
	    }
	    temp=a[i];
	    a[i]=a[min];
	    a[min]=temp;
	}
	printf("\nafter sorting");
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
