#include<stdio.h>

#define LEFT 0
#define RIGHT 1
#define MAX 100

int val[MAX];
int dir[MAX];

void printpermutation(int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",val[i]);
    }
    printf("\n");

}
void johnson_trotter(int n)
{
    
    for(int i=1;i<=n;i++)
    {
        val[i]=i;
        dir[i]=LEFT;
    }
    printpermutation(n);
    while(1)
    {
        int mobile_val=-1;
        int mobile_idx=-1;
        
        for(int i=1;i<=n;i++)
        {
            if(dir[i]==LEFT && i>1)
            {
                if(val[i]>val[i-1] && val[i]>mobile_val)
                {
                    mobile_val=val[i];
                    mobile_idx=i;
                }
            }
            else if(dir[i]==RIGHT && i<n)
            {
                if(val[i]>val[i+1] && val[i]>mobile_val)
                {
                    mobile_val=val[i];
                    mobile_idx=i;
                }
            }
        }
        printf("mobile ele=%d and mobile idx=%d\n",mobile_val,mobile_idx);
        
        if(mobile_idx==-1)
        {
            break;
        }

        
        int next_idx=(dir[mobile_idx]==LEFT)?(mobile_idx-1):(mobile_idx+1);

        
        int temp1=val[mobile_idx];
        val[mobile_idx]=val[next_idx];
        val[next_idx]=temp1;

        int temp2=dir[mobile_idx];
        dir[mobile_idx]=dir[next_idx];
        dir[next_idx]=temp2;

        
        for(int i=1;i<=n;i++)
        {
            if(val[i]>mobile_val)
            {
                if(dir[i]==LEFT)
                {
                    dir[i]=RIGHT;
                }
                else
                {
                    dir[i]=LEFT;
                }
            }
        }

       
        printpermutation(n);

       
    }
}
int main()
{
    int n;
    printf("enter the number of elements");
    scanf("%d",&n);
    johnson_trotter(n);

    return 0;
}
