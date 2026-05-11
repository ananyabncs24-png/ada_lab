#include<stdio.h>
void heapify(int a[],int n,int p)
{
    int c,item;
    item=a[p];
    c=2*p+1;
    while(c<=n-1)
    {
        if(c+1<=n-1)
        {
            if(a[c]<a[c+1])
            {
                c++;
            }
        }
        if(item<a[c])
        {
            a[p]=a[c];
            p=c;
            c=2*p+1;
        }
        else
        {
            break;
        }
    }
    a[p]=item;
}
void build_heap(int a[],int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
    {
        heapify(a,n,i);
    }
}
void heapsort(int a[],int n)
{
    int i,temp;
    build_heap(a,n);
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }

}
int main()
{   int a[100],n,p;
    printf("enter the array size:");
    scanf("%d",&n);
    printf("enter the array");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);}
    heapsort(a,n);

    printf("after sort:");
    for(int i=0;i<n;i++){
    printf("%d ",a[i]);}

}
