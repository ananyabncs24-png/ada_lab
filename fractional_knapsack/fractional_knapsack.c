#include<stdio.h>
void main()
{
   float p[100],w[100],x[100],m,total;
   int n,k;
   printf("enter the number of items");
   scanf("%d",&n);
   printf("enter the capacity of knapsack:");
   scanf("%f",&m);
   for(int i=0;i<n;i++)
   {
       printf("enter profit value %d: ",i+1);
       scanf("%f",&p[i]);
       x[i]=0;
       printf("enter weight value %d: ",i+1);
       scanf("%f",&w[i]);
   }
   int temp;
   for(int i=0;i<n-1;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(p[i]/w[i]<p[j]/w[j])
           {
               temp=p[i];
               p[i]=p[j];
               p[j]=temp;
               temp=w[i];
               w[i]=w[j];
               w[j]=temp;
           }
       }
   }
   int rem_cap=m;
   for(k=0;k<n;k++)
   {
       if(w[k]>rem_cap)
       {
        break;
       }
       rem_cap=rem_cap-w[k];
       x[k]=1;
   }
   if(k<n)
    {
        x[k]=rem_cap/w[k];
    }
      for(int i=0;i<n;i++)
      {
        total=total+x[i]*p[i];
      }

      printf("total profit=%f",total);
}

