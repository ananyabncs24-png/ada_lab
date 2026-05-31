#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

void Prims(int n, int cost[MAX][MAX]) {
    int t[MAX][3];      
    int mincost = 0;    
    int near[MAX];      
    
   
    int min = INF;
    int k = -1, l = -1;
    
    for (int r = 1; r <= n; r++) {        //used to find the edge with the minimum cost
        for (int c = 1; c <= n; c++) {
            if (cost[r][c] < min && r != c) {
                min = cost[r][c];
                k = r;
                l = c;
            }
        }
    }
    
   
    t[1][1] = k;
    t[1][2] = l;
    mincost = cost[k][l];
    
    
    for (int i = 1; i <= n; i++) {      //is the vertex closer to k or l 
        if (cost[i][k] < cost[i][l]) {
            near[i] = k;
        } else {
            near[i] = l;
        }
    }
    
   
    near[k] = 0;
    near[l] = 0;
   
    for (int i = 2; i <= n - 1; i++) {
        int j = -1;
        min = INF;
        
        
        for (int m = 1; m <= n; m++) {        //find the edge with the minimum cost connected to k or l
            if (near[m] != 0 && cost[m][near[m]] < min) {
                min = cost[m][near[m]];
                j = m;
            }
        }
        
      
        t[i][1] = j;
        t[i][2] = near[j];
        
        
        mincost = mincost + cost[j][near[j]];
        near[j] = 0; // Mark vertex j as included in the tree
        
        
        for (int k_idx = 1; k_idx <= n; k_idx++) {
            if (near[k_idx] != 0 && cost[k_idx][near[k_idx]] > cost[k_idx][j]) {
                near[k_idx] = j;
            }
        }
    }
  
    printf("congrats\n");
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int idx = 1; idx <= n - 1; idx++) {
        printf("%d -> %d\n", t[idx][1], t[idx][2]);
    }
    printf("mincost: %d\n", mincost);
}

int main() {
    int n, edges;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize entire cost matrix with Infinity
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges and their weights (format: source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w; // Handled as an undirected graph
    }

    // Run the implementation
    Prims(n, cost);

    return 0;
}
