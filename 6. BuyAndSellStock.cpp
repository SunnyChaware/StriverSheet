#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int profit = 0;
    int mini = prices[0];
    for(auto it: prices){
      // getting the current val
        int val = it - mini;
      //storing the profit
        profit = max(profit, val);
      // updating the mini.
        mini = min(mini, it);
    }
    return profit;
}
