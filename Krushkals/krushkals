#include <stdio.h>

#define MAX 100

int parent[MAX];


int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}


void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main()
{
    int n, cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            // Replace 0 with infinity (except diagonal)
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int mincost = 0;
    int edges = 0;

    printf("\nEdges in MST:\n");

    while(edges < n - 1)
    {
        int min = 999, a = -1, b = -1;

        // Find minimum edge
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        
        if(u != v)
        {
            printf("Edge %d: (%d - %d) cost = %d\n", edges + 1, a, b, min);
            mincost += min;
            unionSet(u, v);
            edges++;
        }

   
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
