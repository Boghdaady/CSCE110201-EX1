#include "f1.h"
#include <iostream>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
  if (n == 0 || W == 0) {
    // Base Case: No items left or Knapsack capacity is 0
    return 0;
  }

  if (wt[n - 1] > W) {
    // If weight of the nth item is more than Knapsack capacity W,
    // then this item cannot be included in the optimal solution
    return knapSack(W, wt, val, n - 1);
  } else {
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) nth item not included
    return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
               knapSack(W, wt, val, n - 1));
  }
}
