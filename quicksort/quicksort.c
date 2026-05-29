#include<stdio.h>
int partition(int a[],int low,int high)
{
    int i,j,key;
    key=a[low];
    i=low+1;
    j=high;
    while(1)
    {while(a[i]<=key && i<high)
    {
        i++;
    }
    while(a[j]>key)
    {
        j--;
    }
    if(i<j)
    {
        int temp;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    else
    {
         int temp;
        temp=a[low];
        a[low]=a[j];
        a[j]=temp;
        return j;
    }
    }
}
void quicksort(int a[],int low,int high)
{
  int j;
  if(low<high)
  {j=partition(a,low,high);
  quicksort(a,low,j-1);
  quicksort(a,j+1,high);}
}
int main()
{
    int n,a[100];
    printf("enter the number of elements in the array");
    scanf("%d",&n);
    printf("enter the original array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;

}

