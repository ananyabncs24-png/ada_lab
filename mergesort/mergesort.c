#include<stdio.h>

 void merge(int a[],int low,int high,int mid)
 {
    int i,j,k,b[50];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
            k++;
            i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
            k++;
            j++;
    }
    for(int x=low;x<=high;x++)
    {
        a[x]=b[x];
    }

 }
 void mergesort(int a[],int low,int high)
 {
    int mid;
    while(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
 }
 int main()
 {  int n,a[100];
    printf("enter the number of elements in the array");
    scanf("%d",&n);
    printf("enter the original array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
 }
