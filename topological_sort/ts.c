#include <stdio.h>
#include <stdlib.h>

#define MAX 100


void toposs(int V[MAX][MAX], int n) {
    int indegree[MAX];
    int check[MAX];
    int TP[MAX]; 
    int tp_count = 0; 

   
    for (int i = 1; i <= n; i++) {
        indegree[i] = 0;
    }

    // Calculate actual indegrees from the adjacency matrix V
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (V[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Initialize the check[] array value to 0 for all vertices
    for (int i = 1; i <= n; i++) {
        check[i] = 0;
    }

    
    while (1) {
        int w = -1;

        /* Let w be any vertex with check[w] == 0 and indegree[w] == 0 */
        for (int i = 1; i <= n; i++) {
            if (check[i] == 0 && indegree[i] == 0) {
                w = i;
                break; // Found a valid vertex
            }
        }

        if (w == -1) {
            break;
        }

        tp_count++;
        TP[tp_count] = w;

        
        check[w] = 1;

       
        for (int v = 1; v <= n; v++) {
            if (V[w][v] == 1) {      //since its directed dont have to decrement V[v][w]
                indegree[v]--;
            }
        }
    }

   
    if (tp_count < n) {
        printf("NO Topological sequence\n");
    } else {
       
        printf("Topological Sequence: ");
        for (int i = 1; i <= tp_count; i++) {
            printf("%d ", TP[i]);
        }
        printf("\n");
    }
}

int main() {
  int v[100][100], n;

printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        scanf("%d", &v[i][j]);
    }
}

    toposs(V, n);

    return 0;
}
