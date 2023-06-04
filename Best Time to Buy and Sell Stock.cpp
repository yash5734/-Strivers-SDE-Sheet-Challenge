#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int maxi = 0;
    int min = INT_MAX;
    
    for(int i=0;i<prices.size();i++){
        if(prices[i]<min){
            min = prices[i];
        }
        else {
            maxi = max(prices[i]-min,maxi);
        }
    }
    return maxi;
}
