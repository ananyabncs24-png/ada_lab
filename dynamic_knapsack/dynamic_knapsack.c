#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

// Function to find the maximum of two integers
int max_value(int a, int b) {
    return (a > b) ? a : b;
}

// Function implementing Knapsack DP matching your pseudocode structure
int knapsackDp(int n, int w[MAX_ITEMS], int p[MAX_ITEMS], int M) {
    // Dynamic programming matrix: Table[n+1][M+1]
    int Table[MAX_ITEMS][MAX_WEIGHT];
    
    // Step 1: Initialize the first column with zeros 
    // Corresponds to your note: Table[i, 0] = 0
    for (int i = 0; i <= n; i++) {
        Table[i][0] = 0;
    }
    
    // Step 2: Initialize the first row with zeros
    // Corresponds to your note: Table[0, j] = 0
    for (int j = 0; j <= M; j++) {
        Table[0][j] = 0;
    }
    
    // Step 3: Fill the DP table tracking items and capacity bounds
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
    
    // Return the final maximum profit stored at the bottom right of the table
    return Table[n][M];
}

int main() {
    int n, M;
    int w[MAX_ITEMS]; // Weights array
    int p[MAX_ITEMS]; // Profits (or values) array

    printf("Enter number of items (n): ");
    scanf("%d", &n);

    printf("Enter maximum capacity of knapsack (M): ");
    scanf("%d", &M);

    // Using 1-based indexing for inputs to mirror the notebook logic
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

    // Run the implementation
    int max_profit = knapsackDp(n, w, p, M);

    // Output Results
    printf("\ncongrats\n");
    printf("Maximum profit obtained: %d\n", max_profit);

    return 0;
}
