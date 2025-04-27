#include<stdio.h>
int main()
{
    int a[]={4,3,2,10,12,1,5,6},n=8, i, j, key;
    printf("before sorting:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    for (i = 1; i < n; i++) 
    {
        key=a[i];
        j=i-1;
        while(j >= 0 && a[j] > key) 
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    printf("\nafter sorting:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
