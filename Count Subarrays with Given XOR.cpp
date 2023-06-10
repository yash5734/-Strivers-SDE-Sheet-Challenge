#include <bits/stdc++.h>

using namespace std;

int subarraysXor(vector<int>& arr, int x) {
    int n = arr.size();
    unordered_map<int, int> mp; // Use unordered_map instead of map for better performance
    int count = 0;
    int xr = 0;
    mp[0] =1;
    
  
    for (int i = 0; i < n; i++) {
        xr ^= arr[i];


        int rem = xr ^ x;

        count += mp[rem];

        mp[xr]++;
    }

    return count;
}
