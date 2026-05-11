#include<stdio.h>

void main()
{
    int c[100][100],s[100],dist[100],v,n;
    printf("enter the number of vertices:");
    scanf("%d",&n);
      printf("enter the cost between each vertex:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    printf("enter the src vertex: ");
    scanf("%d",&v);
    for(int i=0;i<n;i++)
    {
        s[i]=0;
        dist[i]=c[v][i];
    }
    s[v]=1;
    dist[v]=0;
    for(int w=0;w<n-2;w++)
    {
        int min=dist[0];
        int u;
        for(u=0;u<n;u++)
        {
            if (dist[u]<min && s[u]==0)
            {
                min=u;
            }
        }
        s[min]=1;
        for(int k=0;k<n;n++)
        {
            if(dist[k]>(dist[k]+c[u][k]))
            {
                dist[k]=dist[k]+c[u][k];
            }
        }


    }
    for(int i=0;i<n;i++)
    {
        printf("dist[%d]=%d\n",i,dist[i]);
    }


}
