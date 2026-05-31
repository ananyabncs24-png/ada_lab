#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100


int max_value(int a, int b) {
    return (a > b) ? a : b;
}


int knapsackDp(int n, int w[MAX_ITEMS], int p[MAX_ITEMS], int M) {

    int Table[MAX_ITEMS][MAX_WEIGHT];
    for (int i = 0; i <= n; i++) {
        Table[i][0] = 0;        //first column as 0
    }
    
    
    for (int j = 0; j <= M; j++) {
        Table[0][j] = 0;    //first row as 0
    }
    
  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            
            // If current column weight capacity 'j' is less than the item's weight
            if (j < w[i]) {
                Table[i][j] = Table[i - 1][j];
            } 
            // Else take the maximum between excluding or including the current item
            else {
                Table[i][j] = max_value(Table[i - 1][j], Table[i - 1][j - w[i]] + p[i]);
            }
            
        }
    }
    
   
    return Table[n][M];
}

int main() {
    int n, M;
    int w[MAX_ITEMS]; 
    int p[MAX_ITEMS]; 

    printf("Enter number of items (n): ");
    scanf("%d", &n);

    printf("Enter maximum capacity of knapsack (M): ");
    scanf("%d", &M);

   
    printf("Enter weights of the items:\n");
    for (int i = 1; i <= n; i++) {
        printf("Weight for item %d: ", i);
        scanf("%d", &w[i]);
    }

    printf("Enter profits of the items:\n");
    for (int i = 1; i <= n; i++) {
        printf("Profit for item %d: ", i);
        scanf("%d", &p[i]);
    }

    int max_profit = knapsackDp(n, w, p, M);

    printf("\ncongrats\n");
    printf("Maximum profit obtained: %d\n", max_profit);

    return 0;
}
